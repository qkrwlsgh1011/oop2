#include <iostream>
#include <vector>
using namespace std;

int teammade(vector <int> team,int X) {
	int count = team.size() - 1;
	int teamcount = 1;
	int temp = X;
	for (int i = 0; i <= count; i++) {
		temp = team[temp];
		if (X == temp) {
			break;
		}
		else if(i != count){
			teamcount++;
		}
		else {
			teamcount = 0;
		}
	}
	return teamcount;
}

int main() {
	int much;
	cin >> much;
	int many;
	int stu_num;
	while (much--) {
		cin >> many;
		vector <int> v;
		v.push_back(0);
		while (many--) {
			cin >> stu_num;
			v.push_back(stu_num);
		}
		int size = v.size();
		int total_team = 0;
		for (int i = 1; i < size; i++) {
			if (teammade(v, i) == 0) {
				total_team++;
			}
		}
		cout << total_team << endl;
	}
}