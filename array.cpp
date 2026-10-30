#include <iostream>
#include <stdexcept>

using namespace std;

class StackArray {
    static constexpr int CAP = 5;
    int a[CAP];
    int t = -1; // Menandakan stack kosong di awal[cite: 1]
public:
    bool empty() const { return t == -1; }
    
    void push(int x) {
        if (t == CAP - 1) throw overflow_error("penuh"); // Cek kondisi penuh[cite: 1]
        a[++t] = x; // Increment dulu baru masukkan data[cite: 1]
    }
    
    void pop() {
        if (empty()) throw underflow_error("kosong"); // Cek kondisi kosong[cite: 1]
        --t; // Mengurangi indeks top
    }
    
    int top() const {
        if (empty()) throw underflow_error("kosong"); // Cek kondisi kosong[cite: 1]
        return a[t]; // Mengembalikan nilai teratas
    }
};

int main() {
    try {
        StackArray s;
        s.push(5);
        s.push(9);
        s.push(7);
        
        cout << "--- Uji Stack Array ---" << endl;
        cout << "Top awal: " << s.top() << endl; // Output: 7
        s.pop();
        cout << "Top setelah pop: " << s.top() << endl; // Output: 9[cite: 4]
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}