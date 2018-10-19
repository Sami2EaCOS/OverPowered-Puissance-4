#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <iostream>
#include "grid.hpp"
#include "case.hpp"

#include "defining.hpp"

Grid :: Grid() : m_zoom_factor(1.0f), m_type_of_victory(0), m_y(0), m_x(0)
{
    for (int i=0; i < LENGTH_BOARD; ++i)
    {
        std::vector<Case> temp;
        for (int j=0; j < WIDTH_BOARD; ++j)
        {
            Case c;

            temp.push_back(c);
        }
        m_board.push_back(temp);
    }

    if (!m_font.loadFromFile("police.ttf"))
    {
        // erreur...
    }
    m_text_winner.setFont(m_font);
    m_text_winner.setString("");
    m_text_winner.setCharacterSize(30);
    m_text_winner.setColor(sf::Color::White);

    sf::FloatRect rect = m_text_winner.getGlobalBounds();
    int scale = rect.width/2;
    m_text_winner.setPosition(400-scale, 500);
}

int Grid :: colorize(int column, sf::Color color)
{
    for (int b=WIDTH_BOARD-1; b >= 0; --b)
    {
        if (m_board [column] [b].ifEmpty() == false)
        {
            m_board [column] [b].putColor(color);
            return 0;
        }
    }
 }

bool Grid :: ifIsEmpty(int column)
{
    for (int b=0; b < WIDTH_BOARD; ++b)
    {
        if (m_board [column] [b].ifEmpty() == false)
        {
            return true;
        }
    }
    return false;
}

void Grid :: onResize(sf::Vector2f old_size, sf::Vector2f new_size)
{
    float m_zoom_factor = new_size.y / old_size.y; //calcul de proportionnalité pour avoir le coefficient
}

void Grid :: draw(sf::RenderWindow& window)
{
    window.draw(m_text_winner);
    for (std::size_t t=0; t < m_board.size(); ++t)
    {
        for (std::size_t t2=0; t2 < m_board[t].size(); ++t2)
        {
            sf::RectangleShape s(sf::Vector2f(CASE_SIZE * m_zoom_factor, CASE_SIZE * m_zoom_factor));
            s.setOrigin(-1 *((800 - CASE_SIZE * LENGTH_BOARD)/2) * m_zoom_factor, -1 * ((600 - CASE_SIZE * WIDTH_BOARD)/2) * m_zoom_factor);
            s.setFillColor(sf::Color::White);
            s.setOutlineColor(sf::Color::White);
            s.setOutlineThickness(1);
            s.setPosition(t * CASE_SIZE * m_zoom_factor, t2 * CASE_SIZE * m_zoom_factor);

            sf::CircleShape r;
            r.setRadius(CIRCLE_RADIUS * m_zoom_factor);
            r.setOrigin(-1 *((800 - CASE_SIZE * LENGTH_BOARD)/1.95) * m_zoom_factor, -1 * ((600 - CASE_SIZE * WIDTH_BOARD)/1.95) * m_zoom_factor);
            r.setFillColor(m_board[t] [t2].getColor());
            r.setOutlineThickness(1);
            r.setOutlineColor(sf::Color::Black);
            r.setPosition(t * CASE_SIZE * m_zoom_factor, t2 * CASE_SIZE * m_zoom_factor);

            window.draw(s);
            window.draw(r);
        }
    }
}

bool Grid :: victoryVertical(sf::Color color1, sf::Color color2)
{
    int x = 0;
    int y = 0;

    for (int b1=LENGTH_BOARD-1; b1 >= 0; --b1)
    {
        m_nomber_vertical_color1[b1] = 0;
        m_nomber_vertical_color2[b1] = 0;
        for (int b2=WIDTH_BOARD-1; b2 >= 0; --b2)
        {
            if (m_board [b1] [b2].getColor() == color1)
            {
                m_nomber_vertical_color1[b1] += 1;
                m_nomber_vertical_color2[b1] = 0;
            }
            if (m_board [b1] [b2].getColor() == color2)
            {
                m_nomber_vertical_color2[b1] += 1;
                m_nomber_vertical_color1[b1] = 0;
            }
            if (m_board [b1] [b2].getColor() != color1 && m_board [b1] [b2].getColor() != color2)
            {
                m_nomber_vertical_color1[b1] = 0;
                m_nomber_vertical_color2[b1] = 0;
            }

            if (m_nomber_vertical_color1[b1] >= 4 || m_nomber_vertical_color2[b1] >= 4)
            {
                m_b1 = b1;
                m_b2 = b2;
                if (m_nomber_vertical_color1[b1] >= 4)
                {
                    m_text_winner.setString("Le joueur 1 est le vainqueur");
                    m_text_winner.setColor(color1);

                    sf::FloatRect rect = m_text_winner.getGlobalBounds();
                    int scale = rect.width/2;
                    m_text_winner.setPosition(400-scale, 500);

                    x = 1;
                    m_x = 1;
                }
                if (m_nomber_vertical_color2[b1] >= 4)
                {
                    m_text_winner.setString("Le joueur 2 est le vainqueur");
                    m_text_winner.setColor(color2);

                    sf::FloatRect rect = m_text_winner.getGlobalBounds();
                    int scale = rect.width/2;
                    m_text_winner.setPosition(400-scale, 500);

                    y = 1;
                    m_y = 1;
                }
            }
        }
    }
    if (x == 1 || y == 1)
    {
        m_type_of_victory = 1;
        return true;
    }
    else
    {
        return false;
    }
}

