#ifndef EVENT_HPP
#define EVENT_HPP

#include "grid.hpp"
#include "turn.hpp"

#include <SFML/Graphics.hpp>

class Event {

private:
    int m_event;
    bool m_pass;
    sf::Text m_text;
    sf::Text m_text_2;
    sf::Font m_font;
    sf::Color m_player1;
    sf::Color m_player2;

    int m_noEvent;

public:
    Event();
    void chooseRandomEvent(int choiceEvent[]);
    void playEvent(Turn turn, Grid& grid);
    bool canChoose();
    void draw(sf::RenderWindow& window);
    void playerColor(sf::Color player1, sf::Color player2);
    void restart();

};

#endif // EVENT_HPP
