#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

// Mang luu tru cac gia tri Fibonacci da tinh (memoization)
vector<long long> memo;

/**
 * Ham tinh so Fibonacci thu n bang de quy co su dung memoization
 * @param n: vi tri so Fibonacci can tinh
 * @return: gia tri cua so Fibonacci thu n
 */
long long fibonacci(int n) {
    // Truong hop co so
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    
    // Kiem tra xem da tinh gia tri nay chua
    if (memo[n] != -1) {
        return memo[n];
    }
    
    // Tinh va luu lai ket qua
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

/**
 * In day Fibonacci tu F(1) den F(n)
 * @param n: so luong phan tu Fibonacci can in
 */
void printFibonacciSequence(int n) {
    cout << "Day Fibonacci tu F(1) den F(" << n << "):" << endl;
    
    // Format output de de doc hon
    // https://www.geeksforgeeks.org/cpp-20-std-format/
    for (int i = 1; i <= n; i++) {
        // can dong ben trai la F(i)
        // can dong ben phai la gia tri
        cout << "F(" << i << ") = " << setw(10) << fibonacci(i);
        // Xuong dong neu i la so chan
        if (i % 2 == 0) {
            cout << endl;
        } else {
            cout << "\t";
        }
    }
    cout << endl;
}

int main() {
    int n;
    
    cout << "Chuong trinh tinh day Fibonacci su dung de quy" << endl;
    cout << "Nhap so n (1 <= n <= 30): ";

    // Dung do while de kiem tra nhap lieu giong nhu bai 2
    // https://stackoverflow.com/a/19521636
    // Resolve infinite loop when n is invalid type like char or string
    do {
        while(!(cin >> n)) {
            cout << "So N khong hop le, vui long nhap lai N: \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(n <= 0) cout << "N la kieu nguyen duong" << endl;
        if (n > 30) cout << "Gia tri n khong duoc vuot qua 30 de tranh tran so." << endl;
        cout << "Vui long nhap lai N: ";
    } while(n <= 0 || n > 30);
    
    
    // Khoi tao mang memoization voi gia tri -1
    memo.resize(n + 1, -1);
    
    // In day Fibonacci
    printFibonacciSequence(n);
    
    return 0;
}