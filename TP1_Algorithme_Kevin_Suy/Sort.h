#include <iostream>

using namespace std;
class Sort
{
private:
	int *random_array;

public:
	Sort();

	static void quick_sort(int a[], int first, int last);
	static void quick_sort_rand(int *random_array, unsigned len, int MAX = 64);
	static void insertion_sort(int *random_array, int n);
	static void bubble_sort(int *random_array, int size);
	static void merge_sort(int tableau[], int longueur);
	static void heap_sort(int *random_array, unsigned int N);
	static void radix_sort(int *random_array, int n);

	~Sort();
};

