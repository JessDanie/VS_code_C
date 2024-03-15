#include<stdio.h>
#include<stdbool.h>
int main(){
    int CG = 0;
    while(CG++ < 101){
/*****************************************************************/
    int N, i, j, p, s = 0, maxp = 0, B[45001] = {0};
    scanf("%d", &N);
    for (i = 0; i < N; i++){
        scanf("%d", &p);
        switch (p > maxp){
        case true:
            B[maxp = p] = ++s;
            break;
        default:{
            for (j = p + 1; j <= maxp; j++){
                if (B[j]){
                    B[p] = B[j];
                    B[j] = 0;
                    switch (j == maxp){
                    case true:
                        maxp = p;
                    }
                    break;
                }
            }
        }
        }
    }
    printf("%d\n", s);
    /*****************************************************************/
    }
    return 0;
}
