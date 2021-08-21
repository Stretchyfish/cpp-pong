#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Opponent : public GameObject
{
    private:
        sf::RectangleShape shape;
        enum actions { up, down, nothing};
        actions currentAction;
        float moveSpeed = 120;

    public:
        Opponent();
        void Draw(sf::RenderWindow &window);
        void Update(float &deltaTime);
        void Input();

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
    // Figure out what direction to move opponent
    switch (currentAction)
    {
    case up:
        Move(0, -moveSpeed, deltaTime);
        break;
    case down:
        Move(0, moveSpeed, deltaTime);
        break;
    case nothing:
        break;
    }

    // Set graphics relative position
    shape.setPosition(position);
}

void Opponent::Input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && position.y + shape.getSize().y / 2 <= 400)
    {
        currentAction = actions::down;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && position.y - shape.getSize().y / 2 >= 0)
    {
        currentAction = actions::up;
    }
    else
    {
        currentAction = actions::nothing;
    }
}


