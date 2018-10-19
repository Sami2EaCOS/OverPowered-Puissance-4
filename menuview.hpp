#ifndef MENUVIEW_HPP
#define MENUVIEW_HPP

#include <ctime>
#include <SFML/Graphics.hpp>

#include "menu.hpp"

class StateManager;
class MenuView {
    private:
        Menu menu;
    public:
        MenuView();
        void update(sf::Time dt, StateManager& sm, sf::RenderWindow& win);
        void render(sf::RenderWindow& win);
        void process_event(sf::Event event, sf::Time dt, sf::RenderWindow& win, StateManager& sm);
};

#endif // MENUVIEW_HPP
