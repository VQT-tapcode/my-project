#include "Enemy.h"
#include <cmath>

Enemy::Enemy(const std::vector<sf::Vector2f>& pathPoints, float hp, float spd, int money, int dmg)
    : path(pathPoints), health(hp), maxHealth(hp), speed(spd), reward(money), damage(dmg)
{
    if (!path.empty()) position = path[0];

    shape.setRadius(15.f);
    shape.setOrigin(15.f, 15.f);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Blue);
}

bool Enemy::loadTexture(const std::string& filename) {
    if (texture.loadFromFile(filename)) {
        sprite.setTexture(texture);

        frameWidth = 150.f;
        frameHeight = 150.f;
        frameCount = 8;
        frameTime = 0.3f;

        sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(frameWidth), static_cast<int>(frameHeight)));
        sprite.setOrigin(frameWidth / 2.f, frameHeight / 2.f);
        sprite.setPosition(position);

        // 🖌 Scale nhân vật lớn hơn
        float scaleFactor = 2.f; // tăng gấp đôi
        sprite.setScale(scaleFactor, scaleFactor);

        hasTexture = true;
        return true;
    }
    hasTexture = false;
    return false;
}


void Enemy::update(float dt) {
    if (dead || currentWaypoint >= path.size()) return;

    // Di chuyển
    sf::Vector2f target = path[currentWaypoint];
    sf::Vector2f direction = target - position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance < 5.f) {
        currentWaypoint++;
    }
    else {
        direction /= distance;
        position += direction * speed * dt;
        shape.setPosition(position);
        if (hasTexture) sprite.setPosition(position);
    }

    // Animation
    if (hasTexture) {
        animationTimer += dt;
        if (animationTimer >= frameTime) {
            currentFrame = (currentFrame + 1) % frameCount;
            animationTimer = 0.f;
        }
        sprite.setTextureRect(sf::IntRect(
            currentFrame * static_cast<int>(frameWidth),
            0,
            static_cast<int>(frameWidth),
            static_cast<int>(frameHeight)
        ));
    }
}

void Enemy::draw(sf::RenderWindow& window) {
    if (!dead) {
        if (hasTexture)
            window.draw(sprite);
        else
            window.draw(shape);

        // Health bar
        sf::RectangleShape hpBg(sf::Vector2f(35.f, 5.f));
        hpBg.setPosition(position.x - 17.5f, position.y - 28.f);
        hpBg.setFillColor(sf::Color(50, 50, 50));
        hpBg.setOutlineThickness(1.f);
        hpBg.setOutlineColor(sf::Color::Black);
        window.draw(hpBg);

        float hpPercent = health / maxHealth;
        sf::RectangleShape hpBar(sf::Vector2f(35.f * hpPercent, 5.f));
        hpBar.setPosition(position.x - 17.5f, position.y - 28.f);

        if (hpPercent > 0.6f) hpBar.setFillColor(sf::Color::Green);
        else if (hpPercent > 0.3f) hpBar.setFillColor(sf::Color::Yellow);
        else hpBar.setFillColor(sf::Color::Red);

        window.draw(hpBar);
    }
}

void Enemy::takeDamage(float dmg) {
    health -= dmg;
    if (health <= 0) {
        health = 0;
        dead = true;
    }
}

BasicEnemy::BasicEnemy(const std::vector<sf::Vector2f>& pathPoints)
    : Enemy(pathPoints, 250.f, 50.f, 10, 1) {
<<<<<<< HEAD
    loadTexture("C:/Users/HH/Desktop/SFML GAME C++/x64/Debug/assets/Enemy Walk.png"); // chinh lai duong dan khi cai len may khac
    sprite.setScale(1.3f, 1.3f); //to hon 150% so vs goc
=======
    loadTexture("assets/Enemy Walk.png");
    sprite.setScale(1.3f, 1.3f); //to hon 130% so vs goc
>>>>>>> 8f6fa01 (Add assets folder with all game resources)
}

FastEnemy::FastEnemy(const std::vector<sf::Vector2f>& pathPoints)
    : Enemy(pathPoints, 150.f, 100.f, 15, 1) {
<<<<<<< HEAD
    loadTexture("C:/Users/HH/Desktop/SFML GAME C++/x64/Debug/assets/Bat.png"); // chinh lai duong dan khi cai len may khac
=======
    loadTexture("assets/Bat.png");
>>>>>>> 8f6fa01 (Add assets folder with all game resources)
}

TankEnemy::TankEnemy(const std::vector<sf::Vector2f>& pathPoints)
    : Enemy(pathPoints, 4000.f, 30.f, 25, 2) {
<<<<<<< HEAD
    loadTexture("C:/Users/HH/Desktop/SFML GAME C++/x64/Debug/assets/Mushroom.png"); // chinh lai duong dan khi cai len may khac
=======
    loadTexture("assets/Mushroom.png");
>>>>>>> 8f6fa01 (Add assets folder with all game resources)
    sprite.setScale(2.5f, 2.5f);
    shape.setFillColor(sf::Color::Red);
    shape.setRadius(20.f);
    shape.setOrigin(20.f, 20.f);
}
