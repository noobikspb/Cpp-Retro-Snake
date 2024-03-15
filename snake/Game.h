#pragma once
#include "Food.h"
#include "Snake.h"

class Game
{
public:
	Snake snake = Snake();
	Food food = Food(snake.body);
	bool runnig = true;
	int score = 0;

	void Draw();

	void Update();

	void CheckCollisionWithFood();

	void CheckCollisionWithEdges();

	void GameOver();

	void CheckCollisionWithTail();
};

