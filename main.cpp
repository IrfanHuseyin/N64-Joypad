#include <SFML/Graphics.hpp>    

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(600, 600), "N64 Controller GUI By IF", sf::Style::Default, settings);
    sf::Texture texture;
    texture.loadFromFile("graphics/N64controller.png");
    sf::Sprite sprite(texture);

    while (window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Start Button
        sf::CircleShape circleStart(24);
        circleStart.setPosition(276, 191);
        circleStart.setOutlineThickness(1.f);
        circleStart.setOutlineColor(sf::Color(0, 0, 0));

        sf::Color pressedColor(255, 0, 0);
        sf::Color releasedColor(150, 0, 0);

        if (sf::Joystick::isButtonPressed(1, 9))
        {
            circleStart.setFillColor(pressedColor);
        }
        else
        {
            circleStart.setFillColor(releasedColor);
        }

        // A Button
        sf::CircleShape circleA(26);
        circleA.setPosition(429, 228);
        circleA.setOutlineThickness(1.f);
        circleA.setOutlineColor(sf::Color(0, 0, 0));

        sf::Color pressedColor2(0, 0, 255);
        sf::Color releasedColor2(0, 0, 150);

        if (sf::Joystick::isButtonPressed(1, 1))
        {
            circleA.setFillColor(pressedColor2);
        }
        else
        {
            circleA.setFillColor(releasedColor2);
        }

        // B Button
        sf::CircleShape circleB(26);
        circleB.setPosition(386.5, 184.5);
        circleB.setOutlineThickness(1.f);
        circleB.setOutlineColor(sf::Color(0, 0, 0));

        sf::Color pressedColor3(0, 255, 0);
        sf::Color releasedColor3(0, 150, 0);

        if (sf::Joystick::isButtonPressed(1, 2))
        {
            circleB.setFillColor(pressedColor3);
        }
        else
        {
            circleB.setFillColor(releasedColor3);
        }

        // D Middle
        sf::RectangleShape rectangleMiddle(sf::Vector2f(30, 30));
        rectangleMiddle.setPosition(97, 175);
        sf::Color customColor2(80, 80, 80);
        rectangleMiddle.setFillColor(customColor2);

        // D Up
        sf::RectangleShape rectangleUp(sf::Vector2f(30, 30));
        rectangleUp.setPosition(97, 145);

        sf::Color pressedColor4(30, 30, 30);
        sf::Color releasedColor4(80, 80, 80);

        if (sf::Joystick::isButtonPressed(1, 12))
        {
            rectangleUp.setFillColor(pressedColor4);
        }
        else
        {
            rectangleUp.setFillColor(releasedColor4);
        }

        // D Down
        sf::RectangleShape rectangleDown(sf::Vector2f(30, 30));
        rectangleDown.setPosition(97, 205);

        sf::Color pressedColor5(30, 30, 30);
        sf::Color releasedColor5(80, 80, 80);

        if (sf::Joystick::isButtonPressed(1, 14))
        {
            rectangleDown.setFillColor(pressedColor5);
        }
        else
        {
            rectangleDown.setFillColor(releasedColor5);
        }

        // D Left
        sf::RectangleShape rectangleLeft(sf::Vector2f(30, 30));
        rectangleLeft.setPosition(67, 175);

        sf::Color pressedColor6(30, 30, 30);
        sf::Color releasedColor6(80, 80, 80);

        if (sf::Joystick::isButtonPressed(1, 15))
        {
            rectangleLeft.setFillColor(pressedColor6);
        }
        else
        {
            rectangleLeft.setFillColor(releasedColor6);
        }

        // D Right
        sf::RectangleShape rectangleRight(sf::Vector2f(30, 30));
        rectangleRight.setPosition(127, 175);

        sf::Color pressedColor7(30, 30, 30);
        sf::Color releasedColor7(80, 80, 80);

        if (sf::Joystick::isButtonPressed(1, 13))
        {
            rectangleRight.setFillColor(pressedColor7);
        }
        else
        {
            rectangleRight.setFillColor(releasedColor7);
        }

        // Analog Stick
        sf::CircleShape circleStick(30);
        circleStick.setPosition(271, 303);
        sf::Color customColor(180, 180, 180);
        circleStick.setFillColor(customColor);
        circleStick.setOutlineThickness(1.f);
        circleStick.setOutlineColor(sf::Color(0, 0, 0));

        // Get joystick axis values
        float xAxis = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
        float yAxis = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);

        // Linear interpolation to map joystick values to the circle position
        float circleX = 271 + 40 * xAxis / 100.0f;
        float circleY = 303 + 40 * yAxis / 100.0f;
        circleStick.setPosition(circleX, circleY);

        float zAxis = sf::Joystick::getAxisPosition(1, sf::Joystick::Z);

        // C Up
        sf::CircleShape circleUp(19);
        circleUp.setPosition(482, 121);
        circleUp.setOutlineThickness(1.f);
        circleUp.setOutlineColor(sf::Color(0, 0, 0));

        sf::Color pressedColor8(255, 255, 0);
        sf::Color releasedColor8(100, 100, 0);

        if (zAxis < 0.0f)
        {
            circleUp.setFillColor(pressedColor8);
        }
        else
        {
            circleUp.setFillColor(releasedColor8);
        }

        // C Down
        sf::CircleShape circleDown(20);
        circleDown.setPosition(482, 189);
        circleDown.setOutlineThickness(1.f);
        circleDown.setOutlineColor(sf::Color(0, 0, 0));

        sf::Color pressedColor9(255, 255, 0);
        sf::Color releasedColor9(100, 100, 0);

        if (zAxis > 0.1f)
        {
            circleDown.setFillColor(pressedColor9);
        }
        else
        {
            circleDown.setFillColor(releasedColor9);
        }


        float zAxis1 = sf::Joystick::getAxisPosition(1, sf::Joystick::R);

        // C Left
        sf::CircleShape circleLeft(20);
        circleLeft.setPosition(445, 155);
        circleLeft.setOutlineThickness(1.f);
        circleLeft.setOutlineColor(sf::Color(0, 0, 0));

        sf::Color pressedColor10(255, 255, 0);
        sf::Color releasedColor10(100, 100, 0);

        if (zAxis1 > 0.1f)
        {
            circleLeft.setFillColor(pressedColor10);
        }
        else
        {
            circleLeft.setFillColor(releasedColor10);
        }

        // C Right
        sf::CircleShape circleRight(20);
        circleRight.setPosition(519, 155);
        circleRight.setOutlineThickness(1.f);
        circleRight.setOutlineColor(sf::Color(0, 0, 0));

        sf::Color pressedColor11(255, 255, 0);
        sf::Color releasedColor11(100, 100, 0);

        if (zAxis1 < -0.1f)
        {
            circleRight.setFillColor(pressedColor11);
        }
        else
        {
            circleRight.setFillColor(releasedColor11);
        }

        // Z Trigger, left side
        sf::RectangleShape line(sf::Vector2f(100.f, 2.f));
        line.rotate(80.f);
        line.setPosition(215.f, 340.f);

        sf::Color pressedColor12(255, 0, 0);
        sf::Color releasedColor12(100, 100, 100);

        if (sf::Joystick::isButtonPressed(1, 8))
        {
            line.setFillColor(pressedColor12);
        }
        else
        {
            line.setFillColor(releasedColor12);
        }

        // Z Trigger, right side
        sf::RectangleShape line2(sf::Vector2f(100.f, 2.f));
        line2.rotate(100.5f);
        line2.setPosition(386.f, 340.f);

        sf::Color pressedColor13(255, 0, 0);
        sf::Color releasedColor13(100, 100, 100);

        if (sf::Joystick::isButtonPressed(1, 8))
        {
            line2.setFillColor(pressedColor13);
        }
        else
        {
            line2.setFillColor(releasedColor13);
        }

        // L Button
        sf::RectangleShape line3(sf::Vector2f(85.f, 2.f));
        line3.rotate(172.f);
        line3.setPosition(177.f, 55.f);

        sf::Color pressedColor14(255, 0, 0);
        sf::Color releasedColor14(100, 100, 100);

        if (sf::Joystick::isButtonPressed(1, 6))
        {
            line3.setFillColor(pressedColor14);
        }
        else
        {
            line3.setFillColor(releasedColor14);
        }

        // L Button2
        sf::RectangleShape line4(sf::Vector2f(40.f, 2.f));
        line4.rotate(155.f);
        line4.setPosition(93.f, 67.f);

        sf::Color pressedColor15(255, 0, 0);
        sf::Color releasedColor15(100, 100, 100);

        if (sf::Joystick::isButtonPressed(1, 6))
        {
            line4.setFillColor(pressedColor15);
        }
        else
        {
            line4.setFillColor(releasedColor15);
        }

        // L Button3
        sf::RectangleShape line5(sf::Vector2f(12.f, 2.f));
        line5.rotate(95.f);
        line5.setPosition(57.f, 84.f);

        sf::Color pressedColor16(255, 0, 0);
        sf::Color releasedColor16(100, 100, 100);

        if (sf::Joystick::isButtonPressed(1, 6))
        {
            line5.setFillColor(pressedColor16);
        }
        else
        {
            line5.setFillColor(releasedColor16);
        }

        // R Button
        sf::RectangleShape line6(sf::Vector2f(85.f, 2.f));
        line6.rotate(8.5f);
        line6.setPosition(422.f, 52.f);

        sf::Color pressedColor17(255, 0, 0);
        sf::Color releasedColor17(100, 100, 100);

        if (sf::Joystick::isButtonPressed(1, 7))
        {
            line6.setFillColor(pressedColor17);
        }
        else
        {
            line6.setFillColor(releasedColor17);
        }

        // R Button2
        sf::RectangleShape line7(sf::Vector2f(44.f, 2.f));
        line7.rotate(25.f);
        line7.setPosition(505.f, 64.2f);

        sf::Color pressedColor18(255, 0, 0);
        sf::Color releasedColor18(100, 100, 100);

        if (sf::Joystick::isButtonPressed(1, 7))
        {
            line7.setFillColor(pressedColor18);
        }
        else
        {
            line7.setFillColor(releasedColor18);
        }

        // R Button3
        sf::RectangleShape line8(sf::Vector2f(12.f, 2.f));
        line8.rotate(88.f);
        line8.setPosition(545.f, 84.f);

        sf::Color pressedColor19(255, 0, 0);
        sf::Color releasedColor19(100, 100, 100);

        if (sf::Joystick::isButtonPressed(1, 7))
        {
            line8.setFillColor(pressedColor19);
        }
        else
        {
            line8.setFillColor(releasedColor19);
        }

        window.clear();
        window.draw(sprite);
        window.draw(circleStart);
        window.draw(circleA);
        window.draw(circleB);
        window.draw(circleStick);
        window.draw(circleUp);
        window.draw(circleDown);
        window.draw(circleLeft);
        window.draw(circleRight);
        window.draw(line);
        window.draw(line2);
        window.draw(line3);
        window.draw(line4);
        window.draw(line5);
        window.draw(line6);
        window.draw(line7);
        window.draw(line8);

        window.draw(rectangleUp);
        window.draw(rectangleDown);
        window.draw(rectangleLeft);
        window.draw(rectangleRight);
        window.draw(rectangleMiddle);
        window.display();
    }

    return 0;
}
