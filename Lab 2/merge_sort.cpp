#include <iostream>
using namespace std;

void merge(int arr[], int const left, int const mid, int const end) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = end - mid;
    int leftArray[subArrayOne], rightArray[subArrayTwo];
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];
    int i = 0, j = 0;
    int k = left;
    while (i < subArrayOne && j < subArrayTwo) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < subArrayOne) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < subArrayTwo) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int const begin, int const end) {
    if (begin < end) {
        auto mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }
}

int main() {
    time_t start,end;
    int arr[] = {12, 11, 13, 5, 6, 7};
    int array_size = sizeof(arr) / sizeof(arr[0]);
    time(&start);
    mergeSort(arr, 0, array_size - 1);
    time(&end);
    cout << end-start<<endl;
    for (int i = 0; i < array_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}