
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void radixConquer(vector<int>& arr, vector<vector<int>>& buckets)
{
    arr.clear();
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr.push_back(buckets[i][j]);
        }
        buckets[i].clear();
    }
}
void radixSort(vector<int>& arr)
{
    vector<vector<int>> buckets(10);
    bool moreDigitsInNumsAvalible = true;
    int currDigitCount = 0;
    while (moreDigitsInNumsAvalible)
    {
        moreDigitsInNumsAvalible = false;
        for (int i = 0; i < arr.size(); i++)
        {
            int index = arr[i];
            if (currDigitCount)
            {
                index = arr[i] / (10 * currDigitCount);
            }
            if (index != 0)
            {
                moreDigitsInNumsAvalible = true;
            }
            buckets[index % 10].push_back(arr[i]);
        }
        radixConquer(arr, buckets);
        currDigitCount++;
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
    
    radixSort(unsorted);

    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << unsorted[i] << " ";
    }
    cout << (unsorted == sorted);
}

