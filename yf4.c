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
        short B[101], C[101], j, z, J, re = 0;
        bool D[5051] = {false};
        C[0] = 0;
        for(i = 1, j = 0;i < 101;i++){
            if(A[i]){
                B[j++] = i;
                C[j] = C[j - 1] + B[j - 1];
            }
        }
        C[j] = C[j - 1] + B[j - 1];
        for(i = 0;i < q;i++){
            scanf("%hd", &k);
            if(k > sum){
                puts("QAQ");
            } else if(k == sum){
                puts("OK");
            } else {
                J = j;
                while(B[J--] > k);
                short K = k, *td, dd[101] = {0};
                td = dd;
                for(z = J;z >= 0;z--){    
                    if(K >= B[z]){
                        td[re++] = K;
                        K -= B[z];
                    }
                    if(K == 0 || D[K]){
                        K = 0;
                        while(--re >= 0){
                            D[td[re]] = true;
                        }
                        break; 
                    } else if(K > C[z + 1] || K < C[1]){
                        static short d[101] = {0};
                        td = d;
                        re = 0;
                        z = J--;
                        K = k;
                    }
                }
                if(K == 0)
                    puts("OK");
                else
                    puts("QAQ");
            }
        }
    }
/********************************************************************/    
/********************************************************************/
    }
    return 0;
}