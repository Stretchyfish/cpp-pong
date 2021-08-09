#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Player : public GameObject
{
    private:
        sf::RectangleShape shape;
        enum actions { up, down, nothing};
        actions currentAction;
        float moveSpeed = 120;

    public:
        
        Player();

        void Update(float &deltaTime);
        void Draw(sf::RenderWindow &window);
        void Input();
};


Player::Player()
{
    // Setup graphics
    shape.setFillColor(sf::Color::White);
    shape.setSize(sf::Vector2f(12.5f, 50.f));

    // Set initial actions
    currentAction = actions::nothing;

    // Setup origin and position
    shape.setOrigin(shape.getPosition().x + shape.getSize().x / 2, shape.getPosition().y + shape.getSize().y / 2);
    position = sf::Vector2f(385.f, 200.f);
    collider = shape.getSize();
    shape.setPosition(position);
    
}

void Player::Draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

void Player::Update(float &deltaTime)
{
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

    shape.setPosition(position);
};

void Player::Input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && position.y + shape.getSize().y / 2 <= 400)
    {
        currentAction = actions::down;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && position.y - shape.getSize().y / 2 >= 0)
    {
        currentAction = actions::up;
    }
    else
    {
        currentAction = actions::nothing;
    }
};