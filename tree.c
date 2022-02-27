#include<stdio.h>
struct node
{
  struct node *leftChild;
  int data;
  struct node *rightChild;
};

struct node *root=NULL;

int main()
{
  int choice,element;
  do {
        printf("1-insert\n2-delete\n3-search\n4-display\n5-exit\n----------------\nEnter Your choice");
        scanf("%d",&choice);

        switch(choice)
        {
          case 1:printf("insret");
                 break;

          case 2:printf("delete");
                 break;

          case 3:printf("search");
                 break;

          case 4:printf("display");
                 break;

          default:printf("invalid choice");
        }
  } while(choice!=5);

  getch();
  return 0;

}

insert()
{
  struct node *newNode,*parentNode,*currentNode;
  int ele;
  printf("Enter the value");
  scanf("%d",&ele);
  newNode = (struct node)malloc(sizeof(struct node));
  newNode->data=ele;
  newNode->leftChild=NULL;
  newNode->rightChild=NULL;

  if(root==NULL)
  {
    root=newNode;
    root->leftChild=NULL;
    root->rightChild=NULL;
  }
  else
  {
    parentNode=NULL;
    currentNode=root;
    while(currentNode!=NULL)
    {
      parentNode=currentNode;
      if(ele<=currentNode->data)
      {
        currentNode=currentNode->leftChild;
      }
      else
      {
        currentNode=currentNode->rightChild;
      }
    }

    if(ele<=parentNode->data)
    {
      parentNode->leftChild=newNode;
    }
    else
    {
      parentNode->rightChild=newNode;
    }
  }

    printf("value inserted successfully");
}

delete()
{
  struct node *currentNode,*parentNode,*tempRight,*tempParent;
  int key;
  currentNode=root;
  parentNode=NULL;
  printf("Enter the key:");
  scanf("%d",&key);
  while(currentNode->data!=key && currentNode!=NULL)
  {
    parentNode=currentNode;
    if(key<currentNode->data)
    {
        currentNode=currentNode->leftChild;
    }
    else if(key>currentNode->data)
    {
      currentNode=currentNode->rightChild;
    }

  }
  if(currentNode==NULL)
  {
    printf("NOT FOUBND");
  }
  else
  {
    if(currentNode->leftChild==NULL && currentNode->rightChild==NULL)
    {
      if(parentNode==NULL)
      {
        free(root);
        root=NULL;
      }
      else
      {
        if(parentNode->leftChild==currentNode)
        {
          parentNode->leftChild=NULL;
        }
        else
        {
          parentNode->rightChild=NULL;
        }
        free(currentNode);
      }
    }
    else if(currentNode->leftChild!=NULL && currentNode->rightChild==NULL)
    {
      if(parentNode==NULL)
      {
        parentNode=root;
        currentNode=parentNode->leftChild;
        parentNode->data=currentNode->data;
        free(currentNode);
      }
      else
      {
        if(parentNode->leftChild==currentNode)
        {
          parentNode->leftChild=currentNode->leftChild;
        }
        else
        {
          parentNode->rightChild=currentNode->leftChild;
        }

        free(currentNode);
      }
    }
  }
}
