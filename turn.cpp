#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <string>
#include <sstream>
#include "turn.hpp"

Turn :: Turn() : m_turn_nomber(1), m_turn(0), m_turn_event(0), m_turn_played(1)
{
    srand(time(NULL));

    if (!m_font.loadFromFile("police.ttf"))
    {
        // erreur...
    }
    m_text.setFont(m_font);
    m_text.setString("Tour 1");
    m_text.setCharacterSize(15);
    m_text.setColor(sf::Color::White);
    m_text.setPosition(725, 10);

}

int Turn :: nomberOfTurn()
{
    return m_turn_nomber;
}

int Turn :: nextTurn()
{
    std::ostringstream texte;
    std::string texte_1;
    texte_1 = "Tour ";
    m_turn_nomber += 1;
    if (m_turn_nomber%2 == 1 && m_turn_nomber != 1)
    {
        m_turn_played += 1;
        texte << texte_1 << m_turn_played;
        m_text.setString(texte.str());
    }
    return m_turn_nomber;
}

int Turn :: playedTurn()
{
    return m_turn_played;
}

void Turn :: drawTurn(sf::RenderWindow& window)
{
    window.draw(m_text);
}

int Turn :: colorTurn()
{
    m_turn = m_turn_nomber%2;
    return m_turn;
}

int Turn :: randomTurn()
{
    m_turn = rand() % 1;
    return m_turn;
}

int Turn :: eventTurn()
{
    m_turn_event = m_turn_nomber%10;

    return m_turn_event;
}

void Turn :: restart()
{
    m_turn_nomber = 1;
    m_turn = 0;
    m_turn_event = 0;
    m_turn_played = 1;
    m_text.setString("Tour 1");
}
