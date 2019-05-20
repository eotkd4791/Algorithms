#include <cstdio>
#include <cstdlib>

#define TRUE 1
#define FALSE 0

typedef struct _node {
	int data;
	struct _node* next;
}Node;

typedef struct _linkedList {
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
	int (*comp)(int d1, int d2);
} List;

void ListInit(List* plist) {//리스트 생성
	plist->head = (Node*)malloc(sizeof(Node));//
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void SInsert(List * plist,int data) {//오름차순 정렬삽입
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;

	newNode->data = data;
	
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) 
		pred = pred->next;
	

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

int LFirst(List* plist, int* pdata) {
	if (plist->head->next == NULL) 
		return FALSE;
	plist->before = plist->head;
	plist->cur = plist->head->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, int* pdata) {
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LRemove(List* plist) {
	Node* rpos = plist->cur;
	int rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
}

int WhoIsPrecede(int d1, int d2) {
	if (d1 < d2)
		return 0;
	else
		return 1;
}

void SetSortRule(List* plist, int (*comp)(int d1, int d2)) {
	plist->comp = comp;
}

int main() {
	//리스트의 생성 및 초기화 /////
	List list;
	int num;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

	//5개의 데이터 저장
	SInsert(&list, 19);
	SInsert(&list, 93);
	SInsert(&list, 1);
	SInsert(&list, 30);
	
	//저장된 데이터의 전체 출력 /////
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &num)) {
		printf("%d ", num);
		
		while (LNext(&list, &num))
			printf("%d ", num);
	}
	printf("\n\n");

	// 숫자 22을 검색하여 모두 삭제 /////
	if (LFirst(&list, &num)) {
		if (num == 22)
			LRemove(&list);

		while (LNext(&list, &num)) {
			if (num == 22)
				LRemove(&list);
		}
	}

	//삭제 후 남아있는 데이터 전체 출력 //////
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &num)) {
		printf("%d ", num);

		while (LNext(&list, &num))
			printf("%d ", num);
	}
	printf("\n\n");
	return 0;
}