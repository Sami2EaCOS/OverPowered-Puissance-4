#include "sologameview.hpp"
#include "puissance.hpp"
#include "StateManager.hpp"
#include <ctime>
#include <SFML/Graphics.hpp>

SoloGameView :: SoloGameView(): m_player_1(sf::Color::Yellow), m_player_2(sf::Color::Red)
{

}

void SoloGameView :: update(sf::Time dt, StateManager& sm)
{
    m_puissance.puissanceFour(m_player_1, m_player_2);
    m_puissance.victory(dt);
}

void SoloGameView :: render(sf::RenderWindow& win)
{
    m_puissance.puissanceDraw(win);
}

void SoloGameView :: process_event(sf::Event event, sf::Time dt, StateManager& sm, sf::Vector2f Scale_1, sf::Vector2f Scale_2, int choiceEvent[], sf::RenderWindow& win)
{
    m_puissance.puissanceResize(Scale_1, Scale_2);
    m_puissance.puissanceInput(m_player_1, m_player_2, choiceEvent, event, win);
    if (m_puissance.leave(event, sm) ==  1)
    {
        m_puissance.restart();
    }
}
