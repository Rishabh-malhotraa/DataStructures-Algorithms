#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
  // tuple<isBST, sum, minValue, maxValue>
  tuple<bool, int, int, int> traverse(TreeNode *root, int &maxSum, int sum, int minValue, int maxValue)
  {
    if (root == NULL)
    {
      return {true, 0, INT_MAX, INT_MIN};
    }

    auto [lIsBST, lSum, lMin, lMax] = traverse(root->left, maxSum, sum, minValue, maxValue);
    auto [rIsBST, rSum, rMin, rMax] = traverse(root->right, maxSum, sum, minValue, maxValue);

    int leftValue = root->left ? root->left->val : INT_MIN;
    int rightValue = root->right ? root->right->val : INT_MAX;

    // cout << "root - node " << root->val << endl;
    // cout << lIsBST << " " << lSum << " " << endl;
    // cout << rIsBST << " " << rSum << " " << endl;
    // cout << "maxSumOfBST " << maxSum << endl;

    if (lIsBST && rIsBST && (leftValue < root->val && rightValue > root->val) && (lMax < root->val && rMin > root->val))
    {
      maxSum = max(maxSum, lSum + rSum + root->val);
      return {true, lSum + rSum + root->val, min(lMin, root->val), max(rMax, root->val)};
    }

    return {false, sum, INT_MAX, INT_MIN};
  }

public:
  int maxSumBST(TreeNode *root)
  {
    int maxSum = 0;
    traverse(root, maxSum, 0, 0, 0);

    return maxSum;
  }
};
void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  Solution *sol = new Solution();

  // cout << sol->maxSumBSTindex;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}