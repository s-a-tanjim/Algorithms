/*
Counting sort is a sorting technique based on keys between a specific range.
Others sorting algorithms (i.e merge sort, quick sort) are comparison based sort.

Limitations of Counting sort:
-Can't sort negative integers. (but if we change some code, we can sort negative integers)
-Should use only for positive integers and characters.
-Cant apply for scattered data in a array (i.e: 1,500,9999,14777)

Properties:
-Time Complexity: O(n+k) [n=number of elements, k=range of input]
-Auxiliary Space: O(n+k)
-Stable: Yes (for this code)

Stability:
-A sorting algorithm is said to be stable if it maintains the relative order
-of records in the case of equality of keys.
-example:
-Assume an unsorted array: 7,5,5,2
                             | |
-After sorting the array : 2,5,5,7
-Those two 5 will not change their position in stable sorted method
*/
#include<iostream>

template<typename T>
void countSort(T *arr,int size){
    // Finding maximum value from the array
    int max=(int)arr[0];
    for(int i=1;i<size;i++)
        if(arr[i]>max)
            max=arr[i];

    // Create a Count array to store count of individual
    int *Count=new int[max+1];

    // Initialize Count array as 0
    for(int i=0;i<=max;i++)
        Count[i]=0;

    // Store count of each element
    for(int i=0;i<size;i++)
        Count[arr[i]]++;

    // Change Count[i] so that Count[i] now contains actual
    // position of this character in output array
    for(int i=1;i<=max;i++)
        Count[i]=Count[i]+Count[i-1];

    // Create temp array to store sorted data
    T *temp=new T[size];


    // Build the sorted array
    // The reason of starting the loop from last element (size-1) is to make
    // the sorting process stable. You can see details about stability above.
    for(int i=size-1;i>=0;i--)
    {
        int x=--Count[arr[i]];
        temp[x]=arr[i];
    }

    // Copy the sorted array(temp) to main array(arr)
    for(int i=0;i<size;i++)
        arr[i]=temp[i];

    delete []temp;
}

template<typename T>
void printArray(T A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        std::cout<<A[i]<<"  ";
    std::cout<<"\n";
}

// Driver main function
int main(){
    int arr[]={1,0,2,1,0,1,5,9,17,8,6,45};
    char arr2[]={'t','y','e','w','s','y','x','q','w','a'};
    int sizeOfArray= sizeof(arr2)/sizeof(arr2[0]);

    printArray<char>(arr2,sizeOfArray);
    countSort<char>(arr2,sizeOfArray);
    printArray<char>(arr2,sizeOfArray);
}
