#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;         
    struct node *next; 
}*head;
void LinkedList(int n);


int main()
{
    int n;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    LinkedList(n);

    printf("\nData in the list \n");

    return 0;
}
void LinkedList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("cannot alloc memore");
        return;
    }


    printf("Enter the number: ");
    scanf("%d", &data);

    head->data = data; 
    head->next = NULL; 


    temp = head;
    for(i=2; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; 
        newNode->next = NULL; 

        temp->next = newNode; 
        temp = temp->next;    
    }
}

void addNode (struct node **head, int data)
{

  struct node *newnode = (struct node *) malloc (sizeof (struct node));

  newnode->data = data;
  newnode->next = NULL;

  //need this if there is no node present in linked list at all
  if (*head == NULL)
    {
      *head = newnode;
      return;
    }

  struct node *temp = *head;

  while (temp->next != NULL)
    temp = temp->next;

  temp->next = newnode;
}
void removeNodes(struct node **head_ref, int x){
    struct node  *temp = *head_ref, *prev;

    if (temp != NULL && temp->data > x) {
        *head_ref = temp->next; 
        free(temp); 
        temp = *head_ref; 
   
    while (temp != NULL) {
   
        while (temp != NULL && temp->data <= x) {
            prev = temp;
            temp = temp->next;
        }
   
        if (temp == NULL)
            return;
   
        prev->next = temp->next;
   
        free( temp); 
   
        
        temp = prev->next;
    }
}