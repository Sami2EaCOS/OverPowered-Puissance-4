#ifndef MOUSESELECTION_HPP
#define MOUSESELECTION_HPP

#include "SFML/Graphics.hpp"
#include "timecheck.hpp"

class MouseSelection
{
private:
    Timecheck m_timecheck;

public:
    MouseSelection();
    int mouseDetection(sf::RenderWindow& window, sf::Text& text, sf::Event event,  sf::Color color);
    int mouseDetection(sf::RenderWindow& window, sf::Text& text, sf::Event event,  sf::Color color, int a);
    int mouseDetection(sf::RenderWindow& window, sf::RectangleShape& shape, sf::Event event, sf::Color color);
    int mouseDetection(sf::RenderWindow& window, sf::Text& text, sf::Event event);
};

#endif // MOUSESELECTION_HPP
