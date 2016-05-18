/** 
	Kevin SUY 
	Main utilisant les différents algorithmes de tri et faisant une moyenne sur 10 execution de chaque tri avec les différentes tailles de tableau
**/

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "Sort.h"

#define INT_MAX 1000


using namespace std;

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

void initTable(int * table, unsigned n)
{
	srand((unsigned)time(0));

	for (int i = 0; i < n; i++)
	{
		table[i] = (rand() % INT_MAX) + 1;
	}
}

void sortArray(int * table, int n)
{
	Sort::heap_sort(table, n);
}

void sortAndReverse(int * table, int n)
{
	Sort::heap_sort(table, n);
	int temp;
	for (int i = 0; i < (n / 2); i++)
	{
		temp = table[i];
		table[i] = table[(n - 1) - i];
		table[(n - 1) - i] = temp;
	}
}

void bubbleExecutionTime(int * table, unsigned n)
{
	std::clock_t start;
	double duration = 0;

	for (int i = 0; i < 10; i++)
	{
		int * temp;
		temp = new int[n];
		memcpy(temp, table, n);

		start = clock();

		Sort::bubble_sort(temp, n);

		duration += (clock() - start) / ((double)CLOCKS_PER_SEC / 1000);

		delete temp;
	}
	duration /= 10;

	cout << "bubble sort pour " << n << " valeur, duration :  " << duration << " millisecond" << endl;
}

void heapExecutionTime(int * table, unsigned n)
{
	std::clock_t start;
	double duration = 0;

	for (int i = 0; i < 10; i++)
	{
		int * temp;
		temp = new int[n];
		memcpy(temp, table, n);

		start = clock();

		Sort::heap_sort(temp, n);

		duration += (clock() - start) / ((double)CLOCKS_PER_SEC / 1000);

		delete temp;
	}
	duration /= 10;

	cout << "heap sort pour " << n << " valeur, duration :  " << duration << " millisecond" << endl;
}

void insertionExecutionTime(int * table, unsigned n)
{
	std::clock_t start;
	double duration = 0;

	for (int i = 0; i < 10; i++)
	{
		int * temp;
		temp = new int[n];
		memcpy(temp, table, n);

		start = clock();

		Sort::insertion_sort(temp, n);

		duration += (clock() - start) / ((double)CLOCKS_PER_SEC / 1000);

		delete temp;
	}
	duration /= 10;

	cout << "insertion sort pour " << n << " valeur, duration :  " << duration << " millisecond" << endl;
}

void mergeExecutionTime(int * table, unsigned n)
{
	//std::clock_t start;
	//double duration = 0;

	//for (int i = 0; i < 10; i++)
	//{
	//	int * temp;
	//	temp = new int[n];
	//	memcpy(temp, table, n);

	//	start = clock();

	//	Sort::merge_sort(temp, n);

	//	duration += (clock() - start) / ((double)CLOCKS_PER_SEC / 1000);

	//	delete temp;
	//}
	//duration /= 10;

	//cout << "merge sort pour " << n << " valeur, duration :  " << duration << " millisecond" << endl;
}

void radixExecutionTime(int * table, unsigned n)
{
	std::clock_t start;
	double duration = 0;

	for (int i = 0; i < 10; i++)
	{
		int * temp;
		temp = new int[n];
		memcpy(temp, table, n);

		start = clock();

		Sort::radix_sort(temp, n);

		duration += (clock() - start) / ((double)CLOCKS_PER_SEC / 1000);

		delete temp;
	}
	duration /= 10;

	cout << "merge sort pour " << n << " valeur, duration :  " << duration << " millisecond" << endl;
}

void quickExecutionTime(int * table, unsigned n)
{
	std::clock_t start;
	double duration = 0;

	for (int i = 0; i < 10; i++)
	{
		int * temp;
		temp = new int[n];
		memcpy(temp, table, n);

		start = clock();

		Sort::quick_sort(temp, 0, n-1);

		duration += (clock() - start) / ((double)CLOCKS_PER_SEC / 1000);

		delete temp;
	}
	duration /= 10;

	cout << "quick sort pour " << n << " valeur, duration :  " << duration << " millisecond" << endl;
}

void quickRandExecutionTime(int * table, unsigned n)
{
	std::clock_t start;
	double duration = 0;

	for (int i = 0; i < 10; i++)
	{
		int * temp;
		temp = new int[n];
		memcpy(temp, table, n);

		start = clock();

		Sort::quick_sort_rand(temp, n);

		duration += (clock() - start) / ((double)CLOCKS_PER_SEC / 1000);

		delete temp;
	}
	duration /= 10;

	cout << "quick sort rand pour " << n << " valeur, duration :  " << duration << " millisecond" << endl;
}

