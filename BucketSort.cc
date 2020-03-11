#include<algorithm>
#include <vector>
#include <iostream>
using namespace std;
vector<int> BucketSort(vector<int> A){
    auto maxPosition = max_element(A.begin(), A.end());
    int maxValue = *maxPosition;
    auto minPostion = min_element(A.begin(),A.end());
    int spice = ((maxValue-*minPostion)/10)+1;
    cout<<maxValue<<*minPostion<<spice<<endl;
    vector<vector<int>> resultSet;
    for(int i=0;i<spice;i++){
        resultSet.push_back(vector<int>());
    }
    for(int i=0;i<A.size();i++){
        int number = A[i];
        int index = (number-*minPostion)/10;
        vector<int>temp = resultSet[index];
        temp.push_back(number);
        resultSet[index] = temp;
    }
    cout<<"Step1"<<endl;
    for(int i=0;i<spice;i++){
        sort(resultSet[i].begin(),resultSet[i].end());
    }
    cout<<"Step2"<<endl;
    vector<int>A_result;
    for(int i=0;i<spice;i++){
        vector<int>temp = resultSet[i];
        for(int j = 0;j<temp.size();j++){
            A_result.push_back(temp[j]);
        }
    }
    cout<<"Step3"<<endl;
    return A_result;
}
int main(){
    vector<int>A{-10,-20,-30,-21,20,21,31,41,43,42,-31,-32};
    A = BucketSort(A);
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    return 0;
}