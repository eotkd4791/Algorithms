/*
=======================
     짝수와 홀수
=======================
++++++++++++++++++++++++
비트연산자 &
조건연산자 ? :

++++++++++++++++++++++++
*/
#include <string>
#include <vector>
using namespace std;

string solution(int num) {
	return num & 1 ? "Odd" : "Even";
} 
