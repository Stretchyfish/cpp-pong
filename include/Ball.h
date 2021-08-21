#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>

class Ball : public GameObject
{
    private:
        sf::CircleShape shape;
        sf::Vector2f moveDirection;
        float moveSpeed = 50;
        float mapSizeX = 400;
        float mapSizeY = 400;
        double pi = 3.14159265359;

        Player* player;
        Opponent* opponent;
        bool CheckForCollision(sf::Vector2f);
        void ResetBall();
        void DetectGoal();

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

    // Setup random number generator
    srand(time(NULL));

    // Set the balls start direction
    ResetBall();
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
    // Update position
    Move(moveDirection.x, moveDirection.y, deltaTime);
    shape.setPosition(position);
    
    // Handle collision
    if(CheckForCollision(this->position))
    {
        // Calculate the 90 degree angle counterclockwise
        sf::Vector2f potentialMoveDirection;
        potentialMoveDirection.x = (-moveDirection.x) * std::cos(90 * (pi/180)) - (-moveDirection.y) * std::sin(90 * (pi/180));
        potentialMoveDirection.y = (-moveDirection.x) * std::sin(90 * (pi/180)) + (-moveDirection.y) * std::cos(90 * (pi/180));

        // Simulate moving in that direction, and check for collisions
        if(CheckForCollision(this->position + moveDirection * deltaTime))
        {
            moveDirection = potentialMoveDirection;
        }
        else // If that way results in a collision, attempt 90 degree clockwise
        {
            moveDirection.x = (-moveDirection.x) * std::cos(270 * (pi/180)) - (-moveDirection.y) * std::sin(270 * (pi/180));
            moveDirection.y = (-moveDirection.x) * std::sin(270 * (pi/180)) + (-moveDirection.y) * std::cos(270 * (pi/180));
        }
    }

    // Check for position
    DetectGoal();
};

void Ball::ResetBall()
{
    this->position = sf::Vector2f(200,200);
    int newDegree = rand() % 361;
    moveDirection = sf::Vector2f(moveSpeed, moveSpeed);
    moveDirection.x = (moveDirection.x) * std::cos(newDegree * (pi/180)) - (moveDirection.y) * std::sin(newDegree * (pi/180));
    moveDirection.y = (moveDirection.x) * std::sin(newDegree * (pi/180)) + (moveDirection.y) * std::cos(newDegree * (pi/180));
};

bool Ball::CheckForCollision(sf::Vector2f aPosition)
{
    if(
        // Check if collides with player
        (aPosition.x + this->shape.getRadius() > player->position.x - player->collider.x / 2 && aPosition.x + this->shape.getRadius() < player->position.x + player->collider.x / 2
        && aPosition.y + this->shape.getRadius() > player->position.y - player->collider.y / 2 && aPosition.y + this->shape.getRadius() < player->position.y + player->collider.y / 2)
        ||
        // Check if collides with lower wall
        (aPosition.y + this->shape.getRadius() > mapSizeY)
        ||
        // Check if collides with upper wall
        (aPosition.y - this->shape.getRadius() < 0)
        ||
        // Check if collides with opponent
        (aPosition.x - this->shape.getRadius() > opponent->position.x - opponent->collider.x / 2 && aPosition.x - this->shape.getRadius() < opponent->position.x + opponent->collider.x / 2
        && aPosition.y + this->shape.getRadius() > opponent->position.y - opponent->collider.y / 2 && aPosition.y + this->shape.getRadius() < opponent->position.y + opponent->collider.y / 2)
        )
    {
        return true;
    }
    else
    {
        return false;
    }
};


void Ball::DetectGoal()
{
    if(this->position.x - this->shape.getRadius() < 0 || this->position.x + this->shape.getRadius() > mapSizeX)
    {
        ResetBall();
    }
};

void Ball::GetCollisionInfo(Player &_player, Opponent &_opponent)
{
    // Add pointers to the player and the opponent
    player = &_player;
    opponent = &_opponent;
};