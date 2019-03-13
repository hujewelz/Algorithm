/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (38.74%)
 * Total Accepted:    15.4K
 * Total Submissions: 39.7K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pNode = head;
        ListNode *pPrev = NULL;
        while(pNode){
            if (pNode->val == val) {
                if (pPrev == NULL) {
                    head = pNode->next;
                } else {
                    pPrev->next = pNode->next;
                }
            } else {
                pPrev = pNode;
            }
            pNode = pNode->next;
        }
        
        return head;
    }
};
