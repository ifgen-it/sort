#include <iostream>

using namespace std;
void ArPrint(int* Ar, int N);

void MergeSort(int* Ar, int lo, int hi);
void Merge(int* Ar, int lo, int Split, int hi);

int main(){

	const int N = 10;
	int Ar[N] = { 3, 7, -8, 2, 4, 6, 1, 5, 3, 1 };
	cout << "Original array:" << endl;
	ArPrint(Ar, N);

	MergeSort(Ar, 0, N - 1);
	cout << "Sorted array:" << endl;
	ArPrint(Ar, N);
	getchar();
	return 0;
}

void MergeSort(int* Ar, int lo, int hi){
	if (lo < hi){
		int Split = (lo + hi) / 2;
		MergeSort(Ar, lo, Split);
		MergeSort(Ar, Split + 1, hi);
		Merge(Ar, lo, Split, hi);
	}

}
void Merge(int* Ar, int lo, int Split, int hi){
	int* temp = new int[hi - lo + 1];

	int p1 = lo;			// начальная позиция для чтения левой части массива
	int p2 = Split + 1;		// начальная позиция для чтения правой части массива
	int p3 = 0;				// начальная позиция для записи динамического массива

	// пошли слияние
	while (p1 <= Split && p2 <= hi)	
	{
		if (Ar[p1] < Ar[p2]){
			temp[p3++] = Ar[p1++];
		}
		else
		{
			temp[p3++] = Ar[p2++];
		}
	}
	// дописываем оставшиеся элементы из левой части
	while (p1 <= Split)
	{
		temp[p3++] = Ar[p1++];
	}
	// дописываем оставшиеся элементы из правой части
	while (p2 <= hi)
	{
		temp[p3++] = Ar[p2++];
	}
	// копируем элементы из динамического массива в простой массив
	for (int i = 0; i < p3; i++){
		Ar[lo + i] = temp[i];
	}
	// очищаем память от динамического массива
	delete[] temp;
}



void ArPrint(int* Ar, int N){
	for (int i = 0; i < N; i++){
		cout << Ar[i] << " ";
	}
	cout << endl;

}
