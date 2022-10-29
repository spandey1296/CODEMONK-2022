#include<bits/stdc++.h>
using namespace std;
vector<string> solve(int n){
    vector<string> res;
for(int i=1;i<=n;i++){
    string ans="";
    for(int j=1;j<=i;j++){
        ans+=char('0'+j);
    }
    for(int m=i-1;m>0;m--){
        ans+=char('0'+m);
    }
    res.push_back(ans);
}
return res;
}
int main(){
int n;
cin >> n;
vector<string> res = solve(n);
for (string i: res){
cout << i << ' ';
}
return 0;
}