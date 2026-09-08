//Vikram Prakash
#include<stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "d_stack.h"
#include "types.h"

void print_result(dlist **head3,dlist **tail3)
{
    if (head3 == NULL || *head3 == NULL)
    {
        printf("0\n");
        return;
    }
     while(*head3!=NULL&&(*head3)->data==0&&(*head3)->next!=NULL)
    {
        dlist *t;
        t=*head3;
        *head3=t->next;
        (*head3)->prev=NULL;
        free(t);
    }
    dlist *temp;
    temp=*head3;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
void free_list(dlist **head, dlist **tail)
{
    dlist *current = *head;
    while (current != NULL)
    {
        dlist *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    *tail = NULL;
}
status validate(char *argv[],dlist **head1,dlist **tail1,dlist **head2,dlist **tail2)
{
    
    int i=0;
    while(argv[1][i]!='\0')
    {
        if(!isdigit(argv[1][i]))
        {
           free_list(head1,tail1);
           return failure;
        }
        dlist *temp1;
        dlist *new1=malloc(sizeof(dlist));
        if(new1==NULL){free_list(head1,tail1);
            free_list(head2,tail2);return failure;}
        temp1=*head1;
        if(temp1==NULL)
        {
            temp1=new1;
            new1->data=argv[1][i]-'0';
            new1->next=NULL;
            new1->prev=NULL;
            *head1=new1;
            *tail1=new1;
        }
        else
        {
            temp1=*tail1;
            new1->data=argv[1][i]-'0';
            temp1->next=new1;
            new1->prev=temp1;
            new1->next=NULL;
            *tail1=new1;
        }
        i++;
    }
    ///VAlIDATING OPERATOR 2
    i=0;
    
     while(argv[3][i]!='\0')
    {
        if(!isdigit(argv[3][i]))
        {
            free_list(head1,tail1);
            free_list(head2,tail2);
            return failure;
        }
        dlist *temp2;
        dlist *new2=malloc(sizeof(dlist));
        if(new2==NULL){free_list(head1,tail1);
            free_list(head2,tail2);return failure;}
        temp2=*head2;
        if(temp2==NULL)
        {
            temp2=new2;
            new2->data=argv[3][i]-'0';
            new2->next=NULL;
            new2->prev=NULL;
            *head2=new2;
            *tail2=new2; 
        }
        else
        {
            temp2=*tail2;
            new2->data=argv[3][i]-'0';
            temp2->next=new2;
            new2->prev=temp2;
            new2->next=NULL;
            *tail2=new2;
        }
        i++;
    }
   
    return success;
}
status add(dlist **head1,dlist **tail1,dlist **head2,dlist **tail2,dlist **head3,dlist **tail3)
{
    dlist*temp1=*tail1;
    dlist*temp2=*tail2;
    int c=0;
    while(temp1!=NULL&&temp2!=NULL)
    {
        int val=temp1->data+temp2->data;
        int store=0;
        if(c==0)
        {
            if(val>9)
            {
                c=1;
                store=val-10;
            }
            else
            {
                store=val;                
            }
        }
        else
        {
            if((val+1)>9)
            {
                c=1;
                store=(val+1)-10;
            }
            else
            {
                store=val+1;
                c=0;
            }

        }
        ///Storing the data in result
         dlist *new=malloc(sizeof(dlist));
         if(new==NULL){return failure;}
        if(*tail3==NULL)
        {
            new->data=store;
            *tail3=new;
            *head3=new;
            new->prev=NULL;
            new->next=NULL;      
        }
        else
        {
            (*head3)->prev=new;
            new->data=store;
            new->next=*head3;
            *head3=new;
            new->prev=NULL;
        }
        temp1=temp1->prev;
        temp2=temp2->prev;        
    }
    while (temp1 != NULL)
    {
        int val = temp1->data + c;
        c = val / 10;
        int store = val % 10;

        dlist *new = malloc(sizeof(dlist));
        if (new == NULL) { return failure; }
        new->data = store;
        new->next = *head3;
        (*head3)->prev = new;
        new->prev = NULL;
        *head3 = new;

        temp1 = temp1->prev;
    }
    while (temp2 != NULL)
    {
        int val = temp2->data + c;
        c = val / 10;
        int store = val % 10;

        dlist *new = malloc(sizeof(dlist));
        if (new == NULL) { return failure; }
        new->data = store;
        new->next = *head3;
        (*head3)->prev = new;
        new->prev = NULL;
        *head3 = new;
        temp2 = temp2->prev;
    }
    if (c > 0)
    {
        dlist *new = malloc(sizeof(dlist));
        if (new == NULL) { return failure; }
        new->data = c;
        new->next = *head3;
        (*head3)->prev = new;
        new->prev = NULL;
        *head3 = new;
    }
    printf("Addition Completed\n");
    return success;
}
status sub(dlist **head1, dlist **tail1, dlist **head2, dlist **tail2, dlist **head3, dlist **tail3)
{
    int C_n1=0,C_n2=0;
    dlist *cal;
    dlist *temp1;
    dlist *temp2;
    cal=*head1;
    while(cal!=NULL)
    {
        cal=cal->next;
        C_n1++;
    }
    cal=*head2;
     while(cal!=NULL)
    {
        cal=cal->next;
        C_n2++;
    }
    if(C_n1>C_n2)
    {
        temp1=*tail1;
        temp2=*tail2;
    }
    else if (C_n2>C_n1)
    {
        temp1=*tail2;
        temp2=*tail1;
    }
    else
    {
         dlist *f_temp1;
         dlist *f_temp2;
        f_temp1=*head1;
        f_temp2=*head2;
        int flag=0;
        while(f_temp1->data==f_temp2->data&&flag==0)
        {  
            if(f_temp1->next==NULL)
            {
                flag=1;
                printf("Subtraction Completed\n");
                printf("0");
                return success;
            }
             f_temp1=f_temp1->next;
        f_temp2=f_temp2->next;

        }


        if(f_temp1->data>f_temp2->data)
        {
            temp1=*tail1;
            temp2=*tail2;
            
        }
        else
        {
           temp1=*tail2;
           temp2=*tail1; 
        }
        
       
    }
    ////////////Above it will check which num is larger;
    int c=0;
    while(temp1!=NULL||temp2!=NULL)
    {
        int n1,n2;
        if(temp1==NULL)
        {
            n1=0;
            n2=temp2->data;
        }
        else if(temp2==NULL)
        {
            n2=0;
            n1=temp1->data;
        }
        else
        {
            n1=temp1->data;
            n2=temp2->data;
        }
        ////Avoided manythings uk
        int val; 
        if(c==0)
        {
            if(n1>=n2)
            {
                val=n1-n2;
            }
            else
            {
                c=1;
                n1=n1+10;
                val=n1-n2;
            }
        }
        else
        {
            if(n1>=n2)
            {
                if(n1-n2-c>-1)
                {
                    val=n1-n2-c;
                    c=0;
                }
                else
                {
                    n1=10+n1;
                    val=n1-n2-c;
                    c=1;
                }
            }
            else
            {
                n1=n1+10;
                val=n1-n2-c;
                c=1;
            }
        }
        ////Carry and borrow done
       ///Storing the data in result
         dlist *new=malloc(sizeof(dlist));
         if(new==NULL){return failure;}
        if(*tail3==NULL)
        {
            new->data=val;
            *tail3=new;
            *head3=new;
            new->prev=NULL;
            new->next=NULL;      
        }
        else
        {
            (*head3)->prev=new;
            new->data=val;
            new->next=*head3;
            *head3=new;
            new->prev=NULL;
        }
        if(temp1!=NULL)
        {
            temp1=temp1->prev;
        }
        if(temp2!=NULL)
        {
            temp2=temp2->prev;
        }
    }
    printf("Subtraction Completed\n");
    return success;

}
status mul(dlist **head1, dlist **tail1, dlist **head2, dlist **tail2, dlist **head3, dlist **tail3)
{
    int C_n1=0, C_n2=0;
    dlist *cal;
    dlist *temp1;
    dlist *temp2;
    cal=*head1;
    while(cal!=NULL)
    {
        cal=cal->next;
        C_n1++;
    }
    cal=*head2;
    while(cal!=NULL)
    {
        cal=cal->next;
        C_n2++;
    }
    if(C_n1>C_n2)
    {
        temp1=*tail1;
        temp2=*tail2;
    }
    else if (C_n2>C_n1)
    {
        temp1=*tail2;
        temp2=*tail1;
    }
    else
    {
        dlist *f_temp1;
        dlist *f_temp2;
        f_temp1=*head1;
        f_temp2=*head2;
        int flag=0;
        while(f_temp1!=NULL && f_temp2!=NULL && f_temp1->data==f_temp2->data && flag==0)
        {   
            f_temp1=f_temp1->next;
            f_temp2=f_temp2->next;
        }

        if(f_temp1 != NULL && f_temp2 != NULL && f_temp1->data > f_temp2->data)
        {
            temp1=*tail1;
            temp2=*tail2;
        }
        else
        {
            temp1=*tail2;
            temp2=*tail1; 
        }
    }
    ///////////Sets the larger number as operand 1

    dlist *start_temp1 = temp1; // Save head-start for reset in each outer loop
    int count=0;

    while(temp2!=NULL)
    {
        dlist *p_head = NULL;
        dlist *p_tail = NULL;
        int carry = 0;

        // Reset temp1 for every digit of temp2
        temp1 = start_temp1;

      ///add zeros
        int n = count;
        while(n > 0)
        {
            dlist *new = malloc(sizeof(dlist));
            new->data = 0;
            new->prev = NULL;
            new->next = p_head;

            if(p_head == NULL) {
                p_head = new;
                p_tail = new;
            } else {
                p_head->prev = new;
                p_head = new;
            }
            n--;
        }

        // Step 2: Multiply temp1 digits with current temp2 digit
        while(temp1!=NULL)
        {
            int ans = ((temp1->data) * (temp2->data)) + carry;
            carry = ans / 10;
            ans = ans % 10;

            dlist *new = malloc(sizeof(dlist));
            new->data = ans;
            new->prev = NULL;
            new->next = p_head;

            if(p_head == NULL) {
                p_head = new;
                p_tail = new;
            } else {
                p_head->prev = new;
                p_head = new;
            }

            temp1=temp1->prev;
        }

        // Prepend remaining carry
        if(carry > 0)
        {
            dlist *new = malloc(sizeof(dlist));
            new->data = carry;
            new->prev = NULL;
            new->next = p_head;

            if(p_head == NULL) {
                p_head = new;
                p_tail = new;
            } else {
                p_head->prev = new;
                p_head = new;
            }
        }

        
        if(*head3 == NULL)
        {
            *head3 = p_head;
            *tail3 = p_tail;
        }
        else
        {
            dlist *t_res_head = NULL, *t_res_tail = NULL;
            dlist *cur1 = *tail3;
            dlist *cur2 = p_tail;
            int add_carry = 0;

            while(cur1 != NULL || cur2 != NULL || add_carry != 0)
            {
                int sum = add_carry;
                if(cur1 != NULL) { sum += cur1->data; cur1 = cur1->prev; }
                if(cur2 != NULL) { sum += cur2->data; cur2 = cur2->prev; }

                add_carry = sum / 10;
                
                dlist *new = malloc(sizeof(dlist));
                new->data = sum % 10;
                new->prev = NULL;
                new->next = t_res_head;

                if(t_res_head == NULL) {
                    t_res_head = new;
                    t_res_tail = new;
                } else {
                    t_res_head->prev = new;
                    t_res_head = new;
                }
            }

            // Free previous partial result
            dlist *curr = *head3;
            while(curr) {
                dlist *nxt = curr->next;
                free(curr);
                curr = nxt;
            }
            // Free current pass list
            curr = p_head;
            while(curr) {
                dlist *nxt = curr->next;
                free(curr);
                curr = nxt;
            }

            *head3 = t_res_head;
            *tail3 = t_res_tail;
        }

        count++;
        temp2=temp2->prev;
    }
    
    printf("Multiplication Successful\n");
    return success;
}
status my_division(dlist **head1, dlist **tail1, dlist **head2, dlist **tail2, dlist **head3, dlist **tail3)
{
    // Safety check for NULL pointers
    if (!head1 || !*head1 || !head2 || !*head2) {
        return failure;
    }

    // Check for Division by Zero
    if ((*head2)->data == 0 && (*head2)->next == NULL)
    {
        printf("Error: Division by zero\n");
        return failure;
    }

    // Reset result list pointers
    *head3 = NULL;
    *tail3 = NULL;

    // Helper working list for operand 1 (copying list 1)
    dlist *work_head = NULL;
    dlist *work_tail = NULL;

    dlist *curr = *head1;
    while (curr != NULL)
    {
        dlist *new_node = malloc(sizeof(dlist));
        new_node->data = curr->data;
        new_node->next = NULL;
        new_node->prev = work_tail;

        if (work_head == NULL) {
            work_head = new_node;
            work_tail = new_node;
        } else {
            work_tail->next = new_node;
            work_tail = new_node;
        }
        curr = curr->next;
    }

    int count = 0;

    while (1)
    {
        // Calculate length of working list and operand 2
        int C_n1 = 0, C_n2 = 0;
        dlist *cal = work_head;
        while (cal != NULL) {
            C_n1++;
            cal = cal->next;
        }
        cal = *head2;
        while (cal != NULL) {
            C_n2++;
            cal = cal->next;
        }

        int is_greater_or_equal = 0;

        if (C_n1 > C_n2) {
            is_greater_or_equal = 1;
        } else if (C_n1 < C_n2) {
            is_greater_or_equal = 0;
        } else {
            dlist *f_temp1 = work_head;
            dlist *f_temp2 = *head2;

            while (f_temp1 != NULL && f_temp2 != NULL && f_temp1->data == f_temp2->data) {
                f_temp1 = f_temp1->next;
                f_temp2 = f_temp2->next;
            }

            if (f_temp1 == NULL && f_temp2 == NULL) {
                is_greater_or_equal = 1;
            } else if (f_temp1 != NULL && f_temp2 != NULL && f_temp1->data > f_temp2->data) {
                is_greater_or_equal = 1;
            } else {
                is_greater_or_equal = 0;
            }
        }

        if (!is_greater_or_equal) {
            break;
        }

        // Subtraction: work_list - head2
        dlist *t1 = work_tail;
        dlist *t2 = *tail2;
        int borrow = 0;

        while (t1 != NULL)
        {
            int d1 = t1->data - borrow;
            int d2 = (t2 != NULL) ? t2->data : 0;

            if (d1 < d2) {
                d1 += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            t1->data = d1 - d2;
            t1 = t1->prev;
            if (t2 != NULL) t2 = t2->prev;
        }

        // Remove leading zeros
        while (work_head != NULL && work_head->data == 0 && work_head->next != NULL)
        {
            dlist *temp = work_head;
            work_head = work_head->next;
            work_head->prev = NULL;
            free(temp);
        }

        count++;
    }

    // Free working list memory
    curr = work_head;
    while (curr != NULL)
    {
        dlist *nxt = curr->next;
        free(curr);
        curr = nxt;
    }

    // Safely write Quotient into result list (*head3, *tail3)
    if (count == 0)
    {
        dlist *zero_node = malloc(sizeof(dlist));
        zero_node->data = 0;
        zero_node->next = NULL;
        zero_node->prev = NULL;
        *head3 = zero_node;
        *tail3 = zero_node;
    }
    else
    {
        int temp_count = count;
        while (temp_count > 0)
        {
            dlist *new_node = malloc(sizeof(dlist));
            new_node->data = temp_count % 10;
            new_node->prev = NULL;
            new_node->next = *head3;

            if (*head3 == NULL) {
                *head3 = new_node;
                *tail3 = new_node;
            } else {
                (*head3)->prev = new_node;
                *head3 = new_node;
            }
            temp_count /= 10;
        }
    }

    printf("Division Successful\n");
    return success;
}