#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int ID;
char cname[100],Quantity[20],mob[11],Address[30],flavour[15],amount[10];
struct node* next;
}*head=NULL,*p,*q,*t;
int sr;
void main()
{
 int ch,a;
void insert_end();
void delete_begin();
void delete_end();
void update();
void display();
printf("\n# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n");
printf("\n\t|\t\t Ice cream Parlour \t\t|\n");
while(1)
        {
printf("\n# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n");
            printf("\n\t|\t\t1.Ice cream order \t\t|\t\n");
            printf("\t|\t\t2.Completed order \t\t|\t\n");
            printf("\t|\t\t3.Display orders \t\t|\t\n");
            printf("\t|\t\t4.Exit from system \t\t|\t\n");
printf("\n# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n\n");

            printf("\n\nEnter your choice : ");
            scanf("%d",&ch);
            //p->ID=0;

   switch(ch)
        {
           case 1:
               printf("\n\t|-----------------------------------------------------------------------------|\n");
               printf("\t| Flavours:- vanilla, choco, cookies, mint_choco, pecan,  mango , strawberry  |\t\n");
               printf("\t|-----------------------------------------------------------------------------|\n");
               printf("\t| price:-    100 RS | 90 RS | 120 RS |   70 RS  | 100 RS | 80 RS |  120 RS    |\t\n");
               printf("\t|-----------------------------------------------------------------------------|\n");


               a=1;
                 while(a==1)
                 {
                 printf("\nUpload an order\n");
                 ch=1;

                 switch(ch)
                 {
                     case 1:insert_end();
                            break;
                 }
                 printf("Do you want to continue for your next orders:\n\tYes(1)\n\tNo (0) \nEnter your choice : ");
                 scanf("%d",&a);
                 }
                 break;
           case 2:printf("\n Completed order\n");
                    printf("\n\n1.completed first order");
                    printf("\n\n2.completed last order");
                    printf("\n\nEnter your choice :- ");
                    scanf("%d",&ch);
                 switch(ch)
                 {
                     case 1:delete_begin();
                            break;
                     case 2: delete_end();
                            break;
                     default:printf("OOPS ! Your entered wrong choice... ):-");
                     break;
                 }
                 break;
           case 3:display();
                 break;
           case 4:exit(0);
           default:printf("\t\t\tOOPS ! Your entered wrong choice... ):-\n\n");
        }

    }
}

void insert_end()
{
  p=(struct node*)malloc(sizeof(struct node));
  p->next=NULL;
  printf("\tOrder ID : ");
  scanf("%d",&p->ID);
  printf("\tCustomer Name :");
  scanf("%s",p->cname);
  printf("\tIce cream flavour :");
  scanf("%s",p->flavour);
  printf("\tQuantity of ice cream :");
  scanf("%s",p->Quantity);
  printf("\tAmount :");
  scanf("%s",p->amount);
  printf("\tCustomer Address: ");
  scanf("%s",p->Address);
  printf("\tCustomer Mobile Number : ");
  scanf("%s",p->mob);
   if(head==NULL)
     {
      head=p;
      p->next=NULL;
     }
 else
{
   t=head;
   while(t->next!=NULL)
    {
     t=t->next;
    }
    t->next=p;
    p->next=NULL;
}
}


void delete_begin()
{
    if(head==NULL)
    {
        printf("\n the list is empty...\n ");
        return;
    }
    else
    {
        q=head;
printf("You have completed order : \n\n\tID Number :%d \n\tCustomer name :%s \n\tIce cream  flavour :%s\n\tIce cream Quantity :%s\n \t",q->ID,q->cname,q->flavour,q->Quantity);
        head=head->next;
        free(q);
    }
}


void delete_end()
{
    if(head==NULL)
    {
        printf("\nthe list is empty.....\n");
        return;
    }
    else
    {
     q=head;
     while(q->next->next!=NULL)
     {
         q=q->next;
     }
     p=q->next;

printf("You have completed order : \n\n\tID Number :%d \n\tCustomer name :%s \n\tIce cream  flavour :%s\n\tIce cream Quantity :%s\n \t",p->ID,p->cname,p->flavour,p->Quantity);
     q->next=NULL;
     free(p);
    }
}


void display()
{
    if(head==NULL)
    {

        printf("\nthe list is empty\n");
        return;
    }
    else
    {
        q=head;

        printf("\n\nID N0. \tCustomer NAME \tIce cream flavour\t Quantity \t Amount \t Address \t Mobile Number \n");
        while(q->next!=NULL)
        {
            printf("\n%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",q->ID,q->cname,q->flavour,q->Quantity,q->amount,q->Address,q->mob);
            q=q->next;
        }
          printf("\n%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",q->ID,q->cname,q->flavour,q->Quantity,q->amount,q->Address,q->mob);
    }
    getch();
}
