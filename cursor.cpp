#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cmath>
#include "cursor.hpp"

#include "defining.hpp"

Cursor :: Cursor() : m_formCursor(sf::Vector2f(CASE_SIZE * m_zoom_factor_cursor, 6.0f)), m_zoom_factor_cursor(1.0f), m_placement(0)
{
    m_formCursor.setOrigin(-1 *((800 - CASE_SIZE * LENGTH_BOARD)/2) * m_zoom_factor_cursor, -1 * ((600 - CASE_SIZE * WIDTH_BOARD)/2.3f) * m_zoom_factor_cursor);
    m_formCursor.setFillColor(sf::Color::White);
    m_formCursor.setOutlineThickness(2);
    m_formCursor.setOutlineColor(sf::Color::Black);
}

void Cursor :: cursorResize(sf::Vector2f old_size, sf::Vector2f new_size)
{
    float m_zoom_factor_cursor = new_size.y / old_size.y;
}

void Cursor :: cursorMove(int cursor_input)
{
    if (cursor_input == 1)
    {
        if (m_placement != 0)
        {
            m_placement -= 1;
            m_formCursor.setPosition(m_placement * CASE_SIZE * m_zoom_factor_cursor, 1);
        }
    }
    else if (cursor_input == 2)
    {
        if (m_placement != LENGTH_BOARD - 1)
        {
            m_placement += 1;
            m_formCursor.setPosition(m_placement * CASE_SIZE * m_zoom_factor_cursor, 1);
        }
    }
}

void Cursor :: cursorMoveMouse(int cursor_input)
{
    m_placement = cursor_input;
    m_formCursor.setPosition(m_placement * CASE_SIZE * m_zoom_factor_cursor, 1);
}

void Cursor :: cursorColor(sf::Color color)
{
    m_formCursor.setFillColor(color);
}

void Cursor :: cursorColorWin()
{
    /*
    float freq = 1.2f;
    sf::Color fc;

    m_time += time;

    fc.r = SIN(freq, m_time.asSeconds(), 0.0f);
    fc.g = SIN(freq, m_time.asSeconds(), 2.0f);
    fc.b = SIN(freq, m_time.asSeconds(), 4.0f);
    */

    m_formCursor.setFillColor(sf::Color::Black);
}


int Cursor :: positionCursor()
{
    return m_placement;
}

void Cursor :: cursorDraw(sf::RenderWindow& window)
{
    window.draw(m_formCursor);
}

void Cursor :: restart()
{
    m_placement = 0;
    m_formCursor.setPosition(m_placement * CASE_SIZE * m_zoom_factor_cursor, 1);
}
