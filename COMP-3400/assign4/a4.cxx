#include <deque>
#include <iterator>
#include <random>
#include <numeric>
#include <iostream>

#include "card.hxx"

using cards = std::deque<card>;         // using cards for alias to std::deque<card> 

// Operator to overlaoded output data for cards
// "<<" with cards writes out all the card in deque
std::ostream& operator <<(std::ostream& os, cards const& c)
{   
    // Write out all contents in cards into ostream with a whitespace sperating each
    copy(begin(c), end(c), std::ostream_iterator<card>(os, " "));   
    return os;
}

// Generates a deck of cards
cards gen_deck_of_cards()
{
  cards retval;     // Cards holder for return value

  // Loops through all card faces and card suits making a pair with each
  for (card_faces f(card_faces_begin), fEnd; f != fEnd; ++f) // from [ace, king+1) (card.hxx) f/fend calls card_faces constructor
    for (card_suits s(card_suits_begin), sEnd; s != sEnd; ++s) // loops from all the suits
      retval.push_back(card{*f,*s});                           // pushe card with specifc suit/face into cards retval
  return retval;
}

// Radnomly shuffles the deck of cards
void shuffle_cards(cards& cs)
{
    std::random_device rd;              // random number generator
    std::mt19937 gen(rd());             // Is a random number engine based algorithm (generates 32 bit number)
    std::shuffle(cs.begin(), cs.end(), gen); // Radnomly shuffles cards (queue) [begin,end)
}

// Drawng N cards from the deck (cards)
cards draw(size_t num, cards& deck)
{
    auto pos(deck.begin()); // same as "auto pos = deck.begin()".. define pos as beginning iterator of deck
    
    // Checks if the amount wanting to drawn is less or more than the deck
    if(num <= deck.size())
        std::advance(pos,num);   // moves up the iterator (pos) by N (num)
    else
        pos = deck.end();        // set pos to the end of cards (technically the last value after end)
    
    cards drawn(deck.begin(), pos);     // temp cards from beginning of deck to new pos..can also do cards drawn = cards(deck.begin(), pos);
    deck.erase(deck.begin(), pos);      // erase the contents drawn (or none if num_drawn > deck.size)
    return drawn;
}

// Calculating score of hand
auto calc_score(cards const& hand) -> std::pair<size_t, size_t>
{
    // Lambda functions LOW_SUM_OP and HIGH_SUM_OP calculates possible different values based on if hand contains an Ace
    // also the lambda functions setup as binary operation for accumulate (so first argument uses size_t for sum)
    
    auto LOW_SUM_OP = [](size_t const& a, card const& b) 
    {
        card::face_type c = b.face(); // Gets the face value of the card b and store into c
        // Using ternary operators to check if card face is an ace and returns 1.
        // If it isn't an ace and checks if its a jack,queen,king and if it is returns 10. If its either than it returns the card face value
        return a + ((c == card::ace) ? 1 : ((c == card::jack || c == card::king || c == card::queen) ? 10 : c) );
    };

    // Works the same as LOW_SUM_OP but replaces 1 with 11 (ace returns 11 and not 1)
    auto HIGH_SUM_OP = [](size_t const& a, card const& b)
    {
        card::face_type c = b.face();
        // Note: Would have been simpler to just write "c >= card::jack" instead of the "||", but this was more clear.
        return a + ((c == card::ace) ? 11 : ((c == card::jack || c == card::king || c == card::queen) ? 10 : c) );
    };

    // Use accumulate to calculate the score in hand using our defined LOW_SUM_OP and HIGH_SUM_OP as binary operation
    size_t low = accumulate(hand.begin(), hand.end(), size_t{}, LOW_SUM_OP);
    size_t high = accumulate(hand.begin(), hand.end(), size_t{}, HIGH_SUM_OP);

    // Return the low and high calculated score as a pair of size_t
    return {low, high};
}

int main()
{
    cards deck(gen_deck_of_cards()); // Generate cards and set to "deck"
    shuffle_cards(deck);             // Shuffle the deck of cards
    
    // outputs
    std::cout << "Deck: " << deck << '\n';
    std::cout << '\n';
    std::cout << "Drawing 3 cards... \n";

    cards hand(draw(3,deck));   // Draw 3 cards from deck and store the 3 drawn cards into "hand"

    // output the deck and hand
    std::cout << "Deck: " << deck << '\n';
    std::cout << "Hand: " << hand << '\n';

    auto score(calc_score(hand));   // Calculate the score of the hand and set pair return value into score

    // Check if the two scores (low/high) are the same and return output dependingly
    if(score.first == score.second)
        std::cout << "Score: " << score.first << '\n'; // return one score (since pair ==))
    else
        std::cout << "Possible Score: " << score.first << ' ' << score.second << '\n'; // return low then high score (since pair !=)
}