#ifndef TURN_HPP
#define TURN_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

class Turn
{
private:
    int m_turn_nomber;
    int m_turn;
    int m_turn_event;
    int m_turn_played;
    sf::Text m_text;
    sf::Font m_font;

public:
    Turn();
    int nomberOfTurn();
    int nextTurn();
    int playedTurn();
    int colorTurn();
    int randomTurn();
    int eventTurn();
    void drawTurn(sf::RenderWindow& window);
    void restart();

};


#endif // TURN_HPP
