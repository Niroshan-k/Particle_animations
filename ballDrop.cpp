#include <SFML/Graphics.hpp>
#include <iostream>

class Ball {
public:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float mass;
    float gravity;
    float bounceDamping;

    Ball(float radius, float mass, sf::Vector2f position) 
        : mass(mass), gravity(9.81f), bounceDamping(0.9f), velocity(0.f, 0.f) {
        shape.setRadius(radius);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
        shape.setOrigin(radius, radius);
    }

    void update(float dt) {
        // Apply gravity
        velocity.y += gravity * dt;

        // Update position based on velocity
        shape.move(velocity * dt);

        // Check for collision with the ground (window height - radius)
        if (shape.getPosition().y + shape.getRadius() > 600) {
            // Reset position to the floor level
            shape.setPosition(shape.getPosition().x, 600 - shape.getRadius());
            // Reverse velocity and apply damping
            velocity.y = -velocity.y * bounceDamping;

            // If the bounce is very small, stop the ball
            if (std::abs(velocity.y) < 1.0f) {
                velocity.y = 0; // Stop bouncing
            }
        }
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bouncing Ball");

    // Create a ball at the center of the window
    Ball ball(30.f, 0.4f, sf::Vector2f(400, 300));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ball.update(1.0f / 100.0f); // Assuming 60 FPS

        window.clear();
        window.draw(ball.shape);
        window.display();
    }

    return 0;
}

// g++ -I/opt/homebrew/include -L/opt/homebrew/lib -o ballDrop ballDrop.cpp -lsfml-graphics -lsfml-window -lsfml-system 