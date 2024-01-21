#include <iostream>
using namespace std;
int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return GCD(b, a % b);
    }
}
int LCM(int a, int b)
{
    return a / GCD(a, b) * b;
}

int main()
{
    cout << GCD(15, 9) << endl;
    cout << GCD(50780, 320) << endl;
    cout << LCM(30, 6) << endl;
    cout << LCM(35630, 610) << endl;
}

