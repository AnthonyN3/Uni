#include <iostream>
#include <vector>
#include <limits>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <execution>

#include "benchmark.hxx"
#include "iota_iterator.hxx"

// Anthony Nguyen was here.

// Template to make code more re-usable (used with arbitrary types)
// ExecutionPolicy will be used for running this in parallel
template <typename Domain, typename Func, typename ExecutionPolicy>
auto numerical_integration(
    ExecutionPolicy&& ep,
    std::size_t N,
    Domain const& a,
    Domain const& b,
    Func&& f                // Accepts R-value of type Func (which is for our lambda)
)
{
    // Sets N = 1 if its 0 to prevent division by 0 
    if(N == 0)
        N = 1;

    // Calculation for delta_x and half_delta_x for integration calculation
    Domain const delta_x = (b-a)/N;
    Domain const half_delta_x = delta_x/2;   

    // Return the integration calculation (double)
    return std::transform_reduce(
        std::forward<ExecutionPolicy>(ep),      // perfectly forwarding (for execution::par_unseq)
        iota_iterator<size_t>{},                // Fake points to integer values (iota)
        iota_iterator<size_t>{N}, 
        decltype(f(a)){},
        [](auto const& a, auto const& b) 
        {
            // Sums all the sectioned areas just calculated (below)
            return a+b;
        },
        [&delta_x, &half_delta_x,&f](auto const& c)    
        {
            // Applies this onto all elements on input range (iota)
            // integral of that particular slice calculated here
            return f((c*delta_x)+half_delta_x)*delta_x; // applies the function passed in argument
        }
    );
}

// The Protagonist :>
int main()
{
    // Loop for number of intervals (intervals of 10's)
    for (std::size_t i = 1; i <= 100'000'000; i=i*10)   // new C++ versions introduce ability to break long numbers (100'000'00).. NEAT!
    {
        // variable to hold estimation caluclation
        double estimate{};  // default constructed

        // Run benchmark store elapsed time in variable
        auto const par_elapsed_secs = benchmark(
            [&]()   // "&" catches all variables (ie. estimate)
            {
                // Call numerical_integration in lambda function
                // and store its result into the estimate variable
                estimate = numerical_integration(
                    std::execution::par_unseq,
                    i,
                    0.0,
                    1.0,
                    #ifdef USE_EXP_FUNC //preprocessor if statement checks for which lambda function to use based on macro
                    [](double const& x) 
                    {
                        return exp(-x*x);  
                    }
                    #elif defined(USE_PI_ESTIMATE) // pre proc else if. Checks if USE_PI_ESTIMATE is defined
                    [](double const& x) 
                    {
                        return 1.0 / (1.0 + x*x);
                    }
                    #else   // if no macro was defined (if/elif) then print out error message
                    #error "USE_EXP_FUNC or USE_PI_ESTIMATE must be #defined."
                    #endif
                );
            }
            
        );
        
        // writing to stdout (output)
        std::cout
            << "integration estimate of f over [0,1] using "
            << i                // # of intervals
            << " intervals taking "
            << std::defaultfloat    // values after will output in default float (for the benchmark times)
            << par_elapsed_secs
            << " seconds, result: "
            << std::scientific  // Sets output to scientific not.
            << std::setprecision(std::numeric_limits<double>::digits10 + 1) // Sets precision to max double prec w/o loss (change)
            #ifndef  USE_PI_ESTIMATE    // output estimate based on which function is being integrated (macro)
            << estimate 
            #else
            << estimate * 4
            #endif
            << '\n';
    }
}