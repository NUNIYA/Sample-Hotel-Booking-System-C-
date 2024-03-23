#include <iostream>
#include <string>
using namespace std;
struct Room {
    int number;
    string type;
    bool assigned;
    double price;
};
struct Reservation {
    string customerName;
    string customerPhoneNumber;
    int roomNumber;
    bool foodServices;
    double foodServicePrice;
};
Room rooms[5]; // Array to store room information
Reservation reservations[20]; // Array to store reservation information
int numRooms = 5; // Number of available rooms
int numReservations = 0; // Number of reservations made
// Function to initialize room data
void initializeRooms() {
    rooms[0] = {1, "Single", false, 150.0};
    rooms[1] = {2, "Double", false, 180.0};
    rooms[2] = {3, "Deluxe", false, 1120.0};
    rooms[3] = {4, "Suite", false, 1200.0};
    rooms[4] = {5, "Penthouse", false, 10350.0};
}
// Function to display room details
void displayRoomDetails() {
    cout << "Room Details:" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < numRooms; i++) {
        cout << "Room Number: " << rooms[i].number << endl;
        cout << "Room Type: " << rooms[i].type << endl;
        cout << "Price: " << rooms[i].price <<"Birr"<<endl;
        cout << "Assigned: " << (rooms[i].assigned ? "Yes" : "No") << endl;
        cout << "-----------------------" << endl;
    }
}
// Function to book a room
void bookRoom() {
    int roomNumber;
    string customerName;
    string customerPhoneNumber;
    bool foodServices;
    double foodServicePrice = 0.0;
    double totalAmount = 0.0;
    cout << "please Enter your name: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "please Enter your phone number: ";
    getline(cin, customerPhoneNumber);
    displayRoomDetails();
    cout << "Enter the room number you want to book: ";
    cin >> roomNumber;
    if (roomNumber < 1 || roomNumber > numRooms) {
        cout << "Invalid room number. Please try again." << endl;
        return;
    }
    if (rooms[roomNumber - 1].assigned) {
        cout << "Room " << roomNumber << " is already assigned." << endl;
        return;
    }
    rooms[roomNumber - 1].assigned = true;
    cout << "Do you want food services? (click [1] for Yes, click [0] for No): ";
    cin >> foodServices;
    if (foodServices) {
        int choice;
        cout << "please Choose food services: " << endl;
        cout << "1. Breakfast only - 150 Birr" << endl;
        cout << "2. Dinner only - 200 Birr" << endl;
        cout << "3. Both breakfast and dinner - 320 Birr" << endl;
        cout << "please Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                foodServicePrice = 150.0;
                break;
            case 2:
                foodServicePrice = 200.0;
                break;
            case 3:
                foodServicePrice = 320.0;
                break;
            default:
                cout << "Invalid choice. Food services not selected." << endl;
        }
    }
    totalAmount = rooms[roomNumber - 1].price + foodServicePrice;
    cout << "Total Amount: $" << totalAmount << endl;
    // Payment logic goes here (online payment)
    reservations[numReservations] = {customerName, customerPhoneNumber, roomNumber, foodServices, foodServicePrice};
    numReservations++;
    cout << "Room is booked successfully!" << endl;
}
// Function to display reservation history
void displayReservationHistory() {
    cout << "Reservation History:" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < numReservations; i++) {
        cout << "Customer Name: " << reservations[i].customerName << endl;
        cout << "Room Number: " << reservations[i].roomNumber << endl;
        cout << "Phone Number: " << reservations[i].customerPhoneNumber << endl;
        cout << "Food Services: " << (reservations[i].foodServices ? "Yes" : "No") << endl;
        cout << "Food Services Price: " << reservations[i].foodServicePrice <<"Birr"<<endl;
        cout << "-----------------------" << endl;
    }
}
void AboutourHotel() {
    cout << "Hotel Details:\n";
    cout << "Hotel Name: BSN ROYAL HOTEL\n";
    cout << "Construction Year: 2000 G.G\n";
    cout << "Constructed By: JIJI Construction Company\n";
    cout <<"founders:Nuniyat,Bethele,selamawit.\n";
    cout << "Star Rating: 4\n";
    cout <<"motto: a place where  luxury meets affordability, and where every guest is made to feel like a VIP.\n";
}
// Function to cancel a reservation
void cancelReservation() {
    int roomNumber;
    bool found = false;
    cout << "Enter the room number of your reservation: ";
    cin >> roomNumber;
    for (int i = 0; i < numReservations; i++) {
        if (reservations[i].roomNumber == roomNumber) {
            if (reservations[i].foodServices) {
                // Deduct penalty fee for cancellation with food services
                rooms[roomNumber - 1].assigned = false;
                cout << "Penalty fee of 50 birr deducted for cancellation with food services." << endl;
            } else {
                // Deduct penalty fee for cancellation without food services
                rooms[roomNumber - 1].assigned = false;
                cout << "Penalty fee of 20 birr deducted for cancellation without food services." << endl;
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Reservation not found for room " << roomNumber << "." << endl;
    }
}
int main() {
    int choice;
    initializeRooms();
    cout << "\t_______________________________________" << endl;
    cout << "\t\tWELCOME TO BSN ROYAL HOTEL" << endl;
    cout << "\t_______________________________________" << endl;
    do {
        cout << "\t_____________Main Menu________________" << endl;
        cout << "\t Choose 1 to Book a room" << endl;
        cout << "\t Choose 2 View room details" << endl;
        cout << "\t Choose 3 View reservation history" << endl;
        cout << "\t Choose 4 Cancel a reservation" << endl;
        cout << "\t choose 5 to see details about BSN ROYAL HOTEL" << endl;
        cout << "\t Choose 6 to exit" << endl;
        cout << "\t Please Enter your choice from the above menu : ";
        cin >> choice;
        switch (choice) {
            case 1:
                bookRoom();
                break;
            case 2:
                displayRoomDetails();
                break;
            case 3:
                displayReservationHistory();
                break;
            case 4:
                cancelReservation();
                break;
            case 5:
                AboutourHotel();
                break;
            case 6:
                cout << "Thank you for choosing BSN ROYAL HOTEL.Hope to see you soon :)"<< endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}
