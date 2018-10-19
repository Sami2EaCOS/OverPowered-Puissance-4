#include "GameManager.hpp"
#include "StateManager.hpp"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include "defining.hpp"

// Creation of the game's window

GameManager :: GameManager() {
    m_settings.antialiasingLevel = 8;
    m_window.create(
        sf::VideoMode(VIDEOWIDTH,VIDEOHEIGHT),
        "OverPowered Puissance 4",
        sf::Style::Close | sf::Style::Titlebar,
        m_settings);
}

void GameManager :: run(GameManager& gm) {
    while (m_window.isOpen()) {
        sf::Event event;
        sf::Time dt = m_clock.restart();
        sf::Vector2f Scale_1(m_window.getSize());
        sf::Vector2f Scale_2(m_window.getSize());

        while (m_window.pollEvent(event)) {
            switch(event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::Resized:
                std::cout << "New window width: " << event.size.width  << "New window height: " << event.size.height << std::endl;
                sf::Vector2f Scale_3(m_window.getSize());
                Scale_2 = Scale_3;
                break;

            }
            m_sm.process_event(event, dt, m_window, m_sm, gm, Scale_1, Scale_2);
        }

        m_sm.update(dt, m_sm, gm, m_window);

        m_window.clear(sf::Color::Black);
        m_sm.render(m_window);
        m_window.display();
    }
}

void GameManager :: settings(int level)
{
    m_settings.antialiasingLevel = level;
}

int GameManager :: knowAliasing()
{
    return m_settings.antialiasingLevel;
}
