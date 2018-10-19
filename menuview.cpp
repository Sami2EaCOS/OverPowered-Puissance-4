#include "menuview.hpp"

#include <ctime>
#include <SFML/Graphics.hpp>

#include "StateManager.hpp"


MenuView :: MenuView()
{

}

void MenuView :: update(sf::Time dt, StateManager& sm, sf::RenderWindow& win)
{
    menu.playUpdate(dt);
}

void MenuView :: render(sf::RenderWindow& win)
{
    menu.draw(win);
}

void MenuView :: process_event(sf::Event event, sf::Time dt, sf::RenderWindow& win, StateManager& sm)
{
    menu.play(sm, win, event);
}
