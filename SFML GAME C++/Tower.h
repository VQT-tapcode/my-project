#ifndef TOWER_H
#define TOWER_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Bullet.h"
#include <vector>
#include <memory>


class Tower {
protected:
    sf::RectangleShape shape;
    sf::CircleShape rangeCircle;
    sf::Vector2f position;

    float range;
    float damage;
    float fireRate;
    float fireTimer;
    int cost;

    Enemy* currentTarget;

public:
    Tower(sf::Vector2f pos, float rng, float dmg, float rate, int cst);
    virtual ~Tower() {}

    virtual void update(float dt, std::vector<std::unique_ptr<Enemy>>& enemies,
        std::vector<std::unique_ptr<Bullet>>& bullets);
    virtual void draw(sf::RenderWindow& window, bool showRange = false);

    Enemy* findTarget(std::vector<std::unique_ptr<Enemy>>& enemies);
    void shoot(std::vector<std::unique_ptr<Bullet>>& bullets);

    sf::Vector2f getPosition() const { return position; }
    float getRange() const { return range; }
    int getCost() const { return cost; }
};

// Machine Gun Tower - Fast fire rate, low damage
class MachineGunTower : public Tower {
public:
    MachineGunTower(sf::Vector2f pos);
};

// Cannon Tower - Slow fire rate, high damage
class CannonTower : public Tower {
public:
    CannonTower(sf::Vector2f pos);
};

// Sniper Tower - Very slow, very high damage, long range
class SniperTower : public Tower {
public:
    SniperTower(sf::Vector2f pos);
};

#endif