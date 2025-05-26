#ifndef HUMAN_H
#define HUMAN_H

#include "Monster.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>

enum Direction { LEFT = 68, RIGHT = 67, UP = 65, DOWN = 66 };

class Human : public Monster {
public:
	Human(string n = "Human", string i = "H ", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() {}
};

class Tuman : public Human {
public:
	Tuman(string n = "Tuman", string i = "T ", int px = 0, int py = 0)
		: Human(n, i, px, py) {}
	~Tuman() {}

	void move(int** map, int maxx, int maxy) override {}

	void moveHuman(int** map, int maxx, int maxy, unsigned char ch) {
		if (ch == LEFT || ch == 'a') x--;
		else if (ch == RIGHT || ch == 'd') x++;
		else if (ch == UP || ch == 'w') y--;
		else if (ch == DOWN || ch == 's') y++;
		else return;

		clip(maxx, maxy);
		eat(map);
	}
};

#endif
