
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void countingSort(vector<int>& arr)
{
    int minNumber = arr[0];
    int maxNumber = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (maxNumber < arr[i])
        {
            maxNumber = arr[i];
        }
        if (minNumber > arr[i])
        {
            minNumber = arr[i];
        }
    }
    vector<int> numbersCount(maxNumber - minNumber + 1);
    for (int i = 0; i < arr.size(); i++)
    {
        numbersCount[arr[i] - minNumber]++;
    }
    arr.clear();
    for (int i = 0; i < numbersCount.size(); i++)
    {
        while (numbersCount[i] != 0)
        {
            arr.push_back(i + minNumber);
            numbersCount[i]--;
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
    
    countingSort(unsorted);

    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << unsorted[i] << " ";
    }
    cout << (unsorted == sorted);
}

