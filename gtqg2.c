#include<stdio.h>

int main(){
    FILE * f = fopen("a", "w");
    char t[100];
    scanf("%s", t);
    fputs(t, f);
    fclose(f);
    f = fopen("a", "r");
    int n, d, q, p[100] = {0}, c[100] = {0}, r[100] = {0}, i = 0, j = 0, max = 0;
    fscanf(f, "%d;", &n);
    while(~fscanf(f, "%d,%d;", &d, &q)){
        p[d] = q;
    }
    fclose(f);
    for(i = 1;i <= n;i++){
        q = p[i];
        r[i] = i;
        for(j = 1;j < i;j++){
            if(q < p[j] + c[i - j]){
                q = p[j] + c[i - j];
                r[i] = j;
            }
        }
        c[i] = q;
    }
    while(n > 0){
        max += p[r[n]];
        n -= r[n];
    }
    printf("%d", max);
    return 0;
}