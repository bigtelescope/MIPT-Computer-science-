#include "header.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(HIGHT, LENGHT), "Charges & Lines");

    std::vector<Vertex> forward_points;
    std::vector<Vertex> backward_points;

    std::vector<CircleShape> positive_charges;
    std::vector<CircleShape> negative_charges;

    std::vector<CircleShape> charges1;
    std::vector<CircleShape> charges2;

    std::vector<Vertex> centres_positive;
    std::vector<Vertex> centres_negative;

    int space_touch = 0;


    while(window.isOpen())
    {
        Event event;

        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case Event::Closed:
                    window.close();
                    break;


                case Event::KeyPressed:

                    if(event.key.code == Keyboard::R)
                        CreatePositive(window, centres_positive, positive_charges);

                    if(event.key.code == Keyboard::N)
                        CreateNegative(window, centres_negative, negative_charges);
                    break;
                        

                case Event::MouseButtonPressed:

                    if(event.mouseButton.button  == Mouse::Left)
                    {
                        CalculateForce(window, forward_points, backward_points, centres_negative, centres_positive);
                        sf::CircleShape circle(POINT_RADIUS);
                        circle.setFillColor(sf::Color::White);
                        circle.setPosition(forward_points[0].position.x , forward_points[0].position.y);
                        charges1.push_back(circle);

                        for(int i = 1; i < forward_points.size(); i ++)
                        {
                            sf::CircleShape circle2(POINT_RADIUS);
                            circle2.setFillColor(sf::Color::Green);
                            circle2.setPosition(forward_points[i].position.x , forward_points[i].position.y);
                            charges2.push_back(circle2);
                        }
                    }
                    break;
            }
        }
        window.clear();

        for(auto it : positive_charges)
            window.draw(it);
        for(auto it : negative_charges)
            window.draw(it);

        for(auto it : charges1)
            window.draw(it);
        for(auto it : charges2)
            window.draw(it);
        
        window.display();
    }

    return 0;
}
