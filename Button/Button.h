#ifndef _BUTTON_H_
#define _BUTTON_H_
#include <SFML/Graphics.hpp>

class Button{
    std::string _name;
    sf::Sprite _s;
    sf::Texture _t;
    sf::FloatRect _gb;
    sf::Vector2f _pos;
    bool _loaded;

protected:
    Button(float x, float y, std::string name){_pos = sf::Vector2f(x, y), _loaded = false, _name = name;}
public:
    virtual std::string getName() {return _name;}
    virtual sf::Vector2f getPos() {return _pos;}
    virtual sf::Sprite getSprite() {return _s;}
    virtual void setSprite(sf::Sprite s) {_s = s;} 
    virtual sf::Texture getTexture() {return _t;}
    virtual void setTexture(sf::Texture t) {_t = t;}
    virtual sf::FloatRect getGBounds() {return _gb;}
    virtual void setGBounds(sf::FloatRect gb) {_gb = gb;}
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
    virtual bool clicked(float x, float y){;
        float h = _gb.height;
        float w = _gb.width;

        if(x <= _pos.x+w/2 && x >= _pos.x-w/2){
            if(y <= _pos.y+h/2 && y >= _pos.y-h/2){
                return true;
            }
        }
        return false;
    };

};
#endif
