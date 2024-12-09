#include <SFML/Graphics.hpp>
#include <cmath>

int main() {
    // Create a 600x600 window titled "line"
    sf::RenderWindow window(sf::VideoMode(600, 600), "line");

    // Constants
    const float PI = 3.14159265f;
    const float radius = 100.f; // Radius for positioning triangle points around a center

    // Center point coordinates
    const float centerX = 300.f;
    const float centerY = 300.f;

    // Set up a transparent triangle with a red outline
    sf::ConvexShape triangle;
    triangle.setPointCount(3); // A triangle has 3 points

    // Define the triangle's points
    triangle.setPoint(0, sf::Vector2f(centerX, centerY - radius)); // Top point of the triangle
    float xT = centerX - radius * cos(PI / 5);
    float yT = centerY + radius * sin(PI / 5);
    triangle.setPoint(1, sf::Vector2f(xT, yT));                   // Bottom left point
    triangle.setPoint(2, sf::Vector2f(xT + 2 * radius * cos(PI/5), yT)); // Bottom right point

    // Set triangle colors
    triangle.setFillColor(sf::Color(0, 0, 0, 0));    // Transparent fill
    triangle.setOutlineColor(sf::Color::Red);         // Red outline color
    triangle.setOutlineThickness(2.f);                // Outline thickness of 2 pixels

    // Create a small red circle at the center
    sf::CircleShape centerCircle(1.f);
    centerCircle.setPosition(centerX - 1.f, centerY - 1.f); // Centered at (300, 300)
    centerCircle.setFillColor(sf::Color::Red);

    // Create a large transparent circle with a white outline to represent a ring
    sf::CircleShape ring(radius);
    ring.setOrigin(radius, radius);                   // Origin at the center of the circle
    ring.setPosition(centerX, centerY);               // Centered at (300, 300)
    ring.setFillColor(sf::Color::Transparent);        // Transparent fill
    ring.setOutlineColor(sf::Color::White);           // White outline color
    ring.setOutlineThickness(2.f);                    // Outline thickness of 2 pixels

    // Main loop to keep the window open
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();
        
        // Draw shapes
        window.draw(centerCircle);
        window.draw(ring);
        window.draw(triangle);
        
        // Display the shapes on the window
        window.display();
    }

    return 0;
}

