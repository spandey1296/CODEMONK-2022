// https://leetcode.com/problems/add-two-numbers/
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        int carry = 0;

        while (l1 != NULL && l2 != NULL)
        {
            int currSum = l1->val + l2->val + carry;
            ans->next = new ListNode(currSum % 10);
            carry = currSum / 10;
            l1 = l1->next;
            l2 = l2->next;
            ans = ans->next;
        }

        while (l1 != NULL)
        {
            int currSum = l1->val + carry;
            ans->next = new ListNode(currSum % 10);
            carry = currSum / 10;
            l1 = l1->next;
            ans = ans->next;
        }

        while (l2 != NULL)
        {
            int currSum = l2->val + carry;
            ans->next = new ListNode(currSum % 10);
            carry = currSum / 10;
            l2 = l2->next;
            ans = ans->next;
        }

        while (carry > 0)
        {
            ans->next = new ListNode(carry % 10);
            carry = carry / 10;
            ans = ans->next;
        }

        return temp->next;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}