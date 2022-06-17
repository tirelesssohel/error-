
// shortest path to reach upper left to lower right corner
#include <stdio.h>
#include <stdlib.h>
int main(){
    int row, col, shiftCounter = 0, *startPtr, *endPtr, i, j;
    printf("Enter row and column of matrix: ");
    scanf("%d %d", &row, &col);
    int arr[row][col];
    printf("Enter %d elements: ", row*col);
    // taking matrix elements
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &arr[i][j]);
        }
    }



    // initial and final pointer
    startPtr = &arr[0][0];
    endPtr = &arr[row-1][col-1];
    i = 0;
    j = 0;
    printf("Way: \n");
    while(1){

        if(arr[i+1][j] == 1){
            i++;
            shiftCounter++;
            startPtr = &arr[i][j];
            printf("\(%d, %d\) ", i, j);
            if(startPtr == endPtr){
                printf("\nNeeded shift = %d\n", shiftCounter);
                exit(0);
            }
        }else if(arr[i][j+1] == 1){
            j++;
            shiftCounter++;
            startPtr = &arr[i][j];
            printf("\(%d, %d\) ", i, j);
            if(startPtr == endPtr){
                printf("\nNeeded shift = %d\n", shiftCounter);
                exit(0);
            }
        }else{
            printf("\nNot possible\n");
            exit(0);
        }
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
