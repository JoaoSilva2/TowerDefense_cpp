#ifndef _CANON_H_
#define _CANON_H_
#include "Tower.h"



class Canon: public Tower{
    sf::Texture _t;
    sf::Sprite _s;
    float rotation;
    Enemy* target;
    float _aspeed;

public:
    Canon(sf::Vector2f pos): Tower(pos), rotation(0), _aspeed(2.0){}
    void update(std::vector<Enemy*> enemies);
    void render(sf::RenderWindow *screen);
};

#endif
