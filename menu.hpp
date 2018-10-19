#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include "menucursor.hpp"
#include "mouseSelection.hpp"

class StateManager;
class Menu
{
private:
    sf::Font m_font;
    sf::Text m_text_title;
    sf::Text m_text_play;
    sf::Text m_text_settings;
    sf::Text m_text_tutorial;
    MenuCursor m_mc;
    MouseSelection m_ms;

public:
    Menu();
    void draw(sf::RenderWindow& window);
    void play(StateManager& sm, sf::RenderWindow& window, sf::Event event);
    void playUpdate(sf::Time& time);
};

#endif // MENU_HPP
