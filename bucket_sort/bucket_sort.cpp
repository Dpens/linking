#include<iostream>
#include<vector>
#include<cmath>

namespace bucket {                          
	typedef struct _bucket
	{
		double a;
		struct _bucket *next;
	}Bucket;
}

void bucket_sort(double *A, int n)
{
	using namespace bucket;
	Bucket B[10];                     
	std::vector<int>C(n);
	for (int i = 0; i < 10; i++)
	{
		B[i].next = NULL;
		B[i].a = 0;
	}
	double biggest = A[0];            //�ҵ�����������Ԫ��,����������λ��
	C[0] = A[0];
	for (int i = 1; i < n; i++)
	{
		C[i] = A[i];
		if (biggest < A[i])
			biggest = A[i];
	}
	int len = 0;
	while ((int)biggest > 0)
	{
		biggest /= 10;
		len++;
	}
	for (int i = 0; i < n; i++)
	{
		C[i] /= pow(10, len - 1);           //����������Ԫ�ض�����10���������λ��-1�η�,���Դ�Ϊ���ݾ������ǽ������õ�Ͱ
	}
	for (int i = 0; i < n; i++)            //�������е����ݷŵ�Ͱ��
	{
		if (B[C[i]].next == NULL)
		{
			Bucket *temp = new Bucket;
			B[C[i]].next = temp;
			temp->a = A[i];
			temp->next = NULL;
		}
		else
		{
			Bucket *temp = new Bucket;
			Bucket *current = B[C[i]].next;
			while (current->next != NULL && A[i] > current->a)
			{
				current = current->next;
			}
			if (current->next == NULL)          //���ýṹ���������β
			{
				current->next = temp;
				temp->a = A[i];
				temp->next = NULL;
			}
			else
			{
				temp->next = current->next;   //���ýṹ��������ȷλ�õ���һ�� ��3����1,2,4,5�е�4,5֮��
				current->next = temp;			//Ȼ��3��4����
				double Temp = current->a;
				current->a = A[i];
				temp->a = Temp;
			}
		}
	}
	int j = 0;
	for (int i = 0; i < 10; i++)      //��Ͱ�������ó�����������
	{
		Bucket *current = B[i].next;
		while (current != NULL)
		{
			A[j] = current->a;
			current = current->next;
			j++;
		}
	}
}

int main(void)
{
	double A[10] = {20,10,40,50,30,60,23,24,22};
	for (int i = 0; i < 10; i++)
		std::cout << A[i] << std::endl;
	std::cout << std::endl;
	bucket_sort(A, 10);
	for (int i = 0; i < 10; i++)
		std::cout << A[i] << std::endl;
	std::cin.get();
	return 0;
}