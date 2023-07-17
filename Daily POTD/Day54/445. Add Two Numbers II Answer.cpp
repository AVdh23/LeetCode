class Solution {
private:
	//both linkedlist of same size
    int addSameLength(ListNode* head1, ListNode *head2, ListNode* &head){
        if(head1==NULL && head2==NULL){
            return 0;
        }
        int sum=(head1->val+head2->val);
        sum+=addSameLength(head1->next,head2->next,head);
        ListNode *new_node= new ListNode(sum%10);
        new_node->next=head;
        head=new_node;
        return sum/10;
    }
	//Add carry to remaining linkedlist of extra length
    int addCarry(ListNode* head,int carry,ListNode* &new_head,int diff){
        if(head==NULL || diff==0){
            return carry;
        }
        carry=addCarry(head->next,carry,new_head,diff-1);
        int sum=head->val+carry;
        ListNode *new_node=new ListNode(sum%10);
        new_node->next=new_head;
        new_head=new_node;
        return sum/10;
    }
	//Calculates length of linkedlist
    int length(ListNode* head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=length(l1);
        int len2=length(l2);
        
		//Always have l1 list as the longer.
        if(len2>len1){
            swap(l1,l2);
            swap(len1,len2);
        }
        ListNode *curr1=l1;
        int diff=len1-len2;
        for(int i=0;i<diff;i++){
            curr1=curr1->next;
        }
        ListNode *head=NULL;
        int carry=addSameLength(curr1,l2,head);

        carry=addCarry(l1,carry,head,diff);
        if(carry){
            ListNode *new_node=new ListNode(1);
            new_node->next=head;
            head=new_node;
        }
        return head;
    }
};