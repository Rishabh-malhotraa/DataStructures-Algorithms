

/*
 * 
 * Garage -> List<Vehicle>
 * 
 * VehicleSlot ->
 * 
 * 
 * Vehicle -> {}
 * 
 * 
 * 
 * []
 * 
 */


enum VehicleType {
  MOtORCYCLE,
  HATCHBACK,
  CAR;
}

@Data
class Vehicle {
  private String lienceNumber;
  VehicleType vehicletype;
}

class VehicleSlot {
  // getter setter
  private boolean isOccupied;
  private boolean isHandicapped;
  private VehicleType vehicletype;
  private int floor;
  private int slotNumber;
}

@Builder
class Ticket {
  VehicleSlot vehicleSlot;
  Vehicle Vehicle;
  Instant createTime;
}

interface IGarageService {
  public Ticket book(String lienceNumber, VehicleType vehicletype);

  public void exit(Ticket ticket);
}

interface IParkingStrategy {
  VehicleSlot getFreeSlot(VehicleType vehicleType);
  addSlot(VehicleSlot vehicleSlot);
  removeSlot(VehicleSlot vehicleSlot);

}

interface IDisplayService[
void display(String);
]

class ParkingStrategy implements IParkingStrategy {
    int SLOTS_AVAIABLE = 0;
    private ArrayList<VehicleSlot> slots;
    
    public ParkingStrategy(int SLOTS_AVAIABLE, ArrayList<VehicleSlot> slots){
        this.SLOTS_AVAIABLE = SLOTS_AVAIABLE;
        this.slots = slots
    }

    // the first vacant slot
    @Nullable
     public VehicleSlot getFreeSlot(VehicleType vehicleType){
         for (VehicleSlot slot : slots){
             if (slot.vehicletype == vehicleType && slot.isOccupied == false){
                 return slot;
             }
         }
         return null;
     }

    public void printSlotsAvailable () {
        HashMap<VehicleSlot, int> slotsCount;

            for (VehicleSlot slot : slots){
               if (slot.isOccupied == false){
                 slotsCount[slot.vehicleType]++;
             }
           }
      // PRINT 

      for (Pair<VehicleSlot, int> slot : slotsCount ){
            display.display(String.format(" Number of slots for %s : %d", slot.vehicleType, slotslotNumber));
      }

    }

     //

}


// 1. Radom
// 2, LRU -> []

class GarageService implements IGarageService {
    private ParkingStrategy strategy;

    public GarageService (ParkingStrategy strategy) {
        this.strategy = strategy;
    }

    // 
    public synchronized Ticket book(String lienceNumber, VehicleType lienceNumber){
        // 
        VehicleSlot slot = strategy.getFreeSlot(vehicleType);
          
        if (slot == null) {
            throw SlotNotAvailable("Slot is not available")
        }
        
        slot.isOccupied = true;

        Vehicle vehicle = new Vehicle(lienceNumber, lienceNumber);
        return new Ticket(vehicle, slot);
    }

    // free up the slot
    public synchronized void exit(Ticket ticket){
        // assuming we have getter and setter
        VehicleSlot slot = ticket.getSlot(vehicleType);

        slot.isOccupied = false;
    }

}
