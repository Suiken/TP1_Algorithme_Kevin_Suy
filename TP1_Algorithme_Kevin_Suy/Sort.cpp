/** 
	Kevin SUY 
	Classe Sort implémentant les différents algorithmes de tri
**/

#include <random>
#include <ctime>
#include <cstdlib>

#include "Sort.h"
int pivot(int a[], int first, int last);
void swap(int& a, int& b);
void swap_no_temp(int& a, int& b);

Sort::Sort()
{

}

/** Quick Sort **/
void Sort::quick_sort( int a[], int first, int last ) 
{
    int pivot_element;
 
    if(first < last)
    {
        pivot_element = pivot(a, first, last);
        quick_sort(a, first, pivot_element-1);
        quick_sort(a, pivot_element+1, last);
    }
}
 
int pivot(int a[], int first, int last) 
{
    int  p = first;
    int pivot_element = a[first];
 
    for(int i = first+1 ; i <= last ; i++)
    {
        /* If you want to sort the list in the other order, change "<=" to ">" */
        if(a[i] <= pivot_element)
        {
            p++;
            swap(a[i], a[p]);
        }
    }
 
    swap(a[p], a[first]);
 
    return p;
}
 
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
 
void swap_no_temp(int& a, int& b)
{
    a -= b;
    b += a;// b gets the original value of a
    a = (b - a);// a gets the original value of b
}
/****************/

/** Quick Sort Rand **/
void Sort::quick_sort_rand(int *random_array, unsigned len, int MAX)
{
	srand(time(NULL));

	unsigned left = 0, pos = 0, seed = rand();
	unsigned *stack;
	stack = new unsigned[MAX];
	for (; ; ) {                                           /* outer loop */
		for (; left + 1 < len; len++) {                /* sort left to len-1 */
			if (pos == MAX) len = stack[pos = 0];  /* stack overflow, reset */
			int pivot = random_array[left + seed % (len - left)];  /* pick random pivot */
			seed = seed * 69069 + 1;                /* next pseudorandom number */
			stack[pos++] = len;                    /* sort right part later */
			for (unsigned right = left - 1; ; ) { /* inner loop: partitioning */
				while (random_array[++right] < pivot);  /* look for greater element */
				while (pivot < random_array[--len]);    /* look for smaller element */
				if (right >= len) break;           /* partition point found? */
				int temp = random_array[right];
				random_array[right] = random_array[len];                  /* the only swap */
				random_array[len] = temp;
			}                            /* partitioned, continue left part */
		}
		if (pos == 0) break;                               /* stack empty? */
		left = len;                             /* left to right is sorted */
		len = stack[--pos];                      /* get next range to sort */
	}
}
/*********************/

/** Insertion Sort **/
void Sort::insertion_sort(int *random_array, int n)
{
	int i, j;
	int elementInsere;

	for (i = 1; i < n; i++) {
		/* Stockage de la valeur en i */
		elementInsere = random_array[i];
		/* Décale les éléments situés avant t[i] vers la droite
		jusqu'à trouver la position d'insertion */
		for (j = i; j > 0 && random_array[j - 1] > elementInsere; j--) {
			random_array[j] = random_array[j - 1];
		}
		/* Insertion de la valeur stockée à la place vacante */
		random_array[j] = elementInsere;
	}
}
/********************/

/** Bubble Sort **/
void Sort::bubble_sort(int *random_array, int size)
{
	bool en_desordre = true;
	for (int i = 0; i < size && en_desordre; ++i)
	{
		en_desordre = false;
		for (int j = 1; j < size - i; ++j)
			if (random_array[j - 1] > random_array[j])
			{
				swap(random_array[j], random_array[j - 1]);
				en_desordre = true;
			}
	}
}
/*****************/

