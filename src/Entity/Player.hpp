#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"
#include "../Component/Component.hpp"

class Player : public virtual Entity {


public:
    Player(Game*);

    constexpr static float MOVE_SPEED = 5.0f;
    constexpr static float JUMP_SPEED = 10.0f;


};

#endif
