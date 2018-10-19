#include "menucursor.hpp"

#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>

#include "timecheck.hpp"
#include "StateManager.hpp"

#include "defining.hpp"

MenuCursor :: MenuCursor() : m_form(sf::Vector2f(6.0f,20.0f)), m_placement(0), m_input_move(PLAYPOSITION)
{
    m_form.setPosition(475,PLAYPOSITION);
    m_form.setFillColor(sf::Color::White);
    m_form.setOutlineThickness(2);
    m_form.setOutlineColor(sf::Color::Black);

    m_timecheck2.startClock();
}

void MenuCursor :: cursorColor(sf::Time& time)
{
    float freq = 2.5f;
    sf::Color fc;

    m_time += time;

    fc.r = SIN(freq, m_time.asSeconds(), 0.0f);
    fc.g = SIN(freq, m_time.asSeconds(), 0.0f);

    m_form.setFillColor(fc);
}

void MenuCursor :: draw(sf::RenderWindow& window)
{
    window.draw(m_form);
}

void MenuCursor :: cursor(StateManager& sm, int placement)
{
    switch (placement)
    {
    case PLAYPOSITION:
        m_form.setPosition(475, PLAYPOSITION);
        m_placement = 0;
        break;
    case SETTINGSPOSITION:
        m_form.setPosition(475, SETTINGSPOSITION);
        m_placement = 1;
        break;
    case TUTORIALPOSITION:
        m_form.setPosition(475, TUTORIALPOSITION);
        m_placement = 2;
        break;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && m_timecheck.conditionTimer(sf::milliseconds(200)) == true)
    {
        m_timecheck.startClock();
        switch (m_placement)
        {
        case 0:
            m_form.setPosition(475,SETTINGSPOSITION);
            m_placement += 1;
            break;
        case 1:
            m_form.setPosition(475,TUTORIALPOSITION);
            m_placement += 1;
            break;
        case 2:
            break;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && m_timecheck.conditionTimer(sf::milliseconds(200)) == true)
    {
        m_timecheck.startClock();
        switch (m_placement)
        {
        case 0:
            break;
        case 1:
            m_form.setPosition(475,PLAYPOSITION);
            m_placement -= 1;
            break;
        case 2:
            m_form.setPosition(475,SETTINGSPOSITION);
            m_placement -= 1;
            break;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && m_form.getPosition() == sf::Vector2f(475, PLAYPOSITION) && m_timecheck2.conditionTimer(sf::milliseconds(200)))
    {
        m_timecheck2.startClock();
        sm.changeView(SETTINGSMATCH);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && m_form.getPosition() == sf::Vector2f(475, SETTINGSPOSITION) && m_timecheck2.conditionTimer(sf::milliseconds(200)))
    {
        m_timecheck2.startClock();
        sm.changeView(SETTINGSVIEW);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && m_form.getPosition() == sf::Vector2f(475, TUTORIALPOSITION) && m_timecheck2.conditionTimer(sf::milliseconds(200)))
    {
        m_timecheck2.startClock();
        //sm.changeView();
    }
}
