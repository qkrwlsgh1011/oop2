#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int much;
	cin >> much;
	while (much--) {
		string A;
		int B;
		cin >> A >> B;
		int C = (A[0]-'0') % B;
		int size_A = A.size();				//나눌 수 A의 크기. 자릿수.

		for (int i = 1; i < size_A; i++) {
			C = (10 * C + (A[i] - '0')) % B;
		}
		if (C == 0) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
		
	}
}