//
// Created by near on 25.09.24.
//

#include "BlackDragon.h"

#include <format>

#include <iostream>

void BlackDragon::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Sprite sprite;
    sprite.setPosition(sf::Vector2f(1100, 500));
    sf::Texture texture;
    texture.loadFromFile("/home/near/CLionProjects/dragons/res/black_dragon/Dragonblack_img.png");
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(-0.3, 0.3));


    float x = 850;
    float y = 500;
    float szx = 200;
    float szy = 30;
    float dx = 5;
    float dy = 5;

    sf::Font font;
    if (!font.loadFromFile("/home/near/CLionProjects/dragons/res/fonts/Monas-BLBW8.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }

    sf::Text hp;
    hp.setCharacterSize(24);
    hp.setFillColor(sf::Color::Black);
    hp.setPosition(850, 400);
    hp.setFont(font);
    std::string s = std::format("HP:{}/{}", get_health(), get_max_health());
    hp.setString(s);


    sf::Text lvl;
    lvl.setCharacterSize(24);
    lvl.setFillColor(sf::Color::Black);
    lvl.setPosition(850, 430);
    lvl.setFont(font);
    s = std::format("LVL:{}", get_level());
    lvl.setString(s);

    sf::Text dmg;
    dmg.setCharacterSize(24);
    dmg.setFillColor(sf::Color::Black);
    dmg.setPosition(850, 460);
    dmg.setFont(font);
    s = std::format("DMG:{}", get_damage());
    dmg.setString(s);

    sf::RectangleShape out(sf::Vector2f(szx, szy));
    sf::RectangleShape in(sf::Vector2f((szx - 2 * dx) * get_health() / get_max_health(), szy - 2 * dy));
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
    target.draw(sprite, states);
}

void BlackDragon::change_question() {
    int x = gen(1, 99);
    int y = gen(1, 99);
    if (y > x) {
        std::swap(x, y);
    }
    std::string s = std::format("{} - {} = ", x, y);
    set_question(s);
    set_answer(x - y);
}