bool Grid :: victoryHorizontal(sf::Color color1, sf::Color color2)
{
    int x = 0;
    int y = 0;


    for (int b2=WIDTH_BOARD-1; b2 >= 0; --b2)
    {
        m_nomber_horizontal_color1[b2] = 0;
        m_nomber_horizontal_color2[b2] = 0;
        for (int b1=LENGTH_BOARD-1; b1 >= 0; --b1)
        {
            if (m_board [b1] [b2].getColor() == color1)
            {
                m_nomber_horizontal_color1[b2] += 1;
                m_nomber_horizontal_color2[b2] = 0;
            }
            if (m_board [b1] [b2].getColor() == color2)
            {
                m_nomber_horizontal_color2[b2] += 1;
                m_nomber_horizontal_color1[b2] = 0;
            }
            if (m_board [b1] [b2].getColor() != color1 && m_board [b1] [b2].getColor() != color2)
            {
                m_nomber_horizontal_color1[b2] = 0;
                m_nomber_horizontal_color2[b2] = 0;
            }

            if (m_nomber_horizontal_color1[b2] >= 4 || m_nomber_horizontal_color2[b2] >= 4)
            {
                m_b1 = b1;
                m_b2 = b2;
                if (m_nomber_horizontal_color1[b2] >= 4)
                {
                    m_text_winner.setString("Le joueur 1 est le vainqueur");
                    m_text_winner.setColor(color1);

                    sf::FloatRect rect = m_text_winner.getGlobalBounds();
                    int scale = rect.width/2;
                    m_text_winner.setPosition(400-scale, 500);

                    x = 1;
                    m_x = 1;
                }
                if (m_nomber_horizontal_color2[b2] >= 4)
                {
                    m_text_winner.setString("Le joueur 2 est le vainqueur");
                    m_text_winner.setColor(color2);

                    sf::FloatRect rect = m_text_winner.getGlobalBounds();
                    int scale = rect.width/2;
                    m_text_winner.setPosition(400-scale, 500);

                    y = 1;
                    m_y = 1;
                }
            }
        }
    }
    if (x == 1 || y == 1)
    {
        m_type_of_victory = 2;
        return true;
    }
    else
    {
        return false;
    }
}

bool Grid :: victoryLeftDiagonal(sf::Color color1, sf::Color color2)
{
    int length = LENGTH_BOARD-3;
    int width = WIDTH_BOARD-3;

    int x = 0;
    int y = 0;

    for (int b1 = 0; b1 < length; b1++)
    {
        for (int b2 = 0; b2 < width; b2++)
        {
            m_nomber_left_color1[b1] [b2] = 0;
            m_nomber_left_color2[b1] [b2] = 0;
            for (int a = 0; a <= 3; a++)
            {
                int c1 = b1+a;
                int c2 = b2+a;

                if (m_board [c1] [c2].getColor() == color1)
                {
                    m_nomber_left_color1[b1] [b2] += 1;
                    m_nomber_left_color2[b1] [b2] = 0;
                }
                if (m_board [c1] [c2].getColor() == color2)
                {
                    m_nomber_left_color2[b1] [b2] += 1;
                    m_nomber_left_color1[b1] [b2] = 0;
                }
                if (m_board [c1] [c2].getColor() != color1 && m_board [c1] [c2].getColor() != color2)
                {
                    m_nomber_left_color1[b1] [b2] = 0;
                    m_nomber_left_color2[b1] [b2] = 0;
                }

                if (m_nomber_left_color1[b1] [b2] == 4 || m_nomber_left_color2[b1] [b2] == 4)
                {
                    m_b1 = b1;
                    m_b2 = b2;
                    if (m_nomber_left_color1[b1] [b2] == 4)
                    {
                        m_text_winner.setString("Le joueur 1 est le vainqueur");
                        m_text_winner.setColor(color1);

                        sf::FloatRect rect = m_text_winner.getGlobalBounds();
                        int scale = rect.width/2;
                        m_text_winner.setPosition(400-scale, 500);

                        x = 1;
                        m_x = 1;
                    }
                    if (m_nomber_left_color2[b1] [b2] == 4)
                    {
                        m_text_winner.setString("Le joueur 2 est le vainqueur");
                        m_text_winner.setColor(color2);

                        sf::FloatRect rect = m_text_winner.getGlobalBounds();
                        int scale = rect.width/2;
                        m_text_winner.setPosition(400-scale, 500);
                        y = 1;
                        m_y = 1;
                    }
                }
            }
        }
    }
    if (x == 1 || y == 1)
    {
        m_type_of_victory = 3;
        return true;
    }
    else
    {
        return false;
    }
}

