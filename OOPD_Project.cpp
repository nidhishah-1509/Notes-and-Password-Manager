#include <iostream>
#include <fstream> //for i/o files
#include <string> //for string
#include <conio.h> // for system("cls")
#include <windows.h> // for delay/sleep in windows
#include <limits> //used for cin.ignore()

using namespace std;

//MAXIMUM SIZE IS SET TO 100
const int MAX_NOTES = 100;
const int MAX_PASSWORDS = 100;

template <typename T>
class NotesManager
{
    private:
        T notes[MAX_NOTES];
        int numNotes; //To know the number of notes we have

    public:
        NotesManager() //default constructor
        {
            numNotes = 0;
        }

        void viewNotes()
        {
            if (numNotes == 0)
            {
                cout << "Oops! It seems the notes manager went on vacation...without leaving any notes behind!\n" << endl;
                return; //exits the function and control returns to the main without returning any value
            }
            cout << "Notes:" << endl;
            for (int i = 0; i < numNotes; ++i)
            {
                cout << i + 1 << ". " << notes[i] << endl;
            }
            cout << endl;
        }

        void addNote(string &note) //&note is used to avoid unnecessary copies
        {
            if (numNotes < MAX_NOTES) //if enough space is there
            {
                notes[numNotes++] = note;
                cout << "\nNoted and acknowledged!!\n" << endl;
            }
            else //if it is full
            {
                cout << "\"Sorry, the notes manager is full! No more room for your brilliant ideas.\"" << endl;
            }
        }

        void deleteNote(int index)
        {
            if (numNotes == 0)
            {
                cout << "\nAll clear! No notes to delete.\n" << endl;
                return; //exits the function and skips rest of the function
            }

            if (index < 1 || index > numNotes) {
                cout << "\nWhoops! Looks like you're trying to reach notes from a parallel universe... If the list is empty enter any number... \nInvalid index number...\n" << endl;
                return; //exits the function and control returns to the main without returning any value
            }

            for (int i = index - 1; i < numNotes - 1; ++i) {
                notes[i] = notes[i + 1]; //similar to deleting in stacks
            }
            numNotes--;
            cout << "\nYour note has been deleted!\n" << endl;
        }

        void saveNotesToFile(const string& filename)  //const added  since file name is not changing + error being shown without it
        {
            ofstream outfile(filename);
            if (outfile.is_open())
            {
                for (int i = 0; i < numNotes; ++i)
                {
                    outfile << notes[i] << endl;
                }
                //cout << "Notes saved to file successfully." << endl; //tesingPhase
            }
            else
            {
                cout << "Oops, we are having trouble to save your notes..." << endl;
            }
        }

        void loadNotesFromFile(const string& filename) //const added  since file name is not changing + error being shown without it
        {
            ifstream infile(filename);
            if (infile.is_open())
            {
                string note;
                while (getline(infile, note)) //if the line has data it will run
                {
                    if (numNotes < MAX_NOTES)
                    {
                        notes[numNotes++] = note;
                    }
                    else
                    {
                        cout << "Sorry, we've reached the maximum limit..." << endl;
                        break;
                    }
                }
                // cout << "Notes loaded from file successfully." << endl; //tesingPhase
            }
            else
            {
                //cout << "Uh-oh! The file is MIA. Starting with a clean slate for your notes..." << endl; //debugging
            }
        }
        ~NotesManager(){}
    };

template <typename T>
class PasswordManager
{
    private:
        struct PasswordEntry
        {
            T website;
            T username;
            T password;
        };

        PasswordEntry entry[MAX_PASSWORDS];
        int numPasswords;

    public:
        PasswordManager()
        {
            numPasswords = 0;
        }

        void viewPasswords()
        {
            if (numPasswords == 0)
            {
                cout << "Looks like the password fairy took a day off!! No passwords lists are available!\n" << endl;
                return;
            }
            cout << "Passwords:" << endl;
            for (int i = 0; i < numPasswords; ++i)
            {
                cout << i + 1 << ". Website: " << entry[i].website << ", Username: " << entry[i].username << ", Password: " << entry[i].password << endl;
            }
        }

        void addPassword(string &website, string &username, string &password)
        {
            if (numPasswords < MAX_PASSWORDS)
            {
                entry[numPasswords].website = website;
                entry[numPasswords].username = username;
                entry[numPasswords].password = password;
                numPasswords++;
                cout << "\nSuccess! Your new password has been saved!\n" << endl;
            }
            else
            {
                cout << "Oops, your password manager is feeling a bit cramped. Time to de-clutter!!" << endl;
            }
        }

        void deletePassword(int index)
        {
            if (numPasswords == 0)
            {
                cout << "No passwords found, nothing to delete here!!" << endl;
                return;
            }

            if (index < 1 || index > numPasswords)
            {
                cout << "Invalid input. Please choose a valid option from the provided list!\nIf the list is empty then input number!" << endl;
                return;
            }

            for (int i = index - 1; i < numPasswords - 1; ++i)
            {
                entry[i] = entry[i + 1];
            }
            numPasswords--;
            cout << "Done! Password deleted!" << endl;
        }

