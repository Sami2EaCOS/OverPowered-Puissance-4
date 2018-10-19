#ifndef CASE_HPP
#define CASE_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

class Case {
private:
    bool m_full;
    sf::Color m_color;

public:
    Case();

    bool ifEmpty();
    bool putColor(sf::Color color);
    sf::Color getColor();
};

#endif // CASE_HPP
