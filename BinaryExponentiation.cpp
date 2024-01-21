#include <iostream>
using namespace std;//0(log(n))
int binaryPow(int number, int power)
{
    int ans = 1;
    if (power == 0)
    {
        return ans;
    }
    if (power % 2)
    {
        ans = binaryPow(number, power - 1) * number;
    }
    else
    {
        ans = binaryPow(number, power / 2);
        ans *= ans;
    }
    return ans;
}

int main()
{
    cout << binaryPow(2, 10) << endl;
    cout << binaryPow(3, 9) << endl;
    cout << binaryPow(12, 3) << endl;
    cout << binaryPow(233, 2) << endl;
    cout << binaryPow(21, 45) << endl;
    cout << binaryPow(2, 8) << endl;
}

