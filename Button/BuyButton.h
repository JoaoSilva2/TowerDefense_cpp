#ifndef _BUY_BUTTON_H_
#define _BUY_BUTTON_H_
#include "Button.h"

class BuyButton: public Button{

public: 
    BuyButton(float x, float y): Button(x,y, "BuyButton"){
        sf::Texture t;
        t.loadFromFile("images/Buy.png");
        setTexture(t);
    }

};

#endif
