#include "settingsmatch.hpp"

#include <SFML/Graphics.hpp>
#include "timecheck.hpp"
#include "StateManager.hpp"
#include "mouseSelection.hpp"

#include "defining.hpp"

SettingsMatch :: SettingsMatch() : m_changeview(0), m_playmode(1)
{
    for (int f = 0; f < NUMBER_OF_EVENT; f++)
    {
        m_ifEvent[f] = 0;
    }

    if (!m_font.loadFromFile("police.ttf"))
    {
        // erreur...
    }
    m_text_title.setFont(m_font);
    m_text_title.setString("Parametre de la partie");
    m_text_title.setCharacterSize(30);
    m_text_title.setColor(sf::Color::White);

    m_hitbox_title = m_text_title.getGlobalBounds();
    m_text_title.setPosition(450-m_hitbox_title.width/2, 50);

    m_event_title.setFont(m_font);
    m_event_title.setString("Choix des events");
    m_event_title.setCharacterSize(20);
    m_event_title.setColor(sf::Color::White);

    m_hitbox_event_title = m_event_title.getGlobalBounds();
    m_event_title.setPosition(450, 150);

    m_event_tetris.setFont(m_font);
    m_event_tetris.setString("Tetris");
    m_event_tetris.setCharacterSize(20);
    m_event_tetris.setColor(sf::Color::White);

    m_event_tetris.setPosition(500+m_hitbox_event_title.width/2, 200);

    m_hitbox_tetris.setSize(sf::Vector2f(10.0f, 10.0f));
    m_hitbox_tetris.setFillColor(sf::Color::Black);
    m_hitbox_tetris.setOutlineColor(sf::Color::White);
    m_hitbox_tetris.setOutlineThickness(3);
    m_hitbox_tetris.setPosition(475+m_hitbox_event_title.width/2, 205);

    m_event_switch.setFont(m_font);
    m_event_switch.setString("Switch");
    m_event_switch.setCharacterSize(20);
    m_event_switch.setColor(sf::Color::White);

    m_event_switch.setPosition(500+m_hitbox_event_title.width/2, 230);

    m_hitbox_switch.setSize(sf::Vector2f(10.0f, 10.0f));
    m_hitbox_switch.setFillColor(sf::Color::Black);
    m_hitbox_switch.setOutlineColor(sf::Color::White);
    m_hitbox_switch.setOutlineThickness(3);
    m_hitbox_switch.setPosition(475+m_hitbox_event_title.width/2, 235);

    m_event_chute.setFont(m_font);
    m_event_chute.setString("Chute");
    m_event_chute.setCharacterSize(20);
    m_event_chute.setColor(sf::Color::White);

    m_event_chute.setPosition(500+m_hitbox_event_title.width/2, 260);

    m_hitbox_chute.setSize(sf::Vector2f(10.0f, 10.0f));
    m_hitbox_chute.setFillColor(sf::Color::Black);
    m_hitbox_chute.setOutlineColor(sf::Color::White);
    m_hitbox_chute.setOutlineThickness(3);
    m_hitbox_chute.setPosition(475+m_hitbox_event_title.width/2, 265);

    m_confirmation.setFont(m_font);
    m_confirmation.setString("Lancement du jeu");
    m_confirmation.setCharacterSize(25);
    m_confirmation.setColor(sf::Color::White);

    m_confirmation.setPosition(450, 500);

    m_playmode_title.setFont(m_font);
    m_playmode_title.setString("Voulez-vous jouer :");
    m_playmode_title.setCharacterSize(20);
    m_playmode_title.setColor(sf::Color::White);

    m_hitbox_playmode_title = m_playmode_title.getGlobalBounds();
    m_playmode_title.setPosition(100, 150);

    m_playmode_local.setFont(m_font);
    m_playmode_local.setString("Sur le meme ordinateur");
    m_playmode_local.setCharacterSize(20);
    m_playmode_local.setColor(sf::Color::White);

    m_playmode_local.setPosition(75+m_hitbox_event_title.width/2, 200);

    m_playmode_localhost.setFont(m_font);
    m_playmode_localhost.setString("Sur la meme connexion");
    m_playmode_localhost.setCharacterSize(20);
    m_playmode_localhost.setColor(sf::Color::White);

    m_playmode_localhost.setPosition(75+m_hitbox_event_title.width/2, 230);

    m_playmode_online.setFont(m_font);
    m_playmode_online.setString("En ligne");
    m_playmode_online.setCharacterSize(20);
    m_playmode_online.setColor(sf::Color::White);

    m_playmode_online.setPosition(75+m_hitbox_event_title.width/2, 260);

}

void SettingsMatch :: draw(sf::RenderWindow& window)
{
    window.draw(m_text_title);
    window.draw(m_event_title);
    window.draw(m_event_tetris);
    window.draw(m_event_switch);
    window.draw(m_event_chute);

    window.draw(m_hitbox_tetris);
    window.draw(m_hitbox_switch);
    window.draw(m_hitbox_chute);

    window.draw(m_confirmation);

    window.draw(m_playmode_local);
    window.draw(m_playmode_localhost);
    window.draw(m_playmode_online);
    window.draw(m_playmode_title);
}

