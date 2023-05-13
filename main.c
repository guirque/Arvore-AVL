#include <stdio.h>
#include <stdlib.h>
#include "tAVL.h"

int main()
{
    tAVL *myTree;
    tinsert(&myTree, 8);
    tinsert(&myTree, 5);
    tinsert(&myTree, 2);
    tinsert(&myTree, 40);
    tinsert(&myTree, 90);

    printf("Tree (In Order): ");
    tprint(myTree);
    printf("\nHeight: %d", getHeight(myTree));
    printf("\nAll levels: \n");
    tprintAllLevels(myTree);
    int pause; scanf("%d", &pause);
    return 0;
}