module;
#include <SFML/Graphics.hpp>

export module game;
import board;
import tetromino;
import utilities;
import gamestate;

export class Game {
private:
    sf::RenderWindow window;
    BoardEntity entity;
    GameState state;
    sf::Font font;
    sf::Clock clock;
    sf::Clock movement_clock;
    const float move_delay = 0.1f;

public:
    Game() : window(sf::VideoMode((Board::WIDTH + 7) * Board::BLOCK_SIZE, 
                   Board::HEIGHT * Board::BLOCK_SIZE), "Tetris"),
             entity(state.get_board()) {
        window.setFramerateLimit(60);
        if (!font.loadFromFile("arial.ttf")) {
            throw std::runtime_error("Error loading font");
        }
    }

    void run() {
        while (window.isOpen()) {
            handle_events();
            update();
            render();
        }
    }

private:
    void handle_events() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && state.is_game_over()) {
                if (event.key.code == sf::Keyboard::R) {
                    state.reset();
                }
            }
        }
    }

    void update() {
        float delta_time = clock.restart().asSeconds();
        
        if (!state.is_game_over()) {
            handle_input();
            state.update(delta_time);
        }
    }

    void render() {
        window.clear(sf::Color::Black);
        entity.draw(window);
        draw_next_piece(window, state.get_next_piece());
        draw_score(window, state.get_score(), font, state.is_game_over());
        window.display();
    }

    void handle_input() {
        if (movement_clock.getElapsedTime().asSeconds() >= move_delay) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                state.move_left();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                state.move_right();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                state.move_down();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                state.rotate();
            }
            movement_clock.restart();
        }
    }
};
