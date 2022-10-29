#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;
// Declare main function
int main();
void passenger();

// Subway Details Class
class SubwayDetails
{
public:
    SubwayDetails(int id, string station_Name, string next_StationName, string previous_StationName,
                  int distancePre_Station, int timePre_Station, int distance_NextStation, int time_NextStation,
                  float cost_NextStation,
                  float travel_FareStation)
    {
        subwayId = id;
        stationName = station_Name;
        nextStationName = next_StationName;
        previousStationName = previous_StationName;
        distancePreviousStation = distancePre_Station;
        timePreviousStation = timePre_Station;
        distanceNextStation = distance_NextStation;
        timeNextStation = time_NextStation;
        costNextStation = cost_NextStation;
        travelFareStation = travel_FareStation;
    }
    int subwayId;
    string stationName, nextStationName, previousStationName;
    int distancePreviousStation, timePreviousStation, distanceNextStation, timeNextStation;
    float costNextStation;
    float travelFareStation;

    // function for printing values
    void printVal()
    {
        cout << "Station Id :\t" << subwayId << endl;
        cout << "Station Name :\t" << stationName << endl;
        cout << "Next Station Name :\t" << nextStationName << endl;
        cout << "Previous Station Name :\t" << previousStationName << " Km" << endl;
        cout << "Next Station Distance :\t" << distanceNextStation << " Km" << endl;
        cout << "Previous Station Details :\t" << distancePreviousStation << " Km" << endl;
        cout << "Time For Next Station :\t" << timeNextStation << " Min" << endl;
        cout << "Time For Next Station :\t" << timePreviousStation << " Min" << endl;
        cout << "Total Cost :\t" << costNextStation << " RM" << endl;
        cout << "Travel Fare Station :\t" << travelFareStation << endl;
    }
};

// Transaction Details Class
class TransactionDetails
{
public:
    TransactionDetails(int id, int ticketID, string firstStation, string targetStation, string timeAndDate, int departure, int customerid, string name, string customer_idcard)
    {
        transactionId = id;
        ticketId = ticketID;
        firstStationName = firstStation;
        targetStationName = targetStation;
        transactionTimeandDate = timeAndDate;
        departureTime = departure;
        customerId = customerid;
        customerName = name;
        customerIdCard = customer_idcard;
    }

    int customerId, transactionId, ticketId, departureTime;
    string firstStationName, targetStationName, transactionTimeandDate;
    string customerName, customerIdCard;

    // function for printing values
    void printVal()
    {

        cout << "Transaction Id :\t" << transactionId << endl;
        cout << "ticket Id :\t" << ticketId << endl;
        cout << "firstStationName :\t" << firstStationName << endl;
        cout << "targetStationName :\t" << targetStationName << endl;
        cout << "transactionTimeandDate :\t" << transactionTimeandDate << endl;
        cout << "departureTime :\t" << departureTime << endl;
        cout << "customerId :\t" << customerId << endl;
        cout << "customerName :\t" << customerName << endl;
        cout << "customerIdCard :\t" << customerIdCard << endl;
    }
};

// calculate totoal Distance between selected routes
int distanceCalculation(int from, int to, unordered_map<int, SubwayDetails> subway)
{
    int totalDistance = 0;

    if (from < to)
    {
        for (int i = from; i < to; i++)
        {
            totalDistance = totalDistance + subway.at(i).distanceNextStation;
        }
        // cout << totalDistance;
        return totalDistance;
    }
    else
    {

        for (int i = from; i > to; i--)
        {
            totalDistance = totalDistance + subway.at(i).distanceNextStation;
        }
        // cout << totalDistance;
        return totalDistance;
    }
}

// calculate total time between selected routes
int timeCalculation(int from, int to, unordered_map<int, SubwayDetails> subway)
{
    int totalTime = 0;

    if (from < to)
    {
        for (int i = from; i < to; i++)
        {
            totalTime = totalTime + subway.at(i).timeNextStation;
        }
        // cout << totalTime;
        return totalTime;
    }
    else
    {
        for (int i = from; i > to; i--)
        {
            totalTime = totalTime + subway.at(i).timeNextStation;
        }
        // cout << totalTime;
        return totalTime;
    }
}

