#ifndef _WAVE_H_
#define _WAVE_H_

#include "Entities/Enemy.h"
#include "Entities/ballon.h"
#include "Entities/Tower.h"
#include "Entities/Canon.h"

#include <vector>


class Wave{
    std::vector<std::vector<sf::Vector2f>> _paths;
    int _n_mobs;
    int current;
    float interval;
    std::vector<Enemy*> _mobs;
    bool canSpawn;

public:
    Wave(std::vector<std::vector<sf::Vector2f>> path, int n_mobs);
    std::vector<Enemy*> getEnemies() {return _mobs;}
    void spawn();
    void render(sf::RenderWindow* screen);
    void update();
    ~Wave();

};

#endif
