#include <iostream>
#include <string>
#include <vector>
extern int Algorithm_Staircase(unsigned int,std::vector<unsigned int>);
std::string uint_vector2String(std::vector<unsigned int> inVect)
{
    char * actionVect = new char[inVect.size()*3];
    int i;
    for (i = 0;i<inVect.size();i++)
    {
        int currentValue = inVect[i];
        char lv = 48;
        char rv = currentValue%10+48;
        if (currentValue >= 10)
        {
           lv = currentValue/10 + 48; 
        }
        actionVect[3*i] = lv;
        actionVect[3*i+1] = rv;
        actionVect[3*i+2] = ',';
    }
    actionVect[inVect.size()*3-1] = '\0';
    return std::string(actionVect);

}

int main()
{
    // Algorithm_Staircase(numSteps,actionVector)
    // Testing Algorithm
    std::cout<< "Algorithm_Staircase Steps = 0,1,10,13,21"<<std::endl;
    std::cout<< "Action Vector = {1},{1,2,3},{5,10,20},{7}"<<std::endl;
    std::vector<std::vector<unsigned int>> testActions;
    std::vector<unsigned int>testSteps;
    testSteps.push_back(5);
    testSteps.push_back(10);
    testSteps.push_back(13);
    testSteps.push_back(20);
    testSteps.push_back(1000);
    testActions.push_back({1,2,3});
    testActions.push_back({1});
    testActions.push_back({2});
    testActions.push_back({5,10,20});
  

    for(int stepIter =0;stepIter<testSteps.size();stepIter++)
    {
        for(int actionIter = 0; actionIter<testActions.size();actionIter++)
        {
            std::cout<<"Number of Steps: "<<testSteps[stepIter]<<" Actions: "<< uint_vector2String(testActions[actionIter]);
            std::cout<<" Solution: "<<Algorithm_Staircase(testSteps[stepIter],testActions[actionIter])<<std::endl;
        }
    }



}