void stdSortExecutionTime(int * table, unsigned n)
{
	std::clock_t start;
	double duration = 0;

	for (int i = 0; i < 10; i++)
	{
		int * temp;
		temp = new int[n];
		memcpy(temp, table, n);

		start = clock();

		std::sort(&temp[0], &temp[n-1]);

		duration += (clock() - start) / ((double)CLOCKS_PER_SEC / 1000);

		delete temp;
	}
	duration /= 10;

	cout << "std::sort pour " << n << " valeur, duration :  " << duration << " millisecond" << endl;
}

void stdSortHeapExecutionTime(int * table, unsigned n)
{
	std::clock_t start;
	double duration = 0;

	for (int i = 0; i < 10; i++)
	{
		int * temp;
		temp = new int[n];
		memcpy(temp, table, n);

		start = clock();

		std::make_heap(temp, temp+n);
		std::sort_heap(temp, temp+n);

		duration += (clock() - start) / ((double)CLOCKS_PER_SEC / 1000);

		delete temp;
	}
	duration /= 10;

	cout << "std::sort_heap pour " << n << " valeur, duration :  " << duration << " millisecond" << endl;
}

void stdStableSortExecutionTime(int * table, unsigned n)
{
	std::clock_t start;
	double duration = 0;

	for (int i = 0; i < 10; i++)
	{
		int * temp;
		temp = new int[n];
		memcpy(temp, table, n);

		start = clock();

		std::stable_sort(&temp[0], &temp[n - 1]);

		duration += (clock() - start) / ((double)CLOCKS_PER_SEC / 1000);

		delete temp;
	}
	duration /= 10;

	cout << "std::stable_sort pour " << n << " valeur, duration :  " << duration << " millisecond" << endl;
}

