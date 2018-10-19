#include "mouseSelection.hpp"

#include "SFML/Graphics.hpp"

MouseSelection :: MouseSelection()
{

}

int MouseSelection :: mouseDetection(sf::RenderWindow& window, sf::Text& text, sf::Event event)
{
    sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);
    if (rect.contains(sf::Mouse::getPosition(window)))
    {
        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                return 1;
            }
            else if (event.mouseButton.button == sf::Mouse::Right)
            {
                return 2;
            }
        }
        else
        {
            return 3;
        }
    }
    else
    {
        return 0;
    }
}

int MouseSelection :: mouseDetection(sf::RenderWindow& window, sf::Text& text, sf::Event event, sf::Color color)
{
    sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);
    if (rect.contains(sf::Mouse::getPosition(window)))
    {
        text.setColor(color);
        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                return 1;
            }
            else if (event.mouseButton.button == sf::Mouse::Right)
            {
                return 2;
            }
        }
        else
        {
            return 3;
        }
    }
    else
    {
        text.setColor(sf::Color::White);
        return 0;
    }
}

int MouseSelection :: mouseDetection(sf::RenderWindow& window, sf::Text& text, sf::Event event, sf::Color color, int a)
{
    sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);
    if (rect.contains(sf::Mouse::getPosition(window)))
    {
        text.setColor(color);
        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                return 1;
            }
            else if (event.mouseButton.button == sf::Mouse::Right)
            {
                return 2;
            }
        }
        else
        {
            return 3;
        }
    }
    else
    {
        return 0;
    }
}

int MouseSelection :: mouseDetection(sf::RenderWindow& window, sf::RectangleShape& shape, sf::Event event, sf::Color color)
{
    sf::IntRect rect(shape.getPosition().x, shape.getPosition().y, shape.getGlobalBounds().width, shape.getGlobalBounds().height);
    if (rect.contains(sf::Mouse::getPosition(window)))
    {
        shape.setOutlineColor(color);
        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                return 1;
            }
            else if (event.mouseButton.button == sf::Mouse::Right)
            {
                return 2;
            }
        }
        else
        {
            return 3;
        }
    }
    else
    {
        shape.setOutlineColor(sf::Color::White);
        return 0;
    }
}
