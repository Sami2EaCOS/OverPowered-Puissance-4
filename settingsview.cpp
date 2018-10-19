#include "settingsview.hpp"

#include <ctime>
#include <SFML/Graphics.hpp>

#include "StateManager.hpp"
#include "GameManager.hpp"
#include "settings.hpp"

SettingsView :: SettingsView()
{

}

void SettingsView :: update(sf::Time dt, StateManager& sm, GameManager& gm)
{
    m_s.update(gm);
}

void SettingsView :: render(sf::RenderWindow& win)
{
    m_s.draw(win);
}

void SettingsView :: process_event(sf::Event event, sf::Time dt, StateManager& sm, GameManager& gm)
{
    m_s.menu(sm, gm, event);
}

