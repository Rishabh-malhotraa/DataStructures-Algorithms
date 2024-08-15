
import java.lang.reflect.Array;
import java.util.*;
/*
 * 1. Shopping Cart Service
 *   
 *    -> List of Iteams
 * 
 *    -> Total Cost of items in the shopping cart
 *    -> User Information [Billing Address | Shipping Address]
 *    -> Make Payment
 *
 *    -> Logic to implement discount based on certain rules
 * 
 * 
 */

 class Item {
  String itemId;
  double itemCost;
  String itemName;
  String itemSeller;
 };

 class User {
  String name;
  Address billingAddress;
  Address shippingAddress;
 }

 class Address {

 }

 class Discount{
  double totalCost;
  double discount;
  double shippingFee;
 }

 interface Rule{
  boolean isValid(ArrayList<Item> items);
  Discount ruleApplier(ShoppingCart shoppingCart);
 }

interface IRuleEngine{
  void configureRule();
  Pair<Double, Double> applyRules();
}

 class RuleEngine implements IRuleEngine {


  public void applyRule(Rule rule, ShoppingCart cart) {
    ArrayList<Item> items = cart.getItems();
    if (rule.isValid(items)) {
      return rule.ruleApplier(cart);
    }
  }
 }

 interface IShoppingCartService {
  double calculateDiscount();
  double calculateTotal();

  // getter and setter functions
 }


 @Data  // lombok autogenerate getter and setter functions
 class ShoppingCartService extends IShoppingCartService {
  private ArrayList<Rule> rules;
  private ArrayList<Item> items;
  int 
  
  public ShoppingCartService(ShoppingCartConfig config, ArrayList<Item> items) {
    this.rules = config.getRules();
    this.items = items;
  }

  double calculateTotal(){
    double cost = 0.0d;
    for(Item item : items) {
      items += item.itemCost;
    }
    return cost;
  }

  double calculateDiscount() {

    for (rule)
  }
  
 }
    

  @Singleton
  class ShoppingCartConfig {
    private static ArrayList<Rule> rules;
    
    ArrayList<Rule> getRules(){
      return rules;
    }

  }


[Sum] -> apply rule1 -> apply rule2 -> apply rule 3



class ShoppingCart {
  
}



