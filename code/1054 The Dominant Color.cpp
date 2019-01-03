#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
int main()
{
	int pixel;
	int n, m;
	int ans;
	map<int, int> image;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &pixel);
			image[pixel]++;
			if (image[pixel] > n * m / 2)
			{
				ans = pixel;
			}
		}
	}
	printf("%d\n", ans);
	system("pause");
	return 0;
}