import java.time.Instant;
// Entitites

// 1. Meeting Room
// 2. User
// 3. Booking


// Requiremets 
// 1. Can we walk through one working example for this
// User -> selects the room [these rooms can have different sizes? and different features?] 
        // -> selects the time?
        // -> if room unavaible should the service suggest some rooms around?
        // -> people to invite? 
        //     -> should the service poll the availability of the people I am inviting?
        // -> Book the room 
        // -> We want our system to be thread safe? so two people don't book the room at the same time

import java.util.TreeSet;

class MeetingRoom {
  String meetingRoomId;
  TreeSet<Booking> bookings;
  int capcity;
  boolean supportsConferenceCall; // think of a better name
  boolean hasDisplayScreeen;
}

class User{
  String userId;
  String firstName;
}

class Booking implements Comparable<Booking>{
  Instant startTime;
  long duration;
  User host;
  ArrayList<User> invitedUses;

  @Override
  public int compareTo(Booking booking) {
    return Long.compare(startTime.toEpochMilli(), booking.startTime.toEpochMilli());
  }
} 