void SettingsMatch :: selection(sf::RenderWindow& window, StateManager& sm, sf::Event event)
{
    switch (m_ms.mouseDetection(window, m_event_title, event, sf::Color::Red))
    {
    case 1:
        for (int f = 0; f<NUMBER_OF_EVENT; f++)
        {
            m_ifEvent[f] = 1;
        }
        m_hitbox_tetris.setFillColor(sf::Color::White);
        m_hitbox_switch.setFillColor(sf::Color::White);
        m_hitbox_chute.setFillColor(sf::Color::White);
        break;

    case 2:
        for (int f = 0; f<NUMBER_OF_EVENT; f++)
        {
            m_ifEvent[f] = 0;
        }
        m_hitbox_tetris.setFillColor(sf::Color::Black);
        m_hitbox_switch.setFillColor(sf::Color::Black);
        m_hitbox_chute.setFillColor(sf::Color::Black);
        break;

    default:
        break;
    }

    if (m_ms.mouseDetection(window, m_hitbox_tetris, event, sf::Color::Red) ==  1)
    {
        if (m_hitbox_tetris.getFillColor() == sf::Color::White)
        {
            m_hitbox_tetris.setFillColor(sf::Color::Black);
            m_ifEvent[EVENT_TETRIS] = 0;
        }
        else if (m_hitbox_tetris.getFillColor() == sf::Color::Black)
        {
            m_hitbox_tetris.setFillColor(sf::Color::White);
            m_ifEvent[EVENT_TETRIS] = 1;
        }
    }


    if (m_ms.mouseDetection(window, m_hitbox_switch, event, sf::Color::Red) ==  1)
    {
        if (m_hitbox_switch.getFillColor() == sf::Color::White)
        {
            m_hitbox_switch.setFillColor(sf::Color::Black);
            m_ifEvent[EVENT_SWITCH] = 0;
        }
        else if (m_hitbox_switch.getFillColor() == sf::Color::Black)
        {
            m_hitbox_switch.setFillColor(sf::Color::White);
            m_ifEvent[EVENT_SWITCH] = 1;
        }
    }

    if (m_ms.mouseDetection(window, m_hitbox_chute, event, sf::Color::Red) == 1)
    {
        if (m_hitbox_chute.getFillColor() == sf::Color::White)
        {
            m_hitbox_chute.setFillColor(sf::Color::Black);
            m_ifEvent[EVENT_CHUTE] = 0;
        }
        else if (m_hitbox_chute.getFillColor() == sf::Color::Black)
        {
            m_hitbox_chute.setFillColor(sf::Color::White);
            m_ifEvent[EVENT_CHUTE] = 1;
        }
    }

    if (m_ms.mouseDetection(window, m_confirmation, event, sf::Color::Yellow) ==  1)
    {
        sm.savechoice(m_ifEvent);
        for (int f = 0; f<NUMBER_OF_EVENT; f++)
        {
            m_ifEvent[f] = 0;
        }
        m_hitbox_tetris.setFillColor(sf::Color::Black);
        m_hitbox_switch.setFillColor(sf::Color::Black);
        m_hitbox_chute.setFillColor(sf::Color::Black);
        m_confirmation.setColor(sf::Color::White);
        m_playmode = 1;
        sm.changeView(SOLOGAMEVIEW);
    }

    switch (m_ms.mouseDetection(window, m_playmode_local, event))
    {
    case 1:
        m_playmode = 1;
        break;
    case 0:
        if (m_playmode == 1)
        {
            m_playmode_local.setColor(sf::Color::Red);
            break;
        }
        else
        {
            m_playmode_local.setColor(sf::Color::White);
        }
        break;
    }

    switch (m_ms.mouseDetection(window, m_playmode_localhost, event))
    {
    case 1:
        m_playmode = 2;
        break;
    case 0:
        if (m_playmode == 2)
        {
            m_playmode_localhost.setColor(sf::Color::Red);
            break;
        }
        else
        {
            m_playmode_localhost.setColor(sf::Color::White);
        }
        break;
    }

    switch (m_ms.mouseDetection(window, m_playmode_online, event))
    {
    case 1:
        m_playmode = 3;
        break;
    case 0:
        if (m_playmode == 3)
        {
            m_playmode_online.setColor(sf::Color::Red);
            break;
        }
        else
        {
            m_playmode_online.setColor(sf::Color::White);
        }
        break;
    }

    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            for (int f = 0; f<NUMBER_OF_EVENT; f++)
            {
                m_ifEvent[f] = 0;
            }
            m_hitbox_tetris.setFillColor(sf::Color::Black);
            m_hitbox_switch.setFillColor(sf::Color::Black);
            m_hitbox_chute.setFillColor(sf::Color::Black);
            m_playmode = 1;
            sm.changeView(MENUVIEW);
        }
    }
}
