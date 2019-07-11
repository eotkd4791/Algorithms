#include <iostream>
#include <cstdlib>
using namespace std;

int n;

typedef struct _node {
	int num;
	char data;
	_node* left;
	_node* right;
	_node* next;
}node;


typedef struct{
	node* head;
	node* cur;
}tree;


void inorder(node* bt) {
	if (bt == NULL) return;
	inorder(bt->left);
	cout << bt->data;
	inorder(bt->right);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	for (int t = 1; t <= 10; t++) {
		cin >> n;
		tree tl;
		tl.cur = NULL;
		tl.head = NULL;
		for (int i = 1; i <= n; i++) {
			node* newnode = (node*)malloc(sizeof(node));
			if (tl.head == NULL && tl.cur == NULL) {
				tl.head = newnode;
				tl.cur = newnode;
			}
			tl.cur->next = newnode;
			tl.cur = tl.cur->next;
		}
		tl.cur = tl.head;
		
		int idx,l,r; char apb; 
		for (int i = 1; i <= n; i++) {
			cin >> idx >> apb;
			tl.cur->num = idx;
			tl.cur->data = apb;

			if (tl.cur->num * 2 < n) {
				cin >> l >> r;
				node* tmp = tl.cur;
				for (int j = i; j < l; j++) 
					tmp = tmp->next;
				tl.cur->left = tmp;

				/*tmp = tl.cur;
				for (int j = i; j < r; j++) 
					tmp = tmp->next;
				tl.cur->right=tmp;*/

				tl.cur->right = tmp->next;
			}
			else if(tl.cur->num*2 ==n) {
				cin >> l;
				node* tmp = tl.cur;
				for (int j = i; j < l; j++) {
					tmp = tmp->next;
				}
				tl.cur->left = tmp;
				tl.cur->right = NULL;//
			}
			else {
				tl.cur->left = NULL;
				tl.cur->right = NULL;
			}
			tl.cur = tl.cur->next;
		}


		tl.cur = tl.head;
		cout << "#" << t << " ";
		inorder(tl.cur);
		cout << "\n";
		
		
		for (int i = 1; i <= n; i++) {
			node* tmp = tl.cur->next;
			free(tl.cur);
			tl.cur = tmp;
		}
	}
	return 0;
}