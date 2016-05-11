#include<stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

#define N 50

void printNum(int *);
void printNum(int * num)
{
	for (int i = 0; i<N; i++)
	{
		printf("%3d ", num[i]);
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}
}

void myquickSort(int *, int, int);
void quick(int *, int, int);

void heapSort(int *, int, int);
void heap(int *, int, int,int);


void heapSort(int * num, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int middle = (right + left) / 2;

	heapSort(num, left, middle);
	heapSort(num, middle + 1, right);

	heap(num, left, right, middle);
}

void heap(int * num, int left, int right, int middle)
{
	int temp[N];
	int i = 0;
	int l = left;
	int r = right;
	int m = middle+1;
	for (; l <= middle && m<=right; i++)
	{
		if (num[l] <= num[m])
		{
			temp[i] = num[l];
			l++;
		}
		else
		{
			temp[i] = num[m];
			m++;
		}
	}

	while (l<=middle)
	{
		temp[i] = num[l];
		i++;
		l++;
	}

	while (m <= right)
	{
		temp[i] = num[m];
		i++;
		m++;
	}

	for (int j =0; j < i; j++)
	{
		num[j + left] = temp[j];
	}
}

void quick(int * num, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int middle = (left + right) / 2;
	while (right >= left)
	{
		myquickSort(num, left, middle);
		myquickSort(num, middle + 1, right);
		//quick(num,left,middle);
		//quick(num,middle+1,right);
	}
}


void myquickSort(int * num, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int l = left + 1;
	int r = right;

	while (l <= r)
	{

		while (l <= right&&num[l] <= num[left] )
		{
			l++;
		}

		while (r >= left + 1 &&num[r]>num[left]  )
		{
			r--;
		}

		if (l > r)
		{
			break;
		}
		else
		{
		int temp = num[l];
		num[l] = num[r];
		num[r] = temp;
		l++;
		r--;
		}
		
	}


	int temp = num[r];
	num[r] = num[left];
	num[left] = temp;


	myquickSort(num, left, r-1);
	myquickSort(num, r + 1, right);
}

int main(void)
{
	srand((unsigned)time(NULL)); //用时间做种，每次产生随机数不一样
	int num[N];
	for (int i = 0; i<N; i++)
	{
		num[i] = rand() % 101; //产生0-100的随机数
	}

	printf("排序之前\n");
	printNum(num);

	//myquickSort(num, 0, N-1);
	heapSort(num, 0, N - 1);

	printf("排序之后\n");
	printNum(num);

	return 0;
}