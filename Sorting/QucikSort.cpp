#include <iostream>

using namespace std;


int Partition(int arr[],int start,int end) {
  int pivot = arr[start];
  int cnt = 0;
  for(int i = start + 1;i <= end ; i++) {
    if(arr[i] <= pivot) cnt++;
  }

  int PivotIndex = start + cnt;
  swap(arr[PivotIndex],arr[start]);

  int i = start , j = end;

  while(i < PivotIndex && j > PivotIndex) {
    while(arr[i] <= pivot) i++;
    while(arr[j] > pivot) j--;

    if(i < PivotIndex && j > PivotIndex) swap(arr[i++],arr[j--]);
  }
  return PivotIndex;
}

void QuickSort(int arr[],int start,int end) {
  if(start >= end) return;
  int p = Partition(arr,start,end);
  QuickSort(arr,start,p-1);
  QuickSort(arr,p + 1,end);
}

int main() { 
int arr[] = {4,1,5,6,3,2};
int size = 6;

QuickSort(arr,0,size-1);

for(auto &i : arr) cout << i << " ";
}
