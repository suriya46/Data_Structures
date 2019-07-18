#include<stdio.h>
int top=-1;
 char stack[100];
int main()
{

    char str[100];int i=0;
    gets(str);
    while(*(str+i)!='\0')
    {
        if(*(str+i)=='(' || *(str+i)=='{' || *(str+i)=='[')
            {
                push(*(str+i));
            }
        if(*(str+i)==')' || *(str+i)=='}' || *(str+i)==']')
            {
                push(*(str+i));
                check(*(str+i));

            }
            i++;
    }
    if(top==-1)
    {
        printf("Balanced");

    }
    else
        printf("No");
}
void push(char ch)
{
    top++;
    stack[top]=ch;
}
void pop(char ch)
{
    top=top-2;
}
void check(char ch)
{
    switch(ch){
    case ')':
        if(stack[top-1]=='(' ){
            pop('(');
        break;
        }
    case '}':
        if(stack[top-1]=='{')
{
    pop('{');

        break;
}
    case ']':
        if(stack[top-1]=='['){
            pop('[');
        break;
        }
}
}
