#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// This function will get the largest number that is divisible by 3
// and less than or equal to n
bool isDivisibleBy3(int n) {
    return n % 3 == 0;
}

int findLargestDivisibleBy3(const vector<int>& arr) {
    int largest = -1; // Initialize to -1 to indicate no prime found
    for (int num : arr) {
        if (isDivisibleBy3(num)) {
            largest = max(largest, num);
        }
    }
    return largest;
}

int main() {
    
    int n;
    cout << "Nhap N (N>0): ";

    // User input
    // https://stackoverflow.com/a/19521636
    // Resolve infinite loop when n is invalid type like char or string
    do {
        while(!(cin >> n)) {
            cout << "So N khong hop le, vui long nhap lai N: \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(n <= 0) cout << "N la kieu nguyen duong, vui long nhap lai N:\n";
    } while(n <= 0);

    // Init array and allows user to input
    vector<int> arr(n);
    cout << "Nhap " << n << " so nguyen: ";
    for (int i = 0; i < n; i++) {
        cout << "Nhap so thu " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Mang da nhap: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Get the largest number that is divisible by 3
    int largest = findLargestDivisibleBy3(arr);

    if (largest == -1) {
        cout << "Khong co so nguyen to" << endl;
    } else {
        cout << "So nguyen to lon nhat chia het cho 3 la: " << largest << endl;
    }
    return 0;
}