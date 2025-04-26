#include <iostream>
#include <vector>
using namespace std;

vector<int> printPrimeToN(int n) {
    vector<int> primes;
    if (n<=2) return primes;
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    int n;
    cout<< "Enter N: ";
    cin>>n;

    vector<int> primes = printPrimeToN(n);
    if (primes.empty()) {
        cout << "No prime numbers found." << endl;
    } else {
        cout << "Prime numbers up to " << n << ": ";
        for (int prime : primes) {
            cout << prime << " ";
        }
        cout << endl;
    }
}
