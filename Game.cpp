#include "Game.h"

Game::Game(std::vector<Wave> waves, sf::RenderWindow *screen){
    Button *b = new BuyButton(100, 750);
    _screen = screen;
    _waves = waves;
    _buttons.push_back(b);
    _state = "";
    _hp = 30;
    _f.loadFromFile("Font/lato/Lato-Bold.ttf");
    _hp_text.setFont(_f);
    _hp_text.setString(std::to_string(_hp) + "/" + std::to_string(_hp));
    _hp_text.setCharacterSize(32);
    _hp_text.setFillColor(sf::Color::Green);
    //_hp_text.setPosition(59, 1500);
}

void Game::update(){
    for(size_t st = 0; st < _towers.size(); st++){
        _towers[st]->update(_waves[0].getEnemies());
    }

    for(size_t st = 0; st < _waves.size(); st++){
        _waves[st].update();
    }
}

void Game::MouseClicked(float x, float y){
    if(_state == "On Buy"){
        std::cout << "oi" << std::endl;
        Tower *t = new Canon(sf::Vector2f(x, y));
        _towers.push_back(t);
        _state = "";
    }


    else{
        for(size_t st = 0; st < _buttons.size(); st++){
            Button *b = _buttons[st];
            if(b->clicked(x, y)){
                if(b->getName() == "BuyButton"){
                    _state = "On Buy";
                }
            }
        }
    }
}

void Game::render(){
    _screen->draw(_hp_text);

    for(size_t st = 0; st < _buttons.size(); st++){
        _buttons[st]->render(_screen);
    }

    for(size_t st = 0; st < _towers.size(); st++){
        _towers[st]->render(_screen);
    }

    for(size_t st = 0; st < _waves.size(); st++){
        _waves[st].render(_screen);
    }
}

