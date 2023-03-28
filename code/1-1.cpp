#include <iostream>
#include <vector>
#include <string>
using namespace std;

char change(int idx) {
    if (idx == 0)
        return 'A';
    else if (idx == 1)
        return 'C';
    else if (idx == 2)
        return 'G';
    else
        return 'T';
}

int main() {
    int cmd, m, n, d, idx, max;
    cin >> cmd;
    vector<string> v;
    string str;
    int** calc_arr;

    while (cmd--) {
        cin >> m >> n;

        for (int i = 0; i < m; i++) {
            cin >> str;
            v.push_back(str);
        }

        calc_arr = new int* [4];
        for (int i = 0; i < 4; i++) {
            calc_arr[i] = new int[n];
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                calc_arr[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 'A')
                    calc_arr[0][j]++;
                else if (v[i][j] == 'C')
                    calc_arr[1][j]++;
                else if (v[i][j] == 'G')
                    calc_arr[2][j]++;
                else if (v[i][j] == 'T')
                    calc_arr[3][j]++;
            }
        }


        d = 0;
        for (int i = 0; i < n; i++) {
            idx = -1;
            max = -1;
            for (int j = 0; j < 4; j++) {
                if (max < calc_arr[j][i]) {
                    max = calc_arr[j][i];
                    idx = j;
                }
            }
            d += (m - max);
            cout << change(idx);
        }
        cout << endl << d << endl;

        vector<string>().swap(v);

        for (int i = 0; i < 4; i++) {
            delete[] calc_arr[i];
        }
        delete[] calc_arr;
    }
    return 0;
}