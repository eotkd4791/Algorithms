/*scanf와 fgets차이점
fgets는 개행이 포함된다.
그래서 fgets를 이용한 코드에는 -1을 해줬다.
또한 fgets는 NULL문자 뿐만 아니라, 
개행이 끝에 들어가기 때문에 배열의 크기를
바꿔야 했다.*/

#include <iostream>
#include <cstring>
using namespace std;
char word[101];
int str_len;

int main() {
	scanf("%s", word);
	str_len = strlen(word);
	printf("%d", str_len);
	return 0;
}
//
//
//
//
#include <iostream>
#include <cstring>
using namespace std;
char word[102];
int str_len;

int main() {
	fgets(word, 102, stdin);
	str_len = strlen(word) - 1;
	printf("%d\n", str_len);
	return 0;
}