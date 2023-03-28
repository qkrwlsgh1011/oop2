#include <iostream>
#include <vector>
using namespace std;

int main() {
	int much;
	int A, B;
	int test, turn;
	int point_arr;
	cin >> much;
	while (much--) {
		vector <int> point;
		point.push_back(0);
		vector <int> test_arr;
		vector <int> turn_arr;
		cin >> A >> B;
		int copy_A = A;
		while (copy_A--) {
			cin >> point_arr;
			point.push_back(point_arr);
		}
		int copy2_A = A;
		while (copy2_A--) {
			cin >> test >> turn;
			test_arr.push_back(test);
			turn_arr.push_back(turn);
		}
		for (int i = 0; i < A - 1; i++) {
			for (int j = i + 1; j < A; j++) {
				if (turn_arr[i] > turn_arr[j]) {
					swap(turn_arr[i], turn_arr[j]);
					swap(test_arr[i], test_arr[j]);
				}
			}
		}											//정렬순으로 만들기.
		int total = 0;
		for (int idx = 0; idx < A - 1; idx) {
			int count = 1;
			for (int i = idx; i < A - 1; i++) {
				if (test_arr[i] > test_arr[i + 1]) {
					if (i==A - 2) {
						total = total + point[1];
					}
					idx = i + 1;
					break;
				}
				idx = i + 1;
				count++;
			}
			total = total + point[count];
		}
		cout << total << endl;
	}
	return 0;
}