        void savePasswordsToFile(const string &filename)
        {
            ofstream outfile(filename);
            if (outfile.is_open())
            {
                for (int i = 0; i < numPasswords; ++i)
                {
                    outfile << entry[i].website << "," << entry[i].username << "," << entry[i].password << endl;
                }
                //cout << "Passwords saved to file successfully." << endl;
            }
            else
            {
                cout << "Uh-oh! File access denied for saving passwords. Try again later!" << endl;
            }
        }

        void loadPasswordsFromFile(const string& filename)
        {
            ifstream infile(filename);
            if (infile.is_open())
            {
                string website, username, password;
                while (getline(infile, website, ',') && getline(infile, username, ',') && getline(infile, password))
                //istream& getline(istream& is, string& str, char delim);
                //three pieces of information separated by commas and stored in each variable to array (structure)
                {
                    if (numPasswords < MAX_PASSWORDS)
                    {
                        entry[numPasswords].website = website;
                        entry[numPasswords].username = username;
                        entry[numPasswords].password = password;
                        numPasswords++;
                    } else
                    {
                        cout << "Uh-oh! Maximum limit reached. Please delete some passwords to enter more!" << endl;
                        break;
                    }
                }
                // cout << "Passwords loaded from file successfully." << endl;
            }
            else
            {
                //cout << "File not found. Starting with empty passwords." << endl; //debugging
            }
        }
        ~PasswordManager()
        {}
    };

class Authenticator
{
    public:
    void createAccount()
    {
        ofstream file("user.txt");
        if (file.is_open())
        {
            string username, password;
            cout << "-----------------------\n";
            cout << "     Create Account    \n";
            cout << "-----------------------\n";
            cout << "\nEnter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            file << username << " " << password;
            cout << "\nNew User has been registered successfully!!\n\n";
            Sleep(1000);
            system("cls");
        }
        else
        {
            cerr << "Error: Unable to open file for writing!\n";
        }
    }
};

class User
{
    public:
    void loginInput(string& username, string& password) {
        cout << "Welcome! To proceed, please log in with your account credentials...\n" << endl;
        cout << "-----------------------\n";
        cout << "       Login Page      \n";
        cout << "-----------------------\n";
        cout << "\nEnter username: ";
        cin >> username;
        cout << "Enter password: ";

        char ch;
        do {
            ch = getch(); // returns the ASCII value of the character
            if (isdigit(ch) || isalpha(ch) || ispunct(ch)) {
                password += ch;
                cout << "*";
            }
        } while (isdigit(ch) || isalpha(ch) || ispunct(ch));
    }

    bool loginProcess(const string& storedUsername, const string& storedPassword, string username, string password)
    {
        return (username == storedUsername && password == storedPassword);
    }

    void loginOutput(bool success)
    {
        cout << endl;
        if (success)
        {
            cout << "\n-----------------------\n";
            cout << "    Login successful!  \n";
            cout << "-----------------------\n\n";
        }
        else
        {
            cout << "\n-----------------------\n";
            cout << " Invalid username or password! \n";
            cout << "-----------------------\n\n";
        }
    }
};

