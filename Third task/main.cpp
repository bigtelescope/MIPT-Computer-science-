#include "header.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(HIGHT, LENGHT), "Charges & Lines");

    std::vector<Vertex> forward_points;
    std::vector<Vertex> backward_points;

    std::vector<CircleShape> positive_charges;
    std::vector<CircleShape> negative_charges;

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
                        CreateLine();
                    break;
            }
        }
        window.clear();

        for(auto it : positive_charges)
            window.draw(it);
        for(auto it : negative_charges)
            window.draw(it);
        
        window.display();
    }

    return 0;
}
