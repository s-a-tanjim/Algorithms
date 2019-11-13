/*
Merge Sort is a Divide and Conquer algorithm.
It divides input array in two halves, calls itself for the two halves
and then merges the two sorted halves.
The Merge() function is used for merging two halves.
The Merge(arr, start, mid, end) is key process that assumes that arr[start..mid] and arr[mid+1..end]
are sorted and merges the two sorted sub-arrays into one.

Properties:
-Time Complexity: O(nLog n)
-Space Complexity: O(n) (Not InPlace)
-Algorithmic Paradigm: Divide and Conquer
-Sorting In Place: No in a typical implementation
-Stable: Yes
*/

#include <iostream>

template <typename T>
void Merge(T arr[], int start, int mid, int end)
{
  int i, j, k;
  int n1 = mid - start + 1;
  int n2 = end - mid;

  T *leftArray, *rightArray;
  leftArray = new T[n1];
  rightArray = new T[n2];

  // Copy arr[] into left and right array to perform merge sort
  for (i = 0; i < n1; i++)
    leftArray[i] = arr[start + i];
  for (i = 0; i < n2; i++)
    rightArray[i] = arr[mid + 1 + i];

  /* Merge the temp arrays back into arr[l..r]*/
  i = 0;     // Initial index of first subarray (leftArray)
  j = 0;     // Initial index of second subarray (rightArray)
  k = start; // Initial index of merged subarray

  // Copying sorted data to main array (arr)
  while (i < n1 && j < n2)
  {
    if (leftArray[i] <= rightArray[j])
    {
      arr[k] = leftArray[i];
      i++;
    }
    else
    {
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }

  // Copying remaining sorted data(if any) from leftArray to main array (arr)
  while (i < n1)
  {
    arr[k] = leftArray[i];
    i++;
    k++;
  }

  // Copying remaining sorted data(if any) from rightArray to main array (arr)
  while (j < n2)
  {
    arr[k] = rightArray[j];
    j++;
    k++;
  }
  delete[] leftArray;
  delete[] rightArray;
}

template <typename T>
void mergeSort(T arr[], int start, int end)
{
  if (start < end)
  {
    int mid = start + (end - start) / 2;
    mergeSort<T>(arr, start, mid);
    mergeSort<T>(arr, mid + 1, end);

    Merge<T>(arr, start, mid, end);
  }
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
  int arr2[] = {12, 11, 13, 5, 6, 7, 100, 232};
  char arr3[] = {'s', 'd', 'g', 'r', 'j', 'o', 'p', 't'};
  std::string arr[] = {"ddd", "aaac", "bbb", "aaas"};

  int arr_size = sizeof(arr) / sizeof(arr[0]);

  std::cout << "Given array is \n";
  printArray<std::string>(arr, arr_size);

  mergeSort<std::string>(arr, 0, arr_size - 1);

  std::cout << "\nSorted array is \n";
  printArray<std::string>(arr, arr_size);

  return 0;
}
