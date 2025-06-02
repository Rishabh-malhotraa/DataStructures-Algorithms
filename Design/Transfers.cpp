#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

const int THRESHOLD = 100;

struct Transfer {
  string from;
  string to;
  int amount;
};

vector<Transfer> rebalance_accounts(const unordered_map<string, int>& accounts) {
  vector<Transfer> result;

  vector<pair<string, int>> surplus, deficiet;


  for (auto [account, balence] : accounts) {
    if (balence > THRESHOLD) {
      surplus.push_back({ account, balence });
    }
    else if (balence < THRESHOLD) {
      deficiet.push_back({ account, balence });
    }
  }

  int idx1 = 0, idx2 = 0;

  while (idx1 < surplus.size() && idx2 < deficiet.size()) {
    int ammountProvide = surplus[idx1].second - THRESHOLD;
    int amountNeed = THRESHOLD - deficiet[idx2].second;

    int transfer = ammountProvide - amountNeed;
    int canTransfer = min(ammountProvide, amountNeed);


    surplus[idx1].second -= canTransfer;
    deficiet[idx2].second += canTransfer;

    if (transfer > 0) {
      result.push_back(Transfer{ surplus[idx1].first, deficiet[idx2].first, canTransfer });
      idx2++;
    }
    else if (transfer < 0) {
      result.push_back(Transfer{ surplus[idx1].first, deficiet[idx2].first, canTransfer });
      idx1++;
    }
    else {
      result.push_back(Transfer{ surplus[idx1].first, deficiet[idx2].first, canTransfer });
      idx1++, idx2++;
    }
  }

  return result;
}

int main() {
  unordered_map<string, int> accounts = {
    // Sample input
    {"AU", 80},
    {"US", 140},
    {"MX", 110},
    {"SG", 120},
    {"FR", 70}
  };

  vector<Transfer> transfers = rebalance_accounts(accounts);

  for (const auto& t : transfers) {
    cout << "from: " << t.from << ", to: " << t.to << ", amount: " << t.amount << endl;
  }

  return 0;
}