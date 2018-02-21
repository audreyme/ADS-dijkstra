#include <stdio.h>

int main(void)
{
  int TO = 0;
  int FROM = 0;
  int visited = 1;
  int node = 0;// will need adjusting

  //For clarity, rows are FROM and columns are TO
  int adjacencyMatrix [totalNodes][totalNodes] = {{0,3,7,9},
                                                  {3,0,2,4},
                                                  {7,2,0,1},
                                                  {9,4,1,0}};
  int visitedArr [totalNodes] = {1,0,0,0}; //0 = false, 1 = true
  int cost [totalNodes] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
  char previous [totalNodes] = {NULL, NULL, NULL, NULL};

  int nodeCount = 0; //Dynamic internal loop variable
  const int totalNodes = 4;

  while(visited<totalNodes)
  {
    while(nodeCount <= totalNodes)
    {
      if(visited[FROM] == 0 && cost[FROM] != 0) //is this TO node visited? is this TO node the FROM node?
      {
        if(adjacencyMatrix[TO][FROM] < cost[FROM])// is the current cost of the node > the cost of the node from
        {
          //update cost[] and previosu of TO node
          cost[TO] = adjacencyMatrix[TO][FROM];
          previous[TO] = FROM;
        }
      }
    TO++;
    }//barginCosts

    nodeCount = 0;
    int lowestCost;
    int lowestCostPos;

    while(nodeCount < totalNodes)
    {
      if(visitedArr[node] == 0 && currentCost < lowestCost)
      {
        lowestCost = currentCost;
        lowestCostPos = node;                                           //  currentCost needs to be accessed via the cost array
      }
    }//find next FROM node

    visited++;
    nodeCount = 0;
  }//mamaWhileLoop


}//main
