#ifndef MONSTER_WORLD_H
#define MONSTER_WORLD_H

#include "Matrix.h"
#include "Canvas.h"
#include "Human.h"
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define MAXMONS 8

class MonsterWorld {
	Matrix world;
	int xMax, yMax, nMon, nMove;
	Monster* pMon[MAXMONS];
	Canvas canvas;

	int& Map(int x, int y) { return world.elem(x, y); }

	bool isDone() {
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) == 1) return false;
		return true;
	}
	void print() {
		canvas.clear();
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y)) canvas.draw(x, y, "O ");
		for (int i = 0; i < nMon; i++)
			pMon[i]->draw(canvas);
		canvas.print("[ Monster World ]");
	}
public:
	MonsterWorld(int w, int h) : world(h,w), canvas(w,h), xMax(w), yMax(h) {
		nMon = nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				Map(x, y) = 1;
	}
	~MonsterWorld() {
		for (int i = 0; i < nMon; i++) delete pMon[i];
	}
	void add(Monster* m) {
		if (nMon < MAXMONS) pMon[nMon++] = m;
	}
	void play(int maxwalk, int wait) {
		struct termios oldt, newt;
		tcgetattr(STDIN_FILENO, &oldt);
		newt = oldt;
		newt.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(STDIN_FILENO, TCSANOW, &newt);

		print();
		getchar();

		for (int i = 0; i < maxwalk; i++) {
			for (int k = 0; k < nMon - 2; k++)
				pMon[k]->move(world.Data(), xMax, yMax);

			// 입력 처리
			int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
			fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

			int ch = getchar();
			while (ch != EOF) {
				if (ch == 27) { // 방향키
					if (getchar() == '[') {
						int key = getchar();
						((Tuman*)pMon[nMon-1])->moveHuman(world.Data(), xMax, yMax, key);
					}
				} else {
					if (ch >= 'A' && ch <= 'Z') ch += 32;
					((Tuman*)pMon[nMon-2])->moveHuman(world.Data(), xMax, yMax, ch);
				}
				ch = getchar();
			}

			fcntl(STDIN_FILENO, F_SETFL, oldf);

			nMove++;
			print();
			if (isDone()) break;
			usleep(wait * 1000);
		}

		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

		// 승패 출력
		int l = ((Tuman*)pMon[nMon-2])->getItemCount();
		int r = ((Tuman*)pMon[nMon-1])->getItemCount();
		cout << "\nGame Over!\n";
		cout << "Left Player: " << l << "   Right Player: " << r << "\n";
		if (l > r) cout << "🏆 Left Player Wins!\n";
		else if (r > l) cout << "🏆 Right Player Wins!\n";
		else cout << "🤝 It's a Draw!\n";
	}
};

#endif
