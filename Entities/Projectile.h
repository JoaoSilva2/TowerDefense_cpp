#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Projectile{
    sf::Sprite _s;
    sf::Texture _t;
    sf::FloatRect _gb;
    sf::Vector2f _pos;
    Enemy* _target;
    bool _loaded;
    bool _hit;
    float _speed;

protected:
    Projectile(float x, float y, Enemy *target, float speed): _pos(sf::Vector2f(x, y)), _loaded(false), _target(target), _hit(false), _speed(speed) {}

public:
    virtual void update() = 0;
    Enemy* getTarget() {return _target;}
    virtual void setPos(sf::Vector2f pos) {
        _pos = pos;
        _s.setPosition(_pos);
    }
    virtual sf::Vector2f getPos() {return _pos;}
    virtual sf::Sprite getSprite() {return _s;}
    virtual void setSprite(sf::Sprite s) {_s = s;} 
    virtual sf::Texture getTexture() {return _t;}
    virtual void setTexture(sf::Texture t) {_t = t;}
    virtual sf::FloatRect getGBounds() {return _gb;}
    virtual void setGBounds(sf::FloatRect gb) {_gb = gb;}
    virtual bool didHit() {return _hit;}
    virtual void setHit() {_hit = true;}
    virtual float getSpeed() {return _speed;}
    virtual void render(sf::RenderWindow* screen) {
        if(!_loaded){
            _s.setTexture(_t);
            _gb = _s.getGlobalBounds();
            _s.setOrigin(_gb.width/2, _gb.height/2);
            _s.setPosition(_pos);
            _loaded = true;
        }
        screen->draw(_s);
    }
    

};

#endif
