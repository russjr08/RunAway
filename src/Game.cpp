#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Entity/Player.h"

sf::RenderWindow window(sf::VideoMode(800, 600), "RunAway!");
Player player;

// Forward declarations
void render();
void update();

int main(){

    while(window.isOpen()){
    sf::Event event;
        while(window.pollEvent(event)){

          if(event.type == sf::Event::Closed){
            window.close();
            Game::debug("Window exit called");
          }

          if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
            window.close();
            Game::debug("Escape key pressed, closing!");
          }

          window.clear(sf::Color(3, 184, 244)); // Sky blue
          update();
          render();

          window.display();

        }
    }

  return 0;

}

void render(){
    player.render(&window);
}

void update(){
    player.update();
}
