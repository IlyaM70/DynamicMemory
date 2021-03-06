﻿#include<iostream>
using namespace std;
int** Allocate(int m, int n);

void Clear(int** arr, int m, int n);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int m,const int n);

void Print(int arr[], const int n);
void Print(int** arr, const int m, const int n);

int* push_back(int arr[],  int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int value, int index);//значение по указаному индексу

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);//удаляет значение из массива по указанному индексу



//#define DINAMIC_MEMORY_1

#define DINAMIC_MEMORY_2

    using std::cin;
	using std::cout;
	using std::endl;

void main()
{
	setlocale(LC_ALL, "");


#ifdef DINAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	int value;

	cout << "Введите добавляемое значение "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "Удаление последнего элемента массива " << endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "Удаление первого элемента массива " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	

	int index;
	cout << "Введите номер добавляемого числа "<<endl; cin >> index;
	cout << "Введите добавляемое число " << endl; cin >> value;
	arr=insert(arr, n, value, index);
	Print(arr, n);
	cout << "Введите номер удаляемого числа " << endl; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

    delete[] arr;
#endif // DINAMIC_MEMORY_1


	


#ifdef DINAMIC_MEMORY_2
int m; // количество строк
int n;// кол элементов строки

cout << "Введите количество строк "; cin >> m;
cout << "Введите количество элементов строки "; cin >> n;
int** arr=Allocate(m, n);
FillRand(arr, m, n);
Print(arr, m, n);
Clear(arr, m, n);
//FillRand(arr, m, n);
//Print(arr, m, n);

#endif // DINAMIC_MEMORY_2



	

}
int** Allocate(int m, int n)
{
	// 1) создаем массив указателей
	int** arr = new int* [m];
	// 2) выделяем память под строки двумерного массива
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	return arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

	void FillRand(int** arr, const int m, const int n)
		{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = rand() % 100;
			}
		}

	}


void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
		
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
{
	for (int j = 0; j < n; j++)
	{
		cout << arr[i][j] << "\t";
	}
	cout << endl;
}
}


int* push_back(int arr[],  int& n, int value)

{
	/////////////////////////////////////
		// 1) выделить блок памяти нужного размера
		//создаем буферный массив нужного рамзмера 
	int* buffer = new int[n + 1]{};
	//2)копируем значения из исходного значения в буфер
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3)удаляем исходный массив
	delete[]arr;
	//4) подменяем адресс старого массива адресом нового
	arr = buffer;
	//5) записываем значения в конец массива
	arr[n] = value;
	//6) после добавления значения размер массива
	//увеличивается на 1
	n++;
	return arr;
	//////////////////////////////////////
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
		buffer[i + 1] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i<n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	return buffer;
}
int* insert(int arr[], int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
		if (i < index) buffer[i] = arr[i];
		else buffer[i + 1] = arr[i];

	delete[]arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[n-1]{};
	for (int i = 0; i < n; i++)
		if (i < index) buffer[i] = arr[i];
		else buffer[i] = arr[i+1];
		
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}

void Clear(int** arr, int m, int n)
{
	//удаление
//строк
for (int i = 0; i < m; i++)
	delete[] arr[i];
//массив указателей
delete[]arr;
}
