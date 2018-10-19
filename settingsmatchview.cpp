#include "settingsmatchview.hpp"
#include "StateManager.hpp"
#include "settingsmatch.hpp"
#include "GameManager.hpp"

#include <ctime>
#include <SFML/Graphics.hpp>

SettingsMatchView :: SettingsMatchView()
{

}

void SettingsMatchView :: update(sf::Time dt, StateManager& sm, GameManager& gm, sf::RenderWindow& win)
{

}

void SettingsMatchView :: render(sf::RenderWindow& win)
{

    m_smatch.draw(win);
}

void SettingsMatchView :: process_event(sf::Event event, sf::Time dt, sf::RenderWindow& win, StateManager& sm)
{
    m_smatch.selection(win, sm, event);
}
