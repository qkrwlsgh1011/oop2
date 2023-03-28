#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int much;
    cin >> much;
    while (much--) {
        string A, B;
        int LCS[1001][1001];
        string tmpA, tmpB;
        cin >> tmpA >> tmpB;
        A = '0' + tmpA;
        B = '0' + tmpB;

        int length_A = A.size();
        int length_B = B.size();

        for (int i = 0; i < length_A; i++) {
            for (int j = 0; j < length_B; j++) {
                if (i == 0 || j == 0) {
                    LCS[i][j] = 0;
                    continue;
                }
                if (A[i] == B[j]) {
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                }
                else {
                    if ((LCS[i - 1][j] > LCS[i][j - 1])) {
                        LCS[i][j] = LCS[i - 1][j];
                    }
                    else {
                        LCS[i][j] = LCS[i][j - 1];
                    }
                }
            }
        }
        cout << LCS[length_A - 1][length_B - 1] << endl;
    }
    return 0;
}