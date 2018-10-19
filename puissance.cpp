#include <SFML/Graphics.hpp>
#include "puissance.hpp"
#include "grid.hpp"
#include "cursor.hpp"
#include "turn.hpp"
#include "event.hpp"
#include "StateManager.hpp"

#include "defining.hpp"

Puissance :: Puissance() : m_victory_int(0), m_input_move(0)
{
    if (!m_font.loadFromFile("police.ttf"))
    {
        // erreur...
    }
    m_text.setFont(m_font);
    m_text.setString("Quitter avec Echap");
    m_text.setCharacterSize(10);
    m_text.setColor(sf::Color::White);
    m_text.setPosition(10, 575);
}

void Puissance :: puissanceFour(sf::Color player1, sf::Color player2)
{
    m_turn.eventTurn();
    m_event.playerColor(player1, player2);

    if (m_turn.colorTurn() == 1 && m_victory_int == 0)
    {
        m_cursor.cursorColor(player1);
    }
    if (m_turn.colorTurn() == 0 && m_victory_int == 0)
    {
        m_cursor.cursorColor(player2);
    }

    m_cursor.cursorMove(m_input_move);
    m_input_move = 0;

    if (m_victory_int == 0)
    {
        if (m_grid.victoryVertical(player1, player2) == true || m_grid.victoryHorizontal(player1, player2) == true || m_grid.egality() == true || m_grid.victoryRightDiagonal(player1, player2) == true || m_grid.victoryLeftDiagonal(player1, player2) == true)
        {
            m_victory_int = 1;
        }
    }
}

void Puissance :: puissanceInput(sf::Color player1, sf::Color player2, int choiceEvent[], sf::Event event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Left && m_victory_int == 0)
        {
            m_input_move = 1;
        }
        else if (event.key.code == sf::Keyboard::Right && m_victory_int == 0)
        {
            m_input_move = 2;
        }

        if (event.key.code == sf::Keyboard::Space && m_victory_int == 0)
        {
            if (m_turn.colorTurn() == 1 && m_grid.ifIsEmpty(m_cursor.positionCursor()) == true)
            {
                m_grid.colorize(m_cursor.positionCursor(), player1);
                m_turn.nextTurn();
                if (m_event.canChoose() == true)
                {
                    m_event.chooseRandomEvent(choiceEvent);
                }
                m_event.playEvent(m_turn, m_grid);
            }
            else if (m_turn.colorTurn() == 0 && m_grid.ifIsEmpty(m_cursor.positionCursor()) == true)
            {
                m_grid.colorize(m_cursor.positionCursor(), player2);
                m_turn.nextTurn();
                if (m_event.canChoose() == true)
                {
                    m_event.chooseRandomEvent(choiceEvent);
                }
                m_event.playEvent(m_turn, m_grid);
            }
            else
            {
                std::cout << "La colonne est pleine" << std::endl;
            }
        }
    }
    if (m_victory_int == 0)
    {
        for (int f = 0; f < LENGTH_BOARD; f++)
        {
            sf::IntRect rect(VIDEOWIDTH/4 + CASE_SIZE * f,CASE_SIZE, CASE_SIZE, CASE_SIZE*LENGTH_BOARD);
            if (rect.contains(sf::Mouse::getPosition(window)))
            {
                m_cursor.cursorMoveMouse(f);
                if (event.type == sf::Event::MouseButtonReleased)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        if (m_turn.colorTurn() == 1 && m_grid.ifIsEmpty(m_cursor.positionCursor()) == true)
                        {
                            m_grid.colorize(m_cursor.positionCursor(), player1);
                            m_turn.nextTurn();
                                if (m_event.canChoose() == true)
                                {
                                    m_event.chooseRandomEvent(choiceEvent);
                                }
                                m_event.playEvent(m_turn, m_grid);
                        }
                        else if (m_turn.colorTurn() == 0 && m_grid.ifIsEmpty(m_cursor.positionCursor()) == true)
                        {
                            m_grid.colorize(m_cursor.positionCursor(), player2);
                            m_turn.nextTurn();
                            if (m_event.canChoose() == true)
                            {
                                m_event.chooseRandomEvent(choiceEvent);
                            }
                            m_event.playEvent(m_turn, m_grid);
                        }
                        else
                        {
                            std::cout << "La colonne est pleine" << std::endl;
                        }
                    }
                }
            }
        }
    }
}

void Puissance :: victory(sf::Time& time)
{
    if (m_victory_int == 1)
    {
        m_text.setString("Quitter avec Echap ou Enter");
        m_cursor.cursorColorWin();
        m_grid.victoryPlace(time);
    }
}

void Puissance :: puissanceDraw(sf::RenderWindow& window)
{
    m_cursor.cursorDraw(window);
    m_grid.draw(window);
    m_event.draw(window);
    m_turn.drawTurn(window);
    window.draw(m_text);
}

void Puissance :: puissanceResize(sf::Vector2f Scale_1, sf::Vector2f Scale_2)
{
    m_grid.onResize(Scale_1, Scale_2);
    m_cursor.cursorResize(Scale_1, Scale_2);
}

int Puissance :: leave(sf::Event event, StateManager& sm)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            sm.changeView(MENUVIEW);
            return 1;
        }
    }

    if (m_victory_int == 1)
    {
        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Return)
            {
                sm.changeView(MENUVIEW);
                return 1;
            }
        }
    }
    return 0;
}

void Puissance :: restart()
{
    m_victory_int = 0;
    m_input_move = 0;
    m_text.setString("Quitter avec Echap");
    m_event.restart();
    m_grid.restart();
    m_turn.restart();
    m_cursor.restart();
}
