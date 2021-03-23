#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int*& arr, const int n);
void push_back(int* arr, const int n, int value);
void push_front(int* arr, const int n, int value);
void insert(int* arr, const int n, int value);
void pop_back(int* arr, const int n);
void pop_front(int* arr, const int n);

//#define ARRAY_BUFFER
//#define PUSH_BACK
//#define PUSH_FRONT
//#define INSERT
//#define POP_BACK
#define POP_FRONT

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	int value; //����������� ��������
	cout << "������� ����������� ��������: "; cin >> value;
	//-------------------------------------------------------------------------------------
#ifdef ARRAY_BUFFER
	//1) ������� �������� ������ ������� �������
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ����� ���� ��� ������ �����������, �������� ������ ����� �������
	delete[] arr;
	//4) ��������� ����� � ��������� �� �������� ������
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� �������� ����� �������� � ����� �������
	arr[n] = value;
	n++;
	Print(arr, n);
#endif // ARRAY_BUFFER
	//-------------------------------------------------------------------------------------

	//push_back(arr, n, value);
	//push_front(arr, n, value);
	//insert(arr, n, value);
	//pop_back(arr, n);
	pop_front(arr, n);
	//Print(arr, n);
}

//-------------------------------------------------------------------------------------

//��� ���������� �������� � ����� ������� � ��������� ������� push_back();
#ifdef PUSH_BACK
void push_back(int* arr, int n, int value)
{
	//1) ������� �������� ������ ������� �������
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ����� ���� ��� ������ �����������, �������� ������ ����� �������
	delete[] arr;
	//4) ��������� ����� � ��������� �� �������� ������
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� �������� ����� �������� � ����� �������
	arr[n] = value;
	n++;
	Print(arr, n);
}
#endif // PUSH_BACK

//-------------------------------------------------------------------------------------

//��� ���������� �������� � ������ ������� � ��������� ������� push_front();
#ifdef PUSH_FRONT
void push_front(int* arr, int n, int value)
{
	//1) ������� �������� ������ ������� �������
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//3) ����� ���� ��� ������ �����������, �������� ������ ����� �������
	delete[] arr;
	//4) ��������� ����� � ��������� �� �������� ������
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� �������� ����� �������� � ������ �������
	arr[0] = value;
	n++;
	Print(arr, n);
}
#endif // PUSH_FRONT

//-------------------------------------------------------------------------------------

//��� ���������� �������� � ������ �� ���������� ������� � ��������� ������� insert();
#ifdef INSERT
void insert(int* arr, int n, int value)
{
	int index = 0;
	cout << "������� ����� ������� ��� ��������: "; cin >> index;
	//1) ������� �������� ������ ������� �������
	int* buffer = new int[++n]{};
	//2) �������� ��� �������� �� ��������� ������� � �������� �� index
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = value;
	//3) �������� ��� �������� �� ��������� ������� � �������� ����� index
	for (int i = index; i < n - 1; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//4) ����� ���� ��� ������ �����������, �������� ������ ����� �������
	delete[] arr;
	//5) ��������� ����� � ��������� �� �������� ������
	arr = buffer;
	Print(arr, n);
}
#endif // INSERT

//-------------------------------------------------------------------------------------

//������� ��������� ������� �� ������� � ��������� ������� pop_back();
#ifdef POP_BACK
void pop_back(int* arr, int n)
{
	cout << "\n������ ������������ �������� � ����� ������� ��������� ������� � �������: " << endl;
	//1) ������� �������� ������ ������� �������
	int* buffer = new int[n - 1]{};
	//2) �������� ��� �������� �� ��������� ������� � �������� �� 1 ������� ������
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ����� ���� ��� ������ �����������, �������� ������ ����� �������
	delete[] arr;
	//4) ��������� ����� � ��������� �� �������� ������
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� ������� ����� � ����� �������
	n--;
	Print(arr, n);
}
#endif // POP_BACK

//-------------------------------------------------------------------------------------

//������� ������� ������� �� ������� � ��������� ������� pop_back();
#ifdef POP_FRONT
void pop_front(int* arr, int n)
{
	cout << "\n������ ������������ �������� � ����� ������� '0' � �������: " << endl;
	int m = n;
	int i;
	//1) ���� ���� � �������� �������
	for (int i = 0; i < m; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i; j < n - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			m--;
			i--;
		}
	}

	/*for (m = i = 0; i < n; i++)
	{
		if (arr[i] != 0)
			arr[m++] = arr[i];
	}*/

	/*for (m = 0; m < n && arr[m] != 0; m++)
	{
		;
	}
	for (i = m + 1; i < n; i++)
	{
		if (arr[i] != 0)
			arr[m++] = arr[i];
	}*/
	//2) ������� ����� ���������� ��������
	n--;
	Print(arr, n);
	//3) ������ ����� �������
	delete[] arr;
}
#endif // POP_FRONT

//-------------------------------------------------------------------------------------

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int*& arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
		//cout << *(arr + i) << tab;
	}
	cout << endl;
}

//TODO:
//1. ��� ���������� �������� � ����� ������� ������� � ������� ??? push_back(????);
//2. � ������ DynamicMemory �������� �������:
//		??? push_front(???);   //��������� �������� � ������ �������
//		??? insert(???);       //��������� �������� � ������ �� ���������� �������
//		??? pop_back(???);     //������� ���������� ������� �� �������
//		??? pop_front(???);    //������� ������� ������� �� �������
//		??? erase(???);        //������� ������� �� ������� �� ��������� �������
//      ��� ���� ����� ������� ������� �� �������, � �������� ������ ����� �����������
//      ��� ����� ���������� ��������
// #define PUSH_BACK
// #ifdef PUSH_BACK