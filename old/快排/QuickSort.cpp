// C++_test.cpp : 定义控制台应用程序的入口点。
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
		int i = l, j = r, pivot = array[l]; //以最左边元素为主元
		int temp = array[l];
		while (i < j)
		{
			while (i < j && array[j] >= pivot) // 从右向左找第一个小于pivot的数
				j--;
			if (i < j)
				array[i++] = array[j];
			while (i < j && array[i]< pivot) // 从左向右找第一个大于等于pivot的数
				i++;
			if (i < j)
				array[j--] = array[i];
		}
		array[i] = temp;
		qs(array, l, i - 1); // 左边递归
		qs(array, i + 1, r); // 右边递归
	}
}
//*/


int main(int argc, char *argv[])
{
	int i, n, element;
	cout << "输入数组长度n:";
	cin >> n;
	cout << "输入n个数组元素:";
	for (i = 0; i < n; i++)
	{
		cin >> element;
		arr1.push_back(element);
	}
	
	//测试。。。
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

