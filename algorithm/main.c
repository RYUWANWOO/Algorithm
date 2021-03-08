#include <stdio.h>
#include <stdlib.h>

#define HORIGENTAL 0
#define VERTICAL 1

void matrix_init(int ***pmatrix,int row,int col){
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            (*pmatrix)[i][j] = 0;
        }
    }

}

void get_result(int ***pmatrix,int length,int direction,int xpos,int ypos){
    
    int temp_xpos = xpos-1;
    int temp_ypos = ypos-1;
    
    if(direction == HORIGENTAL){
        for(int i=0;i<length;i++){
            (*pmatrix)[temp_xpos][temp_ypos+i] = 1;
        }
    }
    else if(direction == VERTICAL){
        for(int i=0;i<length;i++){
            (*pmatrix)[temp_xpos+i][temp_ypos] = 1;
        }
    }
}

void print_matrix(int ***pmatrix,int row,int col){
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",(*pmatrix)[i][j]);
        }
        printf("\n");
    }
}

int main(void){
        
    
    int length,direction,xpos,ypos;
    
    int row,col;
    scanf("%d %d",&row,&col);
    
    int **matrix = (int **)malloc(sizeof(int *)*row);
    
    for(int i=0;i<row;i++){
        matrix[i] = (int *)malloc(sizeof(int)*col);
    }
    
    matrix_init(&matrix, row, col);
    
    int loop = 0;
    scanf("%d",&loop);
    
    for(int i=0;i<loop;i++){
        scanf("%d %d %d %d",&length,&direction,&xpos,&ypos);
        get_result(&matrix, length, direction, xpos, ypos);
    }
    
    print_matrix(&matrix, row, col);
    
}
