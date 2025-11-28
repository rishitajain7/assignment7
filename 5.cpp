#include <iostream>
using namespace std;

void heapify(int arr[], int index , int n){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;
    
    if(left<n&&arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n&&arr[right]>arr[largest]){
        largest = right;
    }
    
    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,largest,n);
    }
}

void maxheap(int arr[],int n){
    //step down
    
    for (int i= n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
}

void printheap(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortarray(int arr[], int n){
    for (int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,0,i);
    }
}

int main(){
    int arr[]={10,2,33,5,66,7};
    maxheap(arr,6);
    sortarray(arr,6);
    printheap(arr,6);
}
