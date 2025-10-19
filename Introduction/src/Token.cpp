#include "Token.hpp"
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <random>

const unsigned int SEED = 46;
std::default_random_engine engine{SEED};

const int Token::MAX_VALUE = 10;
const std::vector<std::string> Token::colors = {"Green", "Blue", "Yellow", "Red"};

Token::Token(const std::string& color, int value) : color(color), value(value) {}

/**
* Creates a Token with randomly chosen color and value
* ask student to implement random implementation
*/

Token::Token() {

    // Define distributions for value and color
    static std::uniform_int_distribution<int> value_dist(0, MAX_VALUE);
    static std::uniform_int_distribution<size_t> color_dist(0, colors.size() - 1);

    // Use the engine to generate random values
    color = colors[color_dist(engine)];
    value = value_dist(engine);
}

std::string Token::getColor() const {
    return color;
}

int Token::getValue() const {
    return this->value;
}

void Token::setColor(const std::string& color) {
    this->color = color;
}

void Token::setValue(int value) {
    this->value = value;
}

bool Token::isMax() const {
    return value == MAX_VALUE;
}

bool Token::isHighValue() const {
    return (value > (MAX_VALUE/2));
}

std::string Token::toString() const {
    // TODO: Complete this line of code so that it will also print the value of the token
	return std::string("Token's color is ") + color + std::string(" and has value ") + std::to_string(value);
}