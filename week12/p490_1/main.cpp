#include "MonsterWorld.h"
#include <ctime>

int main() {
	srand(time(NULL));
	int w = 16, h = 10;
	MonsterWorld game(w, h);

	game.add(new Monster("Zombie", "Z ", rand() % w, rand() % h));
	game.add(new Monster("Ghost", "G ", rand() % w, rand() % h));
	game.add(new Tuman("LeftPlayer", "L ", 0, 1));
	game.add(new Tuman("RightPlayer", "R ", w-1, h-2));

	game.play(500, 150);
	return 0;
}
