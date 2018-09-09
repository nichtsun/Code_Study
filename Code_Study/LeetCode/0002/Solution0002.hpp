//
//  Solution0002.hpp
//  Code_Study
//
//  Created by nichts on 2018/9/9.
//  Copyright © 2018年 nichts. All rights reserved.
//

#ifndef Solution0002_hpp
#define Solution0002_hpp

#include <stdio.h>

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution0002 {
    
public:
    
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        
        ListNode* head = new ListNode(0);
        ListNode* current = head;
        int increment = 0;
        int num = 0;
        
        while(l1 != NULL || l2 != NULL){
            num = ((l1 != NULL) ? l1->val : 0) + ((l2 != NULL) ? l2->val : 0) + increment;
            ListNode* temp = new ListNode(0);
            if(num > 9){
                increment = 1;
                temp->val = num % 10;
            }else{
                increment = 0;
                temp->val = num;
            }
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
            current->next = temp;
            current = current->next;
        }
        
        if(increment != 0){
            ListNode* temp = new ListNode(1);
            current->next = temp;
        }
        
        return head->next;
    }
    
    //reverse version of add two number
    //ListNode* Solution0002::addTwoNumbers(ListNode* l1, ListNode* l2){
    //
    //    ListNode* parent = new ListNode(0);
    //    ListNode node = ListNode(0);
    //    bool increment = false;
    //    addTwoNumber(parent, &node, l1, l2, increment);
    //    return parent;
    //}
    //
    //void Solution0002::addTwoNumber(ListNode* parent, ListNode *node, ListNode *l1, ListNode *l2, bool &increment){
    //    if(l1 == NULL && l2 == NULL) return;
    //    addTwoNumber(parent->next, node->next, l1->next, l2->next, increment);
    //    int num = ((l1 != NULL)? l1->val : 0) + ((l2 != NULL) ? l2->val : 0) + (increment ? 1 : 0);
    //    if(num > 9){
    //        increment = true;
    //        node->val = num - 10;
    //    }else{
    //        increment = true;
    //        node->val = num;
    //    }
    //    parent->next = node;
    //}
    

};

#endif /* Solution0002_hpp */
