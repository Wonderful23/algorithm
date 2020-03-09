#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Heap {
    private:
        vector<int> heapList;
        int size;
        int LEFT(int i){
            return 2*i+1;
        }
        int RIGHT(int i){
            return 2*i+2;
        }
        int PARENT(int i){
            return (i-1)/2;
        }
        void MAXHEAPIFY(int i){
            int l = LEFT(i);
            int r = RIGHT(i);
            int largest = 0;
            if(l<this->size && this->heapList[l]>this->heapList[i])
                largest = l;
            else
                largest = i;
            if(r<this->size && this->heapList[r]>this->heapList[largest])
                largest = r;
            if(largest != i){
                int temp = this->heapList[largest];
                this->heapList[largest] = this->heapList[i];
                this->heapList[i] = temp;
                MAXHEAPIFY(largest);
            }

        }
        void BUILDMAXHEAP(){
            for(int i= this->size/2-1;i>=0;i--)
              MAXHEAPIFY(i);
        }
    public:
        Heap(vector<int> A){
            this->heapList = A;
            this->size = A.size();
        }
        
        vector<int> HEAPSORT(){
            BUILDMAXHEAP();
            int length = this->size-1; 
            for(int i=length;i>=1;i--){
                int temp = this->heapList[0];
                this->heapList[0] = this->heapList[i];
                this->heapList[i] = temp;

                this->size = this->size - 1;
                MAXHEAPIFY(0);  
            }
            return this->heapList;
        }
};
int main(){
    vector<int>A{3,1,-1,4,2,5,9,7,8};
    Heap* heap = new Heap(A);
    vector<int> result = heap->HEAPSORT();
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}