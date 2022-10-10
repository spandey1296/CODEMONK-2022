// Container with most water

#include<bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> arr){

int i=0; int j=arr.size()-1; int mw=0; 
// mw-> maximum water 
while(i<=j){ 
    int cw=min(arr[i],arr[j])*(j-i); 
// cw-> current water
 mw=max(mw,cw);

        if(arr[i]<arr[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return mw;
}
int main(){
int n;
vector<int> arr;
cin >> n;
for (int i = 0; i < n; i++){
int temp;
cin >> temp;
arr.push_back(temp);
}
int out = solve(n, arr);
cout << out;
return 0;
}