/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void fix_bst2(struct node *root, struct node **bef, struct node **first, struct node **mid,struct  node **last){
	if (root != NULL)
	{
		fix_bst2(root->left, bef, first, mid, last);
		if (*bef && (*bef)->data > root->data)
		{
			if (*first == NULL)
				*last = root;
			else
			{
				*first = *bef;
				*mid = root;
			}
		}
		*bef = root;
		fix_bst2(root->right, bef, first, mid, last);
	}
		
}
void node_swap(int *a, int *b)
{
	int *temp=NULL;
	*temp = *a;
	*a = *b;
	*b = *temp;
}
void fix_bst(struct node *root)
{
	if (root == NULL)
		return;
	struct node *first=NULL,*last=NULL,*mid=NULL,*bef=NULL;
	fix_bst2(root,&bef,&first,&mid,&last);
	if ((first&&mid) == 1)
		node_swap(&(first->data), &(mid->data));
	else if ((first&&last) == 1)
		node_swap(&(first->data), &(last->data));
}
