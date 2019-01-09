/*************************************************************************
 * Name: George Lenz
 * Date: 7/1/2018
 * Description: Insertion sort time analysis
 * **********************************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

//Insertion sort algorithm
void stoogeSort(int* array, int start, int end)
{
    double size = end - start + 1.0;
    if(size==2 && array[start] > array[end])
    {
        int temp = array [start];
        array[start] = array[end];
        array[end] = temp;
        return;
      
    }
    else if (size > 2)
    {
        double m = size/3;
        m = ceil(m);
        int mid = static_cast<int>(m); 
        stoogeSort(array, start, end-mid);
        stoogeSort(array, start+mid, end);
        stoogeSort(array, start, end-mid);
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

    //run insertion sort on array and calculate time.
    t = clock();
    stoogeSort(array, 0, arraySize-1);
    t = clock() - t;
    
    cout <<  "Insert Sort took " << t << " clock cycles." << endl;
    f = static_cast<float>(t)/CLOCKS_PER_SEC;
    cout << "In seconds that is " << f << " seconds." << endl;
   
    return 0;
}

    
