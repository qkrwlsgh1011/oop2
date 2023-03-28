#include <iostream>
#include <vector>
using namespace std;

double clcMedian(int* arr, int B) {
	int med_count = 0;
	double median = 0;
	if (B % 2 != 0) {
		for (int j = 0; j < 201; j++) {
			med_count = med_count + arr[j];
			if (med_count > B / 2) {
				median = j;
				break;
			}
		}
	}
	else {
		int fC = 0;
		int sC = 0;
		for (int i = 0; i < 201; i++) {
			med_count = med_count + arr[i];
			if (med_count >= B / 2 && fC == 0) {
				fC = i;
			}
			if (med_count >= B / 2 + 1 && sC == 0) {
				sC = i;
				median = (fC + sC) / 2.0;
				break;
			}
		}
	}
	return median;
}

int main() {
	int much;
	cin >> much;
	int temp;
	while (much--) {
		vector <int> v;
		int count_Arr[201] = {0};
		int A, B;
		cin >> A >> B;

		for (int i = 0; i < A; i++) {
			cin >> temp;
			v.push_back(temp);
		}
		int count = 0;
		for (int i = 0; i < B; i++) {
			count_Arr[v[i]] = count_Arr[v[i]] + 1;
		}
		for (int i = B; i < A; i++) {
			double median = clcMedian(count_Arr, B);
			if (median * 2 <= v[i]) {
				count++;
			}
			count_Arr[v[i - B]] = count_Arr[v[i - B]] - 1;
			count_Arr[v[i]] = count_Arr[v[i]] + 1;
		}
		cout << count << endl;
	}
}