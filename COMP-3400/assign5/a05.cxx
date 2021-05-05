#include <vector>
#include <memory>
#include <string>
#include <type_traits>
#include <utility>
#include <iostream>

// Animal class will be used mostly for inheritence (Abstract class)
class animal
{
public:
	// Destructor
	virtual ~animal() { }
	// Pure virtual method
	virtual std::string kind() const = 0;	// setting virtual method "=0" makes this an abstract class in Cpp
};

using animal_ptr = std::unique_ptr<animal>;	// Alias for unique_ptr<animal>

// Creates an animal object from t where t is any type (uses T&& implying r value)
// returns animal_ptr of the created object
template <typename T>
animal_ptr make_animal(T&& t)
{
	using type = std::remove_cvref_t<T>;				// use for type traits for use of forward() & new t
	return animal_ptr{ new type(std::forward<T>(t)) };	// creates T t object (allocates space and return its pointer)
}

// cat class inherits from animal publicly and virtually
class cat : public virtual animal
{
public:
	// Overrided method from animal
	std::string kind() const override
	{
	    using namespace std::literals; 	// use of std::literals to make it a std::string and not a const char
	    return "Felis catus";			// returns said string as str::string
	}
};

// dog class inherits from animal publicly and virtually
class dog : public virtual animal
{
private:
	// Variable Delcaration
	std::string dog_name;

public:
	// deleted default constructor
	dog() = delete;
	 // defaulted copy constructor
	dog(const dog& a) = default;
	// defaulted copy assignment operator
	dog& operator =(dog const& b) = default;
	// overloaded constructor
	dog(std::string const& name) : dog_name(name) {};   // Takes string and sets dog_name to it

	// overrided kind() method from inherited animal class
	std::string kind() const override
	{
	    using namespace std::literals;		// use of std::literals to make it a std::string and not a const char
	    return "Canis lupus familiaris";	// returns said string as str::string
	}

	// method that returns the private dog_name property (string)
	std::string const& name()
	{
	    return dog_name;
	}
};

// dog class inherits from dog and cat publicly and virtually
class dogcat : public virtual dog, cat
{
public:
	// default constructor that invokes dog with "hybrid" and cat() in initializer list
	dogcat(): dog("hybrid"), cat()
	{
	}
	// overlaoded constructor that takes a dog and cat object
	// and passes them to its parent/inherited copy constructor respectively
	dogcat(dog const& d, cat const& c) : dog(d), cat(c)
	{
	}
	// default copy assignment operator
	dogcat& operator =(dogcat const& b) = default;

	// overrided kind() method from both dog & cat class
	std::string kind() const override
	{
	    return dog::kind() + " + " +  cat::kind();	// combines the kind() method from both parent class
	}
};

// overloaded + operator for dog and cat object
dogcat operator +(dog const& d, cat const& c)
{
	return dogcat(d,c);	// takes dog/cat arg and combines by invoke dogcat overloaded constructor
}

int main()
{
	// Variable Declarations
	std::vector<animal_ptr> v;		// declare a list(vector) of animal_ptr, v
	dog d("Fido");					// declare dog d with "Fido"
	cat c;							// declare cat c with default constructor

	// vector operations
	v.push_back(make_animal(d));	// initializes dog d and pushes ptr into vecto
	v.emplace_back(new cat());		// initializes cat (r value) and pushes ptr into vector
	v.push_back(make_animal(d+c));	// initializes dogcat class by combing dog and cat and calling make_animal and pushes ptr vector

	// output
	// loops through all the animal_ptr in v
	for(auto const& e : v)
	{
		std::cout << e->kind();							// output e's kind using method call via ptr (->)
		dog* dog_ptr = dynamic_cast<dog*>(e.get());		// declare dog ptr and set it to e's pointer (dynimcally casting dogcat to dog)

		// check if dog_ptr is set to null. If not then return dogs name
		if(dog_ptr != nullptr)
		    std::cout << ", name = " << dog_ptr->name();

		std::cout << '\n';	// :)
	}
}
