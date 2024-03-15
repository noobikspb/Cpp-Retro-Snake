#include "Snake.h"

Vector2 Vector2Add(const Vector2 first, const Vector2 second) {
	return Vector2{ first.x + second.x,first.y + second.y };
}

void Snake::Draw()
{
	for (size_t i = 0; i < body.size(); ++i) {
		int x = body[i].x;
		int y = body[i].y;
		Rectangle segment = Rectangle{ static_cast<float>(x) * cellSize + offset,static_cast<float>(y) * cellSize + offset,static_cast<float>(cellSize),static_cast<float>(cellSize) };
		DrawRectangleRounded(segment, 0.5, 6, darkGreen);
	}
}

void Snake::Update()
{
	body.push_front(Vector2Add(body[0], direction));
	if (addSegment == true) {
		addSegment = false;
	}
	else {
		body.pop_back();
	}
}

void Snake::Reset()
{
	body = { Vector2{6,9},Vector2{5,9},Vector2{4,9} };
	direction = { 0,0 };
}
