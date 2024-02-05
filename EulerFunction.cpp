#include <vector>
#include <iostream>
using namespace std;
int comprime_numbers_count_fast(int n) //O(sqrt(n))
{
    int result = n;
    int prime = 2;
    while (n >= prime * prime)
    {
        if (n % prime == 0)
        {
            result = result / prime * (prime - 1);
            while (n % prime == 0)
            {
                n /= prime;
            }
        }
        prime++;
    }
    if (n != 1)
    {
        result = result / n * (n - 1);
    }
    return result;
}

int gcd(int a, int b)
{
    return (a % b) ? b : gcd(b, b % a);
}

int comprime_numbers_count_gcd(int& n) //O(n*Log(n))
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (gcd(i, n) == 1)
        {
            count++;
        }
    }
    return count;
}


int main()
{
    cout << comprime_numbers_count_fast(6) << endl;
    cout << comprime_numbers_count_fast(9) << endl;
    cout << comprime_numbers_count_fast(36) << endl;
    cout << comprime_numbers_count_fast(84) << endl;
}