#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> getFactors(int n);

int main()
{
    const int DIVISORS = 500;

    int triNum = 0;

    for (size_t i = 1; ; ++i)
    {
        triNum += i;
        cout << triNum << endl;
        
        if (getFactors(triNum).size() >= DIVISORS) {
            cout << "Triangle Number: " << triNum << endl;
            cout << "Number of divisors: " << getFactors(triNum).size() << endl;
            break;
        }   
    }
}

vector<int> getFactors(int n)
{
    vector<int> factors;

    for (int i = 2; i < pow(n, 0.5); ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            factors.push_back(n / i);
        }
    }

    return factors;
}
