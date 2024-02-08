
#include <iostream>
using namespace std;

int bin_pow(int& number, int power)
{
    if (power == 0)
    {
        return 1;
    }
    else if (power % 2 == 0)
    {
        int ans = bin_pow(number, power / 2);
        return ans * ans;
    }
    else
    {
        return bin_pow(number, power - 1) * number;
    }
}

int string_hash(string str)
{
    int hash = 0;
    int prime = 301;
    for (int i = 0; i < str.length(); i++)
    {
        hash += str[i] * bin_pow(prime, i);
    }
    return hash;
}


int main()
{
    string a = "aaa";
    string b = "acahaef";
    string c = "acahaef";

    cout << string_hash(a) << " " << string_hash(b) << " " << string_hash(c) << endl;
}


