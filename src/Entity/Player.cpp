#include "Player.hpp"
#include "../Component/GravityComponent.hpp"
#include "../Component/HealthBarComponent.hpp"

// sf::RectangleShape shape(sf::Vector2f(50, 120));


sf::Texture texture_right;


bool grounded = true;
bool jumping = false;

float speed;


Player::Player(Game* game, Level* level) : Entity(game, level){
    // Add texture to image registry
    game->images.addTexture("player_left", "assets/character/player.png");
    game->images.addTexture("player_right", "assets/character/player.png");

    texture_right = game->images.getImage("player_right");
    sprite.setTexture(texture_right);

    pos.y = (Game::HEIGHT - sprite.getGlobalBounds().height) - 64;


    components.push_back(new GravityComponent());
    components.push_back(new HealthBarComponent());

}

void jump(){
    // TODO: Continue working on jumping...
    // if(grounded){
    //     jumping = true;
    //     speed = 20;
    // }
}

void Entity::update(float delta){

    sprite.setPosition(this->pos);

    for(Component* comp : components){
        comp->update(delta, this);
    }

    if(jumping){
        if(speed > 0){
            int newY = Player::JUMP_SPEED * speed;
            if(!(_level->colliding(getSprite().getGlobalBounds(), sf::Vector2i(this->pos.x, newY)))) {
                this->pos.y = Player::JUMP_SPEED * speed;
                speed -= Player::JUMP_SPEED;
            }
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if(this->pos.x <= 0) return;
        if(_level->colliding(getSprite().getGlobalBounds(), sf::Vector2i(this->pos.x - Player::MOVE_SPEED, this->pos.y))) return;
        this->pos.x = this->pos.x - Player::MOVE_SPEED;
        game->getView().move(-4.2f, 0);

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if(_level->colliding(getSprite().getGlobalBounds(), sf::Vector2i(this->pos.x + Player::MOVE_SPEED, this->pos.y))) return;
        this->pos.x = this->pos.x + Player::MOVE_SPEED;
        game->getView().move(4.2f, 0);

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        jump();
    }
}

void Entity::render(sf::RenderTarget* window){
    for(Component* comp : components) {
        comp->render(window, this);
    }
    window->draw(sprite);
}