int main()
{
    const string notesFilename = "notes.txt";
    const string passwordsFilename = "passwords.txt";

    Authenticator authenticator;
    User user;

    //template used
    NotesManager <string> notesManager;
    PasswordManager <string> passwordManager;

    bool success = false; // Initialize success flag to false
    int loginCount = 0;

    do
    {
        ifstream file("user.txt");

        // If the file stream is in a failed state or if it has reached the end of the file
        if (!file || file.peek() == ifstream::traits_type::eof())
        {
            authenticator.createAccount();
        }
        else
        {
            string storedUsername, storedPassword;
            file >> storedUsername >> storedPassword;
            file.close();

            string username, password;
            user.loginInput(username, password);
            success = user.loginProcess(storedUsername, storedPassword, username, password);
            user.loginOutput(success);
            if((success == false) && (loginCount < 3))
            {
                cout << "You have " << (3 - loginCount) << " attempts left!\n\n";
                loginCount++;
                Sleep(1500);
                system("cls");
            }
            else if (((success == false)) && (loginCount >= 3))
            {
                system("cls");
                cout << "Due to multiple attempts... You have been logged out!!\n\n";
                cout << "-------------------------\n";
                cout << "Exiting the program.\n";
                cout << "-------------------------\n";
                exit(1);

            }
        }
    } while (!success);
    Sleep(1500);
    system("cls");

    notesManager.loadNotesFromFile(notesFilename);
    passwordManager.loadPasswordsFromFile(passwordsFilename); // Load passwords from file

    int mainMenuChoice;
    do {
        cout << "-------------------------\n";
        cout << "       Main Menu:\n";
        cout << "-------------------------\n\n";
        cout << "1. Enter Notes Manager\n";
        cout << "2. Enter Password Manager\n";
        cout << "3. Exit Program\n";
        cout << "Enter your choice: ";
        cin >> mainMenuChoice;
        if (cin.fail())
        {
            cout << "Invalid input. Please choose a valid option from the provided list...\n" << endl;
            cin.clear();
            // to ingore all the remaining characters in the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Sleep(1500);
            system("cls");
            continue;
        }

        system("cls");

        switch (mainMenuChoice) {
            case 1: {
                int notesChoice;
                string note;
                do {
                    cout << "-------------------------\n";
                    cout << "    Notes Manager Menu:" << endl;
                    cout << "-------------------------\n\n";
                    cout << "1. View Note" << endl;
                    cout << "2. Add Note" << endl;
                    cout << "3. Delete Note" << endl;
                    cout << "4. Exit Notes Manager" << endl;
                    cout << "Enter your choice: ";
                    cin >> notesChoice;
                    if (cin.fail())
                    {
                        cout << "Invalid input. Please choose a valid number option from the provided list!" << endl;
                        cin.clear();
                        // to ingore all the remaining characters in the buffer
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        Sleep(1500);
                        system("cls");
                        continue;
                    }
                    cin.ignore();

                    system("cls");
                    switch (notesChoice)
                    {
                        case 1:
                            notesManager.viewNotes();
                            break;
                        case 2:
                            cout << "Enter your note: ";
                            getline(cin, note);
                            notesManager.addNote(note);
                            break;
                        case 3:
                            notesManager.viewNotes();
                            int index;
                            cout << "Enter the index of the note to delete: ";
                            cin >> index;
                            if (cin.fail())
                            {
                                cout << "Invalid input. Please choose a valid number option from the provided list..." << endl;
                                cin.clear();
                                // to ingore all the remaining characters in the buffer
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                Sleep(1500);
                                system("cls");
                                continue;
                            }
                            notesManager.deleteNote(index);
                            break;
                        case 4:
                            cout << "-------------------------\n";
                            cout << "Exiting Notes Manager..." << endl;
                            cout << "-------------------------\n";
                            Sleep(1000);
                            system("cls");
                            break;
                        default:
                            cout << "\nInvalid input. Please choose a valid option from the provided list!" << endl;
                    }
                } while (notesChoice != 4);
                notesManager.saveNotesToFile(notesFilename);
                break;
            }
            case 2: {
                int passwordChoice;
                do {
                    cout << "-------------------------\n";
                    cout << "  Password Manager Menu:\n";
                    cout << "-------------------------\n\n";
                    cout << "1. View Passwords\n";
                    cout << "2. Add Password\n";
                    cout << "3. Delete Password\n";
                    cout << "4. Exit Password Manager\n";
                    cout << "Enter your choice: ";
                    cin >> passwordChoice;
                    if (cin.fail())
                    {
                        cout << "Invalid input. Please choose a valid number option from the provided list!" << endl;
                        cin.clear();
                        // to ingore all the remaining characters in the buffer
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        Sleep(1500);
                        system("cls");
                        continue;
                    }

                    system("cls");
                    switch (passwordChoice) {
                        case 1:
                            passwordManager.viewPasswords();
                            break;
                        case 2: {
                            string website, username, password;
                            cout << "Enter website: ";
                            cin.ignore();
                            getline(cin, website);
                            cout << "Enter username: ";
                            getline(cin, username);
                            cout << "Enter password: ";
                            getline(cin, password);
                            passwordManager.addPassword(website, username, password);
                            break;
                        }
                        case 3: {
                            passwordManager.viewPasswords();
                            int index;
                            cout << "\nEnter the index of the password to delete: ";
                            cin >> index;
                            if (cin.fail())
                            {
                                cout << "Invalid input. Please choose a valid number option from the provided list!" << endl;
                                cin.clear();
                                // to ingore all the remaining characters in the buffer
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                Sleep(1500);
                                system("cls");
                                continue;
                            }
                            passwordManager.deletePassword(index);
                            cout << "\n";
                            break;
                        }
                        case 4:
                            cout << "-------------------------\n";
                            cout << "Exiting Password Manager...\n";
                            cout << "-------------------------\n";
                            Sleep(1000);
                            system("cls");
                            break;
                        default:
                            cout << "Invalid input. Please choose a valid option from the provided list!\n";
                            break;
                    }
                } while (passwordChoice != 4);

                passwordManager.savePasswordsToFile(passwordsFilename); // Save passwords to file before exiting
                break;
            }
            case 3:
                system("cls");
                cout << "----------------------------------\n";
                cout << "Exiting program. Have a great day!\n";
                cout << "----------------------------------\n";
                break;
            default:
                cout << "Invalid input. Please choose a valid option from the provided list!\n";
                break;
        }
    } while (mainMenuChoice != 3);
    return 0;
}
