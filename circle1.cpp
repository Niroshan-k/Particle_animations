#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML Animation");
  
    float rad = 50.0f;  
    sf::CircleShape circle(rad);
    circle.setFillColor(sf::Color::Blue);
    sf::CircleShape circle2(rad);
    circle2.setFillColor(sf::Color::Red);

    float x = 100.0f, y = 300.0f;
    float velocityX = 0.05f;
    float velocityY = 0.05f;
    
    float x2 = 300.0f, y2 = 100.0f;
    float velocityX2 = 0.05f;
    float velocityY2 = 0.05f;

    while (window.isOpen()) {
        
      sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)
                window.close();
        }

      x += velocityX;
      y += velocityY;
      x2 += velocityX2;
      y2 += velocityY2;
      
      float diff_x = fabs(x2 - x);
      float diff_y = fabs(y2 - y);
      float diff = std::sqrt((diff_x * diff_x) + (diff_y*diff_y) );
      
      if(diff < ( 2*rad)){
        velocityX2 = -velocityX2;
        velocityY2 = -velocityY2;
        velocityX = -velocityX;
        velocityY = -velocityY;
      }

      if (x > 550.0f || x < 0.0f) velocityX = -velocityX;
      if (y > 550.0f || y < 50.0f) velocityY = -velocityY;
      if (x2 > 550.0f || x2 < 0.0f) velocityX2 = -velocityX2;
      if (y2 > 550.0f || y2 < 50.0f) velocityY2 = -velocityY2;
        
      circle.setPosition(x, y);
      circle2.setPosition(x2, y2);

      window.clear();
      window.draw(circle);
      window.draw(circle2);
      window.display();
    
    }

    return 0;
}

