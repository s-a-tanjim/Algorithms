/*
QuickSort is a Divide and Conquer algorithm.
It picks an element as pivot and partitions the given array around the picked pivot.

Quick sort is one of the most efficient sorting algorithm. 
Sort function given to us by most of the language libraries are implementation of QuickSort.

Properties:
  Time Complexity: O(nLog n)
  Space Complexity: O(log n) (In Place)
  Algorithmic Paradigm: Divide and Conquer
  Stable: Yes
  Type of Quick Sort: Randomized pivot
*/

#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For srand()

// To swap two elements
template <typename T>
void swap(T *a, T *b)
{
  T temp = *a;
  *a = *b;
  *b = temp;
}

template <typename T>
int partition(T arr[], int start, int end)
{
  T pivot = arr[end]; // last element as pivot
  int i = start - 1;  // Index of smaller element

  for (int j = start; j < end; j++)
  {
    if (arr[j] <= pivot)
    {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[end]);
  return (i + 1);
}

template <typename T>
int RandomPivotPartition(T arr[], int start, int end)
{
  // Random selection of pivot.
  int pivot, n, temp;
  n = rand();
  pivot = start + n % (end - start + 1); // Randomizing the pivot value from sub-array.
  swap(&arr[end], &arr[pivot]);   // Take random pivot to the last element
  return partition<T>(arr, start, end);
}

template <typename T>
void quickSort_(T arr[], int start, int end)
{
  if (start < end)
  {
    int pivotIndex = RandomPivotPartition<T>(arr, start, end);
    quickSort_<T>(arr, start, pivotIndex - 1); // Before pivot
    quickSort_<T>(arr, pivotIndex + 1, end);   // After pivot
  }
}

// Wrapper function for quickSort_()
template <typename T>
void quickSort(T arr[], int start, int end)
{
  srand(time(NULL));
  quickSort_<T>(arr, start, end);
}

//To test the array
template <typename T>
void printArray(T A[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    std::cout << A[i] << "  ";
  std::cout << "\n";
}

// Test driver function
int main()
{
  int arr3[] = {12, 11, 13, 5, 6, 7, 100, 232};
  char arr2[] = {'s', 'd', 'g', 'r', 'j', 'o', 'p', 't'};
  std::string arr[] = {"ddd", "aaac", "bbb", "aaas"};

  int arr_size = sizeof(arr) / sizeof(arr[0]);

  std::cout << "Given array is \n";
  printArray(arr, arr_size);

  quickSort(arr, 0, arr_size - 1);

  std::cout << "\nSorted array is \n";
  printArray(arr, arr_size);

  return 0;
}
