#include <iostream>
#include <vector>
#include <limits>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>

// Anthony Nguyen was here.

// Template to make code more re-usable (used with arbitrary types)
template <typename Domain, typename Func>
auto numerical_integration_serial(
    std::size_t N,
    Domain const& a,
    Domain const& b,    
    Func&& f            // Accepts R-value of type Func (which is for our lambda)
)
{
    // Sets N = 1 if its 0 to prevent division by 0 
    if(N == 0)
        N = 1;
    
    // Variables
    std::vector<std::size_t> indices(N);    // vector with N values (size_t)
    std::vector<Domain> midpoint(N);        // vector with N values (size_t)

    // Populates indices vector form 0 - (N-1)
    std::iota(begin(indices), end(indices), 0);

    // Calculation for delta_x and half_delta_x for integration calculation
    Domain const delta_x = (b-a)/N;
    Domain const half_delta_x = delta_x/2;

    // Populates midpoint with calculations based on
    // labmda calcuation and the indices vector values
    std::transform(
        begin(indices), 
        end(indices), 
        begin(midpoint), 
        [&delta_x, &half_delta_x](std::size_t const& index)
        {
            // iterates through indices and applies this calculation and store into midpoint
            return (index*delta_x)+half_delta_x;    // calculates then sets midpoint of each slice
        }
    );

    // Return the integration calculation (double)
    return std::transform_reduce(
        begin(midpoint),
        end(midpoint), 
        decltype(f(a)){},
        [](auto const& a, auto const& b)
        {
            // Sums all the sectioned areas just calculated (below)
            return a+b;     
        },
        [&delta_x, &f](auto const& c)
        {
            // Applies this onto all elements on input range
            return f(c) * delta_x;      // function on calculated midpoint and multiply by delta_x (approx area of that section)
        }
    );
}

// The Protagonist :>
int main()
{
    // Loop for number of intervals (intervals of 10's)
    for (std::size_t i = 1; i <= 10000; i=i*10)
    {
        // Call numerical_integration_serial and store output into estimate
        auto estimate = numerical_integration_serial(
            i,
            0.0,
            1.0,
            #ifdef USE_EXP_FUNC  //preprocessor if statement checks for which lambda function to use based on macro
            [](double const &x)
            {
                return std::exp(-x*x);  
            }
            #elif defined(USE_PI_ESTIMATE)      // pre proc else if. Checks if USE_PI_ESTIMATE is defined
            [](double const& x) 
            {
                return 1.0 / (1.0 + x*x);
            }
            #else       // if no macro was defined (if/elif) then print out error message
            #error "USE_EXP_FUNC or USE_PI_ESTIMATE must be #defined."
            #endif
        );
        
        // writing to stdout (output)
        std::cout
            << "integration estimate of f over [0,1] using "
            << i        // # of intervals
            << " intervals: "
            << std::scientific      // changing output values fater this to scientific notation 
            << std::setprecision(std::numeric_limits<double>::digits10 + 1) // determines how precise the double is num<double>::digits10 determines how many decimal digits double can hold without loss
            #ifndef  USE_PI_ESTIMATE    // pre processor if statement based on macro
            << estimate 
            #else
            << estimate * 4             // returns the estimate * 4 if calculating pi/4 estimation (returns Pi estimation)
            #endif
            << '\n';
    }
}