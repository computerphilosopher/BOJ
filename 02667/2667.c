#include <stdio.h>
 
 
#include <stdlib.h>
#include <stdbool.h>


int count = 0;

/*같은 단지에 속하는 집 수를 리턴 */

int dfs(int **arr, int size, int row, int col, bool visited[][size]){

    count++;

    visited[row][col] = true;

    /*배열의 상하좌우에 있는 요소들 모두 방문. 인덱스 넘어가지 않도록 처리 */ 

    if(row-1>=0 && arr[row-1][col]){
        if(!visited[row-1][col]){
            dfs(arr, size, row-1, col, visited);
        }
    }

    if(row+1 < size && arr[row+1][col]){
        if(!visited[row+1][col]){
            dfs(arr, size, row+1, col, visited);
        }
    }

    if(col-1 >= 0 && arr[row][col-1]){
        if(!visited[row][col-1]){
            dfs(arr, size, row, col-1, visited);
        }
    }


    if(col+1 < size && arr[row][col+1]){
        if(!visited[row][col+1]){
            dfs(arr, size, row, col+1, visited);
        }
    }

    /*dfs_all 함수에서 단지를 중복되게 세지 않도록, 함수가 끝나면 배열을 0으로 바꿈 */
    arr[row][col] = 0;

    return count;
}


/*2차원 배열에 있는 모든 요소에 dfs를 하는 함수 */
void dfs_all(int **table, int size, int result[]){

    bool visited[size][size];

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            visited[i][j] = false;
        }
    }

    int k = 0; // result 배열의 인덱스로 쓸 변수

    
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(table[i][j]){
                count = 0;
                result[k++] = dfs(table, size, i, j, visited);
            } 
        }
    }
}

/*c 퀵소트 라이브러리를 쓰기 위한 함수 */
int compare (void *first, void *second)
{
    if (*(int*)first < *(int*)second)
        return -1;
    else if (*(int*)first > *(int*)second)
        return 1;
    else 
        return 0;
}

void print_result(int result[], int n){
    int count = 0;

    /*result 배열에서 0이 아닌 부분을 센다. 단지의 수를 세기 위함*/
    for(int i=0; i<n; i++){
        if(result[i]){
            count++;
        }
    }

    printf("%d\n", count);

    /* 0이 아닌 요소들을 차례로 출력.메인함수에서  퀵정렬을 적용했으므로 오름차순 출력됨 */
    for(int i=0; i<n; i++){
        if(result[i]){
            printf("%d", result[i]);
            if(i != n-1){
                printf("\n");
            }
        }
    }

}

int main(){

    int n = 0;
    scanf("%d", &n);

    int **table = (int**) malloc(sizeof(int*)*n);

    for(int i=0; i<n; i++){
        table[i] = (int*) malloc(sizeof(int)*n);
    }

    /* 입력받는 부분 */
    for(int i=0; i<n; i++){
        char str[n+1];
        scanf("%s", str);

        for(int j=0; j<n; j++){
            if(str[j] == '\0'){
                break;
            }
            else if(str[j] == '1'){
                table[i][j] = 1;
            }
            else if(str[j] == '0'){
                table[i][j] = 0;
            }
        }
    }

    /*result 배열의 길이는 임의로 넉넉하게 잡았음 */
    int *result = (int*)calloc(10000, sizeof(int));

    dfs_all(table, n, result);

    qsort(result, 10000, sizeof(int), (const void*)compare);

    print_result(result, 10000);

    free(result);

    for(int i=0; i<n; i++){
        free(table[i]);
    }

    free(table);

}
