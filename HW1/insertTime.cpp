/*************************************************************************
 * Name: George Lenz
 * Date: 7/1/2018
 * Description: Insertion sort time analysis
 * **********************************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

//Insertion sort algorithm
void insertionSort(int* array, int size)
{
    int i=0;
    for(int j=1; j<size; j++)
    {
        int key = array[j];
        i = j - 1;
        while(i >= 0 && array[i] > key)
        {
            array[i+1] = array[i];
            i = i - 1;
        }
        array[i+1] = key;
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
    insertionSort(array, arraySize);
    t = clock() - t;
    
    cout <<  "Insert Sort took " << t << " clock cycles." << endl;
    f = static_cast<float>(t)/CLOCKS_PER_SEC;
    cout << "In seconds that is " << f << " seconds." << endl;
   
    return 0;
}

    
