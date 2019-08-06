#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, input;
int Size;
char ord[6];

typedef struct _Queue {
	int data;
	_Queue* next;
}Queue;

typedef struct {
	Queue* Front;
	Queue* Back;
}Qp;

void QPush(Qp* ptr, int Data) {
	Queue* mnode = (Queue*)malloc(sizeof(Queue));
	Size++;
	mnode->data = Data;
	mnode->next = NULL;

	if (ptr->Front == NULL && ptr->Back == NULL) {
		ptr->Front = mnode;
		ptr->Back = mnode;
	}
	else {
		ptr->Back->next = mnode;
		ptr->Back = ptr->Back->next;
	}
}

int QPop(Qp* ptr) {
	if (ptr->Front==NULL)
		return -1;

	else {
		Queue* del = ptr->Front;
		int tmp = ptr->Front->data;
		ptr->Front = ptr->Front->next;
		free(del);

		if (ptr->Front==NULL) 
			ptr->Back = NULL;
		
		Size--;
		return tmp;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	Qp* ptr = (Qp*)malloc(sizeof(Qp));
	ptr->Front	= NULL;
	ptr->Back	= NULL;
	
	cin >> n;
	while (n--) {
		
		cin >> ord;
		
		if (strcmp(ord, "push") == 0) {
			cin >> input;
			QPush(ptr, input);
		}


		else if (strcmp(ord, "pop") == 0)
			cout << QPop(ptr) << '\n';


		else if (strcmp(ord, "front") == 0) {
			if (ptr->Front == NULL)
				cout << "-1" << "\n";
			else
				cout << ptr->Front->data << "\n";
		}


		else if (strcmp(ord, "back") == 0) {
			if (ptr->Back == NULL)
				cout << "-1" << "\n";
			else
				cout << ptr->Back->data << "\n";
		}

		else if (strcmp(ord, "size") == 0) 
			cout << Size << '\n';
		
		else if (strcmp(ord, "empty") == 0) {
			if (Size == 0)
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}
	}
	return 0;
}