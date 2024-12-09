#include <SFML/Graphics.hpp>
#include <iostream>

class Ball {
public:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float mass;

    Ball(float radius, float mass, sf::Vector2f position, sf::Vector2f velocity) 
        : mass(mass), velocity(velocity) {
        shape.setRadius(radius);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
        shape.setOrigin(radius, radius);
    }

    void update(float dt) {
        // Update position based on velocity
        shape.move(velocity * dt);

        // Check for collision with window boundaries
        if (shape.getPosition().x - shape.getRadius() < 0 || // Left
            shape.getPosition().x + shape.getRadius() > 800) { // Right
            velocity.x = -velocity.x; // Reverse X velocity
        }

        if (shape.getPosition().y - shape.getRadius() < 0 || // Top
            shape.getPosition().y + shape.getRadius() > 600) { // Bottom
            velocity.y = -velocity.y; // Reverse Y velocity
        }
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bouncing Ball");

    // Create a ball with an initial position and velocity
    Ball ball(30.f, 1.0f, sf::Vector2f(400, 300), sf::Vector2f(150, 100)); // Initial velocity

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ball.update(1.0f / 60.0f); // Assuming 60 FPS

        window.clear();
        window.draw(ball.shape);
        window.display();
    }

    return 0;
}

