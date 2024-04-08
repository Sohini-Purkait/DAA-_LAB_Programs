#include <stdio.h>
#include <limits.h>

int MatrixChainMultiplication(int p[], int n) {
    int m[n][n];
    
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
                    
            }
        }
    }

    printf("Minimum cost matrix: \n");

    for(i = 1; i < n; i++) {
		for(j = 1; j < n; j++) {
            if(i > j){
               m[i][j] = 0; 
            }
			printf("%4d ", m[i][j]);
		}
		printf("\n");
	}

    return m[1][n - 1];    
}

int main() {
    int num, i;
    printf("Enter the number of matrix to be multiplied: ");
    scanf("%d",&num);

    int arr[num+1];
    printf("Enter %d dimensions of the matrices: ", num+1);
    for(i = 0; i < num + 1; i++){
        scanf("%d", &arr[i]);
    }
    
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Minimum number of multiplications is %d\n", MatrixChainMultiplication(arr, n));
    return 0;
}