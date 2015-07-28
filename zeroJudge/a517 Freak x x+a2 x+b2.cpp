#include <stdio.h>
#include <math.h>

int main(){
	unsigned long long x, y, z;
	
	while(scanf("%ull %ull %ull", &x, &y, &z)){
		unsigned long long ans, a, b;
		if(x > y){
			if(y > z)
			
			else
				
		}	
		
		a = z - x;
		b = z - y;
		
		a = a*a;
		b = b*b;
		
		//ans = 0;
		//ans += 3*x*x + 2*(a+b)*x + a*a + b*b;
		ans = sqrt(3*x*x + 2*(a+b)*x);
		/*	
			//sqrt -> double
			1.other ถ}ค่ way without sqrt
			2.not sqrt, just try
			3.
		*/
		printf("%ull\n", ans);
		
	
	
	}
	return 0;
}