using namespace std;
#include <iostream>
#include <time.h>


double FindMax(double arr[],const int size) {
	double max = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}


double FindMin(double arr[],const int size) {
	double min = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}


double FindAvg(double arr[], const int size) {
	double sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum / size;
}

double Action(double A[], double B[], const int size, double(*operation)(double[], const int))
{
	double resultA = operation(A, size);
	double resultB = operation(B, size);

	cout << "Result arr A: " << resultA << endl;
	cout << "Result arr B: " << resultB << endl;


	return resultA;
}

int main()
{
	srand(time(0));
	const int SIZE = 10;
	double A[SIZE]{ 2,3,4,6,8,9,11,4,12,-2 };
	double B[SIZE]{7,4,3,7,2,6,8,1,-2.7,32};

	double (*operation[])(double[], const int) = {FindMax ,FindMin ,FindAvg};

	int op;
	do {
		cout << "Select operation:\n";
		cout << "0: Find maximum\n";
		cout << "1: Find minimum\n";
		cout << "2: Find the average\n";
		cout << "3: End program\n";
		cout << "Your choice: ";
		cin >> op;

		if (op >= 0 && op <= 2)
		{
			Action(A, B, SIZE, operation[op]);
		}
		else if (op == 3) 
		{
			cout << "Exit" << endl;
		}
		else
		{
			cout << "Wrong choice! Try again.\n";
		}

		cout << endl; 
	} while (op != 3);
	
}
/*
Написать программу, которая содержит функцию Action, принимающую в качестве
аргумента, указатели на два массива(А и В) и размеры массивов, а также
указатель на функцию.
Пользователю отображается меню, в котором он может выбрать max, min, avg.


выбран max  — передается указатель на функцию, которая ищет максимум, если
выбран min  — передается указатель на функцию, которая ищет минимум, если
выбран avg — передается указатель на функцию, которая ищет среднее.
Возвращаемое значение функции Action результат выбора пользователя max, min,
avg*/