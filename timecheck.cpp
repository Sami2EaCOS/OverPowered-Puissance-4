#include "timecheck.hpp"
#include <SFML/System.hpp>
#include <ctime>
#include <iostream>

Timecheck :: Timecheck() : m_t(sf::Time::Zero), m_current(sf::Time::Zero) //m_t = 0, m_current = 0
{

}

void Timecheck :: startClock()
{
    m_clock.restart();
}

bool Timecheck :: conditionTimer(sf::Time time)
{
    m_t = time;

    if (m_t != sf::Time::Zero)
    {
        m_current = m_clock.getElapsedTime();
    }

     if (m_t > m_current && m_t != sf::Time::Zero)
    {
        return false;
    }
    else
    {
        m_clock.restart();
        m_current = sf::Time::Zero;
        m_t = sf::Time::Zero;
        return true;
    }
}
