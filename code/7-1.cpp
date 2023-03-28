#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pow(int A, int B) {
	int temp = 1;
	if (B == 0) {
		return 1;
	}
	else if (B == 1) {
		return A;
	}
	else {
		while(B--) {
			temp = temp * A;
		}
		return temp;
	}
}

int solve(vector <int> v, int X) {
	int answer = 0;
	for (int i = 0; i < v.size(); i++) {
		int tmp = pow(X,i) % 1013;
		answer += (v[i] * tmp) % 1013;
	}

	return answer % 1013;
}

int main() {
	int much;
	int N;
	int temp; 
	int start;
	int end;
	int X;
	cin >> much;
	while (much--) {
		cin >> N;
		vector <int> v;
		vector <int> vec;
		vector <int> answer;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			v.push_back(temp);
		}
		cin >> start >> end >> X;
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			for (int j = i+1; j < v.size(); j++) {
				if (v[i] > v[j]) {
					swap(v[i], v[j]);
				}
			}
		}

		answer.push_back(solve(v, X));
		while (true) {
			if (next_permutation(v.begin(), v.end()) == false) {
				break;
			}
			answer.push_back(solve(v, X));
		}
		for (int i = 0; i < answer.size(); i++) {
			if (start <= answer[i] && answer[i] <= end) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}