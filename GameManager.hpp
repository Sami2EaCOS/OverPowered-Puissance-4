#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP
#include "StateManager.hpp"
#include <SFML/Graphics.hpp>

class GameManager
{
private:
    sf::ContextSettings m_settings;
    StateManager m_sm;
    sf::RenderWindow m_window;
    sf::Time m_time;
    sf::Clock m_clock;
    // other useful attributes ...

public:
    GameManager();
    void run(GameManager& gm);
    void settings(int level);
    int knowAliasing();
};

#endif // GAMEMANAGER_HPP
