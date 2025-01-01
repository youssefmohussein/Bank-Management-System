#include<iostream>
#include<fstream>
#include<cctype>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

// Declaration of the Client class
class Client
{
    // Static member to hold client data, initialized with size 100
    static Client clientdataa[100];
public:
    // Member variables representing client data
    string name;
    int accountNumber;
    int id;
    long double balance;
    string username;
    string password;
    bool VIP;
    // Static function to display VIP accounts
    static void displayVIPAccounts()
    {
        cout << "VIP Accounts:\n";
        ifstream file("Clients data.txt");
        string line;
        vector<string> prevLines;
        bool foundVIP = false;

        // Loop through each line in the file
        while (getline(file, line)) {
            if (line.find("VIP: ") != string::npos) {
                // Check if the VIP status is true
                if (line.find("VIP: 1") != string::npos) {
                    foundVIP = true;
                    // Print all previous lines before the "VIP: 1" line
                    for (const auto& prevLine : prevLines) {
                        cout << prevLine << endl;
                    }
                    // Print the "VIP: 1" line
                    cout << line << endl;
                    // Clear the previous lines vector
                    prevLines.clear();
                }
                // If the VIP status is false, skip the previous lines
                else {
                    prevLines.clear();
                    continue;
                }
            }
            // Add the current line to the previous lines vector
            prevLines.push_back(line);
        }
        if (!foundVIP && file.eof()) // Check if end-of-file is reached
        {
            cout << "No VIP clients found.\n";
        }

        file.close();
    }
    static void savedata()
    {
        // Open the file "Clients data.txt" for appending
        ofstream saving("Clients data.txt", ios::app);
        // Loop through clientdataa array
        for (int i = 0; i < 100; i++)
        {
            if (clientdataa[i].name != "")
            {
                // Write client data to file
                saving << "Account number: " << clientdataa[i].accountNumber << endl;
                saving << "Name:" << clientdataa[i].name << endl;
                saving << "Id: " << clientdataa[i].id << endl;
                saving << "Username: " << clientdataa[i].username << endl;
                saving << "Password: " << clientdataa[i].password << endl;
                saving << "Balance: " << fixed << setprecision(2) << clientdataa[i].balance << endl;
                saving << "VIP: " << clientdataa[i].VIP << endl;
            }
        }
        // Close the file
        saving.close();
    }
    // Static function to display all clients
    static void displayallclients()
    {
        // Create a new Client object
        Client newclientt;
        // Open the file "Clients data.txt" for reading
        ifstream displayallclients("Clients data.txt");
        string myText;
        // Read and display each line of the file
        while (getline(displayallclients, myText))
        {
            cout << myText;
            cout << endl;
        }
        // Close the file
        displayallclients.close();
    }
    // Static function to search for a client by account number
    static void search(int accountnumber)
    {
        // Open the file "Clients data.txt" for reading
        ifstream file("Clients data.txt");
        string line;
        bool found = false;
        // Loop through each line of the file
        while (getline(file, line))
        {
            // Check if the line contains the given account number
            if (line.find("Account number: " + to_string(accountnumber)) != string::npos) {
                found = true;
                cout << line << endl;
                // Print details of the client
                while (getline(file, line) && line.find("Account number:") == string::npos) {
                    cout << line << endl;
                }
                break;
            }
        }
        // Close the file
        file.close();
    }
    // Static function to update client data
    static void update()
    {
        int accountnumber, newAccountNumber;
        cout << "Enter account number: ";
        cin >> accountnumber;
        ifstream input("Clients data.txt");
        ofstream temp("Clients dataa.txt");
        string myText;
        bool found = false;
        while (getline(input, myText))
        {
            if (myText.find("Account number: " + to_string(accountnumber)) != string::npos)
            {
                found = true;
                cout << "Enter new account number: ";
                cin >> newAccountNumber;
                cout << "Enter new name: ";
                string newName;
                getline(cin, newName);
                getline(cin, newName);
                temp << "Account number: " << newAccountNumber << endl;
                temp << "Name: " << newName << endl;
                cout << "Enter new Id: ";
                int newId;
                cin >> newId;
                temp << "Id: " << newId << endl;
                cout << "Enter new username: ";
                string newUsername;
                getline(cin, newUsername);
                getline(cin, newUsername);
                temp << "Username: " << newUsername << endl;
                cout << "Enter new password: ";
                string newPassword;
                getline(cin, newPassword);
                temp << "Password: " << newPassword << endl;
                cout << "Enter new balance: ";
                long double newBalance;
                cin >> newBalance;
                temp << "Balance: " << fixed << setprecision(2) << newBalance << endl;
                cout << "Is this client a VIP?: ";
                string vipInput;
                getline(cin, vipInput);
                getline(cin, vipInput);
                bool newVIP = (vipInput == "true" || vipInput == "True" || vipInput == "TRUE");
                temp << "VIP: " << newVIP << endl;
                while (getline(input, myText) && myText.find("VIP:") == string::npos) {}
            }
            else
            {
                temp << myText << endl;
            }
        }
        input.close();
        temp.close();
        remove("Clients data.txt");
        rename("Clients dataa.txt", "Clients data.txt");

    }
    // Static function to add a new client
    static void addclient(int numclients)
    {
        for (int i = 0; i < numclients; i++)
        {
            Client newclient;
            cout << "Enter account number: \n";
            cin >> clientdataa[i].accountNumber;
            cout << "Enter name: \n";
            getline(cin, clientdataa[i].name);
            getline(cin, clientdataa[i].name);
            cout << "Enter Id: \n";
            cin >> clientdataa[i].id;
            cout << "Enter initial balance: \n";
            cin.ignore();
            cin >> clientdataa[i].balance;
            cout << "Enter username: \n";
            getline(cin, clientdataa[i].username);
            getline(cin, clientdataa[i].username);
            cout << "Enter password: \n";
            getline(cin, clientdataa[i].password);
            cout << "Is this client a VIP?: \n";
            string input;
            getline(cin, input);
            clientdataa[i].VIP = (input == "true" || input == "True" || input == "TRUE");
            int j = 0;
            while (clientdataa[j].name != "")
            {
                cout << "\n";
                j++;
            }
            clientdataa[j] = newclient;
            savedata();
        }
    }
    // Static function to log in as admin
    // Static function to load client data from file
    static bool load()
    {
        ifstream file("Clients data.txt"); // Adjust the file path accordingly
        if (!file.is_open()) {
            cout << "Error: Unable to open data file." << endl;
            return false;
        }

        string line;
        int i = 0;
        bool success = false; // Flag to indicate if loading was successful
        while (getline(file, line))
        {
            if (line.find("Account number:") != string::npos)
            {
                // Found a new client entry

                clientdataa[i].accountNumber = stoi(line.substr(16)); // Extract account number
                getline(file, clientdataa[i].name); // Read name
                getline(file, line); // Read Id
                clientdataa[i].id = stoi(line.substr(4));
                getline(file, clientdataa[i].username); // Read username
                getline(file, clientdataa[i].password); // Read password
                getline(file, line); // Read balance
                clientdataa[i].balance = stold(line.substr(9));
                getline(file, line); // Read VIP status
                clientdataa[i].VIP = (line.find("1") != string::npos); // Assuming 1 indicates VIP status
                i++; // Move to the next index
                success = true; // Data loaded successfully
            }




        }
        file.close();

        if (success) {
            cout << "Data loaded successfully." << endl;
        }
        else {
            cout << "No valid data found in the file." << endl;
        }
        return success; // Return the loading status
    }
    // Static function to get account number from a line of text
    static int getAccountNumber(string line)
    {
        // Find the position of "Account Number: " in the line
        size_t pos = line.find("Account Number: ");
        // Extract the account number string starting from the position after "Account Number: "
        string accountNumberString = line.substr(pos + 16);
        // Convert the account number string to an integer and return it
        int accountNumber = stoi(accountNumberString);
        return accountNumber;
    }
    // Static function to update balance in file
    static void updateBalance(int accountNumber, double balance)
    {
        // Open input file
        ifstream input("Clients data.txt");
        // Open temporary output file
        ofstream temp("Clients data_temp.txt");
        string line;
        bool found = false;
        // Loop through each line of the input file
        while (getline(input, line))
        {
            // Check if the line contains the given account number
            if (line.find("Account Number: " + to_string(accountNumber)) != string::npos)
            {
                found = true;
                // Write updated account balance to temporary file
                temp << "Account Number: " << accountNumber << endl;
                temp << "Balance: " << fixed << setprecision(2) << balance << endl;
            }
            else
            {
                // Copy unchanged lines to temporary file
                temp << line << endl;
            }
        }
        // Close input and temporary files
        input.close();
        temp.close();
        // Remove original file and rename temporary file
        remove("Clients data.txt");
        rename("Clients data_temp.txt", "Clients data.txt");
    }
    // Static function to log in as client
    static void loginclient(string username, string password)
    {
        // Open the file "Clients data.txt" for reading
        ifstream file("Clients data.txt");
        string line;
        bool found = false;
        double balance = 0;
        int accountNumber = 0;
        // Loop through each line of the file
        while (getline(file, line))
        {
            // Check if the line contains the given username
            if (line.find("Username: " + username) != string::npos)
            {
                found = true;
                // Loop until another "Username:" line is found
                while (getline(file, line) && line.find("Username:") == string::npos)
                {
                    // Check if the line contains the given password
                    if (line.find("Password: " + password) != string::npos)
                    {
                        cout << "Login successful!" << endl;
                        // Loop until another "Username:" line is found
                        while (getline(file, line) && line.find("Username:") == string::npos)
                        {
                            // Check if the line contains the balance
                            if (line.find("Balance: ") != string::npos)
                            {
                                cout << "Your balance is: ";
                                // Extract balance from the line and display it
                                size_t pos = line.find("Balance: ");
                                balance = stod(line.substr(pos + 9));
                                cout << fixed << setprecision(2) << balance << endl;
                                // Extract account number from the line
                                accountNumber = getAccountNumber(line);
                                // Prompt for deposit or withdrawal
                                int casees;
                                cout << "1) Deposit \n2) Withdraw \n";
                                cin >> casees;
                                // Perform deposit or withdrawal based on user input
                                switch (casees)
                                {
                                case 1:
                                    // Handle deposit
                                    double deposit;
                                    cout << "Enter amount \n";
                                    cin >> deposit;
                                    if (deposit > 0)
                                    {
                                        balance += deposit;
                                        updateBalance(accountNumber, balance);
                                        cout << "Deposit successful! Your new balance is: " << fixed << setprecision(2) << balance << endl;
                                    }
                                    break;
                                case 2:
                                    double withdraw;
                                    cout << "Enter amount \n";
                                    cin >> withdraw;
                                    if (withdraw > 0 && withdraw <= balance) {
                                        balance -= withdraw;
                                        updateBalance(accountNumber, balance);
                                        cout << "Withdrawal successful! Your new balance is: " << fixed << setprecision(2) << balance << endl;
                                    }
                                    else {
                                        cout << "Invalid amount!" << endl;
                                    }
                                    break;
                                default:
                                    cout << "Invalid option!" << endl;
                                    break;
                                }
                            }
                        }
                        break;
                    }
                    else
                    {
                        cout << "Incorrect password!" << endl;
                        break;
                    }
                }
                break;
            }
        }
        // Handle username not found
        if (!found)
        {
            cout << "Username not found!" << endl;
        }
        // Close the file
        file.close();
    }
    // Static function to display menu based on user type
    static void displayadminmenu()
    {
        const int max_attempts = 3;
        int attempts = 0; // Track login attempts
        while (attempts < max_attempts)
        {
            string username, password;
            cout << "\tlogin:\n";
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (username == "admin12" && password == "adminn123")
            {
                int choice;
                do
                {
                    // Display admin menu options
                    cout << "\nAdmin Menu:\n";
                    cout << "1. Display All Clients\n";
                    cout << "2. Add New Client\n";
                    cout << "3. Update Client Information\n";
                    cout << "4. Display VIP Clients\n";
                    cout << "5. Search Client by Account Number\n";
                    cout << "6. load Data\n";
                    cout << "7. Exit\n";
                    cout << "*************************** \n";
                    cout << "Enter your choice: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        displayallclients();
                        break;
                    case 2:
                        int numClients;
                        cout << "Enter the number of clients to add: ";
                        cin >> numClients;
                        cin.ignore(); // Clear input buffer to avoid issues with subsequent inputs
                        addclient(numClients);
                        break;
                    case 3:
                        update();
                        break;
                    case 4:
                        displayVIPAccounts();
                        break;
                    case 5:
                        int accountnumber;
                        cout << "Enter the account number to search: ";
                        cin >> accountnumber;
                        cin.ignore(); // Clear input buffer to avoid issues with subsequent inputs
                        search(accountnumber);
                        break;
                    case 6:
                        load();
                        break;
                    case 7:
                        cout << "Exiting Admin Menu.\n";
                        break;
                    }
                } while (choice != 7);
                break; // Exit login loop after successful login
            }
            else
            {
                cout << "Invalid username or password. Try again.\n";
                attempts++;
            }

            if (attempts == max_attempts)
            {
                cout << "Too many failed attempts. Exiting.\n";
            }
        }
    }
    // Function to display the main menu
    static  void displaymenu()
    {
        int choice;
        do
        {
            cout << "Main Menu:\n";
            cout << "1) Admin Login\n";
            cout << "2) Client Login\n";
            cout << "3) Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                displayadminmenu();
                break;
            case 2:
            {
                string username, password;
                cout << "Username :" << endl;
                getline(cin, username);
                getline(cin, username);
                cout << "Password :" << endl;
                getline(cin, password);
                loginclient(username, password); // Implement client login logic
                break;
            }
            case 3:
                cout << "Exited the program.\n";
                break;
            }
        } while (choice != 3);
    }
};




// Main function
int main()
{
    // Create a Client object
    Client display;
    display.displaymenu();
    return 0;
}

