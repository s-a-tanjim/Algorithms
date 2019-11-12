/*
Radix sort is a non-comparative sorting algorithm.
It avoids comparison by creating and distributing elements into buckets according to their radix.
The idea of Radix Sort is to do digit by digit sort starting from least significant digit
to most significant digit. Radix sort uses counting sort as a subroutine to sort.

Limitations of Radix sort:
-Can't sort negative integers. (but if we change some code, we can sort negative integers)
-Should use only for positive integers and characters.

Properties:
-Time Complexity: O(n k) [n=number of elements, k=range of input]
-Auxiliary Space: O(n+k)
-Stable: Yes (for this code)

*/
#include<iostream>

template<typename T>
T getMax(T arr[], int n)
{
  T max = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}

template<typename T>
void countingSort(T *arr,int size,int position){
    const int max=10; // 0 to 9
    int Count[max];
    for(int i=0;i<max;i++)
        Count[i]=0;

    for(int i=0;i<size;i++)
        Count[(((int)arr[i])/position)%10]++;

    for(int i=1;i<=max;i++)
        Count[i]+=Count[i-1];

    T *temp=new T[size];

    for(int i=size-1;i>=0;i--)
    {
        int x=--Count[(((int)arr[i])/position)%10];
        temp[x]=arr[i];
    }

    for(int i=0;i<size;i++)
        arr[i]=temp[i];

    delete []temp;
}

template<typename T>
void radixSort(T *arr,int size){
    int max=(int)getMax<T>(arr,size);
    for(int position=1;max/position>0;position*=10)
        countingSort<T>(arr,size,position);
}

template<typename T>
void printArray(T A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        std::cout<<A[i]<<"  ";
    std::cout<<"\n";
}

int main(){
    int arr[]={1,0,2,1,0,1,5,9,17,8,6,45};
    char arr2[]={'t','y','e','w','s','y','x','q','w','a'};
    int sizeOfArray= sizeof(arr)/sizeof(arr[0]);

    printArray<int>(arr,sizeOfArray);
    radixSort<int>(arr,sizeOfArray);
    printArray<int>(arr,sizeOfArray);
}
