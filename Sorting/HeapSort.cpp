#include <iostream>

using namespace std;

void Heapify(int arr[],int index,const int size) {
  int largest_index = index;
  int LeftChild = 2 * index + 1;
  int RightChild = 2 * index + 2;

  if(LeftChild < size && arr[LeftChild] > arr[largest_index]) largest_index = LeftChild;
  if(RightChild < size && arr[RightChild] > arr[largest_index]) largest_index = RightChild;

  if(largest_index != index) {
    swap(arr[largest_index],arr[index]);
    Heapify(arr,largest_index,size);
  }
}
void HeapSort(int arr[],int size) {
  for(int i = (size-1)/2 ; i >= 0; i--) {
    Heapify(arr,i,size);
  }
  int track = size - 1;
  while(track > 0) {
    swap(arr[0],arr[track]);
    track--;
    Heapify(arr,0,track + 1);
  }
}
int main() {
  int arr[] = {34,12,23,14,5,8};
  int size = sizeof(arr) / sizeof(arr[0]);
  HeapSort(arr,size);
  for(auto i : arr)
    cout << i << " ";
}