bool Grid :: victoryRightDiagonal(sf::Color color1, sf::Color color2)
{
    int length = LENGTH_BOARD-3;
    int width = WIDTH_BOARD-3;

    int x = 0;
    int y = 0;

    for (int b1 = 0; b1 < length; b1++)
    {
        for (int b2 = WIDTH_BOARD-1; b2 >= width; b2--)
        {
            m_nomber_right_color1[b1] [b2] = 0;
            m_nomber_right_color2[b1] [b2] = 0;
            for (int a = 0; a <= 3; a++)
            {
                int c1 = b1+a;
                int c2 = b2-a;

                if (m_board [c1] [c2].getColor() == color1)
                {
                    m_nomber_right_color1[b1] [b2] += 1;
                    m_nomber_right_color2[b1] [b2] = 0;
                }
                if (m_board [c1] [c2].getColor() == color2)
                {
                    m_nomber_right_color2[b1] [b2] += 1;
                    m_nomber_right_color1[b1] [b2] = 0;
                }
                if (m_board [c1] [c2].getColor() != color1 && m_board [c1] [c2].getColor() != color2)
                {
                    m_nomber_right_color1[b1] [b2] = 0;
                    m_nomber_right_color2[b1] [b2] = 0;
                }

                if (m_nomber_right_color1[b1] [b2] == 4 || m_nomber_right_color2[b1] [b2] == 4)
                {
                    m_b1 = b1;
                    m_b2 = b2;
                    if (m_nomber_right_color1[b1] [b2] == 4)
                    {
                        m_text_winner.setString("Le joueur 1 est le vainqueur");
                        m_text_winner.setColor(color1);

                        sf::FloatRect rect = m_text_winner.getGlobalBounds();
                        int scale = rect.width/2;
                        m_text_winner.setPosition(400-scale, 500);
                        x = 1;
                        m_x = 1;
                    }
                    if (m_nomber_right_color2[b1] [b2] == 4)
                    {
                        m_text_winner.setString("Le joueur 2 est le vainqueur");
                        m_text_winner.setColor(color2);

                        sf::FloatRect rect = m_text_winner.getGlobalBounds();
                        int scale = rect.width/2;
                        m_text_winner.setPosition(400-scale, 500);
                        y = 1;
                        m_y = 1;
                    }
                }
            }
        }
    }
    if (x == 1 || y == 1)
    {
        m_type_of_victory = 4;
        return true;
    }
    else
    {
        return false;
    }
}

