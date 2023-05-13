#include <stdio.h>
#include <stdlib.h>

typedef struct tAVL
{
    int data;
    int BF; //Balancing Factor
    tAVL *left;
    tAVL *right;
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