#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct _Deque {
	int data;
	_Deque* prev;
	_Deque* next;
}dqe;

int cnt, n;

typedef struct {
	dqe* head;
	dqe* tail;
}Dptr;


void PushFront(Dptr* ptr, int Ddata) {
	cnt++;
	dqe* newone = (dqe*)malloc(sizeof(dqe));
	newone->data = Ddata;
	newone->prev = NULL;

	if (ptr->head == NULL && ptr->tail == NULL) {
		newone->next = NULL;
		ptr->head = newone;
		ptr->tail = newone;
	}
	else {
		newone->next = ptr->head;
		ptr->head->prev = newone;
		ptr->head = newone;
	}
}

void PushBack(Dptr* ptr, int Ddata) {
	cnt++;
	dqe* newone = (dqe*)malloc(sizeof(dqe));
	newone->data = Ddata;
	newone->next = NULL;

	if (ptr->head == NULL && ptr->tail == NULL) {
		newone->prev = NULL;
		ptr->head = newone;
		ptr->tail = newone;
	}
	else {
		newone->prev = ptr->tail;
		ptr->tail->next = newone;
		ptr->tail = newone;
	}
}

int PopFront(Dptr* ptr) {
	if (cnt == 0) 
		return -1;
	
	else {
		cnt--;
		int temp = ptr->head->data;
		dqe* tmp = ptr->head;

		if (ptr->head->next != NULL) {
			ptr->head = ptr->head->next;
			ptr->head->prev = tmp->prev;
		}
		if (cnt == 0) {
			ptr->head = NULL;
			ptr->tail = NULL;
		}
		free(tmp);
		return temp;
	}
}

int PopBack(Dptr* ptr) {
	if (cnt == 0) 
		return -1;
	
	else {
		cnt--;
		int temp = ptr->tail->data;
		dqe* tmp = ptr->tail;

		if (ptr->tail->prev != NULL) {
			ptr->tail = ptr->tail->prev;
			ptr->tail->next = tmp->next;
		}
		if (cnt == 0) {
			ptr->head = NULL;
			ptr->tail = NULL;
		}
		free(tmp);
		return temp;
	}
}

int main() {

	Dptr* ptr = (Dptr*)malloc(sizeof(Dptr));
	ptr->head = NULL; ptr->tail = NULL;

	int T;
	scanf("%d", &T);

	while (T--) {
		char st[11] = {};
		scanf("%s", st);
		if (strcmp(st, "push_front") == 0) {
			scanf("%d", &n);
			PushFront(ptr,n);
		}
		else if (strcmp(st, "push_back") == 0) {
			scanf("%d", &n);
			PushBack(ptr,n);
		}
		else if (strcmp(st, "pop_front") == 0) 
			printf("%d\n", PopFront(ptr));
		
		else if (strcmp(st, "pop_back") == 0) 
			printf("%d\n", PopBack(ptr));
		
		else if (strcmp(st, "front") == 0) {
			if (ptr->head == NULL)
				printf("-1\n");
			else
				printf("%d\n", ptr->head->data);
		}
		else if (strcmp(st, "back") == 0) {
			if (ptr->tail == NULL)
				printf("-1\n");
			else
				printf("%d\n", ptr->tail->data);
		}
		else if (strcmp(st, "size") == 0) 
			printf("%d\n", cnt);
		
		else {//empty
			if (cnt == 0)
				printf("1\n");
			else
				printf("0\n");
		}
	}
	return 0;
}