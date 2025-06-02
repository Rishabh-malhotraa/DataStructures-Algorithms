#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h>

using namespace std;

/*
Compute the total amount spent per user in USD, but only include transactions that happened in the last N days relative to a given reference timestamp.

This is a nightmare in c++ unfortunately
*/

/*
"<user_id>,<amount>,<currency>,<timestamp>"


	Parse the input strings.
	2.	Group transactions by user_id.
	3.	Return the total amount spent by each user in USD, assuming you are given an exchange rate map:
    std::unordered_map<std::string, double> exchange_rates;
    // e.g., {"USD": 1.0, "EUR": 1.1, "JPY": 0.007}
*/
    struct Transaction {
        string user;
        double amount;
        string currency;
        string timestamp;
    };

    class TransactionCalculator {
    private:        
    unordered_map<string, vector<Transaction>> get_transaction_map(vector<string>& transfers) {
        unordered_map<string, vector<Transaction>> transaction_map;
        for (string transfer : transfers) {
            vector<string> tokens;
            boost::split(tokens, transfer, boost::is_any_of(","));
            
            string user = tokens[0], currency = tokens[2], timestamp = tokens[3];
            double amount = stod(tokens[1]);            
            transaction_map[user].push_back(Transaction{user, amount, currency, timestamp});            
        }
        
        return transaction_map;
    }
    public : 
        vector<pair<string, double>> compute_usd_totals( vector<string>& transfers, unordered_map<string, double>& exchange_rates) {
            unordered_map<string, vector<Transaction>> transaction_map = get_transaction_map(transfers);
            
            vector<pair<string, double>> usd_total;
            for (auto &[userId, transactions] : transaction_map) {
                    double cost = 0.0;
                    for (Transaction &transaction: transactions) {
                            cost += transaction.amount * exchange_rates[transaction.currency];
                    }
                    usd_total.push_back({userId, cost});
            }
            
            return usd_total;
        }
        
        
        vector<pair<string, double>> compute_usd_totals_windowed(
            vector<string>& transactions, unordered_map<string, double>& exchange_rates,
            string& reference_iso_timestamp, int window_days) {
            
            vector<string> prunedTransactions;
            for (string transaction : transactions) {
                int idx = transaction.rfind(',');
                string date = transaction.substr(idx + 1);
            
                time_point<system_clock> tp;
                
                stringstream ss(date);
                
                ss >> chrono::parse("%F%TZ", tp);
                
                
                
                auto time = system_clock::now();
                
            }
            
            
            
            return compute_usd_totals(prunedTransactions, exchange_rates);
        }

    };

int main() {
    vector<string> transactions = {
        "alice,100,USD,2024-06-01T10:00:00Z",
        "bob,200,EUR,2024-06-01T11:00:00Z",
        "alice,300,JPY,2024-06-01T12:00:00Z"
    };

    unordered_map<string, double>exchange_rates = {
    {"USD", 1.0},
    {"EUR", 1.1},
    {"JPY", 0.007}
    };    
    string reference_iso_timestamp = "2024-06-01T23:59:59Z";
    int window_days = 3;
    
    TransactionCalculator tx;
    
    auto result = tx.compute_usd_totals(transactions, exchange_rates);
    auto result2 = tx.compute_usd_totals_windowed(transactions, exchange_rates, reference_iso_timestamp, window_days);
    
    
    sort(result.begin(), result.end(), [](const pair<string, double> &a, const pair<string, double> &b){
        return a.second > b.second;
    });
    
    for (auto [key, value] : result) {
        cout << key << " : " << value << endl;
    }

    return 0;
}
