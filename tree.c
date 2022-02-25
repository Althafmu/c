#include <stdio.h>
#include <stdlib.h>
struct node
{
  int key;
  struct node *left, *right;
};

struct node *newNode(int item) 
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct node *root) 
{
  if (root != NULL) 
  {
    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);
  }
}

void postorder(struct node *root) 
{
  if (root != NULL) 
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d -> ", root->key); 
  }
}

void preorder(struct node *root) 
{
  if (root != NULL) 
  {
    printf("%d -> ", root->key);
    preorder(root->left);
    preorder(root->right);
  }
}

struct node *insert(struct node *node) 
{
	int key;
	printf("\nEnter the element : ");
	scanf("%d",&key);
  	if (node == NULL) 
  	{
  	return newNode(key);
	}
	if (key < node->key)
	{
	  	node->left = insert(node->left);
  	}
  	else
  	{   
  		node->right = insert(node->right);
  	}
  	return node;
}

struct node *minValueNode(struct node *node) 
{
	  struct node *current = node;
	  while (current && current->left != NULL)
	  	current = current->left;
	  return current;
}

struct node *delete(struct node *root )
 {
  int key;
   	printf("\nenter the element to be deleted : ");
 	scanf("%d",&key);
  	if (root == NULL) return root;
	if (key < root->key)
 	   	root->left = delete(root->left);
 	else if (key > root->key)
 	 	root->right = delete(root->right);
	else
	{
    		if (root->left == NULL) 
    		{
      		struct node *temp = root->right;
      		free(root);
      		return temp;
   		}
     		else if (root->right == NULL) 
     		{
     		 	struct node *temp = root->left;
     	 		free(root);
     	 		return temp;
     		}
		struct node *temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = delete(root->right);
  	} 
  return root;
}

int main()
 {
  struct node *root = NULL;
  int n;
  loop:
  printf("\n1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit");
  printf("\nEnter the choice : ");
  scanf("%d",&n);
  switch(n)
  {
  	case 1:root = insert(root);
  	       goto loop;
  	case 2:root = delete(root);
  		 goto loop;
  	case 3:inorder(root);
  		 goto loop;
  	case 4:preorder(root);
  		 goto loop;
  	case 5:postorder(root);
  		 goto loop;
  	case 6:break;
  }
}
