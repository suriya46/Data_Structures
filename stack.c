#include<stdio.h>
#define MAX_SIZE 20
int data;
void push();
void pop();
void display();
int isEmpty();
int isFull();
struct stack{
int stk[MAX_SIZE];
int top;
}s;
int main()
{
    int ch,data;
    s.top=-1;
    while(1)
    {
        printf("\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        printf("\nEnter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:

    push();
    break;
case 2:
    pop();
    break;
case 3:
    display();
    break;
case 4:
    exit(1);
default:
    printf("Enter valid option!");
    break;
}
}
}
void push()
{
if(isFull())
{
    printf("\nOverflow\n");
}
else{
        printf("Enter the data to insert ");
scanf(" %d",&data);
    s.top++;
    s.stk[s.top]=data;
}
}
void pop()
{
if(isEmpty())
{
    printf("\nUnderflow");
}
else{

    data=s.stk[s.top];
      s.top--;
      printf("\nThe popped element is %d",data);
}
}
int isFull()
{
    if(s.top==(MAX_SIZE-1))
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(s.top==-1)
        return 1;
    else
        return 0;
}
void display()
{
    int i;
    printf("\nThe stack elements are\n");
   for(i=0;i<=s.top;i++)
   {
       printf("%d\t",s.stk[i]);
   }
}
