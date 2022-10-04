// https://leetcode.com/problems/palindrome-linked-list/
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
    ListNode *reverse(ListNode *ptr)
    {
        ListNode *pre = NULL;
        ListNode *nex = NULL;
        while (ptr != NULL)
        {
            nex = ptr->next;
            ptr->next = pre;
            pre = ptr;
            ptr = nex;
        }
        return pre;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }

        ListNode *slow = head, *fast = head;

        while (fast->next != NULL and fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode *temp = head;

        while (slow != NULL)
        {
            if (slow->val != temp->val)
            {
                return false;
            }
            slow = slow->next;
            temp = temp->next;
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