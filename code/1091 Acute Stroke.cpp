#include <iostream>
#include <queue>
using namespace std;
int m, n, l, t;
int map[60][1286][128];
int ans = 0;
int total;
int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };
struct Pos
{
	int x;
	int y;
	int z;
	Pos(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};
bool valid(int nl, int nm, int nn)
{
	if (nl < l && nl >= 0 && nm < m && nm >= 0 && nn < n && nn >= 0)
	{
		return true;
	}
	return false;
}
//m, n, l
int InRange(int x, int y, int z)
{
	return x < m && x >= 0 && y < n&&y >= 0 && z < l && z >= 0;
}
void dfs(int l, int m, int n)
{
	queue<Pos> q;
	q.push(Pos(m, n, l));
	while (!q.empty())
	{
		Pos top = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];
			int nz = top.z + dz[i];
			if (valid(nz, nx, ny) && map[nz][nx][ny] == 1)
			{
				total++;
				map[nz][nx][ny] = 0;
				q.push(Pos(nx, ny, nz));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> m >> n >> l >> t;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> map[i][j][k];
			}
		}
	}
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (map[i][j][k] == 1)
				{
					total = 1;
					map[i][j][k] = 0;
					dfs(i, j, k);
					if (total >= t)
					{
						ans += total;
					}
				}
			}
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}