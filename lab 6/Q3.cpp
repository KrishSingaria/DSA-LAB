#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int parent(int i) {
    return (i - 1) / 2;
}

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a Max-Heap from an unsorted array
void buildMaxHeap(vector<int>& arr, int n) {
    // Start from bottommost and alternate halves for sifting up
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

// Function to print the Max-Heap
void Print(const vector<int>& arr, int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to perform Heapsort on an array
void heapSort(vector<int>& arr, int n) {
    // Build a Max-Heap from the input array
    buildMaxHeap(arr, n);
    cout<< "Heap: ";
    Print(arr,n);
    // move it to end, and reduce heap size
    for (int i = n - 1; i > 0; i--) {
        // Move current root (maximum element) to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap (excluding the last element)
        maxHeapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Unsorted array: ";
    Print(arr,n);

    heapSort(arr, n);

    cout << "Sorted array using Heapsort: ";
    Print(arr,n);

    return 0;
}
