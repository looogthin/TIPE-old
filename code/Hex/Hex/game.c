#include "game.h"
#include <stdlib.h>
#include <stdio.h>

Player* initPlayer(Game *game, Player* p) {
	p = malloc(sizeof(Player));
	if (p == NULL)
		return NULL;
	p->nb = 0;
	p->pawn = malloc(game->nbCases * game->nbCases * sizeof(int));
	p->rects = malloc(game->nbCases * game->nbCases * sizeof(SDL_Rect) / 2);
	return p;
}

void addPawn(Player* p, int x, int y, SDL_Rect rect) {
	p->pawn[p->nb * 2] = x;
	p->pawn[p->nb * 2 + 1] = y;
	p->rects[p->nb] = rect;
	p->nb++;
}

bool areInContact(int x1, int y1, int x2, int y2) {
	if ((x1 == x2 && y1 - 1 == y2) ||
		(x1 == x2 && y1 + 1 == y2) ||
		(x1 - 1 == x2 && y1 == y2) ||
		(x1 + 1 == x2 && y1 == y2) ||
		(x1 + 1 == x2 && y1 - 1 == y2) ||
		(x1 - 1 == x2 && y1 + 1 == y2))
		return true;
	return false;
}

bool containsPawn(Player* p, int x, int y) {
	for (unsigned int i = 0; i < p->nb * 2; i += 2)
		if (p->pawn[i] == x && p->pawn[i + 1] == y)
			return true;
	return false;
}

int play(Game *game, int x, int y, SDL_Rect rect) {
	Player* p1 = game->isTurnRed ? game->red : game->blue;
	Player* p2 = game->isTurnRed ? game->blue : game->red;
	if (!containsPawn(p1, x, y) && !containsPawn(p2, x, y))
		addPawn(p1, x, y, rect);
	else
		return -1;
	return 0;
}

bool isWinner(Game* game, Player* player) {
	
	return false;
}