#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() { 
    int F, N, M, W;
    scanf("%d", &F);

    for (int f = 0; f < F; f++){
        int A[6000], B[6000], T[6000], P = 0; 
        bool cycle = false; 
        int dist[500];
        scanf("%d %d %d", &N, &M, &W);
        memset(dist, 0, sizeof(dist)); 

        for (int i = 0; i < M; i++) { 
            scanf("%d %d %d", &A[P],&B[P],&T[P]); 
            A[P]--; 
            B[P]--; 
            A[P + 1] = B[P]; 
            B[P + 1] = A[P]; 
            T[P + 1] = T[P]; 
            P += 2; 
        }

        for (int i = 0; i < W; i++) { 
            scanf("%d %d %d", &A[P],&B[P],&T[P]); 
            A[P]--; 
            B[P]--; 
            T[P] = -T[P]; 
            P++; 
        } 

        for (int r = 0; r <= N; r++)
            for (int i = 0; i < P; i++){
				if(dist[B[i]] < dist[A[i]] + T[i])
					dist[B[i]] = dist[A[i]] + T[i];
			}
        for (int i = 0; i < P; i++)
            if (dist[B[i]] > dist[A[i]] + T[i])
                cycle = true;
        if(cycle)
			puts("YES");
		else
			puts("NO");
    }
	return 0;
}	