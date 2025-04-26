#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Khai bao struct Sinh vien
struct Student {
    string name;
    float mathScore;
    float physicsScore;
    float chemistryScore;
    float averageScore;
};

// Ham nhap thong tin mot sinh vien
Student inputStudent() {
    Student student;
    
    cout << "Nhap ten sinh vien: ";
    getline(cin, student.name);
    
    do {
        cout << "Nhap diem Toan (0-10): ";
        cin >> student.mathScore;
        if (student.mathScore < 0 || student.mathScore > 10) {
            cout << "Diem phai nam trong khoang tu 0 den 10. Vui long nhap lai.\n";
        }
    } while (student.mathScore < 0 || student.mathScore > 10);
    
    do {
        cout << "Nhap diem Ly (0-10): ";
        cin >> student.physicsScore;
        if (student.physicsScore < 0 || student.physicsScore > 10) {
            cout << "Diem phai nam trong khoang tu 0 den 10. Vui long nhap lai.\n";
        }
    } while (student.physicsScore < 0 || student.physicsScore > 10);
    
    do {
        cout << "Nhap diem Hoa (0-10): ";
        cin >> student.chemistryScore;
        if (student.chemistryScore < 0 || student.chemistryScore > 10) {
            cout << "Diem phai nam trong khoang tu 0 den 10. Vui long nhap lai.\n";
        }
    } while (student.chemistryScore < 0 || student.chemistryScore > 10);
    
    // Tinh diem trung binh
    student.averageScore = (student.mathScore + student.physicsScore + student.chemistryScore) / 3;
    
    cin.ignore(); // Xoa bo nho dem de getline hoat dong chinh xac o lan tiep theo
    return student;
}

// Ham hien thi thong tin mot sinh vien
void displayStudent(const Student& student) {
    cout << "Ten: " << student.name << endl;
    cout << "Diem Toan: " << student.mathScore << endl;
    cout << "Diem Ly: " << student.physicsScore << endl;
    cout << "Diem Hoa: " << student.chemistryScore << endl;
    cout << "Diem trung binh: " << fixed << setprecision(2) << student.averageScore << endl;
    cout << "------------------------" << endl;
}

int main() {
    int n;
    vector<Student> students;
    
    // Nhap so luong sinh vien
    do {
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
        if (n <= 0) {
            cout << "So luong sinh vien phai lon hon 0. Vui long nhap lai.\n";
        }
    } while (n <= 0);
    
    cin.ignore(); // Xoa bo nho dem
    
    // Nhap thong tin n sinh vien
    cout << "\n=== NHAP THONG TIN SINH VIEN ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        students.push_back(inputStudent());
    }
    
    // In ra danh sach sinh vien va diem trung binh
    cout << "\n=== DANH SACH SINH VIEN ===" << endl;
    for (const auto& student : students) {
        displayStudent(student);
    }
    
    // In ra cac sinh vien co diem trung binh >= 8
    cout << "\n=== SINH VIEN CO DIEM TRUNG BINH >= 8 ===" << endl;
    bool found = false;
    for (const auto& student : students) {
        if (student.averageScore >= 8) {
            displayStudent(student);
            found = true;
        }
    }
    
    if (!found) {
        cout << "Khong co sinh vien nao co diem trung binh >= 8" << endl;
    }
    
    return 0;
}