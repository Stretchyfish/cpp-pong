#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Engine
{
    private:
        sf::RenderWindow window;
        sf::CircleShape shape;

    public:
        Engine();
        void Start();
        void Update();
};

Engine::Engine()
{
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    window.create(sf::VideoMode(resolution.x, resolution.y), "Steel Engine", sf::Style::Default);

    std::cout << "print me" << std::endl;
    shape = sf::CircleShape(250.0f);
    shape.setFillColor(sf::Color(0, 0, 0));
}


void Engine::Update()
{
    window.draw(shape);
}

void Engine::Start()
{
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        // Make things here
        Update();

        window.display();
    }
}