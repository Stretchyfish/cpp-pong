#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Opponent : public GameObject
{
    private:
        sf::RectangleShape square;

    public:
        Opponent();
        void Draw(sf::RenderWindow &window);
        void Update(float &deltaTime);

};

Opponent::Opponent()
{
    square.setFillColor(sf::Color::White);
    square.setSize(sf::Vector2f(12.5f, 50.f));
    position = sf::Vector2f(10.f, 10.f);
    square.setPosition(position);
};

void Opponent::Draw(sf::RenderWindow &window)
{
    window.draw(square);
};

void Opponent::Update(float &deltaTime)
{
    Move(0, 10, deltaTime);
    square.setPosition(position);
}


