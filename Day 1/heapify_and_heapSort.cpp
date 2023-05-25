#include<iostream>
using namespace std;
#include<algorithm>

void heapify( int *arr, int n, int i){
    // place the i'th element to its correct position
    int index = i;
    // 0 base indexing
    while( index<n){
        // find the child of the current position
        int left = 2*index+1;
        int right = 2*index+2;

        int largest=index;

        // compare the current element to its child element
        // if the child elemet element is greater than swap
        if( left <n && arr[largest] < arr[left] ){
            largest = left;
        }
        if( right< n && arr[largest] < arr[right] ){
            largest = right;
        }

        if( largest != index){
            swap(arr[largest], arr[index]);
            index = largest;
        }else{
            break;
        }
    }
}

void print( int *arr, int n){
    cout<<endl<<" array : ";
    for( int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void buildHeapify( int *arr, int n){
    // leaf nodes are already heapified
    for( int i=n/2; i>=0; i--){
        heapify(arr,n,i);
    }
}

// heap sort
void heapSort( int *arr, int n){
    int index = n-1;

    while( index > 0){
        // swap the first and index elements
        swap(arr[index], arr[0]);
        index--;

        // heapify the top element
        heapify(arr,index+1,0);
    }
}

int main(){
    // int *arr = new int[5];
    int arr[] ={10,20,30,40,50,60,70,80};
    int n = sizeof(arr)/sizeof(arr[0]);

    print(arr,n);
    heapify(arr,n,0);
    print(arr,n);
    heapify(arr,n,4);
    print(arr,n);

    buildHeapify(arr,n);
    print(arr,n);

    heapSort(arr,n);
    print(arr,n);

}