#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <SFML/Graphics.hpp>

//Abstract class. Represents the game enemies
class Enemy{
    std::vector<sf::Vector2f> _path;
    sf::Vector2f _pos;
    sf::FloatRect _gb;
    int _pathIndex;
    float _speed;
    bool _loaded;

protected:
    Enemy(std::vector<sf::Vector2f> path, sf::Vector2f pos, float speed): 
        _path(path), _pos(pos),
        _pathIndex(0), _speed(speed), _loaded(false){}
      
public:
    virtual void update() = 0;
    virtual void render(sf::RenderWindow *screen) = 0;
    virtual void setDelete() = 0;
    virtual bool toDelete() = 0;
    std::vector<sf::Vector2f> getPath(){return _path;}
    void setGBounds(sf::FloatRect gb) {_gb = gb;}
    sf::FloatRect getGBounds() {return _gb;}
    virtual void setPos(sf::Vector2f p) {_pos = p;}
    sf::Vector2f getPos() {return _pos;}
    int getIndex() {return _pathIndex;}
    void incIndex() {_pathIndex++;}
    void resetIndex() {_pathIndex = 0;}
    bool isLoaded() {return _loaded;}
    void setLoaded() {_loaded = !_loaded;}
    float getSpeed() {return _speed;}

    virtual ~Enemy(){}
};

#endif
