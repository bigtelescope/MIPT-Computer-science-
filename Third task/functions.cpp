#include "head.h"

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

	//The first cycle for creating points on the right hand
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

		sf::Vertex front_point; 
		front_point.position.x = forward_points[i].position.x + STEP * ForceX;
		front_point.position.y = forward_points[i].position.y + STEP * ForceY;
		forward_points.push_back(front_point);

		for(int k = 0; k < centres_negative.size(); k++)
			if(abs(forward_points[i].position.x - centres_negative[k].position.x) < RADIUS\
				 && abs(forward_points[i].position.y - centres_negative[k].position.y) < RADIUS)
				end++;

		if(FRONT_X_NOT_ON_SCREEN || FRONT_Y_NOT_ON_SCREEN)
			end++;
	}
	forward_points.pop_back();

	//The second cycle for creating points on the left hand
	for(int i = 0, end = 0; end == 0; i++)
	{
		float ForceX = 0;
		float ForceY = 0;
		float Rad = 0;
		if(centres_positive.size() != 0)
		{
			for (int j = 0; j < centres_positive.size(); j++)
			{
				Rad = sqrt((backward_points[i].position.x - centres_positive[j].position.x) * (backward_points[i].position.x - centres_positive[j].position.x) +\
						(backward_points[i].position.y - centres_positive[j].position.y) * (backward_points[i].position.y - centres_positive[j].position.y));
				ForceX += (backward_points[i].position.x - centres_positive[j].position.x) / (Rad * Rad);
				ForceY += (backward_points[i].position.y - centres_positive[j].position.y) / (Rad * Rad);
			}
		}
		if(centres_negative.size() != 0)
		{
			for (int j = 0; j < centres_negative.size(); j++)
			{
				Rad = sqrt((backward_points[i].position.x - centres_negative[j].position.x) * (backward_points[i].position.x - centres_negative[j].position.x) +\
						(backward_points[i].position.y - centres_negative[j].position.y) * (backward_points[i].position.y - centres_negative[j].position.y));
				ForceX += (centres_negative[j].position.x - backward_points[i].position.x) / (Rad * Rad);
				ForceY += (centres_negative[j].position.y - backward_points[i].position.y) / (Rad * Rad);
			}
		}

		sf::Vertex back_point; 
		back_point.position.x = backward_points[i].position.x - STEP * ForceX;
		back_point.position.y = backward_points[i].position.y - STEP * ForceY;
		backward_points.push_back(back_point);

		for(int k = 0; k < centres_positive.size(); k++)
			if(NEXT_TO_POS_X && NEXT_TO_POS_Y)
				end++;

		if(BACK_X_NOT_ON_SCREEN || BACK_Y_NOT_ON_SCREEN)
			end++;
	}
	backward_points.pop_back();
	
	return;
}

void CreateLine(std::vector<sf::CircleShape>& LineBalls, std::vector<sf::Vertex>& forward_points, std::vector<sf::Vertex>& backward_points)
{
    for(int i = 0; i < forward_points.size(); i ++)
	{
		sf::CircleShape element(POINT_RADIUS);
		element.setFillColor(sf::Color::White);
		element.setPosition(forward_points[i].position.x , forward_points[i].position.y);
		LineBalls.push_back(element);
	}
	forward_points.clear();
	for(int i = 0; i < backward_points.size(); i++)
	{
		sf::CircleShape element(POINT_RADIUS);
		element.setFillColor(sf::Color::White);
		element.setPosition(backward_points[i].position.x , backward_points[i].position.y);
		LineBalls.push_back(element);
	}
	backward_points.clear();
	return;
}
