/*Given two integer arrays A and B of size N.
There are N gas stations along a circular route, where the amount of gas at station i is A[i].

You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i
to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the minimum starting gas station’s index if you can travel around the circuit once, otherwise return -1.

You can only travel in one direction. i to i+1, i+2, … n-1, 0, 1, 2.. Completing the circuit means starting at i and
ending up at i again.*/



int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int fuel = 0, start_i = 0, sum = 0;
    
    for(int i = 0; i < gas.size(); i++){
        sum = sum + (gas[i] - cost[i]);
        fuel = fuel + (gas[i] - cost[i]);
        if(fuel < 0){
            fuel = 0;
            start_i = i+1;
        }
    }
    
    if(sum >= 0){
        return start_i%(gas.size());
    }
    
    return -1;
}