#include <iostream>
#include <stdexcept>

using namespace std;

struct Node { 
    int v; 
    Node* next; 
};

class StackList {
    Node* head = nullptr; // Posisi TOP menunjuk ke head[cite: 2]
public:
    bool empty() const { return !head; }
    
    void push(int x) {
        head = new Node{x, head}; // Menambahkan node baru di depan[cite: 2]
    }
    
    void pop() {
        if (empty()) throw underflow_error("kosong"); // Cek kondisi kosong[cite: 2]
        Node* old = head;
        head = head->next; // Geser head ke node berikutnya[cite: 2]
        delete old; // Hapus node lama untuk bebaskan memori[cite: 2]
    }
    
    int top() const {
        if (empty()) throw underflow_error("kosong"); // Cek kondisi kosong[cite: 2]
        return head->v; // Ambil nilai di node terdepan
    }
    
    ~StackList() { 
        while (!empty()) pop(); // Destruktor untuk membersihkan memori[cite: 2]
    }
};

int main() {
    try {
        StackList s;
        s.push(5);
        s.push(9);
        s.push(7);
        
        cout << "--- Uji Stack Linked List ---" << endl;
        cout << "Top awal: " << s.top() << endl; // Output: 7[cite: 4]
        s.pop();
        cout << "Top setelah pop: " << s.top() << endl; // Output: 9[cite: 4]
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}