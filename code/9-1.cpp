#include <iostream>
#include <vector>
using namespace std;

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
		vector <int> worth_per_1weight;
		while (many--) {
			cin >> inte;
			weight.push_back(inte);
		}
		many = many_copy;
		while (many_copy--) {
			cin >> inte;
			worth.push_back(inte);
		}
		for (int i = 0; i < many; i++) {
			int per_worth = 0;
			per_worth = worth[i] / weight[i];
			worth_per_1weight.push_back(per_worth);
		}
		int max = 0;
		for (int i = 0; i < many; i++) {
			for (int j = 0; j < many - (i + 1); j++) {
				if (worth_per_1weight[j] < worth_per_1weight[j + 1]) {
					swap(worth_per_1weight[j], worth_per_1weight[j + 1]);
					swap(weight[j], weight[j + 1]);
					swap(worth[j], worth[j + 1]);
				}
			}
		}
		int sum = 0;
		int result = 0;
		for (int i = 0; i <= weight_limit; i) {
			if (sum + weight[i] <= weight_limit) {
				sum += weight[i];
				result += worth[i];
			}
			else {
				result = result + worth_per_1weight[i] * (weight_limit - sum);
				break;
			}
			i++;
		}
		cout << result << endl;
	}
}
