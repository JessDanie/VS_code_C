#include<stdio.h>
#include<stdbool.h>

int main(){
    short n, q, k, i;
    while(~scanf("%hd%hd", &n, &q)){
/********************************************************************/
    short A[101] = {0}, sum = 0;
    for(i = 0;i < n;i++){
        scanf("%hd", &k);
        A[k] = 1;
        sum += k;
    }
    if((sum << 1) == n * n + n){
        for(i = 0;i < q;i++){
            scanf("%hd", &k);
            if(sum < k){
                puts("QAQ");
            } else {
                puts("OK");
            }
        }
    } else {
        short B[101], j;
        for(i = 1, j = 0;i < 101;i++){
            if(A[i]){
                B[j++] = i;
            }
        }
        for(i = 0;i < q;i++){
            scanf("%hd", &k);
            if(k > sum){
                puts("QAQ");

            } else if(k == sum){
                puts("OK");
            } else {
				if(k > (sum >> 1))
					k = sum - k;
				

			}

        }
    }
/********************************************************************/
    }
    return 0;
}