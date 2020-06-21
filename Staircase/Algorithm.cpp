#include "stdio.h"
#include "stdlib.h"
#include <vector>
#include <cstring>
using namespace std;
#define MAX_DP_ARRAY_SIZE 256

int Staircase_numPaths_rec(unsigned int numSteps, std::vector<unsigned int> actions, int * solutionMemory);

int Algorithm_Staircase(unsigned int numSteps, std::vector<unsigned int> actions)
{
    int * DPMemory = new int[numSteps+1];
    memset((void *)DPMemory,-1,sizeof(int)*numSteps);
    return Staircase_numPaths_rec(numSteps,actions,DPMemory);

}
int Staircase_numPaths_rec(unsigned int numSteps, std::vector<unsigned int> actions, int * solutionMemory)
{
    int numberOfWays = 0;
    for ( int i = 0; i<actions.size();i++ )
    {
       // Get the possible steps
       // Stair count from the top
       // The remaining number of stairs
       int resultingStair = numSteps - actions[i];
       if (resultingStair < 0)
       {
       // Nothing is needed, will add 0;
            ;
       }
       else if (resultingStair == 0)
       {
            numberOfWays = numberOfWays+1;
       }    
       else if(solutionMemory[resultingStair] == -1)
       {
           numberOfWays = numberOfWays + Staircase_numPaths_rec(resultingStair,actions, solutionMemory);
       }
       else
       {
           numberOfWays = numberOfWays + solutionMemory[resultingStair];
       }
    }
    solutionMemory[numSteps] = numberOfWays;

    return numberOfWays;
};
