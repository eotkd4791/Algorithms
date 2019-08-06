#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

char str[5];
int idx;
int cnt;

typedef struct _node {
	int data;
	_node* next;
	_node* prev;
}node;

typedef struct {
	node* head;
	node* cur;
}stk;

void Spush(stk* pstk, int ctt) {
	node* newnode = (node*)malloc(sizeof(node));
	cnt++;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (pstk->head == NULL) {
		pstk->head = newnode;
		pstk->cur = pstk->head;
		pstk->cur->data = ctt;
	}
	else {
		pstk->cur->next = newnode;
		newnode->prev = pstk->cur;
		pstk->cur = newnode;
		pstk->cur->data = ctt;
	}
}

int Spop(stk* pstk) {
	if (pstk->cur == NULL)
		return -1;
	else {
		int tmp = pstk->cur->data;
		node* del = pstk->cur;
		pstk->cur = pstk->cur->prev;
		if (pstk->cur == NULL)
			pstk->head = NULL;
		free(del);
		cnt--;
		return tmp;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stk* st = (stk*)malloc(sizeof(stk));
	st->head = NULL;
	st->cur = NULL;

	while (n--) {
		cin >> str;
		if (strcmp("push", str) == 0) {
			cin >> idx;
			Spush(st, idx);
		}
		else if (strcmp("pop", str) == 0) {
			cout << Spop(st) << "\n";
		}
		else if (strcmp("empty", str) == 0) {
			if (cnt == 0)
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}
		else if (strcmp("size", str) == 0) {
			cout << cnt << "\n";
		}
		else if(strcmp("top",str) == 0){
			if (st->cur == NULL)
				cout << "-1" << "\n";
			else
				cout << st->cur->data << "\n";
		}
	}
	return 0;
}