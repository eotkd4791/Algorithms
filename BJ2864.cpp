#include <iostream>
#include<math.h>
using namespace std;

int arr1[7] = {};		
int arr2[7] = {};		//입력 받은 두 수 자릿수대로 분해
int tmp1[7] = {};
int tmp2[7] = {};		//tmp1,tmp2 값 유지를 위한 임시 배열(처음 입력한 숫자로 다시 계산하기 위해서 저장해둠)
double min_num[2] = {};		//최솟값 저장하기 위한 배열
double MAX_num[2] = {};		//최댓값 저장하기 위한 배열 (pow함수 때문에 더블형으로 씀)

int min(void) {
	for (int i = 0; i < 7; i++) {
		if (arr1[i] == 6)
			tmp1[i] = 5;
		min_num[0] += tmp1[i] * pow(10, i);  //분해한 성분에서 바꾼 값을 정수로 합쳐줌
	}
	for (int j = 0; j < 7; j++) {
		if (arr2[j] == 6)
			tmp2[j] = 5;
		min_num[1] += tmp2[j] * pow(10, j);
	}

	return min_num[0] + min_num[1];
}												//최소값 구하는 함수

int MAX(void) {
	for (int i = 0; i < 7; i++) {
		if (arr1[i] == 5)
			arr1[i] = 6;
		MAX_num[0] += arr1[i] * pow(10,i);
	}
	for (int j = 0; j < 7; j++) {
		if (arr2[j] == 5)
			arr2[j] = 6;
		MAX_num[1] += arr2[j] * pow(10,j);	
	}
	 
	return MAX_num[0] + MAX_num[1];
}												//최대값 구하는 함수


int main() {
	int num[2] = {};							//입력 받은 두수
	
	for (int i = 0; i < 2; i++)
		scanf_s("%d", &num[i]);					//두수를 입력 받음
	
	


	for (int i = 0; i < 7; i++) {
		arr1[i] = num[0] % 10;
		num[0] /= 10;							//1의 자리 숫자부터 배열에 저장
	}


	for (int i = 0; i < 7; i++) {
		arr2[i] = num[1] % 10;
		num[1] /= 10;
	}

	for (int i = 0; i < 7; i++) {
		tmp1[i] = arr1[i];
		tmp2[i] = arr2[i];
	}

	printf("%d %d\n", min(), MAX());
	return 0;
}