
////////////////////////////////////////
/*
 BOJ6549 히스토그램에서 가장 큰 직사각형
                                      */
////////////////////////////////////////

/*
Segment tree를 활용하여 범위를 쪼개서
범위 내의 막대기 높이가 최소가 되는 인덱스를
구해서 최대가 되는 직사각형의 넓이를 구하는 문제였다.
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void init(vector<int> &arr, vector<int> &tree, int node, int start, int end)
{
	if (start == end)
		tree[node] = start;
	else
	{
		int mid = (start + end) / 2;
		init(arr, tree, node * 2, start, mid);
		init(arr, tree, node * 2 + 1, mid + 1, end);

		// 각 구간에서 막대기 높이가 가장 낮은 것을 노드에 넣어준다.
		if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
			tree[node] = tree[node * 2];
		else
			tree[node] = tree[node * 2 + 1];
	}
}

// 구간에서 가장 최소인 높이의 막대 구하기
int query(vector<int> &arr, vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) // left--right의 범위를 둘다 벗어나면  -1 반환
		return -1;

	if (left <= start && end <= right)
		return tree[node]; // left--right 범위에 start와 end가 들어오면 tree[node]를 반환한다.

	int mid = (start + end) / 2;
	int m1 = query(arr, tree, node * 2, start, mid, left, right);
	int m2 = query(arr, tree, node * 2 + 1, mid + 1, end, left, right); //나누기

	if (m1 == -1)
		return m2;

	else if (m2 == -1)
		return m1;

	else
	{
		if (arr[m1] <= arr[m2])
			return m1;			//범위에 들어오는 값을 인덱스로 막대기 높이의 최소값이 되는 인덱스를 반환한다.
		else
			return m2;
	}
}

long long getMax(vector<int> &arr, vector<int> &tree, int start, int end)
{
	int n = arr.size();
	int m = query(arr, tree, 1, 0, n - 1, start, end); //query함수에서 반환한 인덱스 값


	long long area = (long long)(end - start + 1)*(long long)arr[m]; //n=가로 m은 막대기높이가 저장되어있는 배열의 인덱스


	if (start <= m - 1)
	{
		long long tmp = getMax(arr, tree, start, m - 1);//두 구간으로 나눠서 

		if (area < tmp)
			area = tmp; // 최대값을 area에 저장한다.
	}
	//앞구간

	if (m + 1 <= end)
	{
		long long tmp = getMax(arr, tree, m + 1, end);
		if (area < tmp)
			area = tmp;
	}

	//뒷구간
	return area; //구한 넓이 반환
}

int main()
{
	while (1)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		vector<int> arr(n);


		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);


		int h = (int)(ceil(log2(n)));
		int tree_size = pow(2, (h + 1));

		vector<int> tree(tree_size);


		init(arr, tree, 1, 0, n - 1);

		printf("%lld\n", getMax(arr, tree, 0, n - 1));
	}

	return 0;
}
