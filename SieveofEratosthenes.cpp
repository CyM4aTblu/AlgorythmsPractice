#include <vector>
#include <iostream>
using namespace std;
vector<int> sieve(int n)
{
    if (n == 1)
    {
        return {1};
    }
    vector<bool> isprime(n, true);
    vector<int> primeNumbers;
    primeNumbers.push_back(2);
    for (int i = 2; i < n; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    for (int i = 3; i < isprime.size(); i++)
    {
        if (isprime[i])
        {
            primeNumbers.push_back(i);
        }
    }
    return primeNumbers;
}
int main()
{
    vector<int> primes = sieve(200);
    for (auto prime: primes)
    {
        cout << prime << " ";
    }
}
