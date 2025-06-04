#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 24-point
// 2 3 4 5
// target = 24
// use all four numbers, just once
// 
// (5 - 2 + 3) * 4

// arbitrary (integer) target
// arbitrary number of inputs

// input:
//   vector<int> nums
//   int target
// output: 
//   bool reachable






/*
  5 ->[+ - /  *]  X
  
  4 + 5 / 9
    
    1 -> []
    
    previousValue 
    currValue 
    
    
    previousVALue = cirr
    
    TC : 4^n
    SC: O(n)
*/

class CalculateTarget{
public: 
    bool isReachable(vector<int> &nums, int target) {
        unordered_set<int> visited;
        return isReachableHelper(nums, 0, 0, target, visited);
    }
    
    CalculateTarget(){}

    private:
        vector<string> operation {"+", "-", "*", "/", "*-alt", "/-alt" };
            
        bool isReachableHelper(vector<int>&nums,  int currSum, int previousNum, int target, unordered_set<int> visited) {

        // cout << currSum << " " << visited.size() << endl;
        
        for (int i = 0 ; i < nums.size(); i++ ){
            if (visited.contains(i))
                continue;
            
            visited.insert(i);

            for (string op : operation ) {
                if (op == "+") {
                    currSum += previousNum;
                    previousNum = nums[i];             
                } else if (op == "-" ) {
                    currSum += previousNum;
                    previousNum = -nums[i];
                } else if (op == "*") {
                    previousNum = previousNum * nums[i];
                } else if (op == "/" ){
                    previousNum = previousNum / nums[i];
                } else if (op == "*-alt") {
                    currSum += previousNum;
                    currSum *= nums[i];
                    previousNum = 0;
                } else if (op == "/-alt") {
                    currSum += previousNum;
                    currSum /= nums[i];     
                    previousNum = 0;
                    // 2 X (4 - 2) X 2
                    // 
                    // previousNum = nums[idx] / nums[i];
                }
                
                bool answer = isReachableHelper(nums, currSum, previousNum, target, visited);
                
                if (answer)
                    return true;
                
            }
            
            visited.erase(i);
            
        }
        
        if (visited.size() == nums.size()) {
            return target == (currSum + previousNum);
        }
        
        return false;
      }
    };


    int main(){
        // 
        CalculateTarget t;
        vector<int> nums = {2,3,4,5};
        
        bool answer = t.isReachable(nums, 24);
        
        cout << (answer ? "TARGET FOUND" : "TARGET NOT FOUND") << endl;
        return 0;
        
    }

            /*
            1 + 2 X 3 * 4
                    X
            currSum = 0;
            previousSum = 0;
            
            
            1 + (2 - 1) X 3) * 4
            
            2 - 1 * 5   => 10
            
            currSum => 2 
            previousNum = -1
            */

                    /*
                    two cases: 
                        follow prcesdence
                        
                        2 - 1 * 5
                        currSum = 2
                        previous = -1*5 
                        
                        currSum = -3
                        
                        
                        currSUm = 2
                        
                        currSUm = (currSum + previous) * nums[i]
                        
                        1 2 3 4 5 1
                        
                        isReachableHelper(0) -> [+-/*] 
                                                  -> isReachableHelper(1)
                                                                   ->  isReachableHelper(2)
                                                                   
                                                                   
                      2 3 5 4
                      
                      2 -> [5]                                             
                        
                    */