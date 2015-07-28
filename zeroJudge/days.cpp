#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

	int month[13] = {0, 31, 28, 31,30,31,30,31,31,30,31,30,31};
	int renmonth[13] = {0, 31, 29, 31,30,31,30,31,31,30,31,30,31};

int ren(int y, int yy){
	if(y > yy){
		int temp = y;
		y = yy;
		yy = temp;
	}//y < yy
	y ++;
	yy--;
	if(y > yy)
		return 0;
	while(y % 4)
		y++;
	while(yy % 4)
		yy--;
	
	int r = 0;
	for(int i = y; i <= yy; i+= 4){
		if(y % 100 || (y % 400 == 0))
			r++;
	}
	
	return r;
}

int allday(int y, int m, int d){
	bool ren = false;
	if(y % 4 == 0)
		if(y % 100 || (y % 400 == 0))
			ren = true;
	
	int ans = 0;
	if(ren)
		for(int i = 0; i < m; i++)
			ans += renmonth[i];
	else	
		for(int i = 0; i < m; i++)
			ans += month[i];
			
	ans += d;
	return ans;
}

int restday(int y, int m, int d){
	bool ren = false;
	if(y % 4 == 0)
		if(y % 100 || (y % 400 == 0))
			ren = true;
	
	int ans = 0;
	if(ren)
		for(int i = 0; i < m; i++)
			ans += renmonth[i];
	else	
		for(int i = 0; i < m; i++)
			ans += month[i];
	
	ans += d;
	
	if(ren)
		return 366-ans;
	else
		return 365-ans;
}
int main(){
	int y, m, d, alld;
	int yy, mm, dd, alldd;
	int ans;
	
	while(cin>>y>>m>>d){
		cin>>yy>>mm>>dd;
		ans = 0;
		ans += (abs(y - yy) - 1) * 365;
		//366
		ans += ren(y, yy);
		
		//各自的day
		alld = restday(y, m, d);
		alldd = allday(yy, mm, dd);
		
		ans += alld + alldd;
			
		cout<<ans<<endl;
	}

	return 0;
}