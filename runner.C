#include <stdio.h>
#include<limits.h>

int main(void)
{
/*                                                             */
/****************Array and Variable Declarations****************/
/*                                                             */
  int start = 0;
  int smallCost;
  int smallCostPos;
  const int totalNodes = 4;

  int visited[4] = {1,0,0,0}; //0 = false, 1 = true
  int cost[4] = {0, INT_MAX, INT_MAX, INT_MAX};
  int previous[4] = {-1, -1, -1, -1};
  int adjacencyMatrix [4][4] = {{0,3,7,9},
                                {3,0,2,4},
                                {7,2,0,1},
                                {9,4,1,0}};
/*                                                             */
/******************Executable Code Begins Here******************/
/*                                                             */
  int visitNum;
  for(visitNum = 1; visitNum <= totalNodes; visitNum++)
  {
/******************Find the cheapest path*****************/
    int end;
    for(end = 0; end < totalNodes; end++)
    {
      if(visited[end] == 0 && start != end)
      {
        if(adjacencyMatrix[start][end] < cost[end])
        {
          cost[end] = adjacencyMatrix[start][end];
          previous[end] = start;
        }
      }
    }

/*************Find the next inexpensive start*************/

    smallCost = INT_MAX;
    smallCostPos = -1;
    int node;
    for(node = 0; node < totalNodes; node++)
    {
      if(visited[node] == 0 && cost[node] < smallCost)
      {
        smallCost = cost[node];
        smallCostPos = node;
      }
    }
    start = smallCostPos;
    visited[start] = 1; //sets the new start node as visited
  }
//print to show that I'm a winner
    int i;
    printf("visited:\n");
    for(i = 0; i < totalNodes; i++)
    {
        printf("%d ", visited[i]);
      printf("\n");
    }
    printf("\n");

    int j;
    printf("cost:\n");
    for(j = 0; j < totalNodes; j++)
    {
        printf("%d ", cost[j]);
      printf("\n");
    }
    printf("\n");

    int k;
    printf("previous:\n");
    for(k = 0; k < totalNodes; k++)
    {
        printf("%d ", previous[k]);
      printf("\n");
    }
    printf("\n");
}//main
