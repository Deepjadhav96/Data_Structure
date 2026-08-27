#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node** PPNODE;

void Display(PNODE first)
{
    while (NULL != first)
    {
        printf("| %d |->",first->data);
        first = first -> next;
    }
    printf("NULL\n");
    

}
int Count(PNODE first)
{
    int iCount = 0;
    while (NULL != first)
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

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(NULL == *first)
    {
        *first = newn;
    }
    else 
    {   
        newn->next = *first;
        (*first)->prev = newn;      //$
        *first = newn;

    }

}
void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else 
    {   
        temp  = *first;

        while(temp ->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
        newn->prev = temp;
 

    }
}
void InsertAtPos(PPNODE first, int iPos, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCount = 0;
    iCount = Count(*first);

    int i = 0;

    if((iPos < 1)  && (iCount+1 < iPos))
    {
        printf("Invalid position");
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(first, iNo);
    }
    else if (iPos == iCount)
    {
        InsertLast(first, iNo);
    }
    else
    {
        temp = *first;
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = iNo;
        newn->prev = NULL;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp ->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;//$

        temp->next = newn;
        newn->prev = temp;   //$
        
    }


}

void DeleteFirst(PPNODE first)
{
    if(*first == NULL)
    {
        return;
    }
    else if(((*first)->next == NULL) )
    {
        free(*first);
        *first = NULL;
    }
    else
    {   
        *first = (*first) -> next;
        free((*first)->prev);
        (*first)->prev = NULL;

    }
}
void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
    
    if(*first == NULL)
    {
        return;
    }
    else if(((*first)->next == NULL) )
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
void DeleteAtPos(PPNODE first, int iPos)
{
    
    PNODE temp = NULL;

    int iCount = 0;
    iCount = Count(*first);

    int i = 0;

    if((iCount > 1)  && (iCount+1 < iPos))
    {
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst(first);
    }
    else if (iPos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(i = 1; i< iPos-1; i++)
        {
            temp = temp ->next;
        }
        temp -> next = temp -> next -> next;
        free(temp->next->prev);
        temp->next->prev = temp;
    
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);
    iRet = Count(head);
    printf("Count of nodes are: %d\n",iRet);

    InsertLast(&head,111);
    Display(head);
    iRet = Count(head);
    printf("Count of nodes are: %d\n",iRet);

    InsertAtPos(&head,4,61);
    Display(head);
    iRet = Count(head);
    printf("Count of nodes are: %d\n",iRet);

    DeleteAtPos(&head,4);
    Display(head);
    iRet = Count(head);
    printf("Count of nodes are: %d\n",iRet);


    DeleteFirst(&head);
    Display(head);
    iRet = Count(head);
    printf("Count of nodes are: %d\n",iRet);

    DeleteLast(&head);
    Display(head);
    iRet = Count(head);
    printf("Count of nodes are: %d\n",iRet);
    return 0;
}