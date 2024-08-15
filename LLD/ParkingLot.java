import java.util.*;


class ParkingSlotStrategy implements IParkingSlotStrategy {
  private ArrayList<ParkingSlot> parkingSlots;

  ParkingSlotStrategy(ArrayList<ParkingSlot> parkingSlots) {
    this.parkingSlots = parkingSlots;
  }

  // TC : O(N) ; where N is the number of parking Slots
  // We can make this O(1) by
  public ParkingSlot getAndBookAvailableSlot(VehicleType vehicleType) {
    for (ParkingSlot slot : parkingSlots) {
      if (slot.isAvaiable() && slot.getSlotType() == vehicleType) {
        slot.reserve();
        return slot;
      }
    }

    return null;
  }
}

@Data
@Builder
class Ticket {
  private String liecenseNumber;
  private VehicleType vehicleType;
  private ParkingSlot slot;
}

class ParkingGarageService {
  private ParkingSlotStrategy strategy;

  public ParkingGarageService(ParkingSlotStrategy strategy) {
    this.strategy = strategy;
  }

  public Ticket book(String liecenseNumber, VehicleType vehicleType) throws Exception {
    ParkingSlot slot = strategy.getAndBookAvailableSlot(vehicleType);
    
    if (slot == null) {
      throw new Exception("Parking Slot Not Available");
    }

    return new Ticket();

  }

  public void unbook(Ticket ticket) {
    ParkingSlot slot = ticket.getParkingSlot();
    slot.unreserve();

    return;
  }
}

class ParkingLot {

}

enum VehicleType {
  CAR("car"),
  BIKE("bike"),
  TRUCK("truck");

  private String vehicleType;

  private VehicleType(String vehicleType) {
    this.vehicleType = vehicleType;
  }
};

enum COLOR {
  RED,
  BLUE,
  BLACK
};

class Vehicle {
  private String liecenseNumber;
  private VehicleType vehicleType;

  public Vehicle(String liecenseNumber, VehicleType vehicleType) {
    this.liecenseNumber = liecenseNumber;
    this.vehicleType = vehicleType;
  }

  // get
  // set
}

class MotorBike extends Vehicle {
  public MotorBike(String liecenseNumebr) {
    super(liecenseNumebr, VehicleType.BIKE);
  }
}

class Car extends Vehicle {
  public Car(String liecenseNumebr) {
    super(liecenseNumebr, VehicleType.CAR);
  }
}

class Truck extends Vehicle {
  public Truck(String liecenseNumebr) {
    super(liecenseNumebr, VehicleType.TRUCK);
  }
}

/**
 * ParkingLot
 */
interface IParkingSlotStrategy {
  public ParkingSlot getAndBookAvailableSlot(VehicleType vehicleType);

  // void removeSlot(ParkingSlot slot);
  // void addSlot(ParkingSlot slot);
}

interface ParkingSlot {
  boolean isAvaiable();

  VehicleType getSlotType();

  void reserve();

  void unreserve();
}
