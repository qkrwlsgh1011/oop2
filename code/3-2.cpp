#include <iostream>
#define False 3
#define True 2
using namespace std;
class rou {
public:
	int Found[10001];
	rou() {
		for (int i = 0; i < 10001; i++) {
			this->Found[i] = 0;
		}
	}
};

int main() {
	int much;
	int N;
	int disc;
	int round;
	cin >> much;
	while (much--) {
		rou r;
		int round = 0;
		cin >> N;
		for (int i = 1; i <= N+1; i++) {
			r.Found[i] = False;
		}
		for (int i = 1; i <= N; i++) {
			cin >> disc;
			r.Found[disc] = True;
			if (r.Found[disc + 1] != True) {
				round++;
			}
		}
		cout << round << endl;
	}
}