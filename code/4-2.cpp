#include <iostream>
#include <vector>
using namespace std;
class node {
public:
	int X;
	int Y;
	int queue_a;
	node* next;

	node(int data, int A,int B) {
		this->queue_a = data;
		this->X = A;
		this->Y = B;
		this->next = NULL;
	}
};

class jangi {
public:
	node* head;
	node* tail;
	int queuesize;
	jangi() {
		this->head = NULL;
		this->tail = NULL;
		this->queuesize = 0;
	}
	
	void push(int _data, int _X,int _Y) {
		node* newnode = new node(_data, _X, _Y);
		if (head==NULL) {
			head = tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}
		queuesize++;
	}

	void pop() {
		node* temp;
		if (queuesize == 0) {
			cout << -1 << endl;
		}
		else {
			temp = head;
			head = temp->next;
		}
		queuesize--;
	}
};

int main() {
	int much;
	cin >> much;
	while (much--) {
		int dy[8] = {-1,-2,-2,-1,1,2,1,2 };
		int dx[8] = {-2, -1, 1, 2, -2,-1,2,1};
		jangi* j = new jangi();
		int L;
		int init_X, init_Y;
		int end_X, end_Y;
		cin >> L;
		cin >> init_X >> init_Y >> end_X >> end_Y;
		vector< vector<int>> vec;
		vector<int> v1;
		for (int i = 0; i < L; i++) {
			v1.push_back(-1);
		}
		for (int j = 0; j < L; j++) {
			vec.push_back(v1);
		}

		j->push(0, init_X, init_Y);
		vec[init_X][init_Y] = 0;
		while (j->queuesize != 0) {
			int next_X;
			int next_Y;
			if (j->queuesize == 1) {
				int result = j->head->queue_a;
				int X = j->head->X;
				int Y = j->head->Y;
				if (Y == end_Y && X == end_X) {
					cout << result << endl;
					break;
				}
				for (int i = 0; i < 8; i++) {
					next_X = X + dx[i];
					next_Y = Y + dy[i];
					if (next_Y >= 0 && next_X >= 0 && next_X < L && next_Y < L
						&& vec[next_X][next_Y] == -1) {
						vec[next_X][next_Y] = vec[X][Y] + 1;
						j->push(vec[next_X][next_Y], next_X, next_Y);
					}
				}
			}
			else {
				j->pop();
				int result = j->head->queue_a;
				int X = j->head->X;
				int Y = j->head->Y;
				if (Y == end_Y && X == end_X) {
					cout << result << endl;
					break;
				}
				for (int i = 0; i < 8; i++) {
					next_X = X + dx[i];
					next_Y = Y + dy[i];
					if (next_Y >= 0 && next_X >= 0 && next_X < L && next_Y < L
						&& vec[next_X][next_Y] == -1) {
						vec[next_X][next_Y] = vec[X][Y] + 1;
						j->push(vec[next_X][next_Y], next_X, next_Y);
					}
				}
			}
		}
		delete j;
	}
}