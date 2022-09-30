#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int n, vector<int> nums, int target){
//CODE HERE 
 unordered_map<int,int> mpp;

    for(int i=0;i<n;i++)
    {
        int rem = abs(target - nums[i]);

        if(mpp.find(rem) != mpp.end())
            return {mpp[rem] , i};
        else
            mpp[nums[i]] = i;
    }

    return {-1,-1};
}
int main(){
int n;
vector<int> nums;
int target;
cin >> n;
for (int i = 0; i < n; i++){
int temp;
cin >> temp;
nums.push_back(temp);
}
cin >> target;
vector<int> out = solve(n, nums, target);
for (int i: out){
cout << i << ' ';
}
return 0;
}
