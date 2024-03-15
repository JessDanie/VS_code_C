#include<stdio.h>

int main(){
    FILE * f = fopen("a.txt", "w");
    char t[100];
    scanf("%s", t);
    fputs(t, f);
    fclose(f);
    f = fopen("a.txt", "r");
    int c, n = 0, d, q, p[100] = {0}, P[100][100] = {0}, v[100] = {0}, r[100][100] = {0}, i = 0, j, max = 0;
    fscanf(f, "%d;", &c);
    while(~fscanf(f, "%d,%d;", &d, &q)){
        v[++n] = d;
        p[n] = q;
    }

    fclose(f);
    for(i = 1;i <= n;i++){
        for(j = 1;j <= c;j++){
            if(v[i] <= j && p[i] + P[i - 1][j - v[i]] > P[i - 1][j]){
                P[i][j] = p[i] + P[i - 1][j - v[i]];
                r[i][j] = 1;
            } else {
                P[i][j] = P[i - 1][j];
                r[i][j] = 0;
            }
        }
    }
    for(i = n;i > 0;i--){
        if(r[i][c] == 1){
            max += p[i];
            //printf("%d ", p[i]);
            c -= v[i];
        }
    }
    printf("%d", max);
}