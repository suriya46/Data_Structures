#include<stdio.h>
int array[1000],i,n,j,pos,val,flag=0,num,temp,value,f=0;
void insert();
void delete();
void update();
void search();
void sort();
void display();
int main()
{
    int array[1000],i,n,j,pos,val,flag=0,num,temp,value;
    int ch;

while(1)
{
    printf("\n1.Insertion\n");
    printf("2.Deletion\n");
    printf("3.Updation\n");
    printf("4.display\n");
    printf("5.Searching\n");
    printf("6.Sorting\n");
    printf("7.Exit\n");


 scanf("%d",&ch);
switch(ch)
{
case 1:
    insert();
    break;
case 2:
    delete();
    break;
case 3:
    update();
    break;
case 4:
    display();
    break;
case 5:
     search();
     break;
case 6:
     sort();
     break;
case 7:
    exit(1);
default:
    printf("Enter valid option...");
}

}
}
void insert()
{
    printf("Enter the no of elements to insert\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)

    {
        scanf("%d",&array[i]);


    }

display();
}
void delete()
{
    int flag1=0;
    printf("Enter element to delete\n");
    scanf("%d",&num);
    for(i=0;i<n;i++)

    {
        if(array[i]==num)
        {
flag1=1;
            while(i<n)
            {
                array[i]=array[i+1];
                i++;

                }
                n=n-1;
            break;
        }

    }
    if(flag1==0){
    printf("\nElement not found");
    }
    display();
}
void update()
{
    printf("Enter the position to update\n ");
    scanf("%d",&pos);
        printf("Enter the value to be updated in the position %d\n ",pos);
   scanf("%d",&val);
    array[pos]=val;
 display();
}
void search()
{
  printf("Enter the element to search\n ");
  scanf("%d",&value);
  for(i=0;i<n;i++)
  {
      if(array[i]==value)
      {
          printf("The elemnent is found in the position %d",i);
          flag=1;
      }
  }
  if(flag==0)
  {
      printf("\n The element is not found");
  }

}
void sort()
{
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(array[j]<array[i])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    display();
}
void display()
{
    printf("\nThe elements of the array:");
    for(i=0;i<n;i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
}
