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

	float ForceX = 0;
	float ForceY = 0;
	if(centres_positive.size() != 0)
	{
		for (int i = 0; i < centres_positive.size(); ++i)
		{
			ForceX += 1 / (mousePosition.x - centres_positive[i].position.x);
			ForceY += 1 / (mousePosition.y - centres_positive[i].position.y);
		}
	}
	if(centres_negative.size() != 0)
	{
		for (int i = 0; i < centres_negative.size(); ++i)
		{
			ForceX += 1 / (centres_negative[i].position.x - mousePosition.x);
			ForceY += 1 / (centres_negative[i].position.y - mousePosition.y);
		}
	}

	sf::Vertex point2; 
	point2.position.x = mousePosition.x + STEP * ForceX;
	point2.position.y = mousePosition.y + STEP * ForceY;
	forward_points.push_back(point2);

	//return;
}

void CreateLine()
{
	return;
}
