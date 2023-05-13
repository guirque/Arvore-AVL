#include <stdio.h>
#include <stdlib.h>

typedef struct tAVL
{
    int data;
    int BF; //Balancing Factor
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

//Inserts in Tree
tAVL *tinsertR(tAVL *t, int value, int currentBF)
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
        leaf->BF = currentBF;
        //Instead of returning the node as it is, return (to father) the new node inserted.
        return leaf;
    }
    //Go right
    else if(value > t->data) t->right = tinsertR(t->right, value, currentBF);
    //Go left
    else t->left = tinsertR(t->left, value, currentBF);

    //End of path (return itself to node father)
    return t;

}

//Void Format
void tinsert(tAVL **t, int value){*t = tinsertR(*t, value, 0);}