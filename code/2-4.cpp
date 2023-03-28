#include <iostream>
#include <vector>
using namespace std;

class item {
public:
    int s;
    int e;
    string str;

    item(string str, int s, int e) : s(s), e(e), str(str) {}
};

void bubble_sort(vector<item*>& arr) {
    int n = arr.size();
    item* save;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j]->e > arr[j + 1]->e) {
                save = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = save;
            }
        }
    }
}

int main() {
    int cmd;
    cin >> cmd;
    int n, s, e, count;
    string str;
    vector<item*> v;

    while (cmd--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> str >> s >> e;
            item* tmp = new item(str, s, e);
            v.push_back(tmp);
        }
        bubble_sort(v);
        count = 1;
        e = v[0]->e;
        for (int i = 1; i < n; i++) {
            if (v[i]->s >= e) {
                count++;
                e = v[i]->e;
            }
        }

        cout << count << endl;
        vector<item*>().swap(v);
    }
    return 0;
}