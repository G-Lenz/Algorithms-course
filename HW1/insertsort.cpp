/*************************************************************************
 * Name: George Lenz
 * Date: 7/1/2018
 * Description: Insertion sort implementation on a file named data.txt
 * **********************************************************************/
#include <iostream>
#include <fstream>
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
    //create input and output files and open input file
    ifstream file;
    ofstream oFile("insert.out");
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

    //run insertion sort on array
    insertionSort(array, size);
    
    //output array contents to output file
    for(int i = 0; i<size; i++)
    {
        oFile << array[i] << " ";
    }

    //close output file
    oFile.close();
    return 0;
}

    
