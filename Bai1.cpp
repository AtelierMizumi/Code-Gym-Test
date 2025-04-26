#include <iostream>
#include <vector>
using namespace std;

// This function will return a vector of prime numbers up to n
vector<int> printPrimeToN(int n) {
    vector<int> primes;
    if (n <= 2) {
        return primes; // No prime numbers less than 2, same check as n>2 
    } else {
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
    }
    return primes;
}

int main() {
    int n;
    cout<< "Enter N: ";
    cin>>n; // User input


    // Get prime numbers up to N
    vector<int> primes = printPrimeToN(n); 
    if (primes.empty()) {
        // Check for empty list
        cout << "Khong co so nguyen to" << endl;
    } else {
        // Print prime numbers
        cout << "Cac so nguyen to nho hon " << n << " la: ";
        for (int prime : primes) {
            cout << prime << " ";
        }
        cout << endl;
    }
}
