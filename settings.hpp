#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <ctime>
#include <SFML/Graphics.hpp>

class GameManager;
class StateManager;
class Settings {
    private:
        sf::Font m_font;
        sf::Text m_text_title;
        sf::Text m_text_aliasing;
        sf::Text m_text_level_aliasing;
        sf::Text m_text_rule;
        int m_aliasing;
    public:
        Settings();
        void draw(sf::RenderWindow& window);
        void menu(StateManager& sm, GameManager& gm, sf::Event event);
        void update(GameManager& gm);
};

#endif // SETTINGS_HPP


