#include <iostream>
#define INF 100000
using namespace std;

int N, x;
int num, idx = 1;
int heap[INF];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	while (N--) {
		cin >> x;
		if (x == 0) {//Delete
			cout << heap[1] << '\n';
			if (heap[1] == 0)
				continue;
			heap[1] = heap[num]; 
			heap[num--] = 0;

			idx = 1;
			while (1) {
				if (idx >= num)
					break;
				int left = idx * 2;
				int right = idx * 2 + 1;
				
				if (left > num) //Left(x), Right(x)
					break;
				
				if (left <= num && num < right) {// Left(o), Right(x)
					if (heap[idx] < heap[left]) {
						swap(heap[idx], heap[left]);
						idx = left;
						continue;
					}
					else
						break;
				}
				if (right <= num) {// Left(o), Right(o)
					if (heap[idx] <= heap[left] && heap[idx] <= heap[right]) {//both of sub trees have bigger value their super tree
						if (heap[left] >= heap[right]) {
							swap(heap[idx], heap[left]);
							idx = left;
							continue;
						}
						else {
							swap(heap[idx], heap[right]);
							idx = right;
							continue;
						}
					}
					if (heap[idx] >= heap[left] && heap[idx] <= heap[right]) {//only right sub tree have bigger value its super tree
						swap(heap[idx], heap[right]);
						idx = right;
						continue;
					}
					if (heap[idx] >= heap[right] && heap[idx] <= heap[left]) {//only left sub tree have bigger value its super tree
						swap(heap[idx], heap[left]);
						idx = left;
						continue;
					}
					if (heap[idx] >= heap[left] && heap[idx] >= heap[right])//both of them have less value
						break;
				}
			}
		}
		else {//Insert
			heap[++num] = x;
			idx = num;
			if (num == 1)
				continue;
			while (idx > 1) {
				if (heap[idx] > heap[idx / 2]) {
					swap(heap[idx], heap[idx / 2]);
					idx /= 2;
				}
				else
					break;
			}
		}
	}
	return 0;
}