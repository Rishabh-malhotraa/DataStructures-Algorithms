
/*
   7.12312
1234.10000

result = 0
for (string num: nums) {
  result = addTwo(result, num);
}
  */
#include <bits/stdc++.h>
using namespace std;

void addPadding(string& a, string& b) {

  bool doesExist1 = a.find('.') != string::npos;
  bool doesExist2 = b.find('.') != string::npos;


  int i1 = doesExist1 ? a.size() - 1 - a.find('.') : 0;
  int i2 = doesExist2 ? b.size() - 1 - b.find('.') : 0;

  int diff = abs(i2 - i1);

  if (i2 > i1) {
    a = a + (doesExist1 ? "" : ".") + string(diff, '0');
  }
  else {
    b = b + (doesExist2 ? "" : ".") + string(diff, '0');
  }
}

string addNumber(string a, string b) {
  addPadding(a, b);

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  string result = "";
  int sum = 0, carry = 0;
  for (int i = 0; i < max(a.size(), b.size()); i++) {
    if (i < min(a.size(), b.size()) && a[i] == '.') {
      result.push_back('.');
      continue;
    }

    int val1 = (i < a.size()) ? a[i] - '0' : 0;
    int val2 = (i < b.size()) ? b[i] - '0' : 0;

    sum = (val1 + val2 + carry) % 10;
    carry = (val1 + val2 + carry) / 10;

    result += to_string(sum);
  }

  if (carry) {
    result += to_string(carry);
  }

  reverse(result.begin(), result.end());

  return result;

}



int main() {
  vector<string> numbers = { "1.1", "1212.2", "12321312", "131.12321321312" };

  string result = "";

  for (string number : numbers) {
    result = addNumber(result, number);
  }

  cout << result << endl;
  return 0;
}
