#include<iostream>
#include<vector>
#include<cmath>

void radix_sort(int * A, int n)
{
	using std::vector;
	vector<vector<int>>bucket(10, vector<int>(n, 0)); //as bucket to store statistics
	vector<int>pos(n);      //store number in units
	vector<int>temp(n);     //store number temp[] / 10
	int B[10] = { 0 };      //count the number of whose units is pos
	int biggest = A[0];
	for (int i = 1; i < n; i++)
	{
		if (A[i] > biggest)
			biggest = A[i];
	}
	int number = 0;
	while (biggest > 0)
	{
		number++;
		biggest /= 10;
	}
	for (int v = 0; v < number; v++)
	{
		for (int i = 0; i < n; i++)
			temp[i] = A[i];
		int order = pow(10, v);
		for (int i = 0; i < n; i++)
		{
			if (v > 0)
			{
				temp[i] /= order;
			}
			pos[i] = temp[i] % 10;
		}
		for (int i = 0; i < n; i++)     //put A[] into bucket
		{
			bucket[pos[i]][B[pos[i]]] = A[i];
			B[pos[i]] += 1;
		}
		int m = 0;
		for (int i = 0; i < 10; i++)     //pour bucket into A[]
			for (int j = 0; j < B[i]; j++)
			{
				A[m] = bucket[i][j];
				m++;
			}
		for (int i = 0; i < 10; i++)
			B[i] = 0;
	}
}

int main(void)
{
	int A[10] = { 789,5,9,12,56,43,999,56,4 };
	for (int i = 0; i < 10; i++)
		std::cout << A[i] << std::endl;
	radix_sort(A, 10);
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << A[i] << std::endl;
	std::cin.get();
	return 0;
}