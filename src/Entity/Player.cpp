#include "Player.h"

// sf::RectangleShape shape(sf::Vector2f(50, 120));

sf::Sprite sprite;

sf::Texture texture_right;


bool grounded = true;
bool jumping = false;

float speed;

Player::Player(Game* game) : Entity(game){
    pos.y = 300;
    // Add texture to image registry
    game->images.addTexture("player_left", "assets/character/player-left.png");
    game->images.addTexture("player_right", "assets/character/player-right.png");

    texture_right = game->images.getImage("player_right");
    sprite.setTexture(texture_right);

}

void jump(){
    // TODO: Continue working on jumping...
    if(grounded){
        jumping = true;
        speed = 20;
    }
}

void Entity::update(float delta){

    sprite.setPosition(this->pos);

    if(jumping){
        if(speed > 0){
            this->pos.y = Player::JUMP_SPEED * speed;
            speed -= Player::JUMP_SPEED;
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->pos.x = this->pos.x - Player::MOVE_SPEED;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->pos.x = this->pos.x + Player::MOVE_SPEED;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        jump();
    }
}

void Entity::render(sf::RenderTarget* window){
    window->draw(sprite);
}
