#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct stack
{
int data;
struct stack* next;

}st;

void push(st** top, int data)
{
    st* new = (st*)malloc(sizeof(st));
    
    new->data = data;
    new->next = *top;
    *top = new;
    
}

int peek(st* top)
{
    return top->data;
}

int empty(st* top)
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}
void pop(st** top)
{
    
        st* temp=*top;
        *top=(*top)->next;
        free(temp);
        temp=NULL;    
}

int getMaxArea(int* hist, int n)
{
    int max=0;
    int area=0;
    int i=0,d=0,x=0;
    st* head=NULL; 

    while(i<n)
    {
        if(empty(head) || hist[i]>hist[peek(head)])
        {
            push(&head,i);
        }
        else
        {
            while(!empty(head) && hist[i]<=hist[peek(head)])
            {
                x=hist[peek(head)];
                pop(&head);
                d=empty(head)?i:i-peek(head)-1;
                area=x*d;
                if(area>max)
                    max=area;
            }
            push(&head,i);
        }
        i++;
    }
    while(!empty(head))
    {
        x=hist[peek(head)];
        pop(&head);
        d=empty(head)?i:i-peek(head)-1;
        area=x*d;
        if(area>max)
             max=area;
    }
    return max;
}


int main() {
   
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        
    }
    
    int r = getMaxArea(arr, n);
    printf("%d", r);
    return 0;
}

