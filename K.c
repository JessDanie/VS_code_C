#include<stdio.h>
int N, K;

void quicksort(int *A, int Left, int Right){
	int i, j, t, Tmp;
	if(Left > Right)
		return;
	Tmp = A[Left] ; //temp中存的就是基准数
	i = Left;
	j = Right;
	while(i != j){
		//顺序很重要，要先从右往左找 
		while(A[j] >= Tmp && i < j) j--;
		//再从右往左找
		while(A[i] <= Tmp && i < j) i++;	
		//交换两个数在数组中的位置
		if(i < j){   //当哨兵i和哨兵j没有相遇时 
			t = A[i];
			A[i] = A[j];
			A[j] = t;	  
		}			
	}
	// 最终将基准数归位
	A[Left] = A[i];
	A[i] = Tmp;
    //if(i + K == N + 1){
    if(i == K){
        printf("%d\n", A[i]);
        //return;
    }
	quicksort(A, Left, i - 1); //继续处理左边的 
	quicksort(A, i + 1, Right); //继续处理右边的 
	return;
}
	
int main(){
    int A[1000], i;
    scanf("%d,%d", &N, &K);
    for(i = 0;i < N;i++){
        scanf(",%d", A + i);
    }
	quicksort(A, 0, N); //快速排序的调用
    /*输出排序后的结果
	for(i = 1; i <= N; i++)
		printf("%d ", A[i]);
    */
	return 0;
}