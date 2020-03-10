#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int Partition(vector<int>& A,int p,int r);
void QuickSort(vector<int>&A,int p,int r){
    if(p<r){
        int q = Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}
int Partition(vector<int>& A,int p, int r){
    int temp = A[r];
    int result = p-1;
    for(int i=p;i<r;i++){
        if(A[i]< temp){
            result ++;
            int tempNumber = A[i];
            A[i] = A[result];
            A[result] = tempNumber;
        }
    }
    int tempNumber = A[r];
    A[r] = A[result+1];
    A[result+1] = tempNumber;
    return result+1;
}
int main(){
    vector<int>A{1,2,3,4};
    QuickSort(A,0,A.size()-1);
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    return 0;
}