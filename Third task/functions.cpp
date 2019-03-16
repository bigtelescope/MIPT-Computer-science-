#include "header.h"

void CreatePositive(sf::RenderWindow& window, std::vector<sf::Vertex>& centres_positive, std::vector<sf::CircleShape>& positive_charges)
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

void CreateNegative(sf::RenderWindow& window, std::vector<sf::Vertex>& centres_negative, std::vector<sf::CircleShape>& negative_charges)
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

void MakeForce()
{
	return;
}

void CreateLine()
{
	return;
}

