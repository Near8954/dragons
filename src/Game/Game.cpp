//
// Created by near on 24.09.24.
//

#include "Game.h"

#include <format>

#include "../RedDragon/RedDragon.h"
#include "../BlueDragon/BlueDragon.h"
#include "../BlackDragon/BlackDragon.h"
#include <iostream>
#include <memory>

void gen_random_enemies(std::vector<Enemy *> &units) {
    int n = gen(1, 100);
    for (int i = 0; i < 10; i++) {
        if (n < 50) {
            int x = gen(1, 99);
            int y = gen(1, 10);
            std::string s = std::format("{} * {} = ", x, y);
            units.push_back(new RedDragon(50 + i * 5, 10 + i * 3, x * y, s));
            units.back()->set_level(i + 1);
        } else if (n < 75) {
            int x = gen(1, 99);
            int y = gen(1, 99);
            std::string s = std::format("{} + {} = ", x, y);
            units.push_back(new BlueDragon(50 + i * 5, 10 + i * 3, x + y, s));
            units.back()->set_level(i + 1);
        } else {
            int x = gen(1, 99);
            int y = gen(1, 99);
            if (y > x) {
                std::swap(x, y);
            }
            std::string s = std::format("{} - {} = ", x, y);
            units.push_back(new BlackDragon(50 + i * 5, 10 + i * 3, x - y, s));
            units.back()->set_level(i + 1);
        }
    }
}


Game::Game() {
    window_ = new sf::RenderWindow(sf::VideoMode{320 * 4, 240 * 4}, "Game");
    window_->setFramerateLimit(60);
    window_->setActive(true);
    sf::Texture texture;
    if (!texture.loadFromFile("/home/near/CLionProjects/dragons/res/textures/background.png")) {
    }
    sf::Sprite background;
    background.setScale(sf::Vector2f(window_->getSize().x / 320, window_->getSize().y / 240));
    background.setTexture(texture);
    std::vector<Enemy *> units;
    sf::Font font;
    if (!font.loadFromFile("/home/near/CLionProjects/dragons/res/fonts/ArimoNerdFont-Regular.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    sf::Text text;
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(720, 600);
    text.setFont(font);

    sf::Font final;

    if (!final.loadFromFile("/home/near/CLionProjects/dragons/res/fonts/Debrosee-ALPnL.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    sf::Text win;
    win.setCharacterSize(140);
    win.setFillColor(sf::Color::Red);
    win.setFont(final);
    win.setString("YOU WIN!");
    win.setPosition(window_->getSize().x / 2 - win.getGlobalBounds().width / 2, window_->getSize().y / 2 - win.getGlobalBounds().height / 2);


    sf::Text lose;
    lose.setCharacterSize(140);
    lose.setFillColor(sf::Color::Red);
    lose.setFont(final);
    lose.setString("YOU LOSE!");
    lose.setPosition(window_->getSize().x / 2 - lose.getGlobalBounds().width / 2, window_->getSize().y / 2 - lose.getGlobalBounds().height / 2);



    sf::Text quest;
    quest.setCharacterSize(24);
    quest.setFillColor(sf::Color::Black);
    quest.setPosition(620, 600);
    quest.setFont(font);

    sf::Sprite bubble;
    sf::Texture bubble_texture;
    if (!bubble_texture.loadFromFile("/home/near/CLionProjects/dragons/res/bubble.png")) {
        std::cout << "Error loading bubble texture" << '\n';
    }
    bubble.setTexture(bubble_texture);
    bubble.setPosition(600, 550);
    bubble.setScale(0.3, 0.3);


    std::string input;
    std::string name = "Hero";
    Hero *hero = new Hero(name);


    gen_random_enemies(units);


    while (window_->isOpen()) {
        sf::Event event;
        while (window_->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window_->close();
            }
            if (event.type == sf::Event::TextEntered) {
                if (std::isdigit(event.text.unicode) && input.size() < 4) {
                    input += static_cast<char>(event.text.unicode);
                    text.setString(input);
                    //std::cout << input << std::endl;
                } else if (event.text.unicode == '\b' && !input.empty()) {
                    input.pop_back();
                    text.setString(input);
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                if (!input.empty() && !units.empty()) {
                    Enemy *enemy = units[0];

                    int answer = std::stoi(input);
                    if (enemy->get_answer() != answer) {
                        enemy->attack(*hero);
                    } else {
                        hero->attack(*enemy);
                        dynamic_cast<Dragon *>(enemy)->change_question();
                        //std::cout << enemy->get_health() << '\n';
                    }
                    if (!enemy->isAlive()) {
                        std::cout << hero->get_experience() << '\n';
                        hero->set_experience(hero->get_experience() + enemy->get_max_health());
                        std::cout << hero->get_experience() << '\n';
                        hero->level_up();
                        delete enemy;
                        units.erase(units.begin());
                    }
                    input.clear();
                    quest.setString("");
                    text.setString(input);
                }
            }
        }

        quest.setString(units[0]->get_question());


        window_->clear(sf::Color::White);
        window_->draw(background);
        if (!units.empty() && hero->isAlive()) {
            window_->draw(*units[0]);
            window_->draw(bubble);
            window_->draw(quest);
            window_->draw(text);
            window_->draw(*hero);
        } else if (units.empty() && hero->isAlive()) {
            window_->draw(win);
        } else {
            window_->draw(lose);
        }
        window_->display();
    }
}

Game::~Game() {
    delete window_;
}

void Game::draw_entities(std::vector<Enemy *> &units) {
    window_->draw(*units[0]);
}
