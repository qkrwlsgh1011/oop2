#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int backpack(vector <int> _weight, vector <int> _worth, int n, int _weight_limit) {
	int result;
	int** DP;
	DP = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		DP[i] = new int[_weight_limit + 1];
	}

	for (int i = 0; i <= n; i++) {
		DP[i][0] = 0;
	}
	for (int i = 0; i <= _weight_limit; i++) {
		DP[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= _weight_limit; j++) {
			if (_weight[i - 1] > j) {
				DP[i][j] = DP[i - 1][j];
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - _weight[i - 1]] + _worth[i - 1]);
			}
		}
	}
	result = DP[n][_weight_limit];
	for (int i = 0; i < n + 1; i++) {
		delete[] DP[i];
	}
	delete[] DP;
	return result;
	return result;
}

int main() {
	int much;
	int many, weight_limit;
	cin >> much;
	while (much--) {
		cin >> many >> weight_limit;
		int many_copy = many;
		int inte;
		vector <int> weight;
		vector <int> worth;
		while (many--) {
			cin >> inte;
			weight.push_back(inte);
		}
		many = many_copy;
		while (many_copy--) {
			cin >> inte;
			worth.push_back(inte);
		}
		cout << backpack(weight, worth, many, weight_limit) << endl;
	}

}