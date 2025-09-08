// #notes
//GAS STATION --> LeetCode 134

//solved using "elimination approach". (optimised version)
//(we eliminate those values which can't be the starting idx. The idx we have at the end is the ans.)

//We have "n" stations. The array, gas = [1,2,4,5,9] contains the amount of gas that can be filled at each station.
//The array, cost = [3,4,1,10,1] is the cost of going from i'th station to (i+1)'th station.

//Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise 
//direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

//unique solution means that there can be only "one" starting idx to complete the circular tour.

#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircle(vector<int>& gas, vector<int>& cost)
{
    int totalGas = 0, totalCost = 0;

    //Means a valid starting idx does exist: so find that valid start idx

    int start = 0; //to find starting idx
    int currGas = 0; //to find the qty of gas we have at idx i //initially we had 0 gas.

    for(int i=0; i<gas.size(); i++)
    {
        totalGas += gas[i];          //calculate totalGas by adding all the gas[i] in gas
        totalCost += cost[i];        //calculate totalCost by adding all the cost[i] in cost
        currGas += gas[i] - cost[i];  //calc currGas

        //if currGas becomes -ve, eliminate it, as -ve value can never be the ans. So find a new "start"
        if(currGas < 0)
        {
            start = i+1; //the current idx can also never be the starting idx, hence we need to start from (i+1) idx.
            currGas = 0; //reinitialise it to 0 whenever invalid start is found
        }
    }

    //if the totalGas is < totalCost means we have insufficient gas to cover the circular tour. In this case no valid ans exists, return -1
    //else return the start idx.
    return (totalGas < totalCost) ? -1 : start;

}

int main()
{
    vector<int> gas = {1,2,4,5,9};  //here the last value (i.e 9) having idx = 4 will be the start idx
    vector<int> cost = {3,4,1,10,1};

    cout << "Start idx: " << canCompleteCircle(gas, cost) << endl;

    return 0;
}

//TC = O(n)
//SC = O(1)