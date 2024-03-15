#include "Game.h"

void Game::Draw()
{
	food.Draw();
	snake.Draw();
}

void Game::Update()
{
	if (runnig) {
		snake.Update();
		CheckCollisionWithFood();
		CheckCollisionWithEdges();
		CheckCollisionWithTail();
	}
}

void Game::CheckCollisionWithFood()
{
	if (Vector2Equals(snake.body[0], food.position)) {
		food.position = food.GenerateRandomPos(snake.body);
		snake.addSegment = true;
		score += 10;
	}
}

void Game::CheckCollisionWithEdges()
{
	if (snake.body[0].x == cellCount || snake.body[0].x == -1) {
		GameOver();
	}
	if (snake.body[0].y == cellCount || snake.body[0].y == -1) {
		GameOver();
	}
}

void Game::GameOver()
{
	snake.Reset();
	food.position = food.GenerateRandomPos(snake.body);
	runnig = false;
	score = 0;
}

void Game::CheckCollisionWithTail()
{
	for (int i = 1; i < snake.body.size(); ++i) {
		if (Vector2Equals(snake.body[0], snake.body[i]))
			snake.Reset();
	}
}
