// Anthony Nguyen

#include <iostream>

// struct definition
struct score
{
  // variable declaration
  std::string first_name_;
  std::string last_name_;
  unsigned int score_;
};

// Input(>>) overloaded to allow for input for struct score
std::istream& operator >>(std::istream& is, score& s)
{
  // Store contents in input stream reference into the struct s
  is >> s.first_name_ >> s.last_name_ >> s.score_;
  return is;
}

// Output(<<) overloaded to allow for output for struct score
std::ostream& operator <<(std::ostream& os, score const& s)
{
  // Write out the variables in s into the output stream reference
  os << s.first_name_ << ' ' << s.last_name_ << ' ' << s.score_;
  return os;
}

int main()
{
  score s;  // variable declaration of struct score

  // While loop to loop through standard input which is pushed into s
  // (uses our defined input overload for score)
  while (std::cin >> s)
  {
    std::cout << s << '\n'; // Write out s to standard output using score output overload
  }
}
