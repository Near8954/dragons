//
// Created by near on 24.09.24.
//

#include "Hero.h"

#include <format>

void Hero::level_up() {
    int prev_level = get_level();
    set_level(get_level() + experience_ / (50 * get_level()));
    experience_ = experience_ % (50 * get_level());
    set_max_health(get_max_health() + (get_level() - prev_level) * 10);
    set_health(get_max_health());
    set_damage(get_damage() + (get_level() - prev_level) * 5);
}

void Hero::attack(Unit &target) const {
    if (get_level() + gen(1, 10) >= target.agility()) {
        Attacker::attack(target);
    }
}

bool Hero::isEnemy() {
    return false;
}

void Hero::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Sprite sprite;
    sprite.setPosition(sf::Vector2f(200, 530));
    sf::Texture texture;
    texture.loadFromFile("/home/near/CLionProjects/dragons/res/hero/hero.png");
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.2, 0.2));

    sf::Font font;
    if (!font.loadFromFile("/home/near/CLionProjects/dragons/res/fonts/Monas-BLBW8.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    sf::Text hp;
    hp.setCharacterSize(24);
    hp.setFillColor(sf::Color::Black);
    hp.setPosition(230, 380);
    hp.setFont(font);
    std::string s = std::format("HP:{}/{}", get_health(), get_max_health());
    hp.setString(s);


    sf::Text lvl;
    lvl.setCharacterSize(24);
    lvl.setFillColor(sf::Color::Black);
    lvl.setPosition(230, 410);
    lvl.setFont(font);
    s = std::format("LVL:{}", get_level());
    lvl.setString(s);


    sf::Text dmg;
    dmg.setCharacterSize(24);
    dmg.setFillColor(sf::Color::Black);
    dmg.setPosition(230, 440);
    dmg.setFont(font);
    s = std::format("DMG:{}", get_damage());
    dmg.setString(s);


    float x = 230;
    float y = 480;
    float szx = 200;
    float szy = 30;
    float dx = 5;
    float dy = 5;
    if (isAlive()) {
        sf::RectangleShape out(sf::Vector2f(szx, szy));
        sf::RectangleShape in(sf::Vector2f((szx - 2 * dx) / get_max_health() * get_health(), szy - 2 * dy));
        // std::cout << maxHealth() << ' ' << health() << '\n';
        out.setPosition(x, y);
        in.setPosition(x + dx, y + dy);
        out.setFillColor(sf::Color::Black);
        in.setFillColor(sf::Color::Green);

        target.draw(out, states);
        target.draw(in, states);
        target.draw(hp);
        target.draw(lvl);
        target.draw(dmg);
    }
    target.draw(sprite, states);
}
