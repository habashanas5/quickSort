#include <iostream>
#include <string>
#pragma warning (disable: 4996)
using namespace std;

// function partition
inline int partition(int* Arr, int left, int right)
{
    int pivot = Arr[left];
    int i = left+1;
    int j = right; 

    while (1) 
    {
        while (Arr[i] <= pivot && i < right)
            i++; 
        
        while (Arr[j] >= pivot && j > left)
            j--; 

        if (i >= j)
        {
            swap(Arr[j], Arr[left]);
            return j;
        }

        else
            swap(Arr[i], Arr[j]);
    }

} 

// function quick Sorting
inline void quickSorting(int *Arr, int left, int right) 
{
    if (left < right) 
    {
        // Partition the array
        int pivot = partition(Arr, left, right);

        // Applying quick sorting algorithm on each side
        quickSorting(Arr, left, pivot-1); // Left side
        quickSorting(Arr, pivot + 1, right); // Right side
    }

} 

//function to read array 
inline void read(int* Arr, int size)
{
    cout << endl << "read an elements in the array " << endl;
    for (int k = 1; k <= size; ++k)
    {
        cout << "enter number(" << k << "): ";
        cin >> Arr[k];
    }

}

// function display array 
inline void printArray(int Arr[], int size)
{
    for (register int i = 1; i <= size; i++)
        cout << Arr[i] << "	";
}


int main()
{
    int size;
    cout <<endl<< "Enter the size of the array :";
    cin >> size;
    int* array = new int[size];
    read(array, size);
    cout << endl << endl << "sorting array using (quick Sort) " << endl;
    quickSorting(array, 0, size);
    printArray(array, size);
    cout << endl; 
}