#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<char>> map;

void solve(int n, int x, int y) {
	if (n == 1) {
		map[x][y] = '*';
		return;
	} // cout 되는것이 아닌 map 에 입력을 하는 것.

	int div = n / 3;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1) continue;
			solve(div, x + div * i, y + div * j);
		}
	}
	return;
}
 
/*
 * 27 0 0
 * div = 9
 * i = 0 j = 0
 *    9 0 0
 *    div = 3
 *    i = 0 j = 1
 *       3 0 0
 *       div = 1
 *          i = 0 j = 0
 */

int main() {
	int num;
	cin >> num;

	map.assign(num, vector<char>(num, ' '));

	solve(num, 0, 0);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) cout << map[i][j];
		cout << '\n';
	}
}