// C++_test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>       
#include <vector>
using namespace std;    
vector<int>arr1;


//*
void QS(vector<int>& array, int l, int r)
{
	if (l< r)
	{
		int i = l, j = r, pivot = array[l]; //�������Ԫ��Ϊ��Ԫ
		int temp = array[l];
		while (i < j)
		{
			while (i < j && array[j] >= pivot) // ���������ҵ�һ��С��pivot����
				j--;
			if (i < j)
				array[i++] = array[j];
			while (i < j && array[i]< pivot) // ���������ҵ�һ�����ڵ���pivot����
				i++;
			if (i < j)
				array[j--] = array[i];
		}
		array[i] = temp;
		qs(array, l, i - 1); // ��ߵݹ�
		qs(array, i + 1, r); // �ұߵݹ�
	}
}
//*/


int main(int argc, char *argv[])
{
	int i, n, element;
	cout << "�������鳤��n:";
	cin >> n;
	cout << "����n������Ԫ��:";
	for (i = 0; i < n; i++)
	{
		cin >> element;
		arr1.push_back(element);
	}
	
	//���ԡ�����
	qs(arr1, 0, arr1.size() - 1); 
	cout << endl;
	for (i = 0; i < n; i++)
	{
		cout<<arr1[i]<<" ";
	}
	cout << endl;

	/*
	int optind=0;
	char *a = NULL;
	char *b = NULL;
	a = argv[++optind];
    b = argv[++optind];
	cout<<a<<" "<<b<<endl;
	//*/
	system("pause");    	
	return 0;
}

