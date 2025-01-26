#include <iostream>
#include <vector>

using namespace std;

// Function to swap two elements in the array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// Function to get the parent index in a Max-Heap
int parent(int i) {
    return (i - 1) / 2;
}

// Max-Heapify function
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
// Function to increase the value of a key at a given index
void increaseKey(vector<int>& arr, int n, int i, int newKey) {
    if (i < 0 || i >= n || newKey < arr[i]) {
        cout << "Invalid input: index out of range or new key is smaller than current key" << endl;
        return;
    }

    arr[i] = newKey;

    // Heapify up to maintain Max-Heap property
    while (i > 0 && arr[parent(i)] < arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

// Function to insert a new key into the Max-Heap
void insertKey(vector<int>& arr, int& n, int key) {
    // Resize if heap is full
    if (n == arr.size()) {
        arr.resize(2 * n); // Double the size for potential growth
    }

    arr[n] = key; // Insert the new key at the end
    n++; // Increment heap size

    // Heapify up to maintain Max-Heap property
    int i = n - 1;
    while (i > 0 && arr[parent(i)] < arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = arr.size();

    cout << "Unsorted array: ";
    Print(arr, n);
    
    buildMaxHeap(arr, n);
    cout << "Max-Heap: ";
    Print(arr, n);
   
    // Increase key at index 2 to 10
    increaseKey(arr, n, 2, 10);
    cout << "Max-Heap after increasing key at index 2: ";
    Print(arr, n);

    // Insert a new key 15
    insertKey(arr, n, 15);
    cout << "Max-Heap after inserting key 15: ";
    Print(arr, n);

    return 0;
}