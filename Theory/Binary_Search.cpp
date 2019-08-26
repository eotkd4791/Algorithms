#include <iostream>
using namespace std;

int Binary_Search(int arr[], int length, int target) { //배열 이름, 길이, 찾고자 하는 값
	int first = 0;				//탐색 시작 인덱스 값
	int last = length - 1;	//탐색 마지막 인덱스 값
	int mid;						//탐색의 기준값, 한번 탐색후에 범위 재설정을 위한 변수

	while (first <= last) {
		mid = (first + last) / 2;
		if (target == arr[mid]) return mid;	
		else {
			if (target < arr[mid]) last = mid - 1;
			else first = mid + 1;
		}
	}
	return -1;					 //탐색실패-찾는 값이 범위 내에 없을 때 -1반환
}
int main() {
	int arr[] = { 1,3,5,7,9 };
	int idx=0;
	printf("%d ", arr[]);
	idx = Binary_Search(arr, sizeof(arr) / sizeof(int), n);
	if (idx == -1) printf("찾는 값이 범위 내에 없습니다.\n");
	else printf("타겟이 저장되어 있는 인덱스는 %d 입니다.\n", idx);
	
	idx = Binary_Search(arr, sizeof(arr)/sizeof(int), 4);
	if (idx == -1) printf("찾는 값이 범위 내에 없습니다.\n");
	else printf("타겟이 저장되어 있는 인덱스는 %d 입니다.\n", idx);
	return 0;
}//이진탐색은 오름차순으로 정렬이 되어있는 상태에서 해야한다. 
