#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void bubbleSort(vector<int>& arr)//O(n^2) / in-place
{
    for (int i = 0; i < arr.size(); i++)
    {
        bool isChanged = false;
        for (int j = 1; j < arr.size() - i; j++)
        {
            if (arr[j-1] > arr[j])
            {
                swap(arr[j-1], arr[j]);
                bool isChanged = true;
            }
        }
        if (isChanged)
        {
            return;
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
    
    bubbleSort(unsorted);


    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << unsorted[i] << " ";
    }
    cout << (unsorted == sorted);
}

