#include <iostream>

using namespace std;

void AdjustHeap(int* arr, int i, int size) {
  int leftChild = 2 * i;
  int rightChild = 2 * i + 1;
  int max = i;

  if (i <= size / 2) {
    if (leftChild <= size && arr[leftChild] > arr[max])
      max = leftChild;
    if (rightChild <= size && arr[rightChild] > arr[max])
      max = rightChild;
    if (max != i) {
      swap(arr[i], arr[max]);
      AdjustHeap(arr, max, size);
    }
  }
}

void BuildHeap(int* arr, int size) {
  for (int i = size / 2; i >= 1; i--)
    AdjustHeap(arr, i, size);
}

void HeapSort(int* arr, int size) {
  BuildHeap(arr, size);
  for (int i = size; i >= 1; i--) {
    swap(arr[1], arr[i]);
    AdjustHeap(arr, 1, i - 1);
  }
}

int main() {
  int a[] = {0, 16, 20, 3, 11, 17, 8, 9};
  HeapSort(a, 7);
  for (int i = 1; i <= 7; i++)
    cout << a[i] << endl;
  return 0;
}
