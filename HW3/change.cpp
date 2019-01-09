/******************************************************************************
 * Program Name: change.cpp
 * Author: George Lenz
 * Date: 7/15/2018
 * Description: A DP algorithm to make a minimal amount of change.
 ****************************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//returns coins in minimal amount of change

int* change(vector<int> &V, int A)
{
    int vSize = V.size();
    int* minChange;
    minChange = new int [A+1]; 
    int* coins = new int [A+1];
    int* total = new int [vSize];
    
   

    minChange[0] = 0;
    coins[0] = 0;
    //initialize to number higher than highest number of change possible
    for(int i=1; i<=A; i++)
    {
        minChange[i] = A+1;
    }
    //calculate min amount of change
    for(int i=0; i<vSize; i++)
    {
        for(int j=1; j<=A;j++)
        {
            if(j>=V[i])
            {
                int minimumOfJ = 1 + minChange[j-V[i]];
                if (minimumOfJ < minChange[j]);
                {
                    minChange[j] = minimumOfJ;
                    coins[j] = i;
                    
                }
                
            }
        }
    
    }
    //fill array with number of each coin.
    int s = A;
    while( s > 0)
    {
        total[coins[s]] += 1;
        s = s - V[coins[s]];
    }
    
    
           
    return total;
              

}


int main()
{
    vector<int> V;
    ifstream iFile;
    ofstream oFile;
    iFile.open("amount.txt");
    oFile.open("change.txt");
    int num;
    //fill vector with first number
    while(iFile >> num)
    {
    oFile << num << " ";
    V.push_back(num);
    //fill vector with remaining numbers
    while(iFile.get() != '\n')
    {
        iFile >> num;
        oFile << num << " ";
        V.push_back(num);
    }
    //get amount to make change for
    iFile >> num;
    oFile << endl << num << endl;
    int amount = num;
  
    //compute minimal change
    int* answer = change(V, amount);

    //output to file
    for(int i = 0; i < V.size(); i++)
    {
            oFile << answer[i] << " ";
            
    }
        oFile << endl;
    int total = 0;
    for(int i = 0; i < V.size(); i++)
    {
        total = total + answer[i];
    }
        oFile << total;
        V.clear();
        oFile << endl;
    }
    //close files
    oFile.close();
    iFile.close();
 
    return 0;
}
                    
                       
