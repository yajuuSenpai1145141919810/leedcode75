// reverse linked list
// 詳情可以參考https://www.youtube.com/watch?v=M7lSISwQ8W4
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 需要三個參數 其中一個設在while內
        ListNode* current=head;
        ListNode* prev=nullptr;

        // 每一圈（每一個節點）就地反轉 不是做到底才一次轉!
        while(current!=nullptr){
            ListNode* temp=current->next; // 先複製一份原本的箭頭
            current->next=prev;// 反轉箭頭
            prev=current; // prev移動到下一個
            current=temp;// current移動到下一個

        }
        return prev;
    }
};
