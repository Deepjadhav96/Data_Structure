#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int Data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->",first->Data);
        first = first -> next;
    }
    printf("NULL\n");
}
int Count(PNODE first)
{
    int iCount = 0;
    while(first != NULL)
    {
        iCount++;
        first = first -> next;

    }
    return iCount;
}

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = iNo; 
    newn->next = NULL;

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;

    }

}
void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = iNo; 
    newn->next = NULL;

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
       temp = *first;
       while (temp -> next != NULL)
       {
            temp = temp -> next;
       }
       temp -> next = newn;
       
    }


}
void InsertAtPos(PPNODE first, int iNo, int iPos)
{
    int iCount = 0;
    iCount = Count(*first);

    int i = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first,iNo);
    }
    else if (iPos == iCount+1)
    {
        InsertLast(first,iNo);
    }
    else
    {
        temp = *first;
        newn = (PNODE)malloc(sizeof(NODE));
        newn ->Data = iNo;
        newn-> next = NULL;

        for(i = 1; i< iPos-1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp->next;
        temp->next = newn;
    }

}
void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;
    if(*first == NULL)
    {
        return;
    }
    else if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);

    }

}
void DeleteLast(PPNODE first)
{
     PNODE temp = NULL;
    if(*first == NULL)
    {
        return;
    }
    else if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
       while(temp->next->next != NULL)
       {
        temp = temp -> next;
       }
       free(temp->next);
       temp->next = NULL;

    }
}
void DeleteAtPose(PPNODE first, int iPos)
{
    int iCount = 0;
    iCount = Count(*first);

    int i = 0;

    
    PNODE temp = NULL;
    PNODE target = NULL;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first);
    }
    else if (iPos == iCount+1)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

         for(i = 1; i< iPos-1; i++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp->next = target->next;
        free(target);
        
    }
    


}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head , 111);
    InsertFirst(&head , 101);
    InsertFirst(&head , 51);
    InsertFirst(&head , 21);
    InsertFirst(&head , 11);
    

    Display(head);
    iRet = Count(head);
    printf("Count of nodes are:%d\n",iRet);

    InsertLast(&head, 121);
    InsertLast(&head, 151);
    InsertLast(&head, 161);

    Display(head);
    iRet = Count(head);
    printf("Count of nodes are:%d\n",iRet);

    InsertAtPos(&head, 4, 4);
    Display(head);
    iRet = Count(head);
    printf("Count of nodes are:%d\n",iRet);

    
    DeleteAtPose(&head, 4);
    Display(head);
    iRet = Count(head);
    printf("Count of nodes are:%d\n",iRet);

    DeleteFirst(&head);
    Display(head);
    iRet = Count(head);
    printf("Count of nodes are:%d\n",iRet);

    DeleteLast(&head);
    Display(head);
    iRet = Count(head);
    printf("Count of nodes are:%d\n",iRet);


    return 0;
}