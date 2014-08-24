#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public virtual Entity {

protected:

public:
    Player(Game*);

    constexpr static float MOVE_SPEED = 5.0f;
    constexpr static float JUMP_SPEED = 10.0f;


};

#endif
