#include "header.h"

void CreatePositive(sf::RenderWindow& window,\
						std::vector<sf::Vertex>& centres_positive, std::vector<sf::CircleShape>& positive_charges)
{
	sf::CircleShape circle(RADIUS);
	circle.setFillColor(sf::Color::Red);

	sf::Vertex centres;
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	centres.position.x = mousePosition.x;
	centres.position.y = mousePosition.y;
	circle.setPosition(mousePosition.x - RADIUS, mousePosition.y - RADIUS);

	centres_positive.push_back(centres);
	positive_charges.push_back(circle);
}

void CreateNegative(sf::RenderWindow& window,\
						std::vector<sf::Vertex>& centres_negative, std::vector<sf::CircleShape>& negative_charges)
{
	sf::CircleShape circle(RADIUS);
	circle.setFillColor(sf::Color::Blue);

	sf::Vertex centres;
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	centres.position.x = mousePosition.x;
	centres.position.y = mousePosition.y;
	circle.setPosition(mousePosition.x - RADIUS, mousePosition.y - RADIUS);

	centres_negative.push_back(centres);
	negative_charges.push_back(circle);
}

void CalculateForce(sf::RenderWindow& window,																	\
					std::vector<sf::Vertex>& forward_points, std::vector<sf::Vertex>& backward_points,			\
					std::vector<sf::Vertex>& centres_negative, std::vector<sf::Vertex>& centres_positive)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vertex point;
	point.position.x = mousePosition.x;
	point.position.y = mousePosition.y;
	forward_points.push_back(point);
	backward_points.push_back(point);

	for(int i = 0, end = 0; end == 0; i++)
	{
		float ForceX = 0;
		float ForceY = 0;
		float Rad = 0;
		if(centres_positive.size() != 0)
		{
			for (int j = 0; j < centres_positive.size(); j++)
			{
				Rad = sqrt((forward_points[i].position.x - centres_positive[j].position.x) * (forward_points[i].position.x - centres_positive[j].position.x) +\
						(forward_points[i].position.y - centres_positive[j].position.y) * (forward_points[i].position.y - centres_positive[j].position.y));
				ForceX += (forward_points[i].position.x - centres_positive[j].position.x) / (Rad * Rad);
				ForceY += (forward_points[i].position.y - centres_positive[j].position.y) / (Rad * Rad);
			}
		}
		if(centres_negative.size() != 0)
		{
			for (int j = 0; j < centres_negative.size(); j++)
			{
				Rad = sqrt((forward_points[i].position.x - centres_negative[j].position.x) * (forward_points[i].position.x - centres_negative[j].position.x) +\
						(forward_points[i].position.y - centres_negative[j].position.y) * (forward_points[i].position.y - centres_negative[j].position.y));
				ForceX += (centres_negative[j].position.x - forward_points[i].position.x) / (Rad * Rad);
				ForceY += (centres_negative[j].position.y - forward_points[i].position.y) / (Rad * Rad);
			}
		}

		sf::Vertex point2; 
		point2.position.x = forward_points[i].position.x + STEP * ForceX;
		point2.position.y = forward_points[i].position.y + STEP * ForceY;
		forward_points.push_back(point2);

		for(int k = 0; k < centres_negative.size(); k++)
			if(abs(forward_points[i].position.x - centres_negative[k].position.x) < RADIUS\
				 && abs(forward_points[i].position.y - centres_negative[k].position.y) < RADIUS)
				end++;

		sf::Vertex back_point; 
		back_point.position.x = backward_points[i].position.x + STEP * ForceX;
		back_point.position.y = backward_points[i].position.y + STEP * ForceY;
		backward_points.push_back(back_point);

		for(int k = 0; k < centres_positive.size(); k++)
			if(abs(backward_points[i].position.x - centres_positive[k].position.x) < RADIUS\
				 && abs(backward_points[i].position.y - centres_positive[k].position.y) < RADIUS)
				end++;
	}
	
	return;
}

void CreateLine()
{
	return;
}
