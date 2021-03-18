#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
bool isPrime(int num) {
	if (num == 0 || num == 1) {
		return false;
	}
	for (int i = 2; i < sqrt(num); ++i) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}
int main() {
	string input;
	int L, K;
	while(cin >> L >> K) {
		cin >> input;
		if (L < K) {
			cout << "404" << endl;
			continue;
		}

		int curNum = 0;
		string ans;
		for (int i = 0; i < K; ++i) {
			curNum *= 10;
			curNum += input[i] - '0';
			ans += input[i];
		}

		int baseMod = pow(10, K - 1);
		int curIndex = K;
		while(curIndex < L && !isPrime(curNum)) {
			ans.erase(ans.begin());
			ans.push_back(input[curIndex]);

			curNum = curNum % baseMod;
			curNum = curNum * 10;
			curNum = curNum + input[curIndex] - '0';
			curIndex++;
		}

		ans = isPrime(curNum) ? ans : "404";
		cout << ans << endl;
	}
	return 0;
}