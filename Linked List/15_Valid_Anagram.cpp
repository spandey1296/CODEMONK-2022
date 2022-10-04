// https://leetcode.com/problems/valid-anagram/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        vector<int> arr(26, 0);

        for (int i = 0; i < s.size(); i++)
        {
            arr[(int)(s[i] - 'a')]++;
            arr[(int)(t[i] - 'a')]--;
        }

        for (auto it : arr)
        {
            if (it != 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}