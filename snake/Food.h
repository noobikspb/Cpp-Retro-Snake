#pragma once
#include <raylib.h>
#include <deque>

extern Color darkGreen;

extern int offset;
extern int cellSize;
extern int cellCount;

bool Vector2Equals(const Vector2& first, const Vector2& second);

class Food
{
public:
	Vector2 position;

	Food(const std::deque<Vector2>& snakeBody);

	void Draw();

	Vector2 GenerateRandomPos(const std::deque<Vector2>& snakeBody);
};

