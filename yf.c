#include<stdio.h>

int main(){
    int CG = 0;
//    while(CG++ < 30){
    int n, q, a[101] = {0}, k, i, j;
    scanf("%d%d", &n, &q);
    for(i = 0;i < n;i++){
        scanf("%d", &k);
        a[k]++;
    }

    for(i = 0;i < q;i++){
        n = 0;
        int tn = 0;
        scanf("%d", &k);
        for(j = 0;j < 101;j++){
            n += a[j] * j;
            if((n >= k)){
                if(n==k || k==0){
                    printf("OK\n");
                    break;
                } else {
                    if((n - k)%j == 0){
                        printf("OK\n");
                        break;
                    } else{
                        printf("QAQ\n");
                        break;
                    }   
                }
            } else if(j == 100)
                printf("QAQ\n");
        }
    }
//(U1 ( U2( (U3) (U4 U5) ) ) ) (U6)
    return 0;
}
