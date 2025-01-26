#include <iostream>
#include <vector>

using namespace std;

// Function to swap two elements in the array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
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
void printMaxHeap(const vector<int>& arr, int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to return the maximum element (root) from Max-Heap
int getMax(const vector<int>& arr) {
    return arr[0];
}

// Function to extract the maximum element (root) from Max-Heap
int extractMax(vector<int>& arr, int& n) {
    if (n <= 0) {
        cout << "Heap underflow" << endl;
        return -1;
    }

    int max = arr[0];
    swap(arr[0], arr[n - 1]); // Move the last element to root
    // Call maxHeapify to maintain heap property after root change
    maxHeapify(arr, n-1, 0);
    n--; // Reduce heap size after extraction
    return max;
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = arr.size();

    cout << "Unsorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    buildMaxHeap(arr, n);

    cout << "Max-Heap: ";
    printMaxHeap(arr, n);

    cout << "Maximum element: " << getMax(arr) << endl;

    int extractedMax = extractMax(arr, n);

    cout << "Array after extracting maximum: ";
    printMaxHeap(arr, n);

    return 0;
}