// calculate totoal expanse between selected routes
float expanseCalculation(int from, int to, unordered_map<int, SubwayDetails> subway)
{
    float totalExpanse = 0;

    if (from < to)
    {
        for (int i = from; i < to; i++)
        {
            totalExpanse = totalExpanse + subway.at(i).costNextStation;
        }
        // cout << totalExpanse;
        return totalExpanse;
    }
    else
    {
        for (int i = from; i > to; i--)
        {
            totalExpanse = totalExpanse + subway.at(i).costNextStation;
        }
        // cout << totalExpanse;
        return totalExpanse;
    }
}

// addtransactionHistory

int id = 1;
//  transactionMap.insert({id, purchaseTicket(totaltime, fromStart, toEnd, subwayMap, transactionMap)});
TransactionDetails purchaseTicket(int totaltime, int from, int to, unordered_map<int, SubwayDetails> subway)
{

    string name, idcard;
    time_t now = time(0);
    char *dt = ctime(&now);
    // Transaction Details

    cout << "Enter Your Detail " << endl;

    // discards the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Customer Name : ";
    getline(cin, name);
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Customer Id Card : ";
    cin >> idcard;

    //  TransactionDetails(int id, int ticketID, string firstStation, string targetStation,
    //                      string timeAndDate, int departure, string customerid, string name, string customerIdcard)
    TransactionDetails trans(id, id, subway.at(from).stationName, subway.at(to).stationName,
                             dt, totaltime, id, name, idcard);

    return trans;
}
// search subway details
void searchDetails(unordered_map<int, SubwayDetails> subway)
{
    int search, select;
    cout << "search for more details : ";
    cin >> search;
    subway.at(search).printVal();

    cout << "For Search More other Details : press 1" << endl;
    cout << "Go to Main Menu :press 2" << endl;
    cout << "select : ";
    cin >> select;
    if (select == 1)
    {
        searchDetails(subway);
    }
    else if (select == 2)
    {
        passenger();
    }
}

