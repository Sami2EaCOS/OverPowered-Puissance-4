#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <ctime>
#include <SFML/Graphics.hpp>
#include "menuview.hpp"
#include "sologameview.hpp"
#include "settingsview.hpp"
#include "settingsmatchview.hpp"
#include "defining.hpp"

class GameManager;
class StateManager
{
private:
    SoloGameView m_sgv;
    MenuView m_mv;
    SettingsView m_sv;
    SettingsMatchView m_smv;
    int m_current_view;
    int m_choice[NUMBER_OF_EVENT];

public:
    StateManager();
    void update(sf::Time dt, StateManager& StateManager, GameManager& gm, sf::RenderWindow& window);
    void render(sf::RenderWindow& win);
    void process_event(sf::Event event, sf::Time dt, sf::RenderWindow& win, StateManager& sm, GameManager& gm, sf::Vector2f Scale_1, sf::Vector2f Scale_2);
    void changeView(int view);
    void savechoice(int event[]);
};

#endif // STATEMANAGER_HPP
