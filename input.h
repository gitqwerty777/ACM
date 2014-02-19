/*
	input.h
	For faster input than scanf by using input functions which are specifing input type.
	1.請別放在最外層的輸入(如果要一直輸入的話)，因為沒辦法判斷EOF結尾(2011/6/7 修正)
	=> 可以判斷EOF，但是必須要另外設定 (相關程式參照下面紅色code)
	2.型態請自行修改
	reference: Morris http://mypaper.pchome.com.tw/zerojudge/post/1322053169
*/

/*
* basic input(int)
*/
void Input(int* i){
	char c;  
    int x = 0, flag = 1;
    while(c=getchar())  
        if(c != ' ' && c != '\n')
			break;
    if(c !='-')
        x = x*10 + c -'0';
    else
		flag=-1;
    while(c = getchar()){  
        if(c == ' '|| c == '\n')
			break;
		x = x*10 + c - '0';  
    }
    (*i) = x*flag;
}

/*
* long long int
*/

/************************/

±浮點數

/************************/

double point() {
    char cha;
    double poi=0, num=1;
    while(cha=getchar()) {  
        if(cha==' '||cha=='\n') break;  
         num=num/10;
         poi=poi+(cha-48)*num;
    }  
    return poi;
}        
double Input() {  
    char cha,flag=1;  
    double x=0;  
    while(cha=getchar())  
        if(cha!=' '&&cha!='\n') break;  
    if(cha!='-')
        x=x*10+cha-48;
    else flag=-1;
    while(cha=getchar()) {  
        if(cha==' '||cha=='\n') break;  
         if(cha=='.') {
            x=x+point();
            break;
          }
           x=x*10+cha-48;
    }  
    return x*flag;
}

/**********************/
int Input() { 
    char cha; 
    unsigned int x = 0; 
    while(cha = getchar()) 
        if(cha != ' ' && cha != '\n' || cha == EOF) break; 
    if(cha == EOF) return -1;
    x = cha-48; 
    while(cha = getchar()) { 
        if(cha == ' ' || cha == '\n') break; 
        x = x*10 + cha-48; 
    } 
    return x; 
}
/**********************/
回傳 -1 當作是讀到 EOF，請自行用
n = Input()
if(n == -1) break;
/**********************/
