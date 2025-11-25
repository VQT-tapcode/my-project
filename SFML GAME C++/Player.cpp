#include "Player.h"

Player::Player(int startMoney, int startLives)
    : money(400), score(0), lives(20), wave(1) {
}

void Player::addMoney(int amount) {
    if (amount > 0) {
        money += amount;
    }
}

bool Player::spendMoney(int amount) {
    if (amount <= money && amount > 0) {
        money -= amount;
        return true;
    }
    return false;
}

void Player::addScore(int points) {
    if (points > 0) {
        score += points;
    }
}

void Player::loseLife(int amount) {
    lives -= amount;
    if (lives < 0) {
        lives = 0;
    }
}

void Player::nextWave() {
    wave++;
}

void Player::drawUI(sf::RenderWindow& window, sf::Font& font) {
    const float panelWidth = 280.f;
    const float panelHeight = 130.f;
    const float margin = 5.f;

    // Position ở góc trên bên phải
    sf::Vector2f panelPosition(window.getSize().x - panelWidth - margin, margin);

    sf::RectangleShape uiPanel(sf::Vector2f(panelWidth, panelHeight));
    uiPanel.setPosition(panelPosition);
    uiPanel.setFillColor(sf::Color(0, 0, 0, 180));
    uiPanel.setOutlineThickness(2.f);
    uiPanel.setOutlineColor(sf::Color::White);
    window.draw(uiPanel);

    // Money - BIG and YELLOW
    sf::Text moneyText;
    moneyText.setFont(font);
    moneyText.setString("$ " + std::to_string(money));
    moneyText.setCharacterSize(36);
    moneyText.setFillColor(sf::Color::Yellow);
    moneyText.setStyle(sf::Text::Bold);
    moneyText.setPosition(panelPosition.x + 15.f, panelPosition.y + 10.f);
    window.draw(moneyText);

    // Score
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setCharacterSize(18);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(panelPosition.x + 15.f, panelPosition.y + 55.f);
    window.draw(scoreText);

    // Lives with heart symbol
    sf::Text livesText;
    livesText.setFont(font);
    livesText.setString("Lives: " + std::to_string(lives));
    livesText.setCharacterSize(18);
    livesText.setFillColor(sf::Color::Red);
    livesText.setStyle(sf::Text::Bold);
    livesText.setPosition(panelPosition.x + 15.f, panelPosition.y + 80.f);
    window.draw(livesText);

    // Wave
    sf::Text waveText;
    waveText.setFont(font);
    waveText.setString("Wave: " + std::to_string(wave));
    waveText.setCharacterSize(18);
    waveText.setFillColor(sf::Color::Cyan);
    waveText.setPosition(panelPosition.x + 15.f, panelPosition.y + 105.f);
    window.draw(waveText);
}


void Player::reset() {
    money = 400;
    score = 0;
    lives = 20;
    wave = 1;
}
