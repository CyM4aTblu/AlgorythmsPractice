#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(vector<int>& arr) //O(n^2) / in-place
{
    for (int i = 1; i < arr.size(); i++)
    {
        int currentPositionOfMovingNum = i;
        while (currentPositionOfMovingNum > 0 && arr[currentPositionOfMovingNum - 1] > arr[currentPositionOfMovingNum])
        {
            swap(arr[currentPositionOfMovingNum - 1], arr[currentPositionOfMovingNum]);
            currentPositionOfMovingNum--;
        }
    }
}

int main()
{
    int lengthOfArray = 1000;
    int maxElemInArray = 1000;
    vector<int> unsorted;

    for (int i = 0; i < lengthOfArray; i++)
    {
        unsorted.push_back(rand() % maxElemInArray);
    }
    
    vector<int> sorted = unsorted;
    sort(sorted.begin(), sorted.end());
    
	
    insertionSort(unsorted);
 

    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << unsorted[i] << " ";
    }
    cout << (unsorted == sorted);
}

