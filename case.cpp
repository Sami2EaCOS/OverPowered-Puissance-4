#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cmath>

#include "case.hpp"

// When a case is created, she's empty

Case :: Case() {
    m_full = false;
    m_color = sf::Color::Black;
}

// Method to see if a case is empty or not

bool Case :: ifEmpty() {
    return m_full;
}

// Method to see the color of a case

sf::Color Case :: getColor() {
    return m_color;
}

// Method to change the color of a case

bool Case :: putColor(sf::Color color) {
    m_color = color;

    // if the color isn't black, case is full

    if (m_color == sf::Color::Black) {
        m_full = false;
        return m_full;
    } else {
        m_full = true;
        return m_full;
    }
}



