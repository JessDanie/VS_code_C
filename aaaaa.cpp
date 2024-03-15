#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
};
int min(int a, int b)
{
	if (a > b)
		return b;
	return a;
};
int main()
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		int a[100][100] = { 0 };
		int b[100][100] = { 0 };
		int flog = -1;
		int i, j;
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= m; ++j) {
				cin >> a[i][j];
				if (a[i][j] == 1)
				{
					b[i][j] = min(min(b[i][j - 1], b[i - 1][j]), b[i - 1][j - 1]) + 1;
				}
				flog = max(flog, b[i][j]);
			}
		cout << flog * flog << endl;
	}
	return 0;
}
