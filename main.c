#include <stdio.h>
#include <stdlib.h>
#include "tAVL.h"

int main()
{
    tAVL *myTree;
    //tinsert(&myTree, 90);
    //tinsert(&myTree, 100);
    //tinsert(&myTree, 95);
    //tinsert(&myTree, 101);
    //tinsert(&myTree, 42);
    //tinsert(&myTree, 41);
    //tinsert(&myTree, 50);

    tinsert(&myTree, 100);
    tinsert(&myTree, 90);
    tinsert(&myTree, 200);
    tinsert(&myTree, 125);
    tinsert(&myTree, 115);
    tinsert(&myTree, 112);
    tinsert(&myTree, 210);
    tinsert(&myTree, 205);
    tinsert(&myTree, 215);
    tinsert(&myTree, 220);

    printf("Tree (In Order): ");
    tprint(myTree);
    printf("\nHeight: %d", getHeight(myTree));
    printf("\nAll levels: \n");
    tprintAllLevels(myTree);
    int pause; scanf("%d", &pause);
    return 0;
}