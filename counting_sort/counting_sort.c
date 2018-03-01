#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 10
#define m 100
void counting_sort(int A[n]); //A is thee array which needs to be sorted

int main(void)
{
	int A[n] = { 0 };
	srand((unsigned int)time(0));
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % m;
		printf("A[%d] = %d\n", i, A[i]);
	}
	counting_sort(A);
	for (int i = 0; i < n; i++)
		printf("A[%d] = %d\n", i, *(A + i));
	getchar();
	return 0;
}

void counting_sort(int A[n])
{
	int C[m] = { 0 };
	int B[n] = { 0 };
	for (int i = 0; i < n; i++)
		B[i] = A[i];
	for (int i = 0; i < n; i++)
		C[B[i]] += 1;
	for (int i = 1; i < m; i++)
		C[i] += C[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		A[C[B[i]] - 1] = B[i];    //C[A[i]] - 1 because A[i] must minus itself
		C[B[i]] -= 1;
	}
}