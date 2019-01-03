#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int numbers[100005];
void quickSort(int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = numbers[left];
	int first = left;
	int second = right;
	while (first < second)
	{
		while (first < second && numbers[second] >= key)
		{
			second--;
		}
		numbers[first] = numbers[second];
		while (first < second && numbers[first] <= key)
		{
			first++;
		}
		numbers[second] = numbers[first];
	}
	numbers[first] = key;
	quickSort(left, first - 1);
	quickSort(first + 1, right);
}
int main()
{

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
//	quickSort(0, n - 1);
	sort(numbers, numbers + n);
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
		{
			sum1 += numbers[i];
		}
		else
		{
			sum2 += numbers[i];
		}
	}
	cout << n % 2 << " " << sum2 - sum1 << endl;
	system("pause");
	return 0;
}