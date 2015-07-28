#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){
	double input;
	
	/*while(scanf("%lf", &input) > 0){
		input *= 100;
		int inputi = int(input);
		if(inputi > 0 && input - inputi >= 0.5){
			inputi++;
		} else if(inputi < 0 && inputi - input >= 0.5){
			inputi--;
		}
		printf("%.02lf\n", double(inputi)/100);
	}*/
	
	while(scanf("%lf", &input) > 0){
		int inputi = int(input*1000);
		printf("input*1000 = %lf ,inputi = %d\n",input*1000, inputi);
		if(inputi > 0 && inputi % 10 >= 5){
			inputi += 10;
		} else if(inputi < 0 && (-inputi) % 10 >= 5){
			inputi -= 10;
		}
		if(inputi / 10 == 0){
			puts("0.00");
		} else {
			printf("%.02lf\n", double(inputi / 10)/100);
		}
	}
	/*
	while(scanf("%lf", &input)){
		printf("%.02lf\n", input);
	}*/
	
	
	/*while(scanf("%lf", &input)){
		if(input > 0 && input - inputi >= 0.5){
			inputi++;
		} else if(input < 0 && inputi - input >= 0.5){
			inputi--;
		}
		printf("%.02lf\n", double(inputi)/100);
	}*/
	
	/*
	//this is ok, but not optimized
	char s[120];
	
	while(scanf("%s", s) > 0){
		char* fl = strstr(s, ".");
		if(fl == NULL){
			puts(s);
			continue;
		} else{
			if(*(fl+1) != '\0' && *(fl+2) != '\0' && *(fl+3) != '\0'){
				if(*(fl+3) >= '5'){
					(*(fl+2))++;
					int off = 2;
					while(*(fl+off) > '9'){
						*(fl+off) -= 10;
						if(*(fl+off-1) == '.')
							off--;
						(*(fl+off-1))++;
						off--;
					}
				}
				*(fl+3) = '\0';
				if(atof(s) == 0.00)
					puts("0.00");
				else
					puts(s);
			} else {
				//puts("no need to increase");
				if(atof(s) == 0.00)
					puts("0.00");
				else if(*(fl+1) == '\0'){
					*(fl+1) = '0';
					*(fl+2) = '0';
					*(fl+3) = '\0';
					puts(s);
				} else if(*(fl+2) == '\0'){
					*(fl+2) = '0';
					*(fl+3) = '\0'; 
					puts(s);
				} else {
					puts(s);
				}
			}
			
		}
	}*/
	
	
	return 0;
}