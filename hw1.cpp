#include <iostream>
#include <chrono>
#include <cstdlib> 

// merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int num1 = mid - left + 1;
    int num2 = right - mid;
    int *leftArr = new int[num1];
    int *rightArr = new int[num2];

    for (int i = 0; i < num1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < num2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge arrays
    int i = 0; 
    int j = 0;
    int k = left;

    while (i < num1 && j < num2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < num1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < num2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

// merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./hw1 <array_size>" << std::endl;
        return 1;
    }

    int size = std::atoi(argv[1]);
    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 100;
    }

    // Measure time
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
    auto end = std::chrono::high_resolution_clock::now();

    // Print time
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << size << "," << duration.count() << std::endl;


    delete[] arr;

    return 0;
}
