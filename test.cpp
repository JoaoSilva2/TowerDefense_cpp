#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include "Entities/Enemy.h"
#include "wave.h"
#include "Game.h"

class Game;
class Enemy;
class Baloon;
class Wave;

int main()
{
    srand (time(NULL));
    //window where the game is played
    sf::RenderWindow window(sf::VideoMode(1500, 800), "SFML works!");
    window.setFramerateLimit(25);

    //Clock
    sf::Clock deltaClock;
    
    //texture that will be the background
    sf::Texture t;
    t.loadFromFile("images/background.jpg");
    
    //Resize image to fit window
    sf::Vector2u TextureSize = t.getSize(); //Get size of texture.
    sf::Vector2u WindowSize = window.getSize();             //Get size of window.

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;

    sf::Sprite background(t);
    background.setScale(ScaleX, ScaleY);

    //Path that shape will follow - test
    std::vector<sf::Vector2f> path{sf::Vector2f(19, 383), sf::Vector2f(378, 384), sf::Vector2f(383, 222),
                                   sf::Vector2f(546, 211), sf::Vector2f(553, 131), sf::Vector2f(879, 134),
                                   sf::Vector2f(897, 298), sf::Vector2f(1055, 296), sf::Vector2f(1063, 226),
                                   sf::Vector2f(1471, 218)};
    
    std::vector<sf::Vector2f> path2{sf::Vector2f(19, 383), sf::Vector2f(217, 384), sf::Vector2f(225, 634),
                                    sf::Vector2f(547, 633), sf::Vector2f(552, 556), sf::Vector2f(800, 552),
                                    sf::Vector2f(805, 460), sf::Vector2f(1226, 462), sf::Vector2f(1217, 227),
                                    sf::Vector2f(1466, 223)};

    
    std::vector<std::vector<sf::Vector2f>> paths{path, path2};
    
    Wave wave(paths, 14);
    std::vector<Wave> waves{wave};
    Game *g = new Game(waves, &window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                std::cout 
                     << "sf::Vector2f("
                     << sf::Mouse::getPosition(window).x << ", "
                     << sf::Mouse::getPosition(window).y << ")\n";

                g->MouseClicked(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            }
            
        }

    
        window.clear();
        window.draw(background);
        g->render();
        g->update();
        window.display();
    }

    return 0;
}
