#ifndef CURSOR_HPP
#define CURSOR_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

class Cursor
{
private:

    float m_zoom_factor_cursor;
    sf::RectangleShape m_formCursor;
    int m_placement;
    sf::Time m_time;

public:

    Cursor();

    void cursorResize(sf::Vector2f old_size, sf::Vector2f new_size);
    int positionCursor();
    void cursorColor(sf::Color color);
    void cursorColorWin();
    void cursorMove(int cursor_input);
    void cursorMoveMouse(int cursor_input);
    void cursorDraw(sf::RenderWindow& window);
    void restart();

};

#endif // CURSOR_HPP
