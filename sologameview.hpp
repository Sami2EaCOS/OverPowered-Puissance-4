#ifndef SOLOGAMEVIEW_HPP
#define SOLOGAMEVIEW_HPP

#include <ctime>
#include <SFML/Graphics.hpp>
#include "puissance.hpp"

class StateManager;
class SoloGameView {
    private:
        Puissance m_puissance;
        sf::Color m_player_1;
        sf::Color m_player_2;

    public:
        SoloGameView();
        void update(sf::Time dt, StateManager& StateManager);
        void render(sf::RenderWindow& win);
        void process_event(sf::Event event, sf::Time dt, StateManager& sm, sf::Vector2f Scale_1, sf::Vector2f Scale_2, int choiceEvent[], sf::RenderWindow& win);
};

#endif // SOLOGAMEVIEW_HPP


