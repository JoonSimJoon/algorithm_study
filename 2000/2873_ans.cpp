#include<iostream>
#include<algorithm>
#include<string>

const int MAX = 1000;
const int INF = 987654321;

using namespace std;

int arr[MAX][MAX];
string str = "";


typedef struct {
	int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
char moveChar[4] = { 'D', 'U', 'R', 'L' };

bool visited[MAX][MAX];
bool flag = false;

/*
void BruteForce(int y, int x, int py, int px, int cnt, string s) {
	if (cnt == (R * C) - 1 && y == R - 1 && x == C - 1) {
		cout << s << "\n";
		flag = true;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;
		if (nextY >= 0 && nextY < R && nextX >= 0 && nextX < C) {
			if (!visited[nextY][nextX]) {
				if (nextY == py && nextX == px) {
					continue;
				}
				else {
					visited[nextY][nextX] = true;
					BruteForce(nextY, nextX, py, px, cnt + 1, s + moveChar[i]);
					visited[nextY][nextX] = false;
				}
			}
		}
		if (flag)
			break;
	}
	return;
}
*/

void append(string& str, char c, int end) {
	for (int i = 0; i < end; i++)
		str += c;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int R, C;

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];

	if (R % 2 == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C - 1; j++) {
				if (i % 2 == 0)
					str += 'R';
				else
					str += 'L';
			}
			if (i != R - 1)
				str += 'D';
		}

		cout << str << "\n";
	}
	else if (C % 2 == 1) {
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < R - 1; j++) {
				if (i % 2 == 0)
					str += 'D';
				else
					str += 'U';
			}
			if (i != C - 1)
				str += 'R';
		}

		cout << str << "\n";
	}
	else {
		int pointY = 0, pointX = 0;
		int temp = INF;
		string revAns = "";
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if ((i + j) % 2 == 1 && arr[i][j] < temp) {
					temp = arr[i][j];
					pointY = i, pointX = j;
				}
			}
		}

		int startR = 0, startC = 0, endR = R - 1, endC = C - 1;
		while (endR - startR > 1) {
			if (startR + 1 < pointY) {
				append(str, 'R', C - 1);
				append(str, 'D', 1);
				append(str, 'L', C - 1);
				append(str, 'D', 1);
				startR += 2;
			}
			if (endR - 1 > pointY) {
				append(revAns, 'R', C - 1);
				append(revAns, 'D', 1);
				append(revAns, 'L', C - 1);
				append(revAns, 'D', 1);
				endR -= 2;
			}
		}

		while (endC - startC > 1) {
			if (startC + 1 < pointX) {
				append(str, 'D', 1);
				append(str, 'R', 1);
				append(str, 'U', 1);
				append(str, 'R', 1);
				startC += 2;
			}
			if (endC - 1 > pointX) {
				append(revAns, 'D', 1);
				append(revAns, 'R', 1);
				append(revAns, 'U', 1);
				append(revAns, 'R', 1);
				endC -= 2;
			}
		}
		if (pointY == startR + 1) {
			append(str, 'R', 1);
			append(str, 'D', 1);
		}
		else if (pointY == endR - 1) {
			append(str, 'D', 1);
			append(str, 'R', 1);
		}
		reverse(revAns.begin(), revAns.end());
		str += revAns;
	
		cout << str << "\n";
	}

	return 0;
}