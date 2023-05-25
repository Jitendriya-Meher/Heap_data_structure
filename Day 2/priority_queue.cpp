#include<iostream>
using namespace std;
#include<queue> // for priority queue

int main(){
    
    // declaring a priority queue of integer type
    priority_queue<int> pq;
    // by default it is a max heap

    // push operaton in priority queue
    pq.push(10);
    cout<<" size of priority queue : "<<pq.size()<<endl;
    
    pq.push(200);
    cout<<" size of priority queue : "<<pq.size()<<endl;
    pq.push(300);
    cout<<" size of priority queue : "<<pq.size()<<endl;
    pq.push(10000);
    cout<<" size of priority queue : "<<pq.size()<<endl;
    pq.push(1);
    cout<<" size of priority queue : "<<pq.size()<<endl;

    // top and pop operations 
    cout<<" top of priority queue : "<<pq.top()<<endl;
    pq.pop();
    cout<<" size of priority queue : "<<pq.size()<<endl;

    cout<<" top of priority queue : "<<pq.top()<<endl;
    pq.pop();
    cout<<" size of priority queue : "<<pq.size()<<endl;
    cout<<" top of priority queue : "<<pq.top()<<endl;
    pq.pop();
    cout<<" size of priority queue : "<<pq.size()<<endl;
    cout<<" top of priority queue : "<<pq.top()<<endl;
    pq.pop();
    cout<<" size of priority queue : "<<pq.size()<<endl;
    cout<<" top of priority queue : "<<pq.top()<<endl;

    // empty operation
    cout<<" is empty : "<<pq.empty()<<endl;

    cout<<endl<<endl;

    // min heap
    priority_queue<int,vector<int>, greater<int>> pqm;

    // push operaton in priority queue
    pqm.push(10);
    cout<<" size of priority queue : "<<pqm.size()<<endl;
    pqm.push(200);
    cout<<" size of priority queue : "<<pqm.size()<<endl;
    pqm.push(300);
    cout<<" size of priority queue : "<<pqm.size()<<endl;
    pqm.push(10000);
    cout<<" size of priority queue : "<<pqm.size()<<endl;
    pqm.push(1);
    cout<<" size of priority queue : "<<pqm.size()<<endl;

    // top and pop operations 
    cout<<" top of priority queue : "<<pqm.top()<<endl;
    pqm.pop();
    cout<<" size of priority queue : "<<pqm.size()<<endl;
    cout<<" top of priority queue : "<<pqm.top()<<endl;
    pqm.pop();
    cout<<" size of priority queue : "<<pqm.size()<<endl;
    cout<<" top of priority queue : "<<pqm.top()<<endl;
    pqm.pop();
    cout<<" size of priority queue : "<<pqm.size()<<endl;
    cout<<" top of priority queue : "<<pqm.top()<<endl;
    pqm.pop();
    cout<<" size of priority queue : "<<pqm.size()<<endl;
    cout<<" top of priority queue : "<<pqm.top()<<endl;

    // empty operation
    cout<<" is empty : "<<pqm.empty()<<endl;
    


}