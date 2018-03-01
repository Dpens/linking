#include<iostream>
#include<vector>


template <typename Anytype>
void counting_sort(Anytype *A, int n)
{
	Anytype biggest = A[0];
	for (int i = 1; i < n; i++)
		if (biggest < A[i])
			biggest = A[i];
	std::vector <Anytype> B(n);
	std::vector <Anytype> C(biggest + 1);
	for (int i = 0; i < n; i++)
		B[i] = A[i];
	for (int i = 0; i < n; i++)
		C[B[i]] += 1;
	for (int i = 1; i < biggest + 1; i++)
		C[i] += C[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		A[C[B[i]] - 1] = B[i];
		C[B[i]] -= 1;
	}
}


int main(void)
{
	int A[10] = { 10,20,11,13,78,96,54,23,45 };
	for (int i = 0; i < 10; i++)
		std::cout << A[i] << std::endl;
	std::cout << std::endl;
	counting_sort(A, 10);
	for (int i = 0; i < 10; i++)
		std::cout << A[i] << std::endl;
	std::cin.get();
	return 0;
}