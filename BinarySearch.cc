#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int BinarySearch(int target,vector<int>Array,int low,int high){
    if(low>high)
    return -1;
    if(low == high){
        if(Array[low] == target)
            return low;
        else
        {
            return -1;
        }
    }
    int mid = (low+high)/2;
    if(Array[mid] == target)
        return mid;
    else if(Array[mid]>target){
        return BinarySearch(target,Array,low,mid-1);
    }
    else{
        return BinarySearch(target,Array,mid+1,high);
    }
}
int main(){
    vector<int>A{0,1,2,9,14,15,26,37,48,59,60,61};
    cout<<BinarySearch(-1,A,0,A.size()-1);
}