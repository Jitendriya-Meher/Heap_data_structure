#include<iostream>
using namespace std;
#include<queue>
#include<vector>


class info {
    // class for storing the value with its row and col information.
    public:
        int data;
        int row;
        int col;
    
        // constructor
        info(int data, int row, int col){
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

// costum class for a costum comparetor for creating min heap
class comp {
    public:
        bool operator()(info *a, info *b){
            return a->data > b->data;
        }
};


// mergeKSortedArray functions
vector<int> mergeKSortedArray( vector<vector<int> > arr){
    // create a min heap DS for getting the min element 
    priority_queue< info*, vector< info*> , comp> minheap;
    // vector for storing the result
    vector<int > ans;

    // dimension of array
    int totRow = arr.size();

    // first push the first element of each row into the minheap
    for( int i=0; i<totRow; i++){
        // create info class to store all information about the element
        info *temp = new info(arr[i][0],i,0);
        minheap.push(temp);
    }

    // traverse the minheap until it is empty
    while( !minheap.empty() ){
        // get the min element element information and delete the element
        info *temp = minheap.top();
        minheap.pop();
        
        int data = temp->data;
        int row = temp->row;
        int col = temp->col;

        // push the element to the result
        ans.push_back(data);

        // push the next element of the array to the minheap if exists
        if( ( col+1) < arr[row].size()){
            info *temp = new info(arr[row][col+1], row, col+1);
            minheap.push(temp);
        }
    }
    
    // return the result
    return ans;
}

int main(){

    // creating a 2d vector
    vector<vector<int> > arr = {
        {
            1,3,6,9,12,15
        },
        {
            10,20,30,40,50
        },
        {
            0,5,10,15,20,25,30,35,40,45
        },
        {
            100,200,300,400,500,600,700,800
        }
    };

    vector<int> ans = mergeKSortedArray(arr);

    cout<<" after mergeKSortedArray : ";
    for( auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;

}