#include <iostream>

using namespace std;

int adjustArray(int s[], int left, int right) {
  int i = left;
  int j = right;
  int x = s[i];

  while (i < j) {
    while (i < j && s[j] >= x)
      j--;

    if (i < j)
      s[i++] = s[j];

    while (i < j && s[i] < x)
      i++;

    if (i < j)
      s[j--] = s[i];
  }
  s[i] = x;
  return i;
}

void quickSort(int s[], int left, int right) {
  if (left < right) {
    int position = adjustArray(s, left, right);
    quickSort(s, left, position - 1);
    quickSort(s, position + 1, right);
  }
}

int main() {
  int array[] = {2, 4, 7, 9, 0, 23, 12, 5};
  quickSort(array, 0, 7);

  for (int i = 0; i < 8; i++)
    std::cout << array[i] << std::endl;

  return 0;
}
