#include "gep.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool init = false;
int point = 0, x = 0, y = 0;
char nextStep;
vector<vector<int>> table;

void message(int, string msg) {
	cout << msg << endl;
	exit(0);
}

int Mezo(int i, int j) {
	if (!init) {
		message(0, "hiba, a j�t�kot a Kezd m?velettel kell kezdeni");
	}
	if (i < 0 || i >= table.size() || j < 0 || j >= table.size()) {
		message(0, "hiba, �rv�nytelen param�ter Mezo-ben");
	}
	return table[i][j];
}

void Lep(char c) {
	if (!init) {
		message(0, "hiba, a j�t�kot a Kezd m?velettel kell kezdeni");
	}
	if (c != 'L' && c != 'J') {
		message(0, "hiba, �rv�nytelen param�ter Lep-ben");
	}
	if (c == 'L') {
		if (++x == table.size()) {
			message(0, "hiba, �rv�nytelen param�ter Lep-ben");
		}
	}
	else {
		if (++y == table.size()) {
			message(0, "hiba, �rv�nytelen param�ter Lep-ben");
		}
	}
	point += table[x][y];
	if (x == table.size() - 1) {
		nextStep = 'J';
		++y;
	}
	else {
		nextStep = 'L';
		++x;
	}
	if (x == table.size() - 1 && y == table.size() - 1) {
		message(1, "helyes");
	}
}

char GepLep() {
	if (!init) {
		message(0, "hiba, a j�t�kot a Kezd m?velettel kell kezdeni");
	}
	return nextStep;
}

int Kezd() {
	if (init) {
		message(0, "hiba, Kezd-et csak egyszer szabad h�vni");
	}

	init = true;
	int n, m;
	cin >> n >> m;
	table.resize(n, vector<int>(n, 0));
	for (int i = 0; i < m; ++i) {
		int x, y, k;
		cin >> x >> y >> k;
		table[x][y] = k;
	}
	return n;
}