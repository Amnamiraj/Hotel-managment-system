#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h> 
using namespace std;
class start
{
    void equals_to()
    {
        char a = 205;
        for (int i = 0; i < 65; i++)
        {
            cout << a;
        }
    }
public:
    start()
    {
        cout << "\n\n\n\n";
        equals_to();
        cout << "\n\t\t\t  Starting  \n\t\t\tPlease Wait\n";
        equals_to();

        char c = 219;
        cout << "\n\n";
        Sleep(200);
        for (int i = 0; i < 65; i++)
        {
            cout << c;
            Sleep(100);
        }
        Sleep(1600);
        cout << "\r                          LOADING .....                          \r";

        Sleep(1500); equals_to(); cout << endl;

        cout << "\t\t   Welcome to Galaxy Hotel\n";
        equals_to(); cout << endl;
        Sleep(2000);

        system("CLS");
    }

};
// Room class
class Room
{
private:
    int id;
    string type;
    string status;
    double price;

public:
    Room()
    {
    }
    Room(int id, string type, double price)
    {
        this->id = id;
        this->type = type;
        this->price = price;
        status = "Ready";
    }

    int getId()
    {
        return id;
    }

    string getType()
    {
        return type;
    }

    string getStatus()
    {
        return status;
    }

    double getPrice()
    {
        return price;
    }

    void setStatus(string newStatus)
    {
        status = newStatus;
    }

    void display()
    {
        cout << "Room ID: " << id << ", Type: " << type
            << ", Status: " << status << ", Price: $" << price << endl;
    }
};

// Booking class
class Booking
{
private:
    string customerName;
    int roomNumber;
    string roomType;
    int numberOfNights;
    double totalPrice;

public:
    Booking()
    {
    }
    Booking(string name, int roomNum, string type, int nights, double price)

    {
        this->customerName = name;
        this->roomNumber = roomNum;
        this->roomType = type;
        this->numberOfNights = nights;
        this->totalPrice = price * nights;
    }

    string getCustomerName()
    {
        return customerName;
    }
    int getRoomNumber()
    {
        return roomNumber;
    }
    int getNumberOfNights()
    {
        return numberOfNights;
    }
    double getTotalPrice()
    {
        return totalPrice;
    }

    void display()
    {
        cout << "Customer: " << customerName << ", Room: " << roomNumber
            << ", Type: " << roomType << ", Nights: " << numberOfNights
            << ", Total Price: $" << totalPrice << endl;
    }
};

// Queue for Booking Requests
class BookingRequest
{
private:
    string customerName;
    string roomType;
    int numberOfNights;
    string priority;
    int preferredFloor;

public:
    BookingRequest() {}
    BookingRequest(string name, string type, int nights, string prio, int floor)

    {
        this->customerName = name;
        this->roomType = type;
        this->numberOfNights = nights;
        this->priority = prio;
        this->preferredFloor = floor;
    }

    string getCustomerName()
    {
        return customerName;
    }

    string getRoomType()
    {
        return roomType;
    }

    int getNumberOfNights()
    {
        return numberOfNights;
    }

    string getPriority()
    {
        return priority;
    }

    int getPreferredFloor()
    {
        return preferredFloor;
    }

    void display()
    {
        cout << "Customer: " << customerName << ", Type: " << roomType
            << ", Nights: " << numberOfNights << ", Priority: " << priority
            << ", Preferred Floor: " << preferredFloor << endl;
    }
};

class QNode
{
public:
    BookingRequest request;
    QNode* next;

    QNode(BookingRequest req)
    {
        this->request = req;
        this->next = nullptr;
    }
};

class Queue
{
private:
    QNode* front;
    QNode* rear;
    int count;

public:
    Queue()
    {
        this->front = nullptr;
        this->rear = nullptr;
        this->count = 0;
    }

    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void enqueue(BookingRequest request)
    {
        QNode* newNode = new QNode(request);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    BookingRequest dequeue()
    {
        if (isEmpty())
        {
            throw runtime_error("Error: Queue is empty.");
        }
        QNode* temp = front;
        BookingRequest request = temp->request;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
        count--;
        return request;
    }

    void display()
    {
        QNode* current = front;
        while (current != nullptr)
        {
            current->request.display();
            current = current->next;
        }
    }
};

// Stack for Booking History
class SNode
{
public:
    Booking booking;
    SNode* next;

    SNode(Booking book)
    {
        this->booking = book;
        this->next = nullptr;
    }
};

class Stack
{
private:
    SNode* top;

public:
    Stack()
    {
        this->top = nullptr;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(Booking booking)
    {
        SNode* newNode = new SNode(booking);
        newNode->next = top;
        top = newNode;
    }

    Booking pop()
    {
        if (isEmpty())
        {
            throw runtime_error("Error: Stack is empty.");
        }
        SNode* temp = top;
        Booking booking = temp->booking;
        top = top->next;
        delete temp;
        return booking;
    }

    Booking* peek()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        return &top->booking;
    }

