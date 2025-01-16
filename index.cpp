/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Excel {
public:
  string setCell(string cell, string value) {
    sheet[cell] = value;
  }

  string getCell(string cellName) {
    if (sheet.find(cellName) == sheet.end()) {
      throw invalid_argument("Cell does not exist");
    }
    return sheet[cellName];
  }

  int evaluateCell(string cell) {
    evaluate(sheet[cell]);
  }

private:
  unordered_map<string, string> sheet;

  int evaluate(string formula) 
  {

  }


};





class Solution {
public:
  void updateStack(int num, char& op, stack<int>& nums) {
    int el = INT_MIN;
    if (op == '+') {
      nums.push(num);
    }
    else if (op == '-') {
      nums.push(-num);
    }
    else if (op == '*') {
      nums.top() = nums.top() * num;
    }
    else if (op == '/') {
      nums.top() = nums.top() / num;
    }
  }

  int accumulateStack(stack<int>& s) {
    int sum = 0;
    while (!s.empty()) {
      sum += s.top();
      s.pop();
    }
    return sum;
  }


  int calculate(string s) {
    stack<int> nums;
    string ops = "+-/*";

    string digits = "";
    char op = '+';
    int n = s.size();

    for (int i = 0; i < n; i++) {
      char ch = s[i];
      if (isdigit(ch)) {
        digits += s[i];
      }
      else if (ops.find(ch) != string::npos) {
        updateStack(stoi(digits), op, nums);
        op = ch;
        digits = "";
      }
    }

    updateStack(stoi(digits), op, nums);

    return accumulateStack(nums);
  }
};








int main() {
  Excel excel;

  excel.setCell("A1", "5");
  excel.setCell("B1", "A1 + 10");
  excel.setCell("C1", "B1 - 3");

  cout << "A1: " << excel.evaluateCell("A1") << endl; // Output: 5
  cout << "B1: " << excel.evaluateCell("B1") << endl; // Output: 15
  cout << "C1: " << excel.evaluateCell("C1") << endl; // Output: 12

  return 0;
}