You are given two __non-empty__ linked lists representing two non-negative integers. The digits are stored in __reverse order__ and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

__Example:__

```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```

처음엔 링크드 리스트를 뒤집는 문제라고 생각했지만 답은 의외로 덧셈연산할 때의 순서와 같다. 첫자리부터 덧셈하여 올림을 다음 노드로 넘겨주고 하는 식으로 생각하면 나머지는 쉽게 해답을 찾을 수 있다.

```c++
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {        
        int carry = 0;
        int sum = 0;
        ListNode* result = new ListNode(0), *first = result;
        while(l1 || l2 || carry){            
            sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;            
            carry = sum / 10;
            sum = sum % 10;                                    
            first->next = new ListNode(sum);
            first = first->next;
            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2;            
        }               
        
        
        return result->next;
    }
};
```