    void display()
    {
        SNode* current = top;
        while (current != nullptr)
        {
            current->booking.display();
            current = current->next;
        }
    }
};

// Floor class
class Floor
{
private:
    int floorNumber;
    Room* rooms; // Dynamic array of rooms
    int numRooms;

public:
    Floor()
    {
    }
    Floor(int number, int numRooms)

    {
        this->floorNumber = number;
        this->numRooms = numRooms;
        rooms = new Room[numRooms];
        for (int j = 0; j < numRooms; ++j)
        {
            string type = "Single";
            double price = 100.0;

            if ((j + 1) % 3 == 2)
            {
                type = "Double";
                price = 150.0;
            }
            else if ((j + 1) % 3 == 0)
            {
                type = "Suite";
                price = 250.0;
            }

            rooms[j] = Room((floorNumber * 100) + (j + 1), type, price);
        }
    }

    ~Floor()
    {
        // delete[] rooms;
    }

    int getFloorNumber() const
    {
        return floorNumber;
    }

    Room* findRoomByNumber(int roomNumber)
    {
        for (int j = 0; j < numRooms; ++j)
        {
            if (rooms[j].getId() == roomNumber)
            {
                return &rooms[j];
            }
        }
        return nullptr;
    }

    Room* findAvailableRoomByType(const string& type)
    {
        for (int j = 0; j < numRooms; ++j)
        {
            if (rooms[j].getType() == type && rooms[j].getStatus() == "Ready")
            {
                return &rooms[j];
            }
        }
        return nullptr;
    }

    void displayAvailableRooms()
    {
        cout << "Floor " << floorNumber << ":\n";
        for (int j = 0; j < numRooms; ++j)
        {
            if (rooms[j].getStatus() == "Ready")
            {
                rooms[j].display();
            }
        }
    }
};

// BST Node for managing floors
class BSTNode
{
public:
    Floor floor;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Floor f)
    {
        this->floor = f;
        this->left = NULL;
        this->right = NULL;
    }
};

// Hotel class
class Hotel
{
private:
    BSTNode* root;
    Queue regularRequests;
    Queue highPriorityRequests;
    Stack bookingHistory;
    int maxFloor; // Track the maximum floor

    // Helper to insert a floor into BST
    BSTNode* insertFloor(BSTNode* node, Floor floor)
    {
        if (node == nullptr)
        {
            return new BSTNode(floor);
        }
        if (floor.getFloorNumber() < node->floor.getFloorNumber())
        {
            node->left = insertFloor(node->left, floor);
        }
        else
        {
            node->right = insertFloor(node->right, floor);
        }
        return node;
    }

    // Helper to find a floor by floor number
    Floor* findFloorHelper(BSTNode* node, int floorNumber)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->floor.getFloorNumber() == floorNumber)
        {
            return &node->floor;
        }
        if (floorNumber < node->floor.getFloorNumber())
        {
            return findFloorHelper(node->left, floorNumber);
        }
        else
        {
            return findFloorHelper(node->right, floorNumber);
        }
    }

    // Helper for in-order traversal (display floors)
    void inOrderTraversal(BSTNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrderTraversal(node->left);
        node->floor.displayAvailableRooms();
        inOrderTraversal(node->right);
    }

    // Helper to clear BST nodes
    void clearBST(BSTNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        clearBST(node->left);
        clearBST(node->right);
        delete node;
    }

