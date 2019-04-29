#include<stdio.h>
void ins_beg();
struct node
{
struct node *left;
struct node *right;
int data;
};
struct node *root=NULL;
int main()
{
    int j,option;
    printf("DOUBLY LINKED LIST\n");
    while(1){
printf("\n");
printf("\t\t1.Insertion at beginning\n");
printf("\t\t2.Insertion at end\n");
printf("\t\t3.Insertion at Position...\n");
printf("\t\t4.Deletion at beginning\n");
printf("\t\t5.Deletion at end\n");
printf("\t\t6.Delete particular element..\n");
printf("\t\t7.Search\n");
printf("\t\t8.Update\n");
printf("\t\t9.Display\n");
printf("\t\t10.length\n");
printf("\t\t11.Exit");
printf("\nEnter your option\n");
scanf("%d",&option);
switch(option)
{
case 1:
    ins_beg();
    break;
case 2:
    ins_end();
    break;
case 3:
    ins_pos();
    break;
case 4:
    del_beg();
    break;
case 5:
    del_end();
    break;
case 6:
    del_pos();
    break;
case 7:
    search();
    break;
case 8:
    update();
    break;
case 9:
    display();
    break;
case 10:
    j=length();
    printf("\n The number of elements in the list is %d",j);
    break;
case 11:
    exit(1);
default:
    printf("Enter valid option");

}
}
}
void ins_beg(){
int val,value;
struct node *temp;
temp=(struct node*)malloc(1*sizeof(struct node));
temp->left=NULL;
temp->right=NULL;
if(temp==NULL)
{
    printf("\n memory not allocated\n");
}
else{
printf("Enter the data to insert\n");
scanf("%d",&value);
temp->data=value;
if(root==NULL)
{
    root=temp;
    printf("\n first element is inserted\n");
}
else{
    temp->right=root;
    root->left=temp;
    root=temp;

}
printf("\nINSERTION SUCCESSFULL!!\n");
display();
}
}
void ins_end(){
    int val,value;
struct node *temp,*p;
p=root;
temp=(struct node*)malloc(sizeof(struct node));
temp->left=NULL;
temp->right=NULL;
if(temp==NULL)
{
    printf("\n memory not allocated\n");
}
else{
printf("Enter the data to insert\n");
scanf("%d",&value);
temp->data=value;

if(root==NULL)
{
    root=temp;
}
else{
        while(p->right!=NULL)
        {
         p=p->right;
        }
          p->right=temp;
   temp->left=p;


}
printf("\nINSERTION SUCCESSFULL!!\n");
display();
}
}
void ins_pos(){
    int val,pos,i=1,value,len;
struct node *temp,*p;
p=root;
temp=(struct node*)malloc(sizeof(struct node));
temp->left=NULL;
temp->right=NULL;
if(temp==NULL)
{
    printf("\n memory not allocated\n");
}
else{
printf("Enter the position to insert\n");
scanf("%d",&pos);
printf("Enter the data to insert\n");
scanf("%d",&value);
temp->data=value;
len=length();
if(root==NULL)
{
    root=temp;
}
if(pos==1)
{
      temp->right=root;
    root->left=temp;
    root=temp;
}
else{
if(len<pos)
{
    printf("\nPosition is not available!!!\n");
}
else{

    while(i<pos-1)
    {
        p=p->right;
        i++;
    }
    temp->right=p->right;
    p->right->left=temp;
    temp->left=p;
    p->right=temp;
}

}
printf("\nINSERTION SUCCESSFULL!!\n");
display();
}
}
int length()
{ int count=0,i=0;
    struct node *p;
    p=root;
    while(p!=NULL)
    {
     p=p->right;
     i++;
    }
    return i;
}
void display()
{
    struct node *p;
    p=root;
    if(root==NULL)
    {
        printf("No data in the list...List is empty!!!");
    }
    else
    {
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            p=p->right;
        }
    }
}
void search()
{
    int j,k=1,flag=0,m;
    int value;
    printf("Enter the data to search\n");
    scanf("%d",&value);
    struct node *p;
    p=root;
    j=length();
    m=j+1;
    while(k!=m)
    {
        if(flag==0)
        {
            flag=0;
        }
        else{
            flag=1;
        }
        if(p->data==value)
        {
            printf("\nThe element is found at the position %d\n",k);
            flag=1;
             p=p->right;
        }
        else{
            p=p->right;
        }
        k++;
    }
    if(flag==0)
    {
        printf("\nThe element is not found\n");
    }
}
void update()
{
       int j,k=1,val,flag=0;
    int value;
    printf("Enter the old data to update\n");
    scanf("%d",&value);
     printf("Enter the new data to insert\n");
    scanf("%d",&val);
    struct node *p;
    p=root;
    j=length();
    while(k!=j)
    {
        if(p->data==value)
        {
            p->data=val;
            flag=1;
            break;
        }
        else{
            p=p->right;
        }
        k++;
    }
    if(flag==0)
    {
        printf("\nElement not found\n");
    }
    display();
}
void del_beg()
{

    struct node *p;
    p=root;
    if(root==NULL)
    {
        printf("\nNo element to delete\n");
    }
    else{
    root=p->right;
}

display();
}
void del_end()
{
    struct node *p,*temp;
    p=root;
     if(root==NULL)
    {
        printf("\nNo element to delete\n");
    }
   else if(p->right==NULL)
    {
    root=NULL;
    }
    else{
    while(p->right!=NULL)
    {
        p=p->right;
    }

    p->left->right=NULL;
    free(p);


}
printf("\n Element deleted\n");

display();
}
void del_pos()
{
    struct node *p,*temp;
    int pos,len,i=1;
    printf("\nEnter the position to delete the element :\n ");
    scanf("%d",&pos);
    len=length();
    if(len<pos)
{
    printf("\nPosition is not available!!!\n");
}
else{

    while(i<pos-1)
    {
        p=p->right;
        i++;
    }
temp=p->right;
p->right=temp->right;
temp->right->left=p;
free(temp);

}

display();
}

