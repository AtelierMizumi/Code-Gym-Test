#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n;
    
    // Nhập số lượng phần tử
    cout << "Nhap so luong phan tu n: ";
    cin >> n;
    
    // Kiểm tra đầu vào hợp lệ
    if (n <= 0) {
        cout << "So luong phan tu phai lon hon 0." << endl;
        return 1;
    }
    
    vector<int> arr(n);
    
    // Nhập mảng
    cout << "Nhap " << n << " phan tu cua mang:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> arr[i];
    }
    
    // Sử dụng set để lưu trữ các giá trị phân biệt
    set<int> uniqueValues;
    
    // Thêm tất cả các phần tử của mảng vào set
    // Set tự động loại bỏ các phần tử trùng lặp
    for (int i = 0; i < n; i++) {
        uniqueValues.insert(arr[i]);
    }
    
    // Số lượng phần tử phân biệt chính là kích thước của set
    int count = uniqueValues.size();
    
    // In kết quả
    if (count == 1) {
        cout << "Mang co 1 gia tri phan biet (toan bo phan tu giong nhau)." << endl;
    } else if (count == n) {
        cout << "Mang co " << count << " gia tri phan biet (tat ca phan tu deu khac nhau)." << endl;
    } else {
        cout << "So luong gia tri phan biet trong mang: " << count << endl;
    }
    
    return 0;
}