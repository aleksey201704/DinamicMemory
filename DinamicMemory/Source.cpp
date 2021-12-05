#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

int** allocate(const int rows, const int cols);
void clear(int** arr, const int rows);

void FillRand(int* arr, const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);
void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
void insert(int** arr,int& idrows, int& idcols);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);

void push_col_back(int** arr, const int rows, int& cols);

int* pop_back(int arr[], int& n);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	cout << "Hello" << endl;
	cout << sizeof("+") << endl;
	cout << sizeof('+') << endl;
	int n;	//������ �������
	cout << "������� ������ �������: "; cin >> n;

	//���������� ������������� �������:
	int* arr = new int[n] {};

	FillRand(arr, n);
	Print(arr, n);

	int value;	//����������� ��������
	cout << "������� ����������� ��������: "; cin >> value;

	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	//�������� ������������� �������:
	delete[] arr;
	//Print(arr, n);	//Runtime error  
#endif // DYNAMIC_MEMORY_1

	int rows=3;	//���������� �����	
	int cols=5;	//���������� ��������� ������ (��������)
	int idrows=2;
	int idcols=2;

	/*std::cout << "������� ����� �����: "; cin >> idrows;
	cout << "������� ����� ��������: "; cin >> idcols;*/


	/*std::cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;*/

	int** arr = allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "\n-----------------------------------------\n";

	cout << "��������� �������� � ������ �� ���������� ������� " << endl;
	insert(arr, idrows, idcols);
	Print(arr, rows, cols);

	cout << "\n-----------------------------------------\n";
	cout << "��������� ������ � ����� ���������� ������������� �������" << endl;
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);
		
	cout << "\n-----------------------------------------\n";
	
	cout << "��������� ������ � ������ ���������� ������������� �������" << endl;
	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 500);
	
	Print(arr, rows, cols);
	
	cout << "\n-----------------------------------------\n";

	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		arr[i][cols - 1] = rand();
	}
	Print(arr, rows, cols);


	clear(arr, rows);
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}

int** push_row_front(int** arr, int& rows, const int cols) 
{
	
	int** buffer = new int* [rows + 1]{};
	
	for (int i = 1; i < rows+1; i++)buffer[i] = arr[i-1];
	delete[] arr;
	buffer[0] = new int[cols] {}; // ������� ����� ��������� ������
	rows++;
	return buffer;
}



void insert(int** arr, int& idrows, int& idcols)
{
	arr[idrows][idcols] = rand () % 100;
	cout <<"[" << idrows << "," << idcols << "] = " << arr[idrows][idcols] << endl;
}


int** allocate(const int rows, const int cols)
{
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int [cols] {};
	}
	return arr;
}
void clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void FillRand(int* arr, const int n, int minRand, int maxRand)
{
	//��������� � ��������� ������������� �������:
	for (int i = 0; i < n; i++)
	{
		//����� ���������� ���������� � �������� �������������:
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; cout << arr[i++] << "\t");
	//{
	//	//����� �������� ��������������:
	//	//cout << arr[i] << "\t";
	//	//�������� �������������� ���������� �������� �� �������.
	//}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int* push_back(int arr[], int& n, int value)
{
	//1) ������� �������� ������ ������� �������
	int* buffer = new int[n + 1]{};
	//2) �������� ���������� ��������� ������� � ����� (��������) ������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ����� ���� ��� ������ �����������, �������� ������ ����� �������
	delete[] arr;
	//4) ��������� ����� ������� ������� ������� ������ �������:
	arr = buffer;
	//5) ������ ����� ����� � ������� 'arr' ���������� ��� ���� �������, 
	//	 � ������� ����� ��������� ����������� ��������
	arr[n] = value;
	//6) ����� ���� ��� � ������� �������� ��� ���� �������, ���������� ��� ��������� 
	//	 ����������� �� 1
	n++;
	//Print(arr, n);
	return arr;
	//						Mission complete.
}

int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}


void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}