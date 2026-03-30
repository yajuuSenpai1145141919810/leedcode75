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

            // 順著 current 找到節點，把裡面的 next 地址給 temp。先複製一份原本的箭頭
            ListNode* temp=current->next; 
            
            // 順著 current 找到節點，強行修改節點裡面的 next。 動到結構了!
            current->next=prev;// 反轉箭頭
            
            // 把 current 存的地址複製給 prev。
            prev=current; // prev移動到下一個
            current=temp;// current移動到下一個

        }
        return prev;
    }
};
