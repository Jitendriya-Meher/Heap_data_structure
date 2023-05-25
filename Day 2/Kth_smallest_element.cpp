#include<iostream>
using namespace std;
#include<algorithm>
#include<queue>
#include<vector>

// approach 1
// by sorting       TC -> O(N*log(N))
int solve1( vector<int> arr, int n, int k){
    // sort the array
    sort(arr.begin(), arr.end());
    // the (k-1)th index is the K'th smallest element
    return arr[k-1];
}

// approach 2
// by min heap      TC -> O(Nlog(N))  SC-> (N)
int solve2( vector<int> arr, int n, int k){
    // create a min heap
    priority_queue<int,vector<int>,greater<int>> pq;
    // insert all elements into min heap
    for( int i = 0; i < n; i++ ){
        pq.push(arr[i]);
    }

    // remove the (k-1) smallest element from heap ,so we can get the K'th smallest element
    int remove = k-1;
    while( remove--){
        pq.pop();
    }

    return pq.top();
}


// approach 3
// by max heap      TC -> O(Nlog(K))  SC-> (K)
int solve3( vector<int> arr, int n, int k){
    // create a max heap
    priority_queue<int> pq;
    // insert the first k elements into max heap
    for( int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    // check if the remaining elements in the array are less then top of the heap, if less then push into the heap and pop from the heap
    for( int i=k; i<n; i++){
        if( arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main(){
    vector<int> arr = {10,2,30,4,50,6,70,8};
    int k = 5;
    int n = arr.size();

    // approach 1
    int ans1 = solve1(arr,n,k);
    cout<<" K'th smallest by sorting : "<<ans1<<endl;

    // approach 2
    int ans2 = solve2(arr,n,k);
    cout<<" K'th largest by min heap : "<<ans2<<endl;

    // approach 3
    int ans3 = solve3(arr,n,k);
    cout<<" K'th largest by max heap : "<<ans3<<endl;
}