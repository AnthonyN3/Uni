#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	// Variable declarations
    vector<string> v;		// A vector of strings
    string str;

    // While loop to loop through standard input and take all words/input
    // temporarily storing it in a str string variable
    while(cin >> str)
        v.push_back(str);	// pushes/inserts each standard input string into the vector v

    // Find the first occurance of "begin" and assign its iterator value into pos1 (if found)
    auto pos1 = find(begin(v), end(v), "begin");
    
    // check if pos1 isn't v.end() (begin not found) and increment/move iterator by 1 (to exclude begin in copy)
    if (pos1 != v.end())
        ++pos1;
    
    // Find the first occurance of "end" startfrom from pos1 to the end(v)
    auto pos2 = find(pos1, end(v), "end");	// starts at pos1

    // Copy the contents between the incremetors pos1 and pos2 into cout (between "begind" | "end")
    copy(pos1, pos2, ostream_iterator<string>(cout, " ") );
    cout << '\n';
}
