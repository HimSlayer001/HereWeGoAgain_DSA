/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //linkedList is the pointer->helping each other 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //need to create a new Object
        if(head==nullptr)
        return nullptr;
//this means teap is a pointer to a struct type ListNode
//thus i can point it to head->which is also a pointer carrying addres of given 
//struct
//->so what i am doing here is temp--->head---->struct{}
        ListNode *curr=head;
        ListNode *prev=nullptr;//we copied the the address which was in head into the temp
        //we can use additional space as a vector and print it after that
        //or what we can do is
        while(curr!=nullptr)
        
        {  
         ListNode *hell=curr->next;
        //this hold the future address
        //[1] [2]->[3]->[4]

            curr->next=prev;
            prev=curr;
            curr=hell;
            //now the target is to do in 0(n) and constant space
            //over the move only makes sense
        }

       return prev; 
    }
};
