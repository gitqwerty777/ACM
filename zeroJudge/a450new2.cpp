/**********************************************************************************/
/*  Problem: a450 "棒棒糖比身高" from 從其他題目中突發奇想~       */
/*  Language: CPP (1606 Bytes)                                                    */
/*  Result: AC(0.8s, 26.9MB) judge by this@ZeroJudge                              */
/*  Author: ZJOJSFUS at 2014-02-04 00:07:47                                       */
/**********************************************************************************/


#include <cstdio>
#include <algorithm>
using namespace std;

inline int ReadInt(int *x) {
    static char c, neg;
    while((c = getchar()) < '-')    {if(c == EOF) return EOF;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = getchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

struct Quest{
	int m, i;
};

bool cmp(struct Quest a, struct Quest b){
	return a.m < b.m;
}

struct Quest questm[1000000];
struct Quest questM[1000000];
int arr[1000000];
int ans[1000000][2];
	
int main(){
	int n, m; 
	int low, high;
	int i;
	
	ReadInt(&n);
	ReadInt(&m);
	for(i = 0; i < n; i++)
		ReadInt(&arr[i]);
	for(i = 0; i < m; i++){
		ReadInt(&questm[i].m);
		ReadInt(&questM[i].m);
	}
	for(i = 0; i < m; i++){
		questm[i].i = i;
		questM[i].i = i;
	}
	
	sort(arr, arr+n);
	sort(questm, questm+m, cmp);
	sort(questM, questM+m, cmp);
	
	int nowmi = 0, nowi = 0;
	while(nowmi < m && nowi < n){
		if(questm[nowmi].m <= arr[nowi]){//??
			ans[questm[nowmi++].i][0] = nowi;
		} else {
			nowi++;
		}
	}
	if(nowi == n){
		while(nowmi < m)
			ans[questm[nowmi++].i][0] = n;
	}
	
	nowmi = 0; nowi = 0;
	while(nowmi < m && nowi < n){
		if(questM[nowmi].m < arr[nowi]){//??
			ans[questM[nowmi++].i][1] = nowi;
		} else {
			nowi++;
		}
	}
	if(nowi == n){
		while(nowmi < m)
			ans[questM[nowmi++].i][1] = n;
	}
	
	for(i = 0; i < m; i++){
		if(ans[i][1] == ans[i][0])
			puts("The candies are too short");
		else
			printf("%d\n", ans[i][1] - ans[i][0]);
	}
	
	return 0;
}
