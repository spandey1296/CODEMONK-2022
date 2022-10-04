// https://leetcode.com/problems/linked-list-cycle/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast != NULL and fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}