#ifndef SETTINGSVIEW_HPP
#define SETTINGSVIEW_HPP

#include <ctime>
#include <SFML/Graphics.hpp>

#include "settings.hpp"

class GameManager;
class StateManager;
class SettingsView {
    private:
        Settings m_s;
    public:
        SettingsView();
        void update(sf::Time dt, StateManager& sm, GameManager& gm);
        void render(sf::RenderWindow& win);
        void process_event(sf::Event event, sf::Time dt, StateManager& sm, GameManager& gm);
};

#endif // SETTINGSVIEW_HPP

