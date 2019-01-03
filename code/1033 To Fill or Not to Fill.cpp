#include <iostream>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <float.h>
using namespace std;
class Gas
{
public:
	double price;
	double distance;
	bool operator < (const Gas &A) const
	{
		if (distance == A.distance)
		{
			return price < A.price;
		}
		return distance < A.distance;
	}
}stations[501];
int main()
{
	double cap, distance, Davg;
	int n;
	double maxlen;
	cin >> cap >> distance >> Davg >> n;
	maxlen = Davg * cap;
	double curdis = 0;  //当前已走距离
	double leftoil = 0;	//剩余油量
	double curmax = 0;	//此站加满情况下能走最远距离
	double cost = 0;   //消费
	int index = 0;  //当前所处加油站
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		cin >> stations[i].price >> stations[i].distance;
		if (stations[i].distance == 0)
		{
			flag = true;
		}
	}
	stations[n].distance = distance;
	stations[n].price = 0;
	if (flag)
	{
		sort(stations, stations + n);
		double curprice = stations[0].price;
		while (curdis < distance)
		{
			curmax = curdis + maxlen;
			bool find = false;
			double minprice = DBL_MAX;
			//cout << curdis << " " << index <<" "<<curprice<<" "<<cost<< endl;
			for (int i = index; i <= n; i++)
			{
				if (stations[i].distance > curmax)
				{
					break;
				}
				if (stations[i].distance == curdis)
				{
					continue;
				}
				if(stations[i].price < curprice)
				{
					index = i;
					find = true;
					cost += ((stations[i].distance - curdis) / Davg - leftoil) * curprice;
					leftoil = 0;
					curprice = stations[i].price;
					curdis = stations[i].distance;
					break;
				}
				if (stations[i].price < minprice)
				{
					minprice = stations[i].price;
					index = i;
				}
			}
			if (!find)
			{
				if (minprice == DBL_MAX)
				{
					curdis = curmax;
					flag = false;
					break;
				}
				else
				{
					cost += curprice * (cap - leftoil);
					leftoil = cap - (stations[index].distance - curdis) / Davg;
					curdis = stations[index].distance;
					curprice = stations[index].price;
				}
			}
		}

	}
	if (!flag)
	{
		cout << fixed << setprecision(2) << "The maximum travel distance = " << curdis << endl;
	}
	else
	{
		cout << fixed << setprecision(2) << cost << endl;
	}
	system("pause");
	return 0;
}