/** Merge Sort **/
void fusion(int random_array[], int debut1, int fin1, const int fin2)
{
	int *tableau2;
	int debut2 = fin1 + 1;
	int compteur1 = debut1;
	int compteur2 = debut2;
	int i;

	tableau2 = new int[fin1 - debut1 + 1];

	// copie des éléments du début de tableau
	for (i = debut1; i <= fin1; i++)
		tableau2[i - debut1] = random_array[i];

	// fusion des deux tableaux
	for (i = debut1; i <= fin2; i++)
	{
		if (compteur1 == debut2) // éléments du 1er tableau tous utilisés
			break; // éléments tous classés
		else if (compteur2 == (fin2 + 1)) // éléments du 2nd tableau tous utilisés
		{ // copie en fin de tableau des éléments du 1er sous tableau
			random_array[i] = tableau2[compteur1 - debut1];
			compteur1++;
		}
		else if (tableau2[compteur1 - debut1] < random_array[compteur2])
		{ // ajout d'1 élément du 1er sous tableau
			random_array[i] = tableau2[compteur1 - debut1];
			compteur1++; // on avance ds le 1er sous tableau
		}
		else
		{ // copie de l'élément à la suite du tableau
			random_array[i] = random_array[compteur2];
			compteur2++; // on avance ds le 2nd sous tableau
		}
	}
	delete tableau2;
}

void triFusionAux(int tableau[], const int debut, const int fin)
{
	if (debut != fin) // condition d'arrêt
	{
		int milieu = (debut + fin) / 2;
		triFusionAux(tableau, debut, milieu); // trie partie1
		triFusionAux(tableau, milieu + 1, fin); // trie partie2
		fusion(tableau, debut, milieu, fin); // fusion des deux parties
	}
}

void merge_sort(int tableau[], int longueur)
{
	if (longueur > 0)
		triFusionAux(tableau, 0, longueur - 1);
}
/****************/

/** Heap Sort **/
void Sort::heap_sort(int *random_array, unsigned int N)
{
	if (N == 0) // check if heap is empty
		return;

	int t; /* the temporary value */
	unsigned int n = N, parent = N / 2, index, child; /* heap indexes */
													  /* loop until array is sorted */
	while (1) {
		if (parent > 0) {
			/* first stage - Sorting the heap */
			t = random_array[--parent];  /* save old value to t */
		}
		else {
			/* second stage - Extracting elements in-place */
			n--;                /* make the heap smaller */
			if (n == 0) {
				return; /* When the heap is empty, we are done */
			}
			t = random_array[n];         /* save lost heap entry to temporary */
			random_array[n] = random_array[0];    /* save root entry beyond heap */
		}
		/* insert operation - pushing t down the heap to replace the parent */
		index = parent; /* start at the parent index */
		child = index * 2 + 1; /* get its left child index */
		while (child < n) {
			/* choose the largest child */
			if (child + 1 < n  &&  random_array[child + 1] > random_array[child]) {
				child++; /* right child exists and is bigger */
			}
			/* is the largest child larger than the entry? */
			if (random_array[child] > t) {
				random_array[index] = random_array[child]; /* overwrite entry with child */
				index = child; /* move index to the child */
				child = index * 2 + 1; /* get the left child and go around again */
			}
			else {
				break; /* t's place is found */
			}
		}
		/* store the temporary value at its new location */
		random_array[index] = t;
	}
}
/***************/


void Sort::radix_sort(int *random_array, int length)
{
	vector < vector <int> > buckets;
	buckets.resize(length);
    int temp;
    int m=0;
    //Begin Radix Sort
    for(int i=0;i<7;i++){
    	//Determine which bucket each element should enter
    	for(int j=0;j<length;j++){
    		temp=(int)((random_array[j])/pow(10,i))%10;
    		buckets[temp].push_back((random_array[j]));
    	}
    	//Transfer results of buckets back into main array
    	for(int k=0;k<10;k++){
    		for(int l=0;l<buckets[k].size();l++){
                random_array[m]=buckets[k][l];
    			m++;
    		}
    		//Clear previous bucket
    		buckets[k].clear();
    	}
    	m=0;
    }
    buckets.clear();

}

Sort::~Sort()
{
}
