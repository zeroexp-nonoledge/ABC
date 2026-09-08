#include<stdio.h>
#include<string.h>
#include "d_stack.h"
#include "types.h"

int main(int argc,char *argv[])
{
    if(argv[1][0]=='-'||argv[1][0]=='+')
    {
        argv[1][0]='0';
    }
    if(argv[3][0]=='-'||argv[3][0]=='+')
    {
        argv[3][0]='0';
    }
    dlist *head1=NULL;dlist *tail1=NULL;//Operand 1 
    dlist *head2=NULL;dlist *tail2=NULL;//Operand 2
    dlist *head3=NULL;dlist *tail3=NULL;//Result
    if(validate(argv,&head1,&tail1,&head2,&tail2)==failure)
    {
        printf("Validation Failed\n");
        return 0;
    }
    else
    {
        printf("Validation Completed\n");
        char ch=argv[2][0];
        switch (ch)
        {
        case '+':
        if(add(&head1,&tail1,&head2,&tail2,&head3,&tail3)==failure)
        {
            printf("Addition Failed\n");
            return 0;
        }
        break;
        case '-':
        sub(&head1,&tail1,&head2,&tail2,&head3,&tail3);
        break;
        case '*':
        mul(&head1,&tail1,&head2,&tail2,&head3,&tail3);
        break;
        case '/':
        my_division(&head1,&tail1,&head2,&tail2,&head3,&tail3);
        break;
        default:
        printf("Symbol not recognised\n ");
            break;
        }

        print_result(&head3,&tail3);
        printf("\n");    

    }
   
    

}