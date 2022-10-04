// https://leetcode.com/problems/count-and-say/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    string countAndSay(int n)
    {
        string ans = "1";
        for (int i = 2; i <= n; i++)
        {
            string temp = "";
            for (int j = 0; j < ans.size(); j++)
            {
                int k = j, count = 1;
                while (k < ans.size() - 1 and ans[k] == ans[k + 1])
                {
                    k++;
                    count++;
                }
                temp += to_string(count) + to_string(ans[j]);
                j = k;
            }
            ans = temp;
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}