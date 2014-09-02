#include "HealthBarComponent.hpp"

void HealthBarComponent::render(sf::RenderTarget* window, Entity* entity) {
    // TODO: Draw actual health bar...

    float entityWidth = entity->getSprite().getGlobalBounds().width;
    float entityHeight = entity->getSprite().getGlobalBounds().height;

    // Outer health bar rectangle
    sf::RectangleShape outer(sf::Vector2f(80, 8));
    outer.setOutlineColor(this->getColor(entity));
    outer.setOutlineThickness(2);
    outer.setFillColor(sf::Color::Transparent);
    outer.setPosition(sf::Vector2f(entity->getPos().x - (entityWidth / 2), entity->getPos().y - entityHeight + 4));
    window->draw(outer);

    // Inner health bar rectangle
    sf::RectangleShape inner(sf::Vector2f(entity->getHealth() * 8, 8));
    inner.setFillColor(this->getColor(entity));
    inner.setPosition(sf::Vector2f(entity->getPos().x - (entityWidth / 2), entity->getPos().y - entityHeight + 4));
    window->draw(inner);

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
