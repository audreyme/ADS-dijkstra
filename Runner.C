#include <stdio.h>

int main(void)
{
/*                                                             */
/****************Array and Variable Declarations****************/
/*                                                             */
  int start = 0;
  int smallCost;
  int smallCostPos
  const int totalNodes = 4;

  int visited[totalNodes] = {1,0,0,0}; //0 = false, 1 = true
  int cost[totalNodes] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
  int previous[totalNodes] = {NULL, NULL, NULL, NULL};
  int adjacencyMatrix [totalNodes][totalNodes] = {{0,3,7,9},
                                                  {3,0,2,4},
                                                  {7,2,0,1},
                                                  {9,4,1,0}};
/*                                                             */
/******************Executable Code Begins Here******************/
/*                                                             */
  for(visitNum = 1; visitNum <= totalNodes; visitNum++)
  {
/******************Find the cheapest path*****************/

    for(end = 0; end < totalNodes; end++)
    {
      if(visited[end] == 0 && start != end)
      {
        if(adjacencyMatrix[start][end] < cost[start])
        {
          cost[end] = adjacencyMatrix[start][end];
          previous[end] = start;
        }
      }
    }

/*************Find the next inexpensive start*************/

    smallCost = INT_MAX;
    smallCostPos = -1;

    for(node = 0; node < (totalNodes - visitNum); node++)
   // while(nodeCount < (totalNodes - visited))
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

}//main
