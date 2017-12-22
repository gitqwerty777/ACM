// C++ program to solve knapsack problem using branch and bound
// source: https://www.geeksforgeeks.org/branch-and-bound-set-2-implementation-of-01-knapsack/
#include <bits/stdc++.h>
using namespace std;

struct Item
{
  int weight;
  int value;
  float cp;
  void init(int v, int w){value = v; weight = w; cp = float(v)/w;}
  bool operator<(const Item& right) const{
    return cp > right.cp;
  }
};

Item arr[1004];//at most 1000
long long profitSum[1004];
long long weightSum[1004];
int N, W;//number, weight

struct Node
{
  int level, profit, bound, weight;
  int boundIndex;//the index that node's bound meets to weight limit
  int boundWeight, boundProfit;
  Node(){boundIndex = -1; level = profit = bound = weight = 0;}
};

bool cmp(Item a, Item b)
{
  double r1 = (double)a.value / a.weight;
  double r2 = (double)b.value / b.weight;
  return r1 > r2;
}

// Returns bound of profit in subtree rooted with u.
// This function mainly uses Greedy solution to find
// an upper bound on maximum profit.
int bound(Node& u)
{
  int profit_bound = u.profit;
  int totweight = u.weight;
  int j = u.level+1;
  //because u.boundIndex <= v.boundIndex;

  //TODO: log(n), should remove
  int index = std::upper_bound(weightSum+j, weightSum+N, W-u.weight+weightSum[j]) - (weightSum);
  if(index == N){
    totweight += weightSum[N-1] - weightSum[u.level];
    profit_bound += profitSum[N-1] - profitSum[u.level];
  } else {
    totweight += weightSum[index] - weightSum[u.level];
    profit_bound += profitSum[index] - profitSum[u.level];
  }
  j = index;
  u.boundIndex = index;
  u.boundWeight = totweight;
  u.boundProfit = profit_bound;

  /*j = u.level+1;
  totweight = u.weight;
  profit_bound = u.profit;
  while ((j < N) && (totweight + arr[j].weight <= W))
  {
    totweight += arr[j].weight;
    profit_bound += arr[j].value;
    j++;
  }
  */

  //include last item partially to upper bound
  if (j < N)
    profit_bound += (W - totweight) * arr[j].value /
      arr[j].weight;
  return profit_bound;
}
int bound2(Node& u){
  return bound(u);
}

// Returns maximum profit we can get with capacity W
int knapsack()
{
  // sorting Item on basis of value per unit weight
  sort(arr, arr + N, cmp);
  //from 0 to i(include)
  profitSum[0] = arr[0].value;
  weightSum[0] = arr[0].weight;
  for(int i = 0; i < N; i++){
    profitSum[i] += profitSum[i-1] + arr[i].value;
    weightSum[i] += weightSum[i-1] + arr[i].weight;
  }
  // make a queue for traversing the node
  queue<Node> Q;
  Node u, v;
  // dummy node at starting
  u.level = -1;
  u.profit = u.weight = 0;
  Q.push(u);
  int maxProfit = 0;
  while (!Q.empty())
  {
    // Dequeue a node
    u = Q.front();
    Q.pop();
    // If there is nothing on next level
    if (u.level == N-1)
      continue;
    else
      v.level = u.level + 1;

    //choose current level's item
    v.weight = u.weight + arr[v.level].weight;
    v.profit = u.profit + arr[v.level].value;
    // If cumulated weight is less than W and
    // profit is greater than previous profit,
    // update maxprofit
    if(v.weight <= W){
      if (v.profit > maxProfit){
        maxProfit = v.profit;
        Q.push(v);
      } else {
        // Get the upper bound on profit to decide
        // whether to add v to Q or not.
        v.bound = bound(v);
        //printf("u boundindex %d, v boundindex %d\n", u.boundIndex, v.boundIndex);
        if (v.bound > maxProfit)
          Q.push(v);
      }
    }

    //not choose current level's item
    v.weight = u.weight;
    v.profit = u.profit;
    v.bound = bound2(v);
    //printf("u boundindex %d, v boundindex %d\n", u.boundIndex, v.boundIndex);
    //assert(u.boundIndex <= v.boundIndex);
    if (v.bound > maxProfit)
      Q.push(v);
  }
  return maxProfit;
}

/*
背包大小≤ 5×106，和物品個數  ≤1000，下一行開始每行包含兩個正整數，分別代表物品價值 ≤105，和物品重量 ≤105
*/
int main()
{
  scanf("%d %d", &W, &N);
  int value, weight;
  for(int i = 0; i < N; i++){
    scanf("%d %d", &value, &weight);
    arr[i].init(value, weight);
  }
  printf("%d\n", knapsack());
  return 0;
}