public:
    Hotel(int numFloors, int roomsPerFloor)
    {
        this->root = nullptr;
        this->maxFloor = numFloors;
        for (int i = 1; i <= numFloors; ++i)
        {
            Floor newFloor(i, roomsPerFloor);
            root = insertFloor(root, newFloor);
        }
        start s;

    }

    ~Hotel()
    {
        clearBST(root); // Clear BST nodes to avoid memory leaks
    }

    Room* findRoom(int roomNumber)
    {
        int floorNumber = roomNumber / 100; // for finding the floor number like 303 is 3rd floor
        Floor* floor = findFloorHelper(root, floorNumber);
        if (floor)
        {
            return floor->findRoomByNumber(roomNumber);
        }
        cerr << "Error: Room not found." << endl;
        return nullptr;
    }

    void enqueueBookingRequest(BookingRequest request)
    {
        if (request.getPriority() == "High")
        {
            highPriorityRequests.enqueue(request);
        }
        else
        {
            regularRequests.enqueue(request);
        }
    }

    void processBookingRequests()
    {
        if (highPriorityRequests.isEmpty() && regularRequests.isEmpty())
        {
            cout << "No requests to process.\n";
            return;
        }

        while (!highPriorityRequests.isEmpty() || !regularRequests.isEmpty())
        {
            BookingRequest currentRequest;
            if (!highPriorityRequests.isEmpty())
            {
                currentRequest = highPriorityRequests.dequeue();
            }
            else
            {
                currentRequest = regularRequests.dequeue();
            }

            Room* availableRoom = nullptr;
            for (int i = currentRequest.getPreferredFloor(); i <= maxFloor; ++i)
            {
                Floor* floor = findFloorHelper(root, i);
                if (floor)
                {
                    availableRoom = floor->findAvailableRoomByType(currentRequest.getRoomType());
                    if (availableRoom)
                    {
                        break;
                    }
                }
            }

            if (availableRoom)
            {
                availableRoom->setStatus("Booked");
                string name = currentRequest.getCustomerName();
                int roomNumber = availableRoom->getId();

                string type = availableRoom->getType();

                int nights = currentRequest.getNumberOfNights();

                double price = availableRoom->getPrice();
                Booking newBooking(name, roomNumber, type, nights, price);

                bookingHistory.push(newBooking);

                cout << "Booking Successful:\n";

                newBooking.display();
            }
            else
            {
                cout << "No available room for request:\n";

                currentRequest.display();
            }
        }
    }

    void displayAvailableRooms()
    {
        cout << "\nAvailable Rooms:\n";

        inOrderTraversal(root);
    }

    void displayBookingHistory()
    {
        if (bookingHistory.isEmpty())
        {
            cout << "\nBooking History is empty.\n";
        }
        else
        {
            cout << "\nBooking History:\n";
            bookingHistory.display();
        }
    }

    void checkoutRoom(int roomNumber)
    {
        Room* room = findRoom(roomNumber);

        if (!room || room->getStatus() != "Booked")
        {
            cout << "Room " << roomNumber << " is not currently booked or does not exist.\n";
            return;
        }

        Stack tempStack;
        Booking targetBooking;

        bool found = false;
        while (!bookingHistory.isEmpty())
        {
            Booking booking = bookingHistory.pop();
            if (!found && booking.getRoomNumber() == roomNumber)
            {
                targetBooking = booking;
                found = true;
            }
            else
            {
                tempStack.push(booking);
            }
        }
        while (!tempStack.isEmpty())
        {
            bookingHistory.push(tempStack.pop());
        }

        if (!found)
        {
            cout << "No matching booking found for room " << roomNumber << ".\n";
            return;
        }
        cout << "\nInvoice:\n";
        cout << left << setw(20) << "Room Number:" << roomNumber << endl;
        cout << left << setw(20) << "Total Nights:" << targetBooking.getNumberOfNights() << endl;
        cout << left << setw(20) << "Total Price:" << "$" << targetBooking.getTotalPrice() << endl;
        room->setStatus("Ready");
        cout << "Room " << roomNumber << " has been checked out and is now Ready.\n";
    }



    void cancelLastBooking()
    {
        if (!bookingHistory.isEmpty())
        {
            Booking canceledBooking = bookingHistory.pop();

            cout << "Canceling last booking:\n";

            canceledBooking.display();
            int idd = canceledBooking.getRoomNumber();
            Room* room = findRoom(idd);

            if (room)
            {
                room->setStatus("Ready");
                cout << "Room " << canceledBooking.getRoomNumber() << " is now Ready.\n";
            }
        }
        else
        {
            cout << "No bookings to cancel.\n";
        }
    }

    void displayRequestQueues()
    {
        cout << "\n===== Request Queues =====\n";
        cout << "\nHigh Priority Requests:\n";
        if (highPriorityRequests.isEmpty())
        {
            cout << "No high-priority requests.\n";
        }
        else
        {
            highPriorityRequests.display();
        }
        cout << "\nRegular Requests:\n";
        if (regularRequests.isEmpty())
        {
            cout << "No regular requests.\n";
        }
        else
        {
            regularRequests.display();
        }
    }

};

void displayMenu()
{
    cout << "\n===== Galaxy Hotel Management System =====\n";
    cout << "1. View Available Rooms\n";
    cout << "2. Add Booking Request\n";
    cout << "3. Process Booking Requests\n";
    cout << "4. Display Booking History\n";
    cout << "5. Checkout Room\n";
    cout << "6. Cancel Last Booking\n";
    cout << "7. View Request Queues\n";
    cout << "8. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

int main()
{
    Hotel galaxyHotel(5, 10);
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            galaxyHotel.displayAvailableRooms();
            break;

        case 2:
        {
            string name, type, priority;
            int nights, floor;

            cout << "Enter customer name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter room type (Single/Double/Suite): ";
            getline(cin, type);
            cout << "Enter number of nights: ";
            cin >> nights;
            cout << "Enter priority (High/Regular): ";
            cin.ignore();
            getline(cin, priority);
            cout << "Enter preferred floor: ";
            cin >> floor;

            BookingRequest request(name, type, nights, priority, floor);
            galaxyHotel.enqueueBookingRequest(request);
            break;
        }
        case 3:
            galaxyHotel.processBookingRequests();
            break;

        case 4:
            galaxyHotel.displayBookingHistory();
            break;

        case 5:
        {
            int roomNumber;
            cout << "Enter room number to checkout: ";
            cin >> roomNumber;
            galaxyHotel.checkoutRoom(roomNumber);
            break;
        }

        case 6:
            galaxyHotel.cancelLastBooking();
            break;

        case 7:
            galaxyHotel.displayRequestQueues();
            break;

        case 8:
            cout << "Exiting the system. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}
