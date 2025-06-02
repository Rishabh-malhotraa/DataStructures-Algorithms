
/*
⸻

📦 Shipping Cost Calculator

You’re working on a logistics platform. Given a string of shipping routes, write functions to compute:
	1.	The direct shipping cost from one country to another.
	2.	The cheapest shipping cost, possibly through intermediate countries.

⸻

🔧 Function Signatures

int getDirectShippingCost(const std::string& inputString, const std::string& source, const std::string& destination);

int getCheapestShippingCost(const std::string& inputString, const std::string& source, const std::string& destination);


⸻

🧪 Input Format
	•	inputString: Colon-separated shipping records in the format from,to,provider,cost
	•	Each field is a comma-separated string; cost is a positive integer.

Example:

"US,UK,UPS,5:US,CA,FedEx,3:CA,UK,DHL,7"

	•	source: A 2-letter country code (e.g., "US")
	•	destination: A 2-letter country code (e.g., "UK")

⸻

✅ Output

For getDirectShippingCost:
	•	Return the cost of a direct shipment from source to destination, or -1 if not found.

For getCheapestShippingCost:
	•	Return the minimum total cost from source to destination, possibly via intermediate hops.
	•	Return -1 if no path exists.

⸻

🧾 Examples

Input:

inputString = "US,UK,UPS,5:US,CA,FedEx,3:CA,UK,DHL,7"
source = "US"
destination = "UK"

Output:

getDirectShippingCost(...) → 5
getCheapestShippingCost(...) → 5

Input:

inputString = "US,CA,FedEx,3:CA,UK,DHL,7"
source = "US"
destination = "UK"

Output:

getDirectShippingCost(...) → -1
getCheapestShippingCost(...) → 10


⸻

📁 Constraints
	•	Country codes and provider names are always valid.
	•	Costs are integers ≥ 1.
	•	You can assume a max of 500 shipping records in the input string.

⸻

Let me know when you’re ready to test your implementation — I can generate edge cases or guide you with follow-up questions (like provider preference, cycle handling, etc.).
*/
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <cassert>
#include <iostream>
#include <optional>
#include <string>


using namespace std;
using namespace boost;


struct Route {
    string from;
    string to;
    string provider;
    int cost;
  
};


/*
inputString = "US,UK,UPS,5:US,CA,FedEx,3:CA,UK,DHL,7"
source = "US"
destination = "UK"
*/

class ShippingCost {
    private:
    string rawRoutes;
    unordered_map<string, vector<Route>> shippingGraph;
    void parseRoutes(const string& input) {
        vector<string> routeStrings;
        
        split(routeStrings, input, is_any_of(":"));
        vector<Route> routes;
        for (string routeString : routeStrings){
            vector<string> fields;
            split(fields, routeString, is_any_of(","));
            
            
            shippingGraph[fields[0]].push_back(Route{
                .from = fields[0],
                .to = fields[1],
                .provider = fields[2],
                .cost = stoi(fields[3])
            });
        }
    }
    
    public:
        ShippingCost(string input) {
            this->rawRoutes = input;
            parseRoutes(input);
        }
        
    void calculateCostHelper(string source, string destination, unordered_set<string> visited, int feeSoFar, optional<int> &fee){
        if (source == destination) {
            fee = fee.has_value() ? fee : optional<int>{INT_MAX};
            fee = min(*fee, feeSoFar);
            return;
        }

        
        visited.insert(source);

        
        for (Route route : shippingGraph[source]) {
            if (!visited.contains(route.to)) {
                calculateCostHelper(route.to, destination, visited, feeSoFar + route.cost, fee);
            }
        }
        
        visited.erase(source);
        
        return;
    }
    
        optional<int> calculateCost(string source, string destination){
        unordered_set<string> visited;
        optional<int> fee;
        calculateCostHelper(source, destination, visited, 0.0, fee);
        cout << fee.value() << endl;
        return fee;
    }
};




int main() {
    /*
    US ───► UK  (15)
    │
    ├─► CA ─► MX ─► UK  (4+2+3 = 9)
    │
    └─► FR ─► DE ─► UK  (10+2+1 = 13)

    UK ──► US  (cycle, shouldn't affect cost)
    */
    std::string input =
        "US,UK,FastShip,15:"
        "US,CA,FedEx,4:"
        "CA,MX,DHL,2:"
        "MX,UK,UPS,3:"
        "US,FR,LaPoste,10:"
        "FR,DE,DHL,2:"
        "DE,UK,UPS,1:"
        "UK,US,BackTrack,20";

    std::string source = "US";
    std::string destination = "UK";
    ShippingCost shippingCost(input);

    int expected = 9;
    optional<int> result = shippingCost.calculateCost(source, destination);

    if (result) {
        std::cout << "Computed cost: " << result.value() << std::endl;
    } else {
        cout << "Path Does not exist" << endl;
    }
    
    cout << " " << *result << " " << expected << endl;
    assert(result == expected && "Indirect shipping cost should be 9");

    std::cout << "✅ Test passed!" << std::endl;
    return 0;
}