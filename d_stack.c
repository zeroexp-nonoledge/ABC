//Vikram Prakash
#include<stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "d_stack.h"
#include "types.h"

void print_result(dlist **head3,dlist **tail3)
{
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
    while((*head3)->data==0&&*head3!=NULL)
    {
        dlist *t;
        t=*head3;
        *head3=t->next;
        (*head3)->prev=NULL;
        free(t);
    }
    printf("Subtraction Completed\n");
    return success;

}

status mul(dlist **head1, dlist **tail1, dlist **head2, dlist **tail2, dlist **head3, dlist **tail3)
{
    int C_n1=0,C_n2=0;
    int ans;
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
                f_temp1=f_temp1->next;
                f_temp2=f_temp2->next;
                break;
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
     ///////////Sets the larger number as operand 1
    dlist *new=malloc(sizeof(dlist));
    dlist *r_head=NULL;
    dlist *r_tail=NULL;
    
    
    printf("Multiplication Successful\n");
    return success;
}


status my_division(dlist **head1, dlist **tail1, dlist **head2, dlist **tail2, dlist **head3, dlist **tail3)
{
    printf("Division not yet implemented\n");
    return success;
}
