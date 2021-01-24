#include <iostream>
#include <vector>
#define DEVIDING_STANDARD 2

using namespace std;

int N;
vector<vector<int>> paper;
// 1 is blue, 0 is white

int blue = 0;
int white = 0;

/* the condition of call recursion
 *    if the color is different with initial color
 */

void DC(int len, int x, int y) { // len 길이의 block이 들어왔고, 이제 곧 쪼갤거다. (except the case of len == 1)
	if (len == 1) { // can't devide anymore
		if (paper[y][x]) blue++;
		else white++;

		return;
	}

	int div = len / 2;
	int initial_color = paper[y][x];
	int yVal = y, xVal = x;

	for (int j = yVal; j < yVal + len; j++) {
		for (int i = xVal; i < xVal + len; i++) {
			if (paper[j][i] != initial_color) goto devide; // 쪼개야 하므로 쪼개는 for문으로 gogo!
			if (j == yVal + len - 1 && i == xVal + len - 1) { // 현재 block에 color가 다 똑같을 경우
				if (initial_color) blue++;
				else white++;

				return;
			}
		}
	}
	
	devide:

	for (int j = 0; j < DEVIDING_STANDARD; j++) { // 쪼개는 for문
		for (int i = 0; i < DEVIDING_STANDARD; i++) {
			DC(div, x + div * i, y + div * j); // devide it
		}
	}
}

/* default devide and conquer 는 1 조각까지 쪼개버리지만
 * 이 문제에서는 쪼개지 않는 조건이 필요.
 *    -> 한 block 이 same color 일때.
 */

int main() {
	cin >> N;
	paper.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	DC(N, 0, 0);

	cout << white << '\n' << blue;
}