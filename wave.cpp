#include "wave.h"
#include <iostream>
//NOT COMPLETE


//Clock to track time
sf::Clock deltaClock;

Wave::Wave(std::vector<std::vector<sf::Vector2f>> paths, int n_mobs){
    _paths = paths;
    _n_mobs = n_mobs;
    interval = 0;
    current = 0;
    canSpawn = true;
}


//Spawn enemies in intervals of 1 sec
void Wave::spawn(){
    sf::Time dt = deltaClock.restart();
    interval += dt.asSeconds(); 
    if(interval >= 1.0 && canSpawn){
        interval = 0;
        int r = rand() % 2;
        Enemy *n = new Balloon(_paths[r], _paths[r][0]);
        _mobs.push_back(n);
        current += 1;
    }

    if(current == _n_mobs) canSpawn = false;
}

//Show current enemies
void Wave::render(sf::RenderWindow* screen){
    spawn();
    for(int i = 0; i < current; i++){
        _mobs[i]->render(screen);
    }
}

void Wave::update(){
    int i;
    auto it = _mobs.begin();

    while(it != _mobs.end()){
        if((*it)->toDelete()){
            (*it)->setPos((*it)->getPath()[0]);
            (*it)->resetIndex();
            (*it)->setDelete();
            
        }

        ++it;
    }

    for(i = 0; i < current; i++){
        _mobs[i]->update();
    }

}

Wave::~Wave(){
    for(int i = 0; i < current; i++){
        delete _mobs[i];
    }
}
