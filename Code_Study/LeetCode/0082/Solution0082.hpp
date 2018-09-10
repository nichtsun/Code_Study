//
//  Solution0082.hpp
//  Code_Study
//
//  Created by nichts on 2018/9/10.
//  Copyright © 2018年 nichts. All rights reserved.
//

#ifndef Solution0082_hpp
#define Solution0082_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution0082 {
public:
    static ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head) return head;
        ListNode *pHead = new ListNode(0), *p=pHead, *q;
        pHead->next = head;
        while(p)
        {
            q = p->next;
            if(q && q->next && q->val == q->next->val)
            {
                int val = q->val;
                while(q && q->val == val)
                {
                    p->next = q->next;
                    q = p->next;
                }
            }
            else p = p->next;
        }
        head = pHead->next;
        delete pHead;
        return head;
    }
};

#endif /* Solution0082_hpp */
