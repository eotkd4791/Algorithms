#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct _node {
	int data;
	_node* left;
	_node* right;
}node;

struct tree {
	node* root;
	node* cur;
};

void postorder(node* ptr) {
	if (ptr == NULL) return;
	postorder(ptr->left);
	postorder(ptr->right);
	printf("%d\n", ptr->data);
	free(ptr);
}

int main() {
	tree *tr = (tree*)malloc(sizeof(tree));
	tr->root = NULL;
	tr->cur = NULL;

	int n;
	while (scanf("%d", &n) != EOF) {
		node* newnode = (node*)malloc(sizeof(node));
		tr->cur = tr->root;
		if (tr->root == NULL) {
			tr->root = newnode;
			tr->root->data = n;
			tr->root->left = NULL;
			tr->root->right = NULL;
			tr->cur = tr->root;
		}
			
		else {
			while (1) {
				if (tr->cur->data > n) {
					if (tr->cur->left == NULL) {
						tr->cur->left = newnode;
						tr->cur = tr->cur->left;
						tr->cur->data = n;
						tr->cur->left = NULL;
						tr->cur->left = NULL;
						break;
					}
					tr->cur = tr->cur->left;
				}
				else {
					if (tr->cur->right == NULL) {
						tr->cur->right = newnode;
						tr->cur = tr->cur->right;
						tr->cur->data = n;
						tr->cur->left = NULL;
						tr->cur->right = NULL;
						break;
					}
					tr->cur = tr->cur->right;
				}
			}
		}
	}
	tr->cur = tr->root;
	postorder(tr->cur);
	return 0;
}