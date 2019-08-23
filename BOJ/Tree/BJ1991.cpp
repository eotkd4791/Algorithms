#include <iostream>
#include <cstdlib>
using namespace std;

int N;

typedef struct _tree {
	char data;
	_tree* left;
	_tree* right;
	_tree* next;
}tree;

typedef struct {
	tree* head;
	tree* cur;
	tree* lsub;
	tree* rsub;
}ptr;

void preorder(tree* pptr) {
	cout << pptr->data;
	if (pptr->left != NULL)
		preorder(pptr->left);
	if (pptr->right != NULL)
		preorder(pptr->right);
}
void inorder(tree* pptr) {
	if (pptr->left != NULL)
		inorder(pptr->left);
	cout << pptr->data;
	if (pptr->right != NULL)
		inorder(pptr->right);
}
void postorder(tree* pptr) {
	if(pptr->left!=NULL)
		postorder(pptr->left);
	if(pptr->right!=NULL)
		postorder(pptr->right);
	cout << pptr->data;
	free(pptr);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ptr* tr = (ptr*)malloc(sizeof(ptr));
	tr->head = NULL; tr->cur = NULL; tr->lsub = NULL; tr->rsub = NULL;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		tree* newnode = (tree*)malloc(sizeof(tree));
		newnode->data = 'A' + i;
		newnode->left = NULL;	newnode->right = NULL;
		newnode->next = NULL;

		if (i == 0) {
			tr->head = newnode;
			tr->cur = tr->head;
		}
		else {
			tr->cur->next = newnode;
			tr->cur = tr->cur->next;
		}
	}

	char p, l, r;
	for (int i = 0; i < N; ++i) {
		tr->cur = tr->head; tr->lsub = tr->rsub = tr->cur;
		cin >> p >> l >> r;
		
		while (tr->cur->data != p) 
			tr->cur = tr->cur->next;
		
		if (l != '.') {
			while (tr->lsub->data != l)
				tr->lsub = tr->lsub->next;
			tr->cur->left = tr->lsub;
		}

		if (r != '.') {
			while (tr->rsub->data != r)
				tr->rsub = tr->rsub->next;
			tr->cur->right = tr->rsub;
		}
	}
	preorder(tr->head);
	cout << '\n';
	inorder(tr->head);
	cout << '\n';
	postorder(tr->head);
	return 0;
}