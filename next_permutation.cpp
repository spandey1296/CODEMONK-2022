#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int n, vector<int> nums){
//CODE HERE 
int i;
        for( i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        if(i<0){reverse(nums.begin(),nums.end());}
        else{
            int j=n-1;
            while(j>=0 && nums[j]<=nums[i]){j--;}
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
        return nums;  
}
int main(){
int n;
vector<int> nums;
cin >> n;
for (int i = 0; i < n; i++){
int temp;
cin >> temp;
nums.push_back(temp);
}
vector<int> out = solve(n, nums);
for (int i: out){
cout << i << ' ';
}
return 0;
}