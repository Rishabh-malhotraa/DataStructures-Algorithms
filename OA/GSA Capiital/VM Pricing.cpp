/*
8. VM Pricing
A cloud service provider offers quantity discounts based on the number of virtual machines a customer needs.Their offerings vary from 2 to 2000 instances.

When pricing is requested, the customer's representative refers to a list of past pricing.
Given a list of past price quotes and the number of instances a customer needs, determine the per - instance price for the customer.

📘 Method for Determining Price
If the number of instances needed is exactly the same as the quantity for a prior customer, the unit price is that price.

If there is a price for a larger and a price for a smaller number of instances, linearly interpolate the price of the quantity needed from the unit prices for the closest smaller and larger quantities.

If the quantities for which there is past data are all smaller or all larger than the amount needed, then linearly extrapolate the unit price from the two points closest to the quantity needed.

If the database only has 1 quantity, that is the price per unit.

Ignore any price quotes that are 0 or negative.

🧠 Example
If past prices are :

text
Copy
Edit
instances = [25, 50, 100]
price = [5.0, 4.0, 3.0]
To compute the price for 75:

It lies between 50 and 100.

Interpolate the unit price accordingly.

To compute the price for 150:

It lies beyond the known data.

Extrapolate using the two nearest known points : (50, 4.0) and (100, 3.0)
*/

/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;


pair<int, int> findClosestPoints(vector<pair<int, double>>& ip, int n, int m) {
  if (n < ip[0].first)
    return { 0, 1 };
  else if (n > ip[m - 1].first)
    return { m - 1, m - 2 };
  else {
    for (int i = 0; i + 1 < m; i++) {
      if (ip[i].first < n && ip[i + 1].first > n)
        return { i, i + 1 };
    }
  }
  return { -1, -1 };
}

string trimToDecimal(double number) {
  std::string result = std::to_string(number);

  // Trim to 2 decimal places and remove trailing zeros
  int dot = result.find('.');
  if (dot != std::string::npos) {
    result = result.substr(0, dot + 3);                // keep 2 decimal places max
    while (result.back() == '0') result.pop_back();    // remove trailing zeroes
    if (result.back() == '.') result.pop_back();       // remove dangling dot
  }

  return result;
}

string solve(int n, vector<int>& instances, vector<double>& prices) {
  int m = instances.size();
  vector<pair<int, double>> ip;
  for (int i = 0; i < m; i++) {
    if (prices[i] > 0) {
      if (instances[i] == n)
        return std::to_string(prices[i]);
      ip.push_back({ instances[i], prices[i] });
    }
  }

  if (ip.size() == 1)
    return std::to_string(ip.back().second);

  sort(ip.begin(), ip.end());
  pair<int, int> cp = findClosestPoints(ip, n, ip.size());

  double slope = (ip[cp.second].second - ip[cp.first].second) /
    (ip[cp.second].first - ip[cp.first].first);

  double cost = (std::round((slope * (n - ip[cp.first].first) + ip[cp.first].second) * 100.0) / 100.0);
  return trimToDecimal(cost);
}
