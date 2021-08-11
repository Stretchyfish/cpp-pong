#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <vector>
#include <cmath>

class Ball : public GameObject
{
    private:
        sf::CircleShape shape;
        sf::Vector2f previousPosition;
        sf::Vector2f moveDirection;
        float moveSpeed = 50;
        float mapSizeX = 400;
        float mapSizeY = 400;

        Player* player;
        Opponent* opponent;
        bool CheckForCollision();

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
    moveDirection = sf::Vector2f(moveSpeed, moveSpeed);
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
    //previousPosition = position;
    Move(moveDirection.x, moveDirection.y, deltaTime);
    shape.setPosition(position);

    std::cout << "MoveDirection: " << moveDirection.x << " , " << moveDirection.y << std::endl;
    
    // Handle collision (THIS CODE IS GONNA BE SO UGLY)
    if(CheckForCollision())
    {
        // Calculate the 90 degree angle counterclockwise
        moveDirection.x = std::cos(90 * (moveDirection.x)) - std::sin(90 * (moveDirection.y));
        moveDirection.y = std::sin(90 * (moveDirection.x)) + std::cos(90 * (moveDirection.y));
        moveDirection.x *= moveSpeed;
        moveDirection.y *= moveSpeed;
        //moveDirection = sf::Vector2f(0,0);
    }
};

bool::Ball::CheckForCollision()
{
    if(
        // Check if collides with player
        (this->position.x + this->shape.getRadius() > player->position.x - player->collider.x / 2 && this->position.x + this->shape.getRadius() < player->position.x + player->collider.x / 2
        && this->position.y + this->shape.getRadius() > player->position.y - player->collider.y / 2 && this->position.y + this->shape.getRadius() < player->position.y + player->collider.y / 2)
        ||
        // Check if collides with lower wall
        (this->position.y + this->shape.getRadius() > mapSizeY)
        ||
        (this->position.y - this->shape.getRadius() < 0)
        ||
        (this->position.x + this->shape.getRadius() > opponent->position.x - opponent->collider.x / 2 && this->position.x + this->shape.getRadius() < opponent->position.x - opponent->collider.x / 2
        && this->position.y + this->shape.getRadius() > opponent->position.y - opponent->collider.y / 2 && this->position.y + this->shape.getRadius() < opponent->position.y - opponent->collider.y / 2)
        )
    {
        return true;
    }
    else
    {
        return false;
    }


};

void Ball::GetCollisionInfo(Player &_player, Opponent &_opponent)
{
    // Add pointers to the player and the opponent
    player = &_player;
    opponent = &_opponent;
};