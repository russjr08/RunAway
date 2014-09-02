#pragma once

#include "Component.hpp"

class HealthBarComponent : public Component {

public:
    void render(sf::RenderTarget*, Entity*);
    void update(float, Entity*);

private:
    sf::Color getColor(Entity*);

};
