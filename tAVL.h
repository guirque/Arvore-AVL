#include <stdio.h>
#include <stdlib.h>

typedef struct tAVL
{
    int data;
    struct tAVL *left;
    struct tAVL *right;
} tAVL;

//Prints in order
void tprint(tAVL* t)
{
    if(t != NULL)
    {
        tprint(t->left);
        printf("%d ", t->data);
        tprint(t->right);
    }
}

int getHeight(tAVL *t)
{
    if(t != NULL)
    {
        int heightLeft, heightRight;
        heightLeft = getHeight(t->left);
        heightRight = getHeight(t->right);
        if(heightLeft > heightRight) return heightLeft + 1;
        else return heightRight + 1;
    }
    return 0;
}

//Prints a specific level
void tprintLevel(tAVL *t, int level, int levelOfT)
{
    if(t != NULL)
    {
        if(levelOfT == level) printf("%d ", t->data);
        else
        {
            tprintLevel(t->left, level, levelOfT + 1);
            tprintLevel(t->right, level, levelOfT + 1);
        }
    }
}

//Prints all the levels of a given tree
void tprintAllLevels(tAVL *t)
{
    int height = getHeight(t);
    for(int i = 0; i < height; i++)
    {
        tprintLevel(t, i, 0);
        printf("\n");
    }
}

//Check Balance
tAVL *checkBalance(tAVL *t)
{
    if(t == NULL) return NULL;

    int leftHeight = getHeight(t->left);
    int rightHeight = getHeight(t->right);

    //Rotate right
    if(leftHeight - rightHeight > 1)
    {
        //printf("\n[%d][LeftHeight: %d | RightHeight: %d]", t->data, leftHeight, rightHeight);
        //printf(" - [Rotating right]");
        printf("[Rotating Right] because %d is unbalanced.\n", t->data);
        
        tAVL *leftSubtree = t->left;        //leftSubtree = 42
        tAVL *cutPart = leftSubtree->right; //cutPart = null
        t->left = NULL;                     //Breaking connection: 42 <- 90
        leftSubtree->right = t;             //42 -> 90
        leftSubtree->left->right = cutPart; //41 -> null

        return leftSubtree;
    }
    //Rotate left
    else if(rightHeight - leftHeight > 1)
    {
        //printf("\n[%d][LeftHeight: %d | RightHeight: %d]", t->data,leftHeight, rightHeight);
        //printf("- [Rotating left]");
        printf("[Rotating Left] because %d is unbalanced.\n", t->data);
        
        tAVL *rightSubtree = t->right;        //rightSubtree = 100
        tAVL *cutPart = rightSubtree->left; //cutPart = 95
        t->right = NULL;                     //Breaking connection: 90 -> 100
        rightSubtree->left = t;             //90 <- 100
        rightSubtree->left->right = cutPart; //90 -> 95
        
        return rightSubtree;
    }
    return t;
}

//Inserts in Tree
tAVL *tInsertR(tAVL *t, int value)
{
    //Current BF will hold -1, 0, +1, regarding the difference in height between the right and left subtrees (right - left)

    //Found where to insert leaf
    if(t == NULL)
    {
        //Create Left
        tAVL *leaf = (tAVL*)malloc(sizeof(tAVL));
        leaf->data = value;
        leaf->left = NULL; 
        leaf->right = NULL;
        //Instead of returning the node as it is, return (to father) the new node inserted.
        return leaf;
    }
    //Go right
    else if(value > t->data)
    {
        t->right = tInsertR(t->right, value);
        return checkBalance(t);
    }
    //Go left
    else 
    {
        t->left = tInsertR(t->left, value);
        return checkBalance(t);
    }

    //End of path (return itself to node father)
    return t;

}

//Void Format
void tinsert(tAVL **t, int value){*t = tInsertR(*t, value);}