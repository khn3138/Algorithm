//2022-08-15
#include <iostream>

using namespace std;

int n;

char arr[100][100];
char arr2[100][100];

int cnt1;
int cnt2;//»ö¾à

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void f(int x, int y, char c, int type) {
	char tempc = type ? arr[y][x] : arr2[y][x];
	if (tempc != c)
		return;

	if (type)
		arr[y][x] = 0;
	else
		arr2[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int mx = x + dx[i];
		int my = y + dy[i];
		if (mx >= 0 && my >= 0 && mx < n && my < n) {
			f(mx, my, tempc, type);
		}
	}
}

int main() {
	scanf("%d\n", &n);
	char c[100];
	for (int i = 0; i < n; i++) {
		scanf("%s\n", &c);
		for (int j = 0; j < n; j++) {
			arr[i][j] = c[j];
			arr2[i][j] = c[j] == 'G' ? 'R' : c[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) {
				cnt1++;
				f(j, i, arr[i][j], 1);
			}
			if (arr2[i][j] != 0) {
				cnt2++;
				f(j, i, arr2[i][j], 0);
			}
		}
	}

	printf("%d ", cnt1);
	printf("%d", cnt2);

	return 0;
}