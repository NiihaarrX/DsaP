#include <iostream>

using namespace std;


void Merge(int arr[],int start,int mid,int end) {
  int aN = mid - start + 1;
  int bN = end - mid;

  int arr1 = new int[aN];
  int arr2 = new int[bN];

  for(int i = 0;i < aN ; i++) arr1[i] = arr[start + i];
  for(int j = 0; j < bN ;j++) arr2[j] = arr[mid + 1 + j];


  int i = 0,j = 0,k = start;
  while(i < aN && j < bN) {
    if(arr1[i] < arr2[j]) arr[k++] = arr1[i++];
    else arr[k++] = arr2[j++];
  }

  while(i < aN) arr[k++] = arr1[i++];
  while(j < bN) arr[k++] = arr2[j++];
  }
void MergeSort(int arr[],int start,int end) {
  if(start >= end) return;
  int mid = (start + end) / 2;
  MergeSort(arr,start,mid);
  MergeSort(arr,mid + 1,end);
  Merge(arr,start,mid,end);
}

int main() {
  int arr[] = {23,13,45,60,54,89,65,3};
  int size = sizeof(arr)/sizeof(arr[0]);
  MergeSort(arr,0,size-1);

  for(auto &i : arr)
    cout << i << " ";

  cout << "\n";
}
