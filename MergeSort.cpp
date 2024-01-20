
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> merge(vector<int>right, vector<int> left)
{
    vector<int> result;
    int rIndex = 0;
    int lIndex = 0;
    while (rIndex != right.size() && lIndex != left.size())
    {
        if (left[lIndex] <= right[rIndex])
        {
            result.push_back(left[lIndex]);
            lIndex++;
        }
        else
        {
            result.push_back(right[rIndex]);
            rIndex++;
        }
    }
    while (rIndex != right.size())
    {
        result.push_back(right[rIndex]);
        rIndex++;
    }
    while (lIndex != left.size())
    {
        result.push_back(left[lIndex]);
        lIndex++;
    }
    return result;
}
void mergeSort(vector<int>& arr)
{
    if (arr.size() == 1)
    {
        return;
    }
    int arrayCenter = arr.size() / 2;
    vector<int> rHalf;
    vector<int> lHalf;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i >= arrayCenter)
        {
            lHalf.push_back(arr[i]);
            continue;
        }
        rHalf.push_back(arr[i]);
    }
    mergeSort(lHalf);
    mergeSort(rHalf);

    arr = merge(lHalf, rHalf);
    return;
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
    

    mergeSort(unsorted);

    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << unsorted[i] << " ";
    }
    cout << (unsorted == sorted);
}

