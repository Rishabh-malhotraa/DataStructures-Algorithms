import java.util.*;



class Item {
  String itemCode;
  int quantity;
  double cost;
}


// Vending Machine

interface DisplayService{
  void showMessage(String message);
}


/**
 * VendingMachine
 */
interface IVendingMachine {
  void selectItemAndGetPrice();
  void insertCoin();
  void dispenseItem();
  void cancelTxn();
}


interface IPaymentService {
  public addMoney();
  public dispenseMoney();
  public reset();
}


class PaymentService implements IPaymentService {

}


enum Coin {
  PENNY,
  NICKEL,
  DIME,
  QUARTER
}

class VendingMachineService implement IVendingMachine {
  private PaymentService paymentService;
  private Map<String, Item> itemInventory;
  private Map<String, Cash> cashInventory;
  private DisplayService display;

  public VendingMachineService(){}


  void selectItemAndGetPrice(String itemCode){
    Item item = itemInventory.get(itemCode);
    
    boolean isAvaiable = isItemValidAndAvailable(item);

    if (isAvaiable) { 
      paymentService.setCost(item.cost);
      display.showMessage(String.format("Item Cost : %d", item.cost));
    }
  }

  pubic void insertCoin(Coin coin){
    paymentService.addMoney(coin);
  }

  public void dispenseItem(String itemCode) {
    Item item = itemInventory.get(itemCode);

    if (isItemValidAndAvailable(item) && paymentService.isPaymentComplete()){
      // logic to return change coins

      // cancelTxn()
    }
  }

  public cancelTxn() {
    
  }

  private boolean isItemValidAndAvailable(Item item){
    boolean isAvailable = true;
    if(item == null) {
      display.showMessage("Invalid Item Code");
      isAvailable = false;
    }
    else if (item.quantity == 0) {
      display.showMessage("Insufficient Item quanitity");
      isAvailable = false;
    }
    return isAvailable;
  }
}



class MyUserException extends RuntimeException {
  String message;

  MyUserException(String message) {
    this.message = message;
  }

  @Override
  public String getMessage() {
    return message;
  }

}