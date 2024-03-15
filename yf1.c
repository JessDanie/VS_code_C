#include<stdio.h>

int main(){
    int n, q, a[101] = {0}, k, Q[10001]={0}, i, j;
    scanf("%d%d", &n, &q);
    for(i = 0;i < n;i++){
        scanf("%d", &k);
        a[k]++;
    }
    for(i = 0;i < q;i++){
        scanf("%d", Q + i);
    }
    for(i = 0;i < q;i++){
        n = 0;
        for(j = 100;j+1;j--){
            n = Q[i];
            Q[i] -= a[j] * j;
            if(Q[i] <=0){
                if(Q[i] == 0){
                    printf("OK\n");
                    break;
                } else if(Q[i] < 0){
                    if(n % j == 0){
                        printf("OK\n");
                        break;
                    } else if(j > 0){
                        Q[i] = n;
                        Q[i] -= (Q[i] / j) * j;
                        continue;
                    } else {
                        printf("QAQ\n");
                        break;
                    }
                    
                }
            }
        }
    }
    return 0;
}
