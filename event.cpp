#include "event.hpp"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>

#include "grid.hpp"
#include "turn.hpp"

#include "defining.hpp"

Event :: Event() : m_pass(true)
{
    if (!m_font.loadFromFile("police.ttf"))
    {
        // erreur...
    }
    m_text.setFont(m_font);
    m_text.setString("prochain event : ");
    m_text.setCharacterSize(15);
    m_text.setColor(sf::Color::White);
    m_text.setPosition(10, 10);

    m_text_2.setFont(m_font);
    m_text_2.setString("");
    m_text_2.setCharacterSize(15);
    m_text_2.setColor(sf::Color::White);
    m_text_2.setPosition(10, 25);

}

void Event :: chooseRandomEvent(int choiceEvent[])
{
    m_noEvent = 0;
    srand(time(0));

    for (int f = 0; f < NUMBER_OF_EVENT; f++)
    {
        if (choiceEvent[f] == 1)
        {
            m_noEvent = 1;
        }
    }

    while (m_pass == true && m_noEvent == 1)
    {
        m_event = rand() % NUMBER_OF_EVENT;
        switch (m_event)
        {
        case EVENT_TETRIS:
            if (choiceEvent[EVENT_TETRIS] == 1)
            {
                m_text.setString("prochain event : Tetris");
                m_text_2.setString("");
                m_pass = false;
                break;
            }
            break;

        case EVENT_SWITCH:
            if (choiceEvent[EVENT_SWITCH] == 1)
            {
                m_text.setString("prochain event : Switch");
                m_text_2.setString("");
                m_pass = false;
                break;
            }
            break;

        case EVENT_CHUTE:
            if (choiceEvent[EVENT_CHUTE] == 1)
            {
                m_text.setString("prochain event : Chute");
                m_text_2.setString("");
                m_pass = false;
                break;
            }
            break;

        default:
            m_text.setString("prochain event : Aucun");
            break;
        }
    }
}

void Event :: playEvent(Turn turn, Grid& grid)
{
    if (m_noEvent == 1)
    {
        std::ostringstream texte;
        std::string texte_1;
        texte_1 = "Nombre.s de Jetons avant l'event : ";
        int tour;
        tour = JETON_AVANT_EVENT - turn.eventTurn();

        switch (m_event)
        {
        case EVENT_TETRIS:
            if (turn.eventTurn() == 0)
            {
                m_text_2.setString("Event actif");
                grid.tetris();
                m_pass = true;
                break;
            }
            texte << texte_1 << tour;
            m_text_2.setString(texte.str());
            break;

        case EVENT_SWITCH:
            if (turn.eventTurn() == 0)
            {
                m_text_2.setString("Event actif");
                grid.switchEvent(m_player1, m_player2);
                m_pass = true;
                break;
            }
            texte << texte_1 << tour;
            m_text_2.setString(texte.str());
            break;

        case EVENT_CHUTE:
            if (turn.eventTurn() == 0)
            {
                m_text_2.setString("Event actif");
                grid.chute();
                m_pass = true;
                break;
            }
            texte << texte_1 << tour;
            m_text_2.setString(texte.str());
            break;

        default:
            break;
        }
    }
    else
    {
        m_text.setString("prochain event : Aucun");
    }
}

bool Event :: canChoose()
{
    return m_pass;
}

void Event :: draw(sf::RenderWindow& window)
{
    window.draw(m_text);
    window.draw(m_text_2);
}

void Event :: playerColor(sf::Color player1, sf::Color player2)
{
    m_player1 = player1;
    m_player2 = player2;
}

void Event :: restart()
{
    m_noEvent = 0;
    m_text.setString("prochain event : en attente");
    m_text_2.setString("");
    m_event = NUMBER_OF_EVENT;
    m_pass = true;
}
