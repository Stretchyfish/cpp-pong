#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Opponent : public GameObject
{
    private:
        sf::RectangleShape shape;

    public:
        Opponent();
        void Draw(sf::RenderWindow &window);
        void Update(float &deltaTime);

};

Opponent::Opponent()
{
    // Setup graphics
    shape.setFillColor(sf::Color::White);
    shape.setSize(sf::Vector2f(12.5f, 50.f));

    // Setup origin and position
    shape.setOrigin(shape.getPosition().x + shape.getSize().x / 2, shape.getPosition().y + shape.getSize().y / 2);
    position = sf::Vector2f(15.f, 200.f);
    collider = shape.getSize();
    shape.setPosition(position);
};

void Opponent::Draw(sf::RenderWindow &window)
{
    window.draw(shape);
};

void Opponent::Update(float &deltaTime)
{
    Move(0, 10, deltaTime);

    // Set graphics relative position
    shape.setPosition(position);
}


