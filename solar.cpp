#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(600.f, 600.f), "Hollow Circle");

    // Draw the axis lines
    sf::Vertex line1[] = {
        sf::Vertex(sf::Vector2f(0.f, 300.f)), // Starting point
        sf::Vertex(sf::Vector2f(600.f, 300.f))// End point
    };
    sf::Vertex line2[] = {
        sf::Vertex(sf::Vector2f(300.f, 600.f)), // Starting point
        sf::Vertex(sf::Vector2f(300.f, 0.f)) // End point
    };

    // Center marker (Red dot at the center)
    sf::CircleShape black(2.0f);
    black.setPosition(298.f, 298.f);
    black.setFillColor(sf::Color::Red);

    // Sun outer circle (transparent inside with yellow outline)
    sf::CircleShape sun1(30.0f);
    sun1.setOrigin(30.0f, 30.0f); // Center origin
    sun1.setPosition(300.f, 300.f);
    sun1.setFillColor(sf::Color::Transparent); // Hollow
    sun1.setOutlineColor(sf::Color::Yellow);
    sun1.setOutlineThickness(5.f);

    // Sun inner circle (solid yellow)
    sf::CircleShape sun2(25.0f);
    sun2.setOrigin(25.0f, 25.0f); // Center origin
    sun2.setPosition(300.f, 300.f);
    sun2.setFillColor(sf::Color::Yellow); // Solid yellow

    // Planetary ring
    sf::CircleShape ring1(70.0f);
    ring1.setOrigin(70.0f, 70.0f); // Center origin
    ring1.setPosition(300.f, 300.f);
    ring1.setFillColor(sf::Color::Transparent); // Hollow ring
    ring1.setOutlineColor(sf::Color::White);
    ring1.setOutlineThickness(1.0f);
    
    sf::CircleShape ring2(110.f);
    ring2.setOrigin(110.f, 110.f);
    ring2.setPosition(300.f, 300.f);
    ring2.setFillColor(sf::Color::Transparent);
    ring2.setOutlineColor(sf::Color::White);
    ring2.setOutlineThickness(1.f);


    // Mercury (Green planet)
    sf::CircleShape murcury(10.0f);
    murcury.setOrigin(10.0f, 10.0f); // Center origin
    murcury.setFillColor(sf::Color::Green);

    sf::CircleShape venus(20.f);
    venus.setOrigin(20.f, 20.f);
    venus.setFillColor(sf::Color::Blue);

    // Circular motion parameters
    float angleM = 0.0f; // Angle in radians
    float angleV = 1.f;
    float Mx = 370.f, My = 300.f;
    float Vx = 300 + 110.f * cos(angleV), Vy = 300.f + 110.f * sin(angleV);
    float speedM = 0.00009f; // Slow orbit speed
    float speedV = 0.00006f;
    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update Mercury's position to orbit around the Sun
        angleM += speedM; // Increment angle to make it orbit
        angleV += speedV;
        Mx = 300.f + 70.f * cos(angleM); // X-coordinate for circular motion
        My = 300.f + 70.f * sin(angleM); // Y-coordinate for circular motion
        Vx = 300 + 110.f * cos(angleV);
        Vy = 300 + 110.f * sin(angleV);
        murcury.setPosition(Mx, My);
        venus.setPosition(Vx, Vy);

        // Clear window and draw everything
        window.clear();
        window.draw(line1, 2, sf::Lines);   // X-axis
        window.draw(line2, 2, sf::Lines);   // Y-axis
        window.draw(sun1);                  // Outer Sun circle (hollow)
        window.draw(sun2);                  // Inner Sun circle (filled)
        window.draw(black);                 // Center red dot
        window.draw(ring1);                 // Planetary ring
        window.draw(murcury);               // Mercury
        window.draw(ring2);
        window.draw(venus);
        window.display();
    }

    return 0;
}

