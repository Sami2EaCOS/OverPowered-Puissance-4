#ifndef SETTINGSMATCHVIEW_HPP
#define SETTINGSMATCHVIEW_HPP

#include <ctime>
#include <SFML/Graphics.hpp>

#include "settingsmatch.hpp"

class GameManager;
class StateManager;
class SettingsMatchView
{
private:
    SettingsMatch m_smatch;
public:
    SettingsMatchView();
    void update(sf::Time dt, StateManager& sm, GameManager& gm, sf::RenderWindow& win);
    void render(sf::RenderWindow& win);
    void process_event(sf::Event event, sf::Time dt, sf::RenderWindow& win, StateManager& sm);
};

#endif // SETTINGSMATCHVIEW_HPP
