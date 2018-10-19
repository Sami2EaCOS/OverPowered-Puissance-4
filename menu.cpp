#include "menu.hpp"
#include <SFML/Graphics.hpp>

#include "StateManager.hpp"
#include "menucursor.hpp"

#include "defining.hpp"

Menu :: Menu()
{
    if (!m_font.loadFromFile("police.ttf"))
    {
        // erreur...
    }
    m_text_title.setFont(m_font);
    m_text_title.setString("Overpowered Puissance 4");
    m_text_title.setCharacterSize(35);
    m_text_title.setColor(sf::Color::White);

    sf::FloatRect rect = m_text_title.getGlobalBounds();
    int scale = rect.width/2;
    m_text_title.setPosition(400-scale, 100);

    m_text_play.setFont(m_font);
    m_text_play.setString("Jouer");
    m_text_play.setCharacterSize(25);
    m_text_play.setColor(sf::Color::White);

    m_text_play.setPosition(500, 250);

    m_text_settings.setFont(m_font);
    m_text_settings.setString("Parametres");
    m_text_settings.setCharacterSize(25);
    m_text_settings.setColor(sf::Color::White);

    m_text_settings.setPosition(500, 300);

    m_text_tutorial.setFont(m_font);
    m_text_tutorial.setString("Tutoriel");
    m_text_tutorial.setCharacterSize(25);
    m_text_tutorial.setColor(sf::Color::White);

    m_text_tutorial.setPosition(500, 350);

}

void Menu :: draw(sf::RenderWindow& window)
{
    window.draw(m_text_title);
    window.draw(m_text_play);
    window.draw(m_text_settings);
    window.draw(m_text_tutorial);
    m_mc.draw(window);
}

void Menu :: play(StateManager& sm, sf::RenderWindow& window, sf::Event event)
{
    int placement = 0;

    switch (m_ms.mouseDetection(window, m_text_play, event))
    {
    case 3:
        placement = PLAYPOSITION;
        break;
    case 1:
        sm.changeView(SETTINGSMATCH);
        break;
    default:
        break;
    }

    switch (m_ms.mouseDetection(window, m_text_settings, event))
    {
    case 3:
        placement = SETTINGSPOSITION;
        break;
    case 1:
        sm.changeView(SETTINGSVIEW);
        break;
    default:
        break;
    }

    switch (m_ms.mouseDetection(window, m_text_tutorial, event))
    {
    case 3:
        placement = TUTORIALPOSITION;
        break;
    case 1:
        break;
    default:
        break;
    }
    m_mc.cursor(sm, placement);
}

void Menu :: playUpdate(sf::Time& time)
{
    m_mc.cursorColor(time);
}
