#include "HealthBarComponent.hpp"

void HealthBarComponent::render(sf::RenderTarget* window, Entity* entity) {
    // TODO: Draw actual health bar...
}

void HealthBarComponent::update(float delta, Entity* entity) {}

sf::Color HealthBarComponent::getColor(Entity* entity) {
    if (entity->getHealth() >= 6) {
        return sf::Color::Green;
    }

    if (entity->getHealth() >= 4) {
        return sf::Color(255, 165, 0);
    }

    if (entity->getHealth() >= 1) {
        return sf::Color::Red;
    }

    return sf::Color::White;

}
