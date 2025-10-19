#include "Bag.hpp"
#include <iostream>

/**
 * A Bag is a collection of Tokens (chips) that supports
 * functions that work by enumerating the contents.
 *
 * @author: Caden Matuszewicz
 */

Bag::Bag(int numTokens) : contents(numTokens) {}

void Bag::firstToken() const {
    if (!contents.empty())
        std::cout << contents[0].toString() << std::endl;
}

void Bag::allTokens() const {
    for (const auto& token : contents) {
        std::cout << token.toString() << std::endl;
    }
}

void Bag::allTokensWhile() const {
    size_t i = 0;
    // TODO: turn this into a while loop that enumerates and
    // prints all of the tokens in the bag
    while (i < contents.size()) {
        std::cout << contents[i].toString() << std::endl;
        ++i;
    }
}

int Bag::addTokens() const {
    // TODO: write a loop that enumerates the entire bag
	// and sums the total of all of the Token values
    int sum {0};
    for (size_t i{0}; i < contents.size(); ++i) {
            sum += contents[i].getValue();
    }
    return sum;
}

int Bag::highValueTokens() const {
    // TODO: write a loop that enumerates the entire bag
    // and returns the number of high value Tokens
    int sum {0};
    for (size_t i{0}; i < contents.size(); ++i) {
        if (contents[i].isHighValue()) {
            sum += contents[i].getValue();
        }
    }
    return sum;
}

int Bag::firstGreen() const {
    // TODO: search bag for a green Token, if found, return its index
    for (size_t i{0}; i < contents.size(); ++i) {
        if (contents[i].getColor() == std::string("Green)")) {
            return i;
        }
    }	
    return -1;
}