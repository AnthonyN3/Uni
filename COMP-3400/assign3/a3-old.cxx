#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <map> 

using namespace std;

//------

struct card
{
    enum class suit { club, spade, diamond, heart };
    enum { ace=1, jack=10, queen=11, king=12 };
    using number = int;

    number num_;
    suit suit_;
};

bool operator ==(card const& a, card const& b)
{
    return a.num_ == b.num_ && a.suit_ == b.suit_;
}

bool operator <(card const& a, card const& b)
{
    return a.num_ < b.num_;
}

istream& operator >>(istream& is, card& c)
{
    // number followed by the suit (CSHD)...
    is >> c.num_;

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

struct cards
{
    //vector<card> cs_;
    map<card, unsigned> freqhist;
};

ostream& operator <<(ostream& os, cards const& mycards)
{
    for (auto& elem: mycards.freqhist)
        os << elem.first << " occurs " << elem.second << " time(s)" << '\n';
    return os;
}

istream& operator >>(istream& is, cards& mycards)
{
    size_t sz;
    if (is >> sz)
    {
        //mycards.cs_ = vector<card>{}; // assign an empty vector to mycards.cs_

        for (size_t i=0; i != sz; ++i)
        {
            card c;
            if (is >> c)
                ++mycards.freqhist[c];
            else
            {
                is.setstate(ios::badbit);
                break;
            }
        }
    }
  return is;
}

int main()
{
    cards mycards;
    if (cin >> mycards)
        cout << mycards;
}


