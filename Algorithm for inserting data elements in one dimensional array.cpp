#include <iostream>
using namespace std;

void insertElement(int arr[], int &size, int element, int position) {
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
}

void displayArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;
    int* arr = new int[size + 1]; 
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    displayArray(arr, size);
    int element, position;
    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the position to insert (0 to " << size << "): ";
    cin >> position;
    if (position < 0 || position > size) {
        cout << "Invalid position!" << endl;
    } else {
        insertElement(arr, size, element, position);
        displayArray(arr, size);
    }
    delete[] arr;
    return 0;
}