/*************************************************************************
 * Name: George Lenz
 * Date: 7/8/2018
 * Description: Stooge sort implementation on a file named data.txt
 * **********************************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

//Stooge sort algorithm
void stoogeSort(int* array, int start, int end)
{
    //calculate size
    double size = end - start + 1.0;
    //swap items on base case (size is 2 items)
    if(size==2 && array[start] > array[end])
    {
        int temp = array [start];
        array[start] = array[end];
        array[end] = temp;
        return;
      
    }
    else if (size > 2)
    {
        //calcualte ceiling of 1/3 point of array
        double m = size/3;
        m = ceil(m);
        int mid = static_cast<int>(m); 
        //sort first two-third of array
        stoogeSort(array, start, end-mid);
        //sort last two-third of array
        stoogeSort(array, start+mid, end);
        //sort first two-thirds of array
        stoogeSort(array, start, end-mid);
    }
}
       
    


int main()
{
    //create input and output files and open input file
    ifstream file;
    ofstream oFile("stooge.out");
    file.open("data.txt");
    
    //create input buffer x, set first input to size
    int x;
    file >> x;
    int size = x;
    //create array of size x
    int array[size];

    //fill array with items in file
    for(int i = 0; file >> x; i++)
    {
        array[i] = x;
    }
    //close input file
    file.close();

    //run stooge sort on array
    stoogeSort(array, 0, size-1);
    
    //output array contents to output file
    for(int i = 0; i<size; i++)
    {
        oFile << array[i] << " ";
    }

    //close output file
    oFile.close();
    return 0;
}

    
