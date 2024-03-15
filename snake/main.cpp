#include <iostream>
#include <raylib.h>
#include <deque>
#include "Game.h"

Color green = { 173,204,96,255 };
Color darkGreen = { 43,51,24,255 };

int cellSize = 30;
int cellCount = 25;
int offset = 75;

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

void WhatKeyPressed(Game& game) {
	if (EventTriggered(0.2)) {
		game.Update();
	}

	if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && game.snake.direction.y != 1) {
		game.snake.direction = { 0,-1 };
		game.runnig = true;
	}
	if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && game.snake.direction.y != -1) {
		game.snake.direction = { 0,1 };
		game.runnig = true;
	}
	if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && game.snake.direction.x != 1) {
		game.snake.direction = { -1,0 };
		game.runnig = true;
	}
	if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) && game.snake.direction.x != -1) {
		game.snake.direction = { 1,0 };
		game.runnig = true;
	}
}

void Drawing(Game& game) {
	ClearBackground(green);
	DrawRectangleLinesEx(Rectangle{ static_cast<float>(offset) - 5,static_cast<float>(offset) - 5,static_cast<float>(cellSize) * cellCount + 10,static_cast<float>(cellSize) * cellCount + 10 }, 5, darkGreen);
	DrawText("Retro Snake", offset - 5, 20, 40, darkGreen);
	DrawText(TextFormat("%i", game.score), offset - 5, offset + cellSize * cellCount + 10, 40, darkGreen);
	game.Draw();
}

int main() {
	InitWindow(2*offset + cellSize * cellCount, 2*offset + cellSize * cellCount, "Retro Snake");
	SetTargetFPS(144);

	Game game = Game();

	while (!WindowShouldClose()) {
		BeginDrawing();

		WhatKeyPressed(game);

		Drawing(game);

		EndDrawing();
	}


	CloseWindow();
	return 0;
}