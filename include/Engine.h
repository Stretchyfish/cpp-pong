#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

#include "GameObject.h"
#include "Player.h"
#include "Opponent.h"
#include "Ball.h"

class Engine
{
    private:
        sf::RenderWindow window;

        Player player;
        Opponent opponent;
        Ball ball;

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
    // Add variables to ball
    ball.GetCollisionInfo(player, opponent);

    // Create window
    window.create(sf::VideoMode(400, 400), "PONG", sf::Style::Default);
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
    player.Update(deltaTime);
    opponent.Update(deltaTime);
    ball.Update(deltaTime);
}

void Engine::Input()
{
    player.Input();
    opponent.Input();
}

void Engine::Draw()
{
    player.Draw(window);
    opponent.Draw(window);
    ball.Draw(window);
}