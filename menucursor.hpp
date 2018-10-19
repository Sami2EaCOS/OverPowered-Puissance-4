#ifndef MENUCURSOR_HPP
#define MENUCURSOR_HPP

#include <SFML/Graphics.hpp>
#include <ctime>

#include "timecheck.hpp"
#include "mouseSelection.hpp"

class StateManager;
class MenuCursor
{
private:
    sf::RectangleShape m_form;
    sf::Time m_time;
    int m_placement;
    int m_input_move;
    Timecheck m_timecheck;
    Timecheck m_timecheck2;

public:
    MenuCursor();
    void cursorColor(sf::Time& time);
    void draw(sf::RenderWindow& window);
    void cursor(StateManager& sm, int placement);
};

#endif // MENUCURSOR_HPP
