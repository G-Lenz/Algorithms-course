/*************************************************************************
 * Name: George Lenz
 * Date: 7/1/2018
 * Description: merge sort implementation on a file named data.txt
 * **********************************************************************/
#include <iostream>
#include <fstream>
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
    //create input and output files and open input file
    ifstream file;
    ofstream oFile("merge.out");
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

    //run merge sort on array
    mergeSort(array, 0, size-1);
    
    //output array contents to output file
    for(int i = 0; i<size; i++)
    {
        oFile << array[i] << " ";
    }

    //close output file
    oFile.close();
    return 0;
}

    
