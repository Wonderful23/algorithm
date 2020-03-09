#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> sortArray(vector<int>&A){
    for(int i=0;i<A.size()-1;i++){
        for(int j=0;j<A.size()-i-1;j++){
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    return A;
}
int main(){
    vector<int>A{9,8,7,6,5,4,3,2,1};
    A = sortArray(A);
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
