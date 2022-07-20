int binarySearch(int input[], int size, int element) {

  if (size == 0)return -1;

  int mid = (size-1) / 2;
  if (input[mid] == element)return mid;

  if (input[mid] > element) {
    int ans = binarySearch(input, mid, element);
    return ans;
  }

  int ans = binarySearch(input +mid + 1, size - mid - 1, element);
  if (ans == -1)return -1;
  else return ans + mid + 1;
  

}

