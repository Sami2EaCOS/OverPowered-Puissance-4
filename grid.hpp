#ifndef GRID_HPP
#define GRID_HPP
#include <vector>
#include <string>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "case.hpp"

#define LENGTH_BOARD 7
#define WIDTH_BOARD 6

class Grid
{
private:
    std::vector<std::vector<Case>> m_board;
    float m_zoom_factor;

    int m_nomber_vertical_color1[LENGTH_BOARD];
    int m_nomber_vertical_color2[LENGTH_BOARD];

    int m_nomber_horizontal_color1[WIDTH_BOARD];
    int m_nomber_horizontal_color2[WIDTH_BOARD];

    int m_nomber_right_color1[LENGTH_BOARD] [WIDTH_BOARD];
    int m_nomber_right_color2[LENGTH_BOARD] [WIDTH_BOARD];

    int m_nomber_left_color1[LENGTH_BOARD] [WIDTH_BOARD];
    int m_nomber_left_color2[LENGTH_BOARD] [WIDTH_BOARD];

    int m_type_of_victory;

    int m_empty;

    sf::Font m_font;
    sf::Text m_text_winner;

    sf::Time m_time;

    int m_b1;
    int m_b2;

    int m_x;
    int m_y;

public:

    Grid();

    void onResize(sf::Vector2f old_size, sf::Vector2f new_size);

    int colorize(int column, sf::Color color);

    bool ifIsEmpty(int column);

    void draw(sf::RenderWindow& window);

    bool victoryVertical(sf::Color color1, sf::Color color2);
    bool victoryHorizontal(sf::Color color1, sf::Color color2);
    bool victoryRightDiagonal(sf::Color color1, sf::Color color2);
    bool victoryLeftDiagonal(sf::Color color1, sf::Color color2);

    void victoryPlace(sf::Time& time);

    bool egality();

    void tetris();
    void chute();
    void switchEvent(sf::Color player1, sf::Color player2);

    void restart();
};

#endif // GRID_HPP
