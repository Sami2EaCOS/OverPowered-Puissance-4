#include "settings.hpp"

#include <ctime>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

#include "StateManager.hpp"
#include "GameManager.hpp"


#include "defining.hpp"

Settings :: Settings() : m_aliasing(8)
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

    m_text_aliasing.setFont(m_font);
    m_text_aliasing.setString("Anti-Aliasing");
    m_text_aliasing.setCharacterSize(25);
    m_text_aliasing.setColor(sf::Color::White);

    m_text_aliasing.setPosition(300, 250);


    m_text_rule.setFont(m_font);
    m_text_rule.setString("Appuyez sur + ou - pour augmenter ou baisser le parametre, pour quitter les parametres, cliquez sur Echap");
    m_text_rule.setCharacterSize(10);
    m_text_rule.setColor(sf::Color::White);

    m_text_rule.setPosition(10, 575);

    m_text_level_aliasing.setFont(m_font);
}

void Settings :: menu(StateManager& sm, GameManager& gm, sf::Event event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Key::Add)
        {
            m_aliasing += 1;
            gm.settings(m_aliasing);
        }
        else if (event.key.code == sf::Keyboard::Key::Subtract)
        {
            if (m_aliasing != 0)
            {
                m_aliasing -= 1;
                gm.settings(m_aliasing);
            }
        }
        if (event.key.code == sf::Keyboard::Key::Escape)
        {
            sm.changeView(MENUVIEW);
        }
    }
}

void Settings :: update(GameManager& gm)
{
    std::ostringstream ss;
    ss << gm.knowAliasing();
    m_text_level_aliasing.setCharacterSize(25);
    m_text_level_aliasing.setColor(sf::Color::White);
    m_text_level_aliasing.setString(ss.str());

    sf::FloatRect rect2 = m_text_aliasing.getGlobalBounds();
    m_text_level_aliasing.setPosition(350+rect2.width, 250);
}

void Settings :: draw(sf::RenderWindow& window)
{
    window.draw(m_text_title);
    window.draw(m_text_aliasing);
    window.draw(m_text_level_aliasing);
    window.draw(m_text_rule);
}
