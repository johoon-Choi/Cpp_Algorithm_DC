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

void DC(int len, int x, int y) { // len ������ block�� ���԰�, ���� �� �ɰ��Ŵ�. (except the case of len == 1)
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
			if (paper[j][i] != initial_color) goto devide; // �ɰ��� �ϹǷ� �ɰ��� for������ gogo!
			if (j == yVal + len - 1 && i == xVal + len - 1) { // ���� block�� color�� �� �Ȱ��� ���
				if (initial_color) blue++;
				else white++;

				return;
			}
		}
	}
	
	devide:

	for (int j = 0; j < DEVIDING_STANDARD; j++) { // �ɰ��� for��
		for (int i = 0; i < DEVIDING_STANDARD; i++) {
			DC(div, x + div * i, y + div * j); // devide it
		}
	}
}

/* default devide and conquer �� 1 �������� �ɰ���������
 * �� ���������� �ɰ��� �ʴ� ������ �ʿ�.
 *    -> �� block �� same color �϶�.
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