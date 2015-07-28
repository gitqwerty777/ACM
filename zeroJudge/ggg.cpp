#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

struct Matrix
{
    int r, c;       // 矩陣大小
    int a[10];   // 矩陣元素，用一維陣列當作二維矩陣
 
    Matrix(int r, int c): r(r), c(c)
    {
        memset(a, 0, sizeof(a));
    }
 
    // 覆寫[]，方便存取矩陣元素
    const int* operator[](int i) const {return a + i*c;}
    int* operator[](int i) {return a + i*c;}
 
    // O(N^3) 的矩陣乘法，還可以再加速
    friend Matrix operator*(const Matrix& m1, const Matrix& m2)
    {
        Matrix m(m1.r, m2.c);
        for (int i=0; i < m1.r; ++i)
            for (int j=0; j < m1.c; ++j)
                for (int k=0; k < m2.c; ++k){
                    m[i][k] += m1[i][j] * m2[j][k];
					m[i][k] %= 10007;
				}
        return m;
    }
 
    // O(logE * N^3) 矩陣次方計算，遞迴版本
    friend Matrix operator^(const Matrix& m1, const int& n)
    {
        if (n == 1) return m1;
 
        Matrix m = m1 ^ (n >> 1);
        if (n & 1) return m * m * m1;
        else return m * m;
    }
};
 
int main()
{
    // a0向量
    Matrix a0(2, 1);
    a0[0][0] = 1, a0[0][1] = 1;
 
    // transition rate matrix
    Matrix T(2, 2);
    T[0][0] = 0, T[0][1] = 1, T[1][0] = 1, T[1][1] = 1;
 
    // an向量
	/*
    Matrix an(2, 1);
    an = (T ^ 10) * a0;     // 欲求出第十項的值
    cout << an[0][0] << endl;   // 印出第十項的值
 */
	int n;
    // 只算到a9其實就夠了，可以省一點時間
	while(cin>>n){
		an = (T ^ (n-1)) * a0;          // 欲求出第十項的值
		cout << an[0][1] << endl;   // 印出第十項的值
	}
    return 0;
}