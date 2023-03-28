#include <iostream>
#include <string>
using namespace std;


bool Is_search(string A) {
	for (int i = 0; i < A.length(); i++) {
		if (A[i] != A[A.length() - i - 1])
			return false;
	}
	return true;
}

int main() {
	int much;
	cin >> much;
	while (much--) {
		string word;
		cin >> word;
		for (int i = 0; i < word.length(); i++) {
			if (word[i] >= 'a' && word[i] <= 'z') {
				word[i] = word[i] - 32;
			}										//소문자 대문자로 변환
			else if (word[i] >= 'A' && word[i] <= 'Z') {
			}										//대문자
			else {
				if (i == word.length() - 1) {
					word.pop_back();
				}
				else {
					for (int j = i; j < word.length() - 1; j++) {
						word[j] = word[j + 1];
					}
					word.pop_back();
					i--;
				}
			}										//기호가 나오면 배열에서 없앰.
		}
		if (Is_search(word) == 1) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}