#include <iostream>
#include <vector>
using namespace std;

int large(vector <int> v) {
	int size = v.size();
	int largest = v[0];
	for (int i = 0; i < size; i++) {
		if (largest < v[i]) {
			largest = v[i];
		}
	}
	return largest;
}

int search(vector <int> v, int X) {
	int size = v.size();
	int temp = -1;
	for (int i = 0; i < size; i++) {
		if (v[i] == X) {
			temp = i;
		}
	}
	return temp;
}

int main() {
	int much;
	int circle;
	int bulk;
	cin >> much;
	while (much--) {
		cin >> circle;
		vector <int> comp;
		while (circle--) {
			cin >> bulk;
			comp.push_back(bulk);
		}
		int count = 0;							//횟수 새기
		while (comp.size() != 0) {						//vector가 다 없어질 때까지 반복
			int largest = large(comp);
			int temp = search(comp, largest);						//최댓값이 저장되어 있는 번째 저장할 변수
			comp.erase(comp.begin() + temp);
			largest--;
			for (int j = temp; j < comp.size(); j++) {
				if (comp[j] == largest) {
					comp.erase(comp.begin() + j);
					j--;
					largest--;
				}
			}
			count++;
		}
		cout << count << endl;
	}
}