void Grid :: victoryPlace(sf::Time& time)
{
    float freq = 1.5f;
    sf::Color fc;
    m_time += time;

    switch (m_type_of_victory)
    {
    case 1:
        for (int i=0; i<4; ++i)
        {
            fc.r = SIN(freq, m_time.asSeconds() + 0.20f*i, 0.0f);
            fc.g = SIN(freq, m_time.asSeconds() + 0.20f*i, 2.0f);
            fc.b = SIN(freq, m_time.asSeconds() + 0.20f*i, 4.0f);

            m_board [m_b1] [m_b2+i].putColor(fc);
        }
        break;

    case 2:
        for (int i=0; i<4; ++i)
        {
            fc.r = SIN(freq, m_time.asSeconds() + 0.20f*i, 0.0f);
            fc.g = SIN(freq, m_time.asSeconds() + 0.20f*i, 2.0f);
            fc.b = SIN(freq, m_time.asSeconds() + 0.20f*i, 4.0f);

            m_board [m_b1+i] [m_b2].putColor(fc);
        }
        break;

    case 3:
        for (int i=0; i<4; ++i)
        {
            fc.r = SIN(freq, m_time.asSeconds() + 0.20f*i, 0.0f);
            fc.g = SIN(freq, m_time.asSeconds() + 0.20f*i, 2.0f);
            fc.b = SIN(freq, m_time.asSeconds() + 0.20f*i, 4.0f);

            m_board [m_b1+i] [m_b2+i].putColor(fc);
        }
        break;

    case 4:
        for (int i=0; i<4; ++i)
        {
            fc.r = SIN(freq, m_time.asSeconds() + 0.20f*i, 0.0f);
            fc.g = SIN(freq, m_time.asSeconds() + 0.20f*i, 2.0f);
            fc.b = SIN(freq, m_time.asSeconds() + 0.20f*i, 4.0f);

            m_board [m_b1+i] [m_b2-i].putColor(fc);
        }
        break;

    case 5:
        fc.r = SIN(freq, m_time.asSeconds(), 0.0f);
        fc.g = SIN(freq, m_time.asSeconds(), 2.0f);
        fc.b = SIN(freq, m_time.asSeconds(), 4.0f);

        m_text_winner.setColor(fc);
        break;

    default:
        break;
    }
}

bool Grid :: egality()
{
    for (std::size_t t=0; t < m_board.size(); ++t)
    {
        for (std::size_t t2=0; t2 < m_board[t].size(); ++t2)
        {
            if (m_board [t] [t2].ifEmpty() == false)
            {
                return false;
            }
        }
    }
    m_type_of_victory = 5;
    m_text_winner.setString("ex aequo");
    m_text_winner.setColor(sf::Color::White);

    sf::FloatRect rect = m_text_winner.getGlobalBounds();
    int scale = rect.width/2;
    m_text_winner.setPosition(400-scale, 500);
    return true;
}

void Grid :: tetris()
{
    m_empty = 0;
    while (m_empty == 0)
    {
        for (int t2 = LENGTH_BOARD-1; t2 >= 0; --t2)
        {
            if (m_board [t2] [WIDTH_BOARD-1].ifEmpty() == false)
            {
                m_empty = 1;
            }
        }
        if (m_empty == 0)
        {
            for (int t = WIDTH_BOARD-1; t >= 0; --t)
            {
                for (int t2 = LENGTH_BOARD-1; t2 >= 0; --t2)
                {
                    sf::Color color = m_board [t2] [t].getColor();
                    if (t != WIDTH_BOARD-1)
                    {
                        m_board [t2] [t+1].putColor(color);
                    }
                }
            }

            for (int t2 = LENGTH_BOARD-1; t2 >= 0; --t2)
            {
                m_board [t2] [0].putColor(sf::Color::Black);
            }
        }
    }
}

void Grid :: chute()
{
    for (int t = WIDTH_BOARD-2; t >= 0; --t)
    {
        for (int t2 = LENGTH_BOARD-1; t2 >= 0; --t2)
        {
            sf::Color color = m_board [t2] [t].getColor();
            m_board [t2] [t+1].putColor(color);
        }
    }

    for (int t2 = LENGTH_BOARD-1; t2 >= 0; --t2)
    {
        m_board [t2] [0].putColor(sf::Color::Black);
    }
}

void Grid :: switchEvent(sf::Color player1, sf::Color player2)
{
    for (int t = LENGTH_BOARD-1; t >= 0; --t)
    {
        for (int b=WIDTH_BOARD-1; b >= 0; --b)
        {
            if (m_board [t] [b].ifEmpty() == false)
            {
                if (player1 == m_board [t] [b+1].getColor())
                {
                    m_board [t] [b+1].putColor(player2);
                }
                else if (player2 == m_board [t] [b+1].getColor())
                {
                    m_board [t] [b+1].putColor(player1);
                }
            }
        }
        if (m_board [t] [0].ifEmpty() == true)
        {
            if (player1 == m_board [t] [0].getColor())
            {
                m_board [t] [0].putColor(player2);
            }
            else if (player2 == m_board [t] [0].getColor())
            {
                m_board [t] [0].putColor(player1);
            }
        }
    }
}

void Grid :: restart()
{
    for (std::size_t t=0; t < m_board.size(); ++t)
    {
        for (std::size_t t2=0; t2 < m_board[t].size(); ++t2)
        {
            m_board [t] [t2].putColor(sf::Color::Black);
        }
    }
    m_type_of_victory = 0;
    m_x = 0;
    m_y = 0;
    m_text_winner.setString("");
}
