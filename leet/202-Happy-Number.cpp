class Solution{
public:
  map<int, bool> m;
  Solution(){
    m[1] = true;
    m[2] = false;
    m[3] = false;
  }
  bool isHappy(int n){
    if(m.find(n) != m.end())
      return m[n];
    else{
      set<int> numv;
      numv.insert(n);
      while(n != 1){
	if(n <= 3){
	  n = (m[n])?1:0;
	  break;
	}
	int newn = 0;
	while(n != 0){
	  newn += (n % 10)*(n % 10);
	  n /= 10;
	}
	n = newn;
	if(numv.insert(n).second == false)
	  break;
      }
      bool ishappy = (n == 1);
      for(auto it = numv.begin(); it != numv.end(); it++){
	m[*it] = ishappy;
      }
      return ishappy;
    }
  }
};
