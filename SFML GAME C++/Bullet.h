#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <memory>

class Bullet {
private:
    sf::CircleShape shape;
    sf::Vector2f position;
    sf::Vector2f velocity;
    float damage;
    float speed;
    bool active;
    Enemy* target;

public:
    Bullet(sf::Vector2f startPos, Enemy* targetEnemy, float dmg, float spd);

    void update(float dt);
    void draw(sf::RenderWindow& window);

    bool isActive() const { return active; }
    void deactivate() { active = false; }

    bool checkHit();
};

#endif