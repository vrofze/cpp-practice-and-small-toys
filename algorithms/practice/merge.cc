#include <cstdlib>
#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *p1 = pHead1, *p2 = pHead2;
        ListNode *res;
        if(p1->val <= p2->val){
            res = new ListNode(p1->val);
            p1 = p1->next;
        }
        else {
            res = new ListNode(p2->val);
            p2 = p2->next;
        }
        ListNode *p = res;
        while(p1 != NULL && p2 != NULL){
            if(p1->val <= p2->val){
                p->next = new ListNode(p1->val);
                p = p->next;
                p1 = p1->next;
            }
            else {
                p->next = new ListNode(p2->val);
                p = p->next;
                p2 = p2->next;
            }
        }
        if(p1 != NULL)
            while(p1 != NULL){
            p->next = new ListNode(p1->val);
            p = p->next;
            p1 = p1->next;
        }
        if(p2 != NULL)
            while(p2 != NULL){
            p->next = new ListNode(p2->val);
            p = p->next;
            p2 = p2->next;
        }
        return res;
    }
};


int main()
{
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    Solution sol;
    ListNode *p = sol.Merge(p1, p2);

    if(p != NULL){
        std::cout << p->val << " ";
        p = p->next;
    }

    return 0;
}
