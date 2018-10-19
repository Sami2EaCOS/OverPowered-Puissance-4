#include "StateManager.hpp"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include "menuview.hpp"
#include "sologameview.hpp"
#include "settingsview.hpp"
#include "settingsmatchview.hpp"

#include "defining.hpp"

StateManager :: StateManager(): m_current_view(MENUVIEW)
{

}

void StateManager :: update(sf::Time dt, StateManager& sm, GameManager& gm, sf::RenderWindow& window)
{
    switch (m_current_view)
    {
        case MENUVIEW:
            m_mv.update(dt, sm, window);
            break;

        case SOLOGAMEVIEW:
            m_sgv.update(dt, sm);
            break;

        case SETTINGSVIEW:
            m_sv.update(dt, sm, gm);
            break;

        case SETTINGSMATCH:
            m_smv.update(dt, sm, gm, window);
            break;

        default:
            break;
    }
}

void StateManager :: render(sf::RenderWindow& win)
{
    switch (m_current_view)
    {
        case MENUVIEW:
            m_mv.render(win);
            break;

        case SOLOGAMEVIEW:
            m_sgv.render(win);
            break;

        case SETTINGSVIEW:
            m_sv.render(win);
            break;

        case SETTINGSMATCH:
            m_smv.render(win);
            break;

        default:
            break;
    }
}

void StateManager :: process_event(sf::Event event, sf::Time dt, sf::RenderWindow& win, StateManager& sm, GameManager& gm, sf::Vector2f Scale_1, sf::Vector2f Scale_2)
{
    switch (m_current_view)
    {
        case MENUVIEW:
            m_mv.process_event(event, dt, win, sm);
            break;

        case SOLOGAMEVIEW:
            m_sgv.process_event(event, dt, sm, Scale_1, Scale_2, m_choice, win);
            break;

        case SETTINGSVIEW:
            m_sv.process_event(event, dt, sm, gm);
            break;

        case SETTINGSMATCH:
            m_smv.process_event(event, dt, win, sm);
            break;

        default:
            break;
    }
}

void StateManager :: changeView(int view)
{
    m_current_view = view;
}

void StateManager :: savechoice(int event[])
{
        for (int f = 0; f < NUMBER_OF_EVENT; f++)
        {
            m_choice [f] = event [f];
        }
}
