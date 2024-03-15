#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct hfm{
    int legth;
    bool code[32];
};

int main(){
    int fre[7][4] = {0}, i, j, n, visited, team, len;
    char word[100];
    struct hfm H[7];
    scanf("%s", word);
    len = strlen(word);
    for(i = 0;i < len;i++){
        fre[word[i] - 'a'][0]++;
    }
    for (j = 0, i = 0; j < 7; j++){
        H[j].legth = 0;
        if (fre[j][0] !=  0){
            fre[i][1] = fre[j][0];
            fre[i++][0] = j;
        }
    }
    n = i;
    while(i--){
        int m1 = 99999, m2 = 100000, m1_j = 0, m2_j = 0;
        for(j = 0;j < n;j++){
            if(fre[j][2])
                continue;
            if(fre[j][1] < m1)
                m2 = m1, m1 = fre[j][1], m2_j = m1_j, m1_j = j;
            else if(fre[j][1] < m2)
                m2 = fre[j][1], m2_j = j;
        }
        if(fre[m1_j][3] == 0)
            fre[m1_j][3] = i;
        if(fre[m2_j][3] == 0)
            fre[m2_j][3] = i;
        team = fre[m1_j][3] < fre[m2_j][3] ? fre[m1_j][3] : fre[m2_j][3];
        if (m1 < m2){
            for (j = 0; j < n; j++){
                if (fre[j][1] == m1 && fre[m1_j][3] == fre[j][3]){
                    H[fre[j][0]].code[H[fre[j][0]].legth++] = 0;
                    fre[j][1] = m1 + m2, fre[j][2] = 1, fre[j][3] = team;
                    visited = j;
                }
                else if (fre[j][1] == m2 && fre[m2_j][3] == fre[j][3]){
                    H[fre[j][0]].code[H[fre[j][0]].legth++] = 1;
                    fre[j][1] = m1 + m2, fre[j][2] = 1, fre[j][3] = team;
                    visited = j;
                }
            }
            fre[visited][2] = 0;
        } else {
            if (fre[m1_j][3] > fre[m2_j][3]){
                j = m1_j, m1_j = m2_j, m2_j = j;
            }
            if (fre[m1_j][3] != fre[m2_j][3]){
                for (j = 0; j < n; j++){
                    if (fre[j][1] == m1){
                        if (fre[m1_j][3] == fre[j][3]){
                            H[fre[j][0]].code[H[fre[j][0]].legth++] = 0;
                        } else if (fre[m2_j][3] == fre[j][3]){
                            H[fre[j][0]].code[H[fre[j][0]].legth++] = 1;
                        }
                        fre[j][1] = m1 + m2, fre[j][2] = 1, fre[j][3] = team;
                        visited = j;
                    }
                }
                fre[visited][2] = 0;
            }
            else{
                H[fre[m1_j][0]].code[H[fre[m1_j][0]].legth++] = 0;
                H[fre[m2_j][0]].code[H[fre[m2_j][0]].legth++] = 1;
                fre[m1_j][1] = fre[m2_j][1] = 2 * m1, fre[m1_j][2] = 1;
                fre[m1_j][3] = fre[m2_j][3] = team;
            }
        }
    }
    
    for(i = 0;i < len;i++){
        for(j = H[word[i] - 'a'].legth - 2;j >= 0;j--)
            printf("%d", H[word[i] - 'a'].code[j]);
        putchar(';');
    }  
    return 0;
}