#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class GameObject
{
    private:
    public:
        sf::Vector2f position;
        sf::Vector2f collider;

        GameObject();
        ~GameObject();
        virtual void Draw(sf::RenderWindow &window);
        virtual void Update(float &deltaTime);
        virtual void Input();

        void Move(float x, float y, float &deltaTime);
};


GameObject::GameObject()
{

};

GameObject::~GameObject()
{

};

void GameObject::Draw(sf::RenderWindow &window)
{

};

void GameObject::Update(float &deltaTime)
{

};

void GameObject::Input()
{

};

void GameObject::Move(float x, float y, float &deltaTime)
{
    sf::Vector2f newPosition(position.x + x * deltaTime, position.y + y * deltaTime);
    position = newPosition;
};