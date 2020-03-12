#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> CountingSort(vector<int>A){
    int maxValue = *max_element(A.begin(),A.end());
    vector<int>Counting(maxValue+1);
    for(int i=0;i<A.size();i++){
        Counting[A[i]] = Counting[A[i]]+1;
    }
    for(int i=1;i<=maxValue;i++){
        Counting[i] = Counting[i] + Counting[i-1];
    }
    vector<int>B(A.size());
    for(int i = A.size()-1;i>=0;i--){
        B[Counting[A[i]]-1] = A[i];
        Counting[A[i]] = Counting[A[i]]-1;
    }
    return B;
}
int main(){
    vector<int>A{1,3,2,8,7,5,6,9,10};
    A = CountingSort(A);
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    return 0;
}