#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include "wave.h"
#include "Entities/Enemy.h"
#include "Entities/Tower.h"
#include "Entities/Canon.h"
#include "Button/Button.h"
#include "Button/BuyButton.h"



class Game{
    sf::RenderWindow *_screen;
    std::vector<Wave> _waves;
    std::vector<Tower*> _towers; 
    std::vector<Button*> _buttons;
    sf::Font _f;
    sf::Text _hp_text;
    std::string _state;
    int _hp;

public:
    Game(std::vector<Wave> waves, sf::RenderWindow *screen);

    void update();
    void MouseClicked(float x, float y);
    void render();
};
#endif
