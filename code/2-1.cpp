#include <iostream>
#include <vector>
#include <string>
using namespace std;

int hamming_distance(string str, string substr) {
    int hd = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != substr[i])
            hd++;
    }

    return hd;
}

int find_min_hd(vector<string> v, string substr) {
    int hd = 0;
    int min = substr.length() + 1;
    int idx = 0;
    for (int i = 0; i < v.size(); i++) {
        hd = hamming_distance(v[i], substr);

        if (hd < min) {
            min = hd;
            idx = i;
        }
    }
    return idx;
}

int main() {
    int cmd, l, m, n;
    vector<string> v;
    string str, substr;
    cin >> cmd;

    while (cmd--) {
        cin >> m >> n;

        for (int i = 0; i < m; i++) {
            cin >> str;
            v.push_back(str);
        }

        cin >> l >> str;


        for (int i = 0; i < (l / n); i++) {
            printf("%c", find_min_hd(v, str.substr(i * n, n)) + 65);
        }
        cout << endl;
        vector<string>().swap(v);
    }
    return 0;
}