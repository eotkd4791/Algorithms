#include <iostream>
#include<algorithm>

using namespace std;

int main() {
	int score[8] = {};
	int i, sum = 0;
	int check[8] = {};
	int num[8] = {};
	int tmp = 0;


	for (i = 0; i < 8; i++) {
		scanf_s("%d", &score[i]); //8개 숫자 입력받음
		check[i] = score[i];
	}

	sort(score, score + 8);

	for (int j = 3; j < 8; j++) {
		sum += score[j];

	}

	printf("%d\n", sum);



	for (i = 3; i < 8; i++) {                 //문제 번호 출력하기
		for (int j = 0; j < 8; j++) {
			if (score[i] == check[j]) {
				tmp = j + 1;
				num[j] = tmp;

			}



		}
	}

	sort(num, num + 8);

	for (i = 3; i < 8; i++)
		printf("%d ", num[i]);




	return 0;
}