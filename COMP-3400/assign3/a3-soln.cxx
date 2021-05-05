#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <map> 

using namespace std;

//------ (parts taken from code example in class)

// Object card that holds card number and suit
struct card
{
    // Our defined enumerations for suits and card #'s > 9
    enum class suit { club, spade, diamond, heart };
    enum { ace=1, jack=10, queen=11, king=12 };
    using number = int;     // alias

    // Variables
    number num_;
    suit suit_;
};

// defining comparison operation between card struct
bool operator ==(card const& a, card const& b)
{
    return a.num_ == b.num_ && a.suit_ == b.suit_;  // if suit and number equal than return true
}

// defining less than comparison between card struct
bool operator <(card const& a, card const& b)
{
    return a.num_ < b.num_;         // Check if number on a is less than b then return true.
}

// define input from standard input into card
// just store input values into card struct
istream& operator >>(istream& is, card& c)
{
    // number followed by the suit (CSHD)...
    is >> c.num_;
    
    // grab the char value (suit) and determine 
    // what suit it is and store into card "c"
    char ch;
    if (is >> ch)
    {
        switch (ch)
        {
        case 'C': c.suit_ = card::suit::club; break;
        case 'S': c.suit_ = card::suit::spade; break;
        case 'H': c.suit_ = card::suit::heart; break;
        case 'D': c.suit_ = card::suit::diamond; break;
        default:
            is.setstate(ios::failbit);
            break;
        }
    }
    else
        is.setstate(ios::badbit);
    return is;
}

// define output to stanrdard ouput
// writes out "NS" where N = number on card and S = Suit of card
ostream& operator <<(ostream& os, card const& c)
{
    os << c.num_;

    switch (c.suit_)
    {
        // card::suit allows us to access suit
        // suit::club allows us to access club
        // thus, card::suit::club lets us access club
        case card::suit::club:
        os << 'C';
        break;

        case card::suit::spade:
        os << 'S';
        break;

        case card::suit::diamond:
        os << 'D';
        break;

        case card::suit::heart:
        os << 'H';
        break;
    }

    return os;
}

//------

// struct just holds a map of cards with their frequency
struct cards
{
    map<card, unsigned> freqhist;
};

// Output(<<) overloaded to allow for output for struct cards
// Writes out contents of cards map of cards into standard output
ostream& operator <<(ostream& os, cards const& mycards)
{
    for (auto& elem: mycards.freqhist)
        os << elem.first << " occurs " << elem.second << " time(s)" << '\n';
    return os;
}

// Input(>>) overloaded to allow for input for struct cards
// Standard input goes into mapping
istream& operator >>(istream& is, cards& mycards)
{
    card c; // Temporary card variable to hold input

    // stores standard input into the card c (if statement used to check for error detection)
    if (is >> c)
        ++mycards.freqhist[c];  // stores card value into map if not already in map and increment by 1 
    else
        is.setstate(ios::badbit);   // Error in reading standard input and storing into card c
    return is;
}

int main()
{   
    cards mycards;              // variable cards declaration
    while (cin >> mycards);     // takes standard input and stores into mapping and loop till eof/error
    cout << mycards;            // Writes out the mapping of the cards to standard output
}