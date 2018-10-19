#ifndef SETTINGSMATCH_HPP
#define SETTINGSMATCH_HPP

#include <SFML/Graphics.hpp>
#include "timecheck.hpp"
#include "mouseSelection.hpp"

#include "defining.hpp"

class StateManager;
class SettingsMatch
{
private:
    Timecheck m_timecheck;

    MouseSelection m_ms;

    sf::Font m_font;

    sf::Text m_text_title;

    sf::Text m_event_title, m_event_tetris, m_event_switch, m_event_chute;

    sf::Text m_confirmation;

    sf::Text m_playmode_title;

    sf::Text m_playmode_local, m_playmode_localhost, m_playmode_online;

    sf::FloatRect m_hitbox_title;
    sf::FloatRect m_hitbox_event_title;
    sf::FloatRect m_hitbox_playmode_title;

    sf::RectangleShape m_hitbox_tetris, m_hitbox_switch, m_hitbox_chute;

    int m_ifEvent[NUMBER_OF_EVENT];

    int m_playmode;

    int m_changeview;

public:
    SettingsMatch();
    void draw(sf::RenderWindow& window);
    void selection(sf::RenderWindow& window, StateManager& sm, sf::Event event);

};

#endif // SETTINGSMATCH_HPP
