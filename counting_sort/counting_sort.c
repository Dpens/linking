#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 10
#define m 100
int * counting_sort(int A[n],int B[n]); //A is thee array which needs to be sorted,B is used to store sorted array

int main(void)
{
	int A[n] = { 0 };
	int B[n] = { 0 };
	srand((unsigned int)time(0));
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % m;
		printf("A[%d] = %d\n", i, A[i]);
	}
	int *p = counting_sort(A, B);
	for (int i = 0; i < n; i++)
		printf("B[%d] = %d\n", i, *(p + i));
	getchar();
	return 0;
}

int *counting_sort(int A[n],int B[n])
{
	int C[m] = { 0 };
	for (int i = 0; i < n; i++)
		C[A[i]] += 1;
	for (int i = 1; i < m; i++)
		C[i] += C[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		B[C[A[i]] - 1] = A[i];    //C[A[i]] - 1 because A[i] must minus itself
		C[A[i]] -= 1;
	}
	return B;
}