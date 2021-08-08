#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class GameObject
{
    private:


    public:
        sf::Vector2f position;

        GameObject();
        ~GameObject();
        virtual void Draw(sf::RenderWindow &window);
        virtual void Update(float &deltaTime);

        void Move(float x, float y, float &deltaTime)
        {
            sf::Vector2f newPosition(position.x + x * deltaTime, position.y + y * deltaTime);
            position = newPosition;
        }
};


GameObject::GameObject()
{

};

GameObject::~GameObject()
{

};

void GameObject::Draw(sf::RenderWindow &window)
{
    std::cout << "I am hidden" << std::endl;
};

void GameObject::Update(float &deltaTime)
{

};