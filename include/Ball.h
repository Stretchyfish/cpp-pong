#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <vector>

class Ball : public GameObject
{
    private:
        sf::CircleShape shape;
        sf::Vector2f moveDirection;
        float moveSpeed = 50;

        Player* player;
        Opponent* opponent;

    public:
        Ball();
        ~Ball();
        void Draw(sf::RenderWindow &window);
        void Update(float &deltaTime);

        void GetCollisionInfo(Player&, Opponent&);

};

Ball::Ball()
{
    // Setup ball graphics
    shape = sf::CircleShape(12.5f);
    shape.setFillColor(sf::Color::White);

    // Center origin
    shape.setOrigin(shape.getPosition().x + shape.getRadius(), shape.getPosition().y + shape.getRadius());
    shape.setPosition(sf::Vector2f(200,200));
    position = sf::Vector2f(200,200);

    // Set the balls start direction
    moveDirection = sf::Vector2f(moveSpeed, 0);
};

Ball::~Ball()
{

};

void Ball::Draw(sf::RenderWindow &window)
{
    window.draw(shape);
};

void Ball::Update(float &deltaTime)
{
    //std::cout << player->position.y << std::endl;

    // Update position
    Move(moveDirection.x, moveDirection.y, deltaTime);
    shape.setPosition(position);

    // Handle collision
    if(this->position.x + this->shape.getRadius() > player->position.x - player->collider.x / 2 && this->position.x + this->shape.getRadius() < player->position.x + player->collider.x / 2
        && this->position.y + this->shape.getRadius() > player->position.y - player->collider.y / 2 && this->position.y + this->shape.getRadius() < player->position.y + player->collider.y / 2)
    {
        moveDirection = sf::Vector2f(0,0);
    }
};

void Ball::GetCollisionInfo(Player &_player, Opponent &_opponent)
{
    // Add pointers to the player and the opponent
    player = &_player;
    opponent = &_opponent;
};