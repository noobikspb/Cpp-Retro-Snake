#pragma once
#include <raylib.h>
#include <deque>

extern Color darkGreen;

extern int offset;
extern int cellSize;

Vector2 Vector2Add(const Vector2 first, const Vector2 second);

class Snake
{
public:
	std::deque<Vector2> body = { Vector2{6,9},Vector2{5,9},Vector2{4,9} };
	Vector2 direction = { 0,0 };
	bool addSegment = false;

	void Draw();

	void Update();

	void Reset();
};

