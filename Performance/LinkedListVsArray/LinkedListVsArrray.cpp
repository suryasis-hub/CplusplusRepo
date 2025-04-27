#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node {
    int value;
    Node* next;
};

int main() {
    const int size = 1024 * 1024 * 20;
    vector<int> arr(size, 1);
    Node* head = new Node{1, nullptr};
    Node* curr = head;
    for (int i = 1; i < size; ++i) {
        curr->next = new Node{1, nullptr};
        curr = curr->next;
    }
    volatile long long sum = 0;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    auto end = high_resolution_clock::now();
    cout << "Array Traversal: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    sum = 0; 
    start = high_resolution_clock::now();
    curr = head;
    while (curr != nullptr) {
        sum += curr->value;
        curr = curr->next;
    }
    end = high_resolution_clock::now();
    cout << "Linked List Traversal: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    return 0;
}
