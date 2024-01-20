
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quickSortContext(vector<int>& arr, int startIndex, int finishIndex)
{
    if (finishIndex - startIndex <= 1)
    {
        return;
    }
    int pivot = (startIndex + finishIndex) / 2;
    swap(arr[startIndex], arr[pivot]);
    int loverHalfIndex = startIndex;
    int higherHalfIndex = startIndex;
    for (int i = startIndex+1; i < finishIndex; i++)
    {
        if (pivot <= arr[i])
        {
            higherHalfIndex++;
        }
        else
        {
            swap(arr[loverHalfIndex + 1], arr[i]);
            higherHalfIndex++;
            loverHalfIndex++;
        }
    }
    swap(arr[startIndex], arr[loverHalfIndex]);
    quickSortContext(arr, startIndex, loverHalfIndex);
    quickSortContext(arr, loverHalfIndex+1, finishIndex);
    return;
}
void quickSort(vector<int>& arr)
{
    quickSortContext(arr, 0, arr.size());
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
    
    quickSort(unsorted);

    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << unsorted[i] << " ";
    }
    cout << (unsorted == sorted);
}