// Passener Function
unordered_map<int, TransactionDetails> transactionMap; // globally transaction map for storing transaction data
void passenger()
{
    system("CLS");
    // variable initializing
    unordered_map<int, SubwayDetails> subwayMap;

    // // Don't Touch it:
    // Subway Map
    subwayMap.insert({1, SubwayDetails(01, "Titiwangsa", "PWTC", "-", 0, 0, 4, 3, 0.40, 1.20)});
    subwayMap.insert({2, SubwayDetails(02, "PWTC", "Sultan  Ismail", "Titiwangsa", 4, 3, 8, 7, 0.80, 1.60)});
    subwayMap.insert({3, SubwayDetails(03, "Sultan Ismail", "Majlis Jamek", "PWTC", 8, 7, 8, 7, 0.80, 1.20)});
    subwayMap.insert({4, SubwayDetails(04, "Majlis Jamek", "Plaza Rakyat", "Sultan Ismail", 8, 7, 6, 5, 0.60, 1.60)});
    subwayMap.insert({5, SubwayDetails(05, "Plaza Rakyat", "Hang Tuah", "Majlis Jamek", 6, 5, 10, 9, 1.00, 1.50)});
    subwayMap.insert({6, SubwayDetails(06, "Hang Tuah", "Pudu", "Plaza Rakyat", 10, 9, 5, 4, 0.50, 1.00)});
    subwayMap.insert({7, SubwayDetails(07, "Pudu", "Chan Sow Lin", "Hang Tuah", 4, 5, 4, 5, 0.50, 0.5)});
    subwayMap.insert({8, SubwayDetails(07, "Chan Sow Lin", "-", "Pudu", 5, 4, 0, 0, 0.50, 0.5)});
    // *****--------------******-------------------------******-----------------------**********-----------------****

    cout << "\t\t -- WELCOME TO Passenger Portal -- \n"
         << endl;

    // Select Your Route From to
    int choice, fromStart, toEnd;
    int totalDistance, totaltime;
    float totalExpanse;

    cout << "Display the list of station : press 1" << endl;
    cout << "Book a ticket : press 2" << endl;
    cout << "See Transaction History : press 3" << endl;
    cout << "Go To main Menu : press 4" << endl;
    cout << "Exit: press 5" << endl;

    cout << "select : ";
    cin >> choice;

    if (choice == 1)
    {
        system("CLS"); // clear screen Function
        int select;
        cout << "List of All Station" << endl;
        // Function to print all values
        for (int i = 1; i <= subwayMap.size(); i++)
        {
            cout << i << " : " << subwayMap.at(i).stationName << endl;
        }
        // For More Info
        cout << "For Search More Details : press 1" << endl;
        cout << "Go to Main Menu :press 2" << endl;
        cout << "select : ";
        cin >> select;
        if (select == 1)
        {
            searchDetails(subwayMap);
        }
        else if (select == 2)
        {
            passenger();
        }
    }
    else if (choice == 2)
    {
        system("CLS");
        // Select Route
        cout << "Where You want to start your journey?" << endl;
        cout << "List of station" << endl;

        for (int i = 1; i <= subwayMap.size(); i++)
        {
            cout << i << " : " << subwayMap.at(i).stationName << endl;
        }
        cout << "Please select your starting route from a list of station" << endl;
        cout << "from ";
        cin >> fromStart;

        cout << "Please select your ending route from a list of station" << endl;
        cout << "to ";
        cin >> toEnd;
        cout << "Your journey start from " << subwayMap.at(fromStart).stationName << " to " << subwayMap.at(toEnd).stationName << endl;

        // display total distance between selected cities
        totalDistance = distanceCalculation(fromStart, toEnd, subwayMap);
        totaltime = timeCalculation(fromStart, toEnd, subwayMap);
        totalExpanse = expanseCalculation(fromStart, toEnd, subwayMap);
        cout << "Total Distance " << totalDistance << " Km" << endl;
        cout << "Total Expanse " << totalExpanse << " RM" << endl;
        cout << "Total Time " << totaltime << " Min" << endl;

        // Ticket Purchasing
        int choose;
        cout << "for purchase ticket :press 1" << endl;
        cout << "Go to main menu :press 2" << endl;
        cout << "choose : ";
        cin >> choose;

        if (choose == 1)
        {

            // cout << "Create your ticket Id : ";
            // cin >> ticketID;
            // purchaseTicket(totaltime, fromStart, toEnd, subwayMap, transactionMap);

            transactionMap.insert({id, purchaseTicket(totaltime, fromStart, toEnd, subwayMap)});
            id++;
            // transactionMap[ticketID] = purchaseTicket(ticketID, totaltime, fromStart, toEnd, subwayMap);
            // cout << transactionMap.size() << endl;
            int choise;
            cout << "To check your Ticket : press 1" << endl;
            cout << "Go for Main menu : press 2" << endl;
            cout << "select : ";
            cin >> choise;
            if (choise == 1)
            {
                char a;
                system("CLS");
                cout << "Your Ticket is ready" << endl;
                // cout << transactionMap.size() << endl;
                transactionMap.at(transactionMap.size()).printVal();
                cout << "Press any key to go for the main menu" << endl;
                cin >> a;
                passenger();
            }
            else if (choise == 2)
            {
                passenger();
            }
        }
        else if (choose == 2)
        {
            passenger();
        }
    }
    else if (choice == 3)
    {
        system("CLS");
        int choose;
        cout << "Transaction History" << endl;
        cout << transactionMap.size() << endl;
        cout << "transaction length : " << transactionMap.size() << endl;
        for (auto &pair : transactionMap)
        {
            pair.second.printVal(); // print all values in the map
            cout << endl;
        }
        cout << "\n";
        cout << "Delete Transaction : press 1" << endl;
        cout << "Go to Main menu: press 2" << endl;
        // select
        cout << "select : ";
        cin >> choose;
        if (choose == 1)
        {
            int key;
            cout << "Which history you want delete " << endl;

            for (auto &pair : transactionMap)
            {
                cout << pair.first << endl;
                // pair.second.printVal(); // print all values in the map
            }
            cout << "Enter id to delete : ";
            cin >> key;
            transactionMap.erase(key);
            for (auto &pair : transactionMap)
            {
                // cout << pair.first << endl;
                pair.second.printVal(); // print all values in the map
            }
            cout << "Press any key to go for main menu: ";
            int i;
            cin >> i;
            passenger();
        }
        else if (choose == 2)
        {
            passenger();
        }
    }
    else if (choice == 4)
    {
        system("CLS");
        main();
    }
    else if (choice == 5)
    {
        system("CLS");
        cout << "\t\t--- *Thanks For Coming* ---" << endl;
        // exit = 1;
        return;
    }
}

// Main function
int main()
{

    cout << "\t\t -- WELCOME TO SUBWAY STATION --" << endl;

    cout << "Login with Admin press : 1\nLogin with Passenger press : 2\nExit press : 3" << endl;
    int user;

    cout << "Select : ";
    cin >> user;

    if (user == 1)
    {
        cout << "\t\t -- WELCOME TO Admin Portal --" << endl;
    }
    else if (user == 2)
    {

        passenger();
    }
    else if (user == 3)
    {
        return 0;
    }

    return 0;
}
