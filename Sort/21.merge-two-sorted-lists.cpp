/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (52.07%)
 * Total Accepted:    41.3K
 * Total Submissions: 79.3K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return NULL;
        }
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode *head = NULL;
        if (l1->val <= l2->val) {
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        } else {
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }
        
        return head;
    }
};
