#ifndef PUISSANCE_HPP
#define PUISSANCE_HPP
#include "grid.hpp"
#include "cursor.hpp"
#include "timecheck.hpp"
#include "turn.hpp"
#include "event.hpp"

class StateManager;
class Puissance
{
private:

    int m_victory_int;
    int m_input_move;
    Turn m_turn;
    Grid m_grid;
    Cursor m_cursor;
    Event m_event;
    sf::Text m_text;
    sf::Font m_font;

public:
    Puissance();
    void puissanceFour(sf::Color player1, sf::Color player2);
    void puissanceInput(sf::Color player1, sf::Color player2, int choiceEvent[], sf::Event event, sf::RenderWindow& window);
    void victory(sf::Time& time);
    void puissanceDraw(sf::RenderWindow& window);
    void puissanceResize(sf::Vector2f Scale_1, sf::Vector2f Scale_2);
    int leave(sf::Event event, StateManager& sm);
    void restart();
};


#endif // PUISSANCE_HPP
