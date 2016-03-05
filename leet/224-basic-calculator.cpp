//including basic calculator2

#include <cctype>
#include <stack>
#include <string>
#include <cstdio>

class Solution {
public:

  Solution(){
    operatorLevel['+'] = 1;
    operatorLevel['-'] = 1;
    operatorLevel['*'] = 2;
    operatorLevel['/'] = 2;
    operatorLevel['('] = 0;
    operatorLevel[')'] = 0;
  }
  
  std::stack<char> operatorStack;
  std::stack<int> numberStack;
  std::string s;
  int calculate(std::string s) {
    //printf("handle %s\n", s.c_str());
    this->s = s;
    for(int i = 0; i < s.length(); i++){
      if(isdigit(s[i])){//read all digits
	handleDigit(i);
      } else {
	handleOperator(i);
      }
    }
    calculateStack();
    return numberStack.top();
  }

  inline void calculateStack(){
    while(!operatorStack.empty())
      doOperation();
  }
  
  inline void handleDigit(int& i){
    long num = 0;
    while(1){
      num += s[i]-'0';
      num *= 10;
      i++;
      if(!((isdigit(s[i]) && i < s.length()))){
	i--;
	break;
      }
    }
    num /= 10;
    //printf("num = %d, now i = %d\n", num, i);
    numberStack.push(num);
  }

  int operatorLevel[256];//ascii
  inline void handleOperator(int i){
    if(s[i] == ' ')
      return;
    //printf("handle %c\n", s[i]);
    int level = operatorLevel[s[i]];
    if((!operatorStack.empty()) && (s[i] != '(') && (s[i] != ')')){
      int preOp = operatorStack.top();
      int preLevel = operatorLevel[preOp];
      while(level <= preLevel){
	//fprintf(stderr, "prelevel, do operation, ");
	doOperation();
	if(operatorStack.empty())
	  break;
	preOp = operatorStack.top();
	preLevel = operatorLevel[preOp];
      }
    }
    if(s[i] == ')'){
      char op;
      op = operatorStack.top();
      while(op != '('){
	doOperation();
	op = operatorStack.top();
      }
      operatorStack.pop();// '('
    } else{
      operatorStack.push(s[i]);
    }
  }

  inline void doOperation(){
    int a, b, c;
    char op;
    b = numberStack.top();
    numberStack.pop();
    a = numberStack.top();
    numberStack.pop();
    op = operatorStack.top();
    operatorStack.pop();

    switch(op){
    case '+':
      c = a + b;
      break;
    case '-':
      c = a - b;
      break;
    case '*':
      c = a * b;
      break;
    case '/':
      c = a / b;
      break;
      //default://do nothing
      //break;
    }
    numberStack.push(c);
  }
};

int main(){
  Solution s;
  std::string str("(1+3/2)*4+7");
  printf("ans = %d\n", s.calculate(str));
}

  
