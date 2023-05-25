#include<iostream>
using namespace std;
#include<algorithm>

class Heap{
    private:
        // heap as array
        int *arr;
        // size of the heap
        int size;
    
    public:
        // constructor
        Heap(){
            arr = new int[101];
            // heap with 1 base indexing
            arr[0] = -1;
            size = 0;
        }

        // insert into heap
        void insert(int data){
            // increase the size of the heap
            size++;
            int index = size;
            // inser the data in the last position of the array
            arr[index] = data;

            // place the new element to its correct position by comparing with its parent element
            while( index > 1){
                // parent index
                int parentIndex = index/2;
                // if parent element is smaller then swap
                if( arr[parentIndex] < arr[index] ){
                    swap(arr[index], arr[parentIndex]);
                    // and new index will be parent index
                    index = parentIndex;
                }
                else{
                    // the element is in correct position -> break
                    break;
                }
            }
        }

        
        int pop(){
            // if heap is alread empty
            if( size == 0){
                return -1;
            }

            // always the top element from the heap is deleted
            int top = arr[1];
            // swap the top element with last element and decrease the size , so the top element will be deleted
            swap(arr[1],arr[size]);
            size--;

            // now place the new top element to its original position
            int index = 1;
            while( index <= size){
                // compare the current element with its child element
                int left = 2*index;
                int right = 2*index+1;

                int largest = index;

                // compare with its child if the child is greater then swap
                if( left <= size && arr[largest] < arr[left]){
                    largest = left;
                }
                if( right <= size && arr[largest] < arr[right]){
                    largest = right;
                }

                // if its child is greater then swap
                if( index != largest ){
                    swap(arr[index], arr[largest]);
                    index = largest;
                }
                else{
                    // the current element is in correct position
                    break;
                }
            }
            return top;
        }

        // pint the heap
        void print(){
            // base index is 1 to size of heap
            cout<<endl<<" Printing the Heap : ";
            for( int i = 1; i <=size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};


int main(){

    Heap h;
    h.insert(80);
    h.print();
    h.insert(100);
    h.print();
    h.insert(90);
    h.print();
    h.insert(120);
    h.print();

    cout<<h.pop();
    h.print();
    cout<<h.pop();
    h.print();
    cout<<h.pop();
    h.print();
    cout<<h.pop();
    h.print();
    cout<<h.pop();
    h.print();
    cout<<h.pop();
    h.print();

    return 1;
}