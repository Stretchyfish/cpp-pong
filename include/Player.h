#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Player : public GameObject
{
    private:

    public:
        sf::CircleShape shape;
        

        Player()
        {
            // Instantiate UI
            shape = sf::CircleShape(50.0f);
            shape.setFillColor(sf::Color(0, 0, 0));
            shape.setPosition(sf::Vector2f(25.f, 25.f));
        };

        
        void Draw(sf::RenderWindow &window)
        {
            window.draw(shape);
        }
        

};