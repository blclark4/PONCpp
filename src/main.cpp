#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code.
        // We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/>
        // breakpoint for you, but you can always add more by pressing
        // <shortcut actionId="ToggleLineBreakpoint"/>.
        std::cout << "i = " << i << std::endl;
    }

    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "Move the Rectangle");
    int ColorVelocity = 0;
    int colorSpeedLimit = 600;
    int colorRefraction = 30000;
    int colorAccelleration = 50;
    int colorDrag = 3;
    int colorIndex = 3;
    std::vector<sf::Color> colors = {
        sf::Color::Magenta,
        sf::Color::Red,
        sf::Color::Yellow,
        sf::Color::Green,
        sf::Color::Cyan,
        sf::Color::Blue,
        sf::Color::White
    };

    window.setFramerateLimit(144);
    sf::RectangleShape rectangle(sf::Vector2f(100.0f, 50.0f));  // Width = 100, Height = 50
    rectangle.setFillColor(colors[colorIndex]);
    rectangle.setPosition(sf::Vector2f(350.0f, 275.0f));  // Initial position


    while (window.isOpen())
    {
        std::optional event = window.pollEvent();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        if (ColorVelocity > 0) {
            colorRefraction += ColorVelocity;
            if (colorRefraction >= colors.size() * 10000) { colorRefraction = 0; }
            colorIndex = colorRefraction / 10000;
            if (colors[colorIndex] != rectangle.getFillColor()) {
                rectangle.setFillColor(colors[colorIndex]);

            }
            std::cout << "Color Velocity: " <<  ColorVelocity << ".  Color: " << colors[colorIndex].toInteger() << std::endl;
            ColorVelocity -= colorDrag;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) {
            rectangle.move(sf::Vector2f(0, -2));  // move up
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) {
            rectangle.move(sf::Vector2f(0, 2));   // move down
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
            rectangle.move(sf::Vector2f(-5,0));   // move left
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
            rectangle.move(sf::Vector2f(5, 0));   // move right
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space)) {
            // begin color transition
            if (ColorVelocity < colorSpeedLimit) {
                ColorVelocity += colorAccelleration;
            }
        }

        window.clear(sf::Color::Black); // Clear the screen
        window.draw(rectangle);         // Draw the rectangle
        window.display();               // Display the content
    }


    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.