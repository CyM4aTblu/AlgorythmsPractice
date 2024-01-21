#include <vector>
#include <iostream>
using namespace std;
int binSearchContext(vector<int>& array,  int searchable, int leftBorder, int rightBorder)
{
    int middle = (leftBorder + rightBorder) / 2;
    if (middle == searchable)
    {
        return middle;
    }
    else if (leftBorder == rightBorder)
    {
        return -1;
    }
    else if (middle < searchable)
    {
        return binSearchContext(array, searchable, middle, rightBorder);
    }
    else
    {
        return binSearchContext(array, searchable, leftBorder, middle);
    }
}
int binSearch(vector<int>& array, int searchable)
{
    return binSearchContext(array, searchable, 0, array.size());
}


int main()
{
    vector<int> arr;
    int size = 100;
    for (int i = 0; i < size; i++)
    {
        arr.push_back(i);
    }
    cout << binSearch(arr, 49) << " ";
    cout << binSearch(arr, 42) << " ";
    cout << binSearch(arr, 99) << " ";
    cout << binSearch(arr, 0) << " ";
}
