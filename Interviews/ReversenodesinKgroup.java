public ListNode reverseKGroup(ListNode head, int k) {
        List<Integer> list = new ArrayList<>();
        List<Integer> reverList = new ArrayList<>();
        ListNode ans = new ListNode(0);
        ListNode temp1;
        if (head == null) {
            return null;
        }
        while (head != null) {
            list.add(head.val); //先取出全部的數字
            head = head.next;
        }

        if (list.size() == 1) {
            ans = new ListNode(list.get(0));
            return ans;
        }


        if (list.size() >= k) {
            for (int i = 0; i < list.size() / k; i++) {
                for (int j = k * i + (k - 1); j >=k*i; j--) {
                    reverList.add(list.get(j));
                }
            }
            if (list.size() % k != 0) {
                for (int i = list.size() - (list.size() % k) ; i <list.size(); i++) {
                    reverList.add(list.get(i));
                }
            }
        }else{
            reverList.addAll(list);
        }

        temp1 = new ListNode(reverList.get(0));
        for (int i = 0; i < list.size() - 1; i++) {
            temp1.next = new ListNode(reverList.get(i + 1));
            if (i == 0) {
                ans = temp1;
            }
            temp1 = temp1.next;
        }
        return ans;
    }

    /*struct node * copy(struct node * head) 
{
   struct node *dummy;
   struct node *dummy1=dummy;
   struct node *head1=head;

   struct node *map[1000000];
   while(head) {
      dummy->next=new struct node;
      map[head]=dummy->next;
      dummy->next->data=head->data;
      dummy=dummy->next;
      head=head->next
   }
   dummy=dummy1;
   head=head1;
   while(head){
      dummy->next->arb=map[head->arb];
      dummy=dummy->next;
      head=head->next;
   }
   return dummy1->next;
}*/