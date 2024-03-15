#include "Food.h"

bool Vector2Equals(const Vector2& first, const Vector2& second) {
	if (first.x == second.x && first.y == second.y)
		return true;
	return false;
}

Food::Food(const std::deque<Vector2>& snakeBody)
{
	position = GenerateRandomPos(snakeBody);
}

void Food::Draw()
{
	DrawRectangle(offset + position.x * cellSize, offset + position.y * cellSize, cellSize, cellSize, darkGreen);
}

Vector2 Food::GenerateRandomPos(const std::deque<Vector2>& snakeBody)
{
	float x = GetRandomValue(0, cellCount - 1);
	float y = GetRandomValue(0, cellCount - 1);
	Vector2 position = { x,y };
	for (int i = 0; i < snakeBody.size(); ++i) {
		if (Vector2Equals(snakeBody[i], position)) {
			position = GenerateRandomPos(snakeBody);
			break;
		}
	}
	return position;
}
