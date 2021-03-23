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
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	int value; //Добавляемое значение
	cout << "Введите добавляемое значение: "; cin >> value;
	//-------------------------------------------------------------------------------------
#ifdef ARRAY_BUFFER
	//1) Создаем буферный массив нужного размера
	int* buffer = new int[n + 1]{};
	//2) Копируем все значения из исходного массива в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) После того как данные скопированы, исходный массив можно удалить
	delete[] arr;
	//4) Подменяем адрес в указателе на исходный массив
	arr = buffer;
	//5) И только после всего этого можно записать новое значение в конец массива
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

//Код добавления значения в конец массива в отдельной функции push_back();
#ifdef PUSH_BACK
void push_back(int* arr, int n, int value)
{
	//1) Создаем буферный массив нужного размера
	int* buffer = new int[n + 1]{};
	//2) Копируем все значения из исходного массива в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) После того как данные скопированы, исходный массив можно удалить
	delete[] arr;
	//4) Подменяем адрес в указателе на исходный массив
	arr = buffer;
	//5) И только после всего этого можно записать новое значение в конец массива
	arr[n] = value;
	n++;
	Print(arr, n);
}
#endif // PUSH_BACK

//-------------------------------------------------------------------------------------

//Код добавления значения в начало массива в отдельной функции push_front();
#ifdef PUSH_FRONT
void push_front(int* arr, int n, int value)
{
	//1) Создаем буферный массив нужного размера
	int* buffer = new int[n + 1]{};
	//2) Копируем все значения из исходного массива в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//3) После того как данные скопированы, исходный массив можно удалить
	delete[] arr;
	//4) Подменяем адрес в указателе на исходный массив
	arr = buffer;
	//5) И только после всего этого можно записать новое значение в начало массива
	arr[0] = value;
	n++;
	Print(arr, n);
}
#endif // PUSH_FRONT

//-------------------------------------------------------------------------------------

//Код добавления значения в массив по указанному индексу в отдельной функции insert();
#ifdef INSERT
void insert(int* arr, int n, int value)
{
	int index = 0;
	cout << "Введите номер индекса для значения: "; cin >> index;
	//1) Создаем буферный массив нужного размера
	int* buffer = new int[++n]{};
	//2) Копируем все значения из исходного массива в буферный до index
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = value;
	//3) Копируем все значения из исходного массива в буферный после index
	for (int i = index; i < n - 1; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//4) После того как данные скопированы, исходный массив можно удалить
	delete[] arr;
	//5) Подменяем адрес в указателе на исходный массив
	arr = buffer;
	Print(arr, n);
}
#endif // INSERT

//-------------------------------------------------------------------------------------

//Удаляет последний элемент из массива в отдельной функции pop_back();
#ifdef POP_BACK
void pop_back(int* arr, int n)
{
	cout << "\nВместо добавляемого значения я решил удалить последний элемент в массиве: " << endl;
	//1) Создаем буферный массив нужного размера
	int* buffer = new int[n - 1]{};
	//2) Копируем все значения из исходного массива в буферный на 1 элемент меньше
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	//3) После того как данные скопированы, исходный массив можно удалить
	delete[] arr;
	//4) Подменяем адрес в указателе на исходный массив
	arr = buffer;
	//5) И только после всего этого можно удалить мусор в конце массива
	n--;
	Print(arr, n);
}
#endif // POP_BACK

//-------------------------------------------------------------------------------------

//Удаляет нулевой элемент из массива в отдельной функции pop_back();
#ifdef POP_FRONT
void pop_front(int* arr, int n)
{
	cout << "\nВместо добавляемого значения я решил удалить '0' в массиве: " << endl;
	int m = n;
	int i;
	//1) Ищем нули в исходном массиве
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
	//2) Удаляем копию последнего элемента
	n--;
	Print(arr, n);
	//3) массив можно удалить
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
//1. Код добавления значения в конец массива вынести в функцию ??? push_back(????);
//2. В проект DynamicMemory добавить функции:
//		??? push_front(???);   //Добавляет значение в начало массива
//		??? insert(???);       //Вставляет значение в массив по указанному индексу
//		??? pop_back(???);     //Удаляет последниий элемент из массива
//		??? pop_front(???);    //Удаляет нулевой элемент из массива
//		??? erase(???);        //Удаляет элемент из массива по заданному индексу
//      Для того чтобы удалить элемент из массива, в буферный массив нужно скопировать
//      все кроме удаляемого элемента
// #define PUSH_BACK
// #ifdef PUSH_BACK