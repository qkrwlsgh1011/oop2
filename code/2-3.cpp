#include <iostream>
#include <string>
using namespace std;

int find_min_string(string s, string r) {
    int win_arr[128] = { 0 };
    int r_arr[128] = { 0 };
    int count = 0;
    int start = 0;
    int end = 0;
    int win_len = 0;
    int min_len = s.length() + 1;
    int s_len = s.length();
    int r_len = r.length();

    for (int i = 0; i < r.length(); i++) {
        r_arr[r[i]]++;
    }

    while (end <= s_len) {
        win_arr[s[end]]++;

        if (win_arr[s[end]] <= r_arr[s[end]])
            count++;

        while (count == r_len) {
            win_len = end - start + 1;

            if (win_len < min_len)
                min_len = win_len;

            if (win_arr[s[start]] <= r_arr[s[start]])
                count--;
            win_arr[s[start]]--;

            start++;
        }

        end++;
    }

    if (min_len > s_len)
        return 0;
    return min_len;
}

int main() {
    int cmd;
    cin >> cmd;
    string r, s;

    while (cmd--) {
        cin >> s;
        cin >> r;

        cout << find_min_string(s, r) << endl;
    }
    return 0;
}