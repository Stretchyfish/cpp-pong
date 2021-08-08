#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

#include "GameObject.h"
#include "Player.h"
#include "Opponent.h"

class Engine
{
    private:
        sf::RenderWindow window;
        sf::CircleShape shape;


        GameObject player2;
        Player player;
        Opponent opponent;

    public:
        float deltaTime;
        Engine();
        void Start();
        void Update();
        void Input();
        void Draw();
};

Engine::Engine()
{
    // Full screen settings
    /*
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    window.create(sf::VideoMode(resolution.x, resolution.y), "Steel Engine", sf::Style::Default);
    */

    window.create(sf::VideoMode(400, 400), "PONG", sf::Style::Default);

    std::cout << "print me" << std::endl;
    shape = sf::CircleShape(50.0f);
    shape.setFillColor(sf::Color(0, 0, 0));
}

void Engine::Start()
{
    sf::Clock clock;

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

        // Calculate deltaTime
        sf::Time dt = clock.restart();
        deltaTime = dt.asSeconds();

        // Background
        window.clear(sf::Color::Black);

        // Update game
        Update();
        Input();
        Draw();
        window.display();
    }
}

void Engine::Update()
{
    opponent.Update(deltaTime);
}

void Engine::Input()
{

}

void Engine::Draw()
{
    player.Draw(window);
    opponent.Draw(window);
}