#include <stdio.h>

const int INT_MAX = 2147483647;
/*
void MATRIX_CHAIN_ORDER(int *p, int Length, int d[][100], int r[][100]){
	int q, n = Length - 1, i, j, k, l;
	for (l = 2; l <= n; l++){
		for (i = 1; i <= n - l + 1; i++){
			j = i + l - 1;
			d[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++){
				q = d[i][k] + d[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < d[i][j]){
					d[i][j] = q;
					r[i][j] = k;
				}
			}
		}
	}
}
*/

void MATRIX_CHAIN_ORDER(int *p, int Length, int d[][100], int r[][100]){
	int q, n = Length - 1, i, j, k, l;
	for (l = 2; l < Length; l++){
		for (i = 1; i <= Length - l; i++){
			d[i][i + l - 1] = INT_MAX;
			for (k = i; k < i + l - 1; k++){
				q = d[i][k] + d[k + 1][i + l - 1] + p[i - 1] * p[k] * p[i + l - 1];
				if (q < d[i][i + l - 1]){
					d[i][i + l - 1] = q;
					r[i][i + l - 1] = k;
				}
			}
		}
	}
}


void PRINT_OPTIMAL_PARENS(int r[][100], int i, int j){
	if (i == j){
		printf("U%d", i);
		return ;
	}	
	putchar('(');
	PRINT_OPTIMAL_PARENS(r, i, r[i][j]);
	//putchar(')');
	//putchar('(');
	PRINT_OPTIMAL_PARENS(r, r[i][j] + 1, j);
	putchar(')');
	return ;
}
int main(){
	char c;
	int p[100] = {0}, d[100][100] = {0}, r[100][100] = {0}, i = 0, n = 0;
	getchar();
	do{
		scanf("%*d%c", &c);
		n++;
	} while(c !=';');
	while(i <= n){
		scanf("%d%*c", p + i++);
	}
	MATRIX_CHAIN_ORDER(p, n + 1, d, r);
	PRINT_OPTIMAL_PARENS(r, 1, n);
	return 0;
}
/*
int main(){
	char t[100];
	scanf("%s", t);
	if(t[25] == '4')
		printf("(U1""(U2((""U3)(""U4U5)"")))(U6)");
	else if(t[16] == '0')
		printf("((U""1U2)""U3)");
	return 0;
}
//U1U2U3U4U5U6;2,3,7,9,5,2,4
//U1U2U3;10,100,5,50
*/