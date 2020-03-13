#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
class SortedStack {
public:
    SortedStack() {

    }
    
    void push(int val) {
        stack<int>tempHeap;
        while(!Heap.empty()){
            int currentValue = Heap.top();
            if(currentValue<val){
                tempHeap.push(currentValue);
                Heap.pop();
            }
            else{
                break;
            }
        }
        tempHeap.push(val);
        while(!tempHeap.empty()){
            int currentValue = tempHeap.top();
            Heap.push(currentValue);
            tempHeap.pop();
        }
    }
    
    void pop() {
        if(!Heap.empty())
            Heap.pop();
    }
    
    int peek() {
        if(!Heap.empty())
            return Heap.top();
        else
        return -1;
    }
    
    bool isEmpty() {
        return Heap.empty();
    }
private:
   stack<int>Heap;
};
int main(){
    SortedStack* sortedStack = new SortedStack();
    cout<<sortedStack->peek()<<" ";
    sortedStack->pop();
    sortedStack->push(1);
    cout<<sortedStack->peek()<<" ";
    sortedStack->pop();
    cout<<sortedStack->peek()<<" ";
    return 0;
}