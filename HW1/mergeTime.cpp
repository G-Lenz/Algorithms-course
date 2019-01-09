/*************************************************************************
 * Name: George Lenz
 * Date: 7/1/2018
 * Description: Merge sort time analysis.
 * **********************************************************************/
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;

//Merge sort algorithm
void merge(int* array, int left, int middle, int right)
{
    //get size of left and right array
    int n1 = middle - left + 1;
    int n2 = right - middle;

    //initialize arrays
    int leftArray[n1];
    int rightArray[n2];

    //fill left array with left half of original array
    for(int i = 0; i < n1; i++)
    {
        leftArray[i] = array[left + i];
    }
   
    //fill rightArray with right half of original array
    for(int j=0; j<n2; j++)
    {
        rightArray[j] = array[middle + 1 + j];
    }
    
    int i = 0;
    int j = 0;
    int k = left;

    //merge the two arrays back together in sorted order
   while(i < n1 && j < n2)
    {
        if(leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
    
}
    
void mergeSort(int* array, int left, int right)
{
    if(left < right)
    {
        int middle = (left + right) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

int main()
{
    clock_t t;
    float f;
    t = clock();
    int arraySize;
    srand(time(NULL));

     //get array size from user
    cout << "How large would you like your array to be" << endl;
    cin >> arraySize;
    int array[arraySize];

    //fill array with items
    for(int i = 0;i < arraySize; i++)
    {
        array[i] = (rand() % 1001);
    }

    //run merge sort on array and calculate time.
    t = clock();
    mergeSort(array, 0, arraySize);
    t = clock() - t;
    
    cout <<  "Insert Sort took " << t << " clock cycles." << endl;
    f = static_cast<float>(t)/CLOCKS_PER_SEC;
    cout << "In seconds that is " << f << " seconds." << endl;
   
    return 0;
}

    
