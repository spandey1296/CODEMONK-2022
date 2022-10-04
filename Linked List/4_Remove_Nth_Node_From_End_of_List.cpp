// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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

/*
Input :-
[1]
1
*/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *start = new ListNode(-1);
        start->next = head;
        ListNode *fast = start, *slow = start;
        while (n > 0)
        {
            fast = fast->next;
            n--;
        }

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return start->next;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}