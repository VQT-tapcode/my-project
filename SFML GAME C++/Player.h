#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>


class Player {
private:
    int money;
    int score;
    int lives;
    int wave;
    int bestScore;

public:
    Player(int startMoney = 100, int startLives = 10);

    // Money
    void addMoney(int amount);
    bool spendMoney(int amount);
    int getMoney() const { return money; }

    // Score
    void addScore(int points);
    int getScore() const { return score; }
    int getBestScore() const { return bestScore; }
    void updateBestScore();

    // Lives
    void loseLife(int amount = 1);
    int getLives() const { return lives; }
    bool isGameOver() const { return lives <= 0; }

    // Wave
    void nextWave();
    int getWave() const { return wave; }

    // UI
    void drawUI(sf::RenderWindow& window, sf::Font& font);

    // Save/Load
    void saveBestScore(const std::string& filename = "bestscore.dat");
    void loadBestScore(const std::string& filename = "bestscore.dat");

    // Reset
    void reset();
};

#endif
