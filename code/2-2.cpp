#include <iostream>
#define BLACK 'B'
#define WHITE 'W'
#define CONTINUE 'C'
#define WIN 'W'

using namespace std;

char check(int x, int y, char color, char** graph) {
    int ptr_x = x;
    int ptr_y = y;
    int cnt = 0;

    while (graph[ptr_x][ptr_y] == color) {
        cnt++;
        ptr_x--;
    }

    ptr_x = x;

    while (graph[ptr_x][ptr_y] == color) {
        cnt++;
        ptr_x++;
    }

    if (cnt == 6)
        return WIN;
    cnt = 0;
    ptr_x = x;

    while (graph[ptr_x][ptr_y] == color) {
        cnt++;
        ptr_y--;
    }

    ptr_y = y;

    while (graph[ptr_x][ptr_y] == color) {
        cnt++;
        ptr_y++;
    }

    if (cnt == 6)
        return WIN;
    cnt = 0;
    ptr_y = y;

    while (graph[ptr_x][ptr_y] == color) {
        cnt++;
        ptr_x--;
        ptr_y--;
    }

    ptr_x = x;
    ptr_y = y;

    while (graph[ptr_x][ptr_y] == color) {
        cnt++;
        ptr_x++;
        ptr_y++;
    }

    if (cnt == 6)
        return WIN;
    cnt = 0;
    ptr_y = y;
    ptr_x = x;

    while (graph[ptr_x][ptr_y] == color) {
        cnt++;
        ptr_x++;
        ptr_y--;
    }
    ptr_x = x;
    ptr_y = y;

    while (graph[ptr_x][ptr_y] == color) {
        cnt++;
        ptr_x--;
        ptr_y++;
    }

    if (cnt == 6)
        return WIN;
    return CONTINUE;
}

int main() {
    char** graph;
    int cmd, x, y, end;
    char color, result, win_col;
    cin >> cmd;

    while (cmd--) {
        graph = new char* [18];
        for (int i = 0; i < 18; i++) {
            graph[i] = new char[18];
        }
        end = 0;
        win_col = BLACK;

        result = CONTINUE;
        for (int i = 0; i < 225; i++) {
            if (result == CONTINUE) {
                cin >> x >> y;
                if (i % 2 == 0)
                    color = BLACK;
                else
                    color = WHITE;

                graph[x][y] = color;

                result = check(x, y, color, graph);
                if (result == WIN) {
                    win_col = color;
                    end = i + 1;
                }
            }
            else
                cin >> x >> y;
        }
        cout << end << ' ' << win_col << endl;
    }
    return 0;
}