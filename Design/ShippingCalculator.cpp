#include<bits/stdc++.h>

using namespace std;

struct Product{
    string product;
    string country;
    optional<int> flatPricing;
    vector<pair<int, int>> tieredPricing;
};


struct UserOrder{
    string product;
    string country;
    int quantity;
};


class CheckoutPriceCalculator {
    private:
    unordered_map<string, Product> catalog;
    
    string getHash(Product product) {
        return product.product + "#" + product.country;
    }
    
    string getHash(UserOrder userOrder) {
        return userOrder.product + "#" + userOrder.country;
    }
    
    int flatPricing(UserOrder userOrder){
        return userOrder.quantity * catalog[getHash(userOrder)].flatPricing.value();
    }
    
    int tieredPricing(UserOrder userOrder){
        vector<pair<int, int>> tieredPricing = catalog[getHash(userOrder)].tieredPricing;
        int quantity = userOrder.quantity;
        int price = 0, idx = 0, previous = 0;
        while (quantity != 0) {
            int maxQuantityForTier = (idx == tieredPricing.size() - 1 ? INT_MAX : tieredPricing[idx].first - previous);
            
            int transfer = min(maxQuantityForTier, quantity);
            price += transfer * tieredPricing[idx].second;
            
            quantity -= transfer;
            previous = tieredPricing[idx].first;
            
            idx++;   
        }
            return price;
    }
    
    public:
        CheckoutPriceCalculator(vector<Product> products){
            for (Product product: products) {
                this->catalog[getHash(product)] = product;
            }
        }
        
        int calculatePrice(vector<UserOrder> userOrders){
            int price = 0;
            for (UserOrder userOrder : userOrders) {
                Product product = catalog[getHash(userOrder)];
                if (product.flatPricing.has_value()) {
                    price += this->flatPricing(userOrder);
                } else {
                    price += this->tieredPricing(userOrder);
                }
            }
            
            return price;
        }
};


int main(){
    vector<Product> products{
        {"apple", "US", nullopt, {
            {30, 105},
            {60, 95},
            {100, 85}
        }},
        {"banana", "US", nullopt, {
            {20, 120},
            {50, 100},
            {90, 80}
        }},
        {"apple", "CA", nullopt, {
            {40, 110},
            {75, 90},
            {100, 70}
        }},
        {"banana", "CA", nullopt, {
            {25, 130},
            {65, 100},
            {95, 75}
        }},
    };
    vector<UserOrder> userOrders{
        {"apple", "US", 61},
        };    
        
    CheckoutPriceCalculator checkoutPriceCalculator(products);
    
    cout << "User Fee " << checkoutPriceCalculator.calculatePrice(userOrders);
    return 0;
}