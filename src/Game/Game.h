//
// Created by near on 24.09.24.
//

#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "../Hero/Hero.h"
#include "../Dragon/Dragon.h"
class Game {
public:
    Game();

    void draw_entities(std::vector<Enemy *> &units);


    ~Game();
private:
    sf::RenderWindow *window_;

};


#endif //GAME_H
