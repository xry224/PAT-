#pragma warning(disable:4996)
#include <stdio.h>
int main()
{
	int s1, k1, g1, s2, k2, g2;
	scanf("%d.%d.%d", &g1, &s1, &k1);
	scanf("%d.%d.%d", &g2, &s2, &k2);
	int s, k, g;
	k = k1 + k2;
	s = s1 + s2;
	g = g1 + g2;
	if (k >= 29)
	{
		s++;
		k -= 29;
	}
	if (s >= 17)
	{
		g++;
		s -= 17;
	}
	printf("%d.%d.%d", g, s, k);
	return 0;
}