int main()
{
	unsigned n = 100;
	int *tableN;
	int *table2N;
	int *table3N;
	int *table5N;
	int *table7N;
	int *table10N;
	int *table100N;
	int *table10NSort;
	int *table100NSort;
	int *table10NInvert;
	int *table100NInvert;

	tableN = new int[n];
	table2N = new int[2 * n];
	table3N = new int[3 * n];
	table5N = new int[5 * n];
	table7N = new int[7 * n];
	table10N = new int[10 * n];
	table100N = new int[100 * n];
	table10NSort = new int[10 * n];
	table100NSort = new int[100 * n];
	table10NInvert = new int[10 * n];
	table100NInvert = new int[100 * n];

	initTable(tableN, n);
	initTable(table2N, 2 * n);
	initTable(table3N, 3 * n);
	initTable(table5N, 5 * n);
	initTable(table7N, 7 * n);
	initTable(table10N, 10 * n);
	initTable(table100N, 100 * n);
	initTable(table10NSort, 10 * n);
	initTable(table100NSort, 100 * n);
	initTable(table10NInvert, 10 * n);
	initTable(table100NInvert, 100 * n);

	sortArray(table10NSort, 10 * n);
	sortArray(table100NSort, 100 * n);

	sortAndReverse(table10NInvert, 10 * n);
	sortAndReverse(table100NInvert, 100 * n);

	mergeExecutionTime(tableN, n);
	mergeExecutionTime(table2N, 2 * n);
	mergeExecutionTime(table3N, 3 * n);
	mergeExecutionTime(table5N, 5 * n);
	mergeExecutionTime(table7N, 7 * n);
	mergeExecutionTime(table10N, 10 * n);
	mergeExecutionTime(table100N, 100 * n);
	mergeExecutionTime(table10NSort, 10 * n);
	mergeExecutionTime(table100NSort, 100 * n);
	mergeExecutionTime(table10NInvert, 10 * n);
	mergeExecutionTime(table100NInvert, 100 * n);


	bubbleExecutionTime(tableN, n);
	bubbleExecutionTime(table2N, 2 * n);
	bubbleExecutionTime(table3N, 3 * n);
	bubbleExecutionTime(table5N, 5 * n);
	bubbleExecutionTime(table7N, 7 * n);
	bubbleExecutionTime(table10N, 10 * n);
	bubbleExecutionTime(table100N, 100 * n);
	bubbleExecutionTime(table10NSort, 10 * n);
	bubbleExecutionTime(table100NSort, 100 * n);
	bubbleExecutionTime(table10NInvert, 10 * n);
	bubbleExecutionTime(table100NInvert, 100 * n);

	quickExecutionTime(tableN, n);
	quickExecutionTime(table2N, 2 * n);
	quickExecutionTime(table3N, 3 * n);
	quickExecutionTime(table5N, 5 * n);
	quickExecutionTime(table7N, 7 * n);
	quickExecutionTime(table10N, 10 * n);
	quickExecutionTime(table10NSort, 10 * n);
	quickExecutionTime(table10NInvert, 10 * n);

	quickRandExecutionTime(tableN, n);
	quickRandExecutionTime(table2N, 2 * n);
	quickRandExecutionTime(table3N, 3 * n);
	quickRandExecutionTime(table5N, 5 * n);
	quickRandExecutionTime(table7N, 7 * n);
	quickRandExecutionTime(table10N, 10 * n);
	quickRandExecutionTime(table100N, 100 * n);
	quickRandExecutionTime(table10NSort, 10 * n);
	quickRandExecutionTime(table100NSort, 100 * n);
	quickRandExecutionTime(table10NInvert, 10 * n);
	quickRandExecutionTime(table100NInvert, 100 * n);

	insertionExecutionTime(tableN, n);
	insertionExecutionTime(table2N, 2 * n);
	insertionExecutionTime(table3N, 3 * n);
	insertionExecutionTime(table5N, 5 * n);
	insertionExecutionTime(table7N, 7 * n);
	insertionExecutionTime(table10N, 10 * n);
	insertionExecutionTime(table100N, 100 * n);
	insertionExecutionTime(table10NSort, 10 * n);
	insertionExecutionTime(table100NSort, 100 * n);
	insertionExecutionTime(table10NInvert, 10 * n);
	insertionExecutionTime(table100NInvert, 100 * n);

	heapExecutionTime(tableN, n);
	heapExecutionTime(table2N, 2 * n);
	heapExecutionTime(table3N, 3 * n);
	heapExecutionTime(table5N, 5 * n);
	heapExecutionTime(table7N, 7 * n);
	heapExecutionTime(table10N, 10 * n);
	heapExecutionTime(table100N, 100 * n);
	heapExecutionTime(table10NSort, 10 * n);
	heapExecutionTime(table100NSort, 100 * n);
	heapExecutionTime(table10NInvert, 10 * n);
	heapExecutionTime(table100NInvert, 100 * n);

	stdSortExecutionTime(tableN, n);
	stdSortExecutionTime(table2N, 2 * n);
	stdSortExecutionTime(table3N, 3 * n);
	stdSortExecutionTime(table5N, 5 * n);
	stdSortExecutionTime(table7N, 7 * n);
	stdSortExecutionTime(table10N, 10 * n);
	stdSortExecutionTime(table100N, 100 * n);
	stdSortExecutionTime(table10NSort, 10 * n);
	stdSortExecutionTime(table100NSort, 100 * n);
	stdSortExecutionTime(table10NInvert, 10 * n);
	stdSortExecutionTime(table100NInvert, 100 * n);

	stdStableSortExecutionTime(tableN, n);
	stdStableSortExecutionTime(table2N, 2 * n);
	stdStableSortExecutionTime(table3N, 3 * n);
	stdStableSortExecutionTime(table5N, 5 * n);
	stdStableSortExecutionTime(table7N, 7 * n);
	stdStableSortExecutionTime(table10N, 10 * n);
	stdStableSortExecutionTime(table100N, 100 * n);
	stdStableSortExecutionTime(table10NSort, 10 * n);
	stdStableSortExecutionTime(table100NSort, 100 * n);
	stdStableSortExecutionTime(table10NInvert, 10 * n);
	stdStableSortExecutionTime(table100NInvert, 100 * n);


	radixExecutionTime(tableN, n);
	radixExecutionTime(table2N, 2 * n);
	radixExecutionTime(table3N, 3 * n);
	radixExecutionTime(table5N, 5 * n);
	radixExecutionTime(table7N, 7 * n);
	radixExecutionTime(table10N, 10 * n);
	radixExecutionTime(table100N, 100 * n);
	radixExecutionTime(table10NSort, 10 * n);
	radixExecutionTime(table100NSort, 100 * n);
	radixExecutionTime(table10NInvert, 10 * n);
	radixExecutionTime(table100NInvert, 100 * n);

	
	stdSortHeapExecutionTime(tableN, n);
	stdSortHeapExecutionTime(table2N, 2 * n);
	stdSortHeapExecutionTime(table3N, 3 * n);
	stdSortHeapExecutionTime(table5N, 5 * n);
	stdSortHeapExecutionTime(table7N, 7 * n);
	stdSortHeapExecutionTime(table10N, 10 * n);
	stdSortHeapExecutionTime(table100N, 100 * n);
	stdSortHeapExecutionTime(table10NSort, 10 * n);
	stdSortHeapExecutionTime(table100NSort, 100 * n);
	stdSortHeapExecutionTime(table10NInvert, 10 * n);
	stdSortHeapExecutionTime(table100NInvert, 100 * n);
	

	delete tableN;
	delete table2N;
	delete table3N;
	delete table5N;
	delete table7N;
	delete table10N;
	delete table100N;
	delete table10NSort;
	delete table100NSort;
	delete table10NInvert;
	delete table100NInvert;

	return 0;
}