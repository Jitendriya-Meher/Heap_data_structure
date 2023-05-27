#include <iostream>
using namespace std;
#include <vector>
#include <queue>


class node{
  public:
    int data;
    node* next;

    node( int data){
      this->data= data;
      this->next=NULL;
    }
};


node* createLL(){
  cout<<" data sholud be +ve -> ";
  int data;
  cin>>data;

  if( data < 0){
    return NULL;
  }

  node* newnode = new node(data);
  newnode->next = createLL();

  return newnode;
}


void print(node* &head){
  node* temp=head;
  while( temp!=NULL){
    cout<<temp->data<<" -> ";
    temp=temp->next;
  }
  cout<<"NULL\n";
}


// constum class for a contum comparetor for creating min heap
class comp {
    public:
        bool operator()(node *a, node *b){
            return a->data > b->data;
        }
};

// KSortList function
node* KSortList(vector<node*> list){
    // create a minheap to store the min node
    priority_queue<node*, vector<node*> , comp> minheap;

    // create a dummy head to store the ans 
    node *head = new node(-1);
    node *temp = head;

    // push the first node of each list into the minheap
    for( int i=0; i<list.size(); i++ ){
        node *top = list[i];
        // push into minheap if it is not NULL
        if( top != NULL){
            minheap.push(list[i]);
        }
    }

    // treverse the minheap until it is empty
    while( !minheap.empty() ){
        // get the min element element heap and delete the element
        node *top = minheap.top();
        minheap.pop();
        
        int data = top->data;
        node* last = top->next;

        // push the element to the result
        temp->next = top;
        temp = temp->next;

        // push the next element of the top to the minheap if exists
        if( last != NULL){
            minheap.push(last);
        }
    }

    // retuen head->next , as head is a dumy node
    return head->next;

}


int main() {

    cout<<" enter the number of LL : ";
    int k;
    cin>>k;

    vector<node*> list(k);

    for( int i=0; i<k; i++ ) {
        cout<<" enter the sorted data for "<<i+1<<" linked list"<<endl;
        list[i] = createLL();
    }
  
    cout<<endl<<" list are : "<<endl;
    for( int i=0; i<k; i++ ) {
        print(list[i]);
    }

    node* ans = KSortList(list);

    cout<<endl<<" K sorted List is : "<<endl;
    print(ans);
  
}