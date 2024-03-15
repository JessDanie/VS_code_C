#include <stdio.h>
#include<stdbool.h>

int mapx[205][205];
bool v[205];
int c[205];
int n;

int dfs(int x)
{
	for (int i = 1; i <= n; i++)
	{
		if (!v[i] && mapx[x][i])
		{
			v[i] = 1;
			if (!c[i] || dfs(c[i]))
			{
				c[i] = x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int t;
    scanf("%d", &t);

	while (t--)//多组输入
	{
		scanf("%d", &n);

		memset(c, 0, sizeof (c));

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
                scanf("%d", mapx[i] + j);
			}
		}

		long long k = 0;
		for (int i = 1; i <= n; i++)
		{
			memset(v, 0, sizeof (v));
			if(dfs(i)) k++;
		}
		if (k == n) puts("Yes");
		else pits("No");
	}
}
