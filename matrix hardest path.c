

// shortest path to reach upper left to lower right corner
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROW 5
#define COL 5

int arr[ROW][COL], *startPtr, *endPtr, i = 0, j = 0;

// checking if going to negative index
bool isNegative(int a, int b){
    if(a < 0 || b < 0){
        return true;
    }
    return false;
}

void goDown(int a, int b){
    if(arr[i+1][j] != 0){
        i++;
        startPtr = arr[i][j];
        if(startPtr == endPtr){
            printf("Possible\n");
            exit(0);
        }else{
            goDown(i, j);
            goRight(i, j);
            goLeft(i, j);
            goUp(i, j);
        }
    }
}

void goRight(int a, int b){
    if(arr[i][j+1] != 0){
        j++;
        startPtr = arr[i][j];
        if(startPtr == endPtr){
            printf("Possible\n");
            exit(0);
        }else{
            goDown(i, j);
            goRight(i, j);
            goLeft(i, j);
            goUp(i, j);
        }
    }
}

void goUp(int a, int b){
    if(!isNegative(a, b) && arr[i-1][j] != 0){
        i--;
        startPtr = arr[i][j];
        if(startPtr == endPtr){
            printf("Possible\n");
            exit(0);
        }else{
            goRight(i, j);
            goLeft(i, j);
            goUp(i, j);
            goDown(i, j);
        }
    }
}

void goLeft(int a, int b){
    if(!isNegative(a, b) && arr[i][j-1] != 0){
        j--;
        startPtr = arr[i][j];
        if(startPtr == endPtr){
            printf("Possible\n");
            exit(0);
        }else{
            goDown(i, j);
            goLeft(i, j);
            goRight(i, j);
            goUp(i, j);
        }
    }
}


int main(){

    printf("Enter %d elements: ", ROW*COL);
    // taking matrix elements
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    // initial and final pointer
    startPtr = &arr[0][0];
    endPtr = &arr[ROW-1][COL-1];

    if(arr[i+1][j] != 0){
        goDown(i, j);
    }
    i = 0;
    j = 0;
    if(arr[i][j+1] != 0){
        goRight(i, j);
    }


return 0;
}




/*

possible:
1 0 0 0 0
1 1 0 1 1
0 1 1 1 0
1 0 0 1 0
1 0 0 1 1

possible:
1 1 1 0 0
0 0 1 1 1
0 1 1 1 0
1 0 0 1 0
1 0 0 1 1

impossible:
1 1 1 0 0
1 0 1 1 1
1 0 1 1 0
0 0 0 1 0
1 0 0 1 1




*/
