<h1>Notes and Password Manager</h1>
<h2>Introduction</h2>
Keeping track of a never-ending list of passwords and sensitive data in this modern digital world can be difficult, and potentially risky for a user’s security. 

To overcome this difficulty, a Password and Notes Manager has been created, by leveraging the power of object-oriented programming (OOP) concepts. This methodology cultivates a logical and modular design, guaranteeing that every constituent operates autonomously while exhibiting smooth interoperability. This results in a number of important advantages. The security of the users’  data is the top priority in the Password and Notes Manager. It uses strong encryption techniques to prevent unauthorized access to the users’ private data. Because users’ passwords and notes are protected by top-notch security safeguards, one can keep them with total confidence. 

But not only security, but inherent flexibility are its main advantages. The Password and Notes Manager is easily customizable to meet changing requirements by design. The system is designed to easily integrate new features and functionalities without interfering with existing ones, as one’s data management needs change. This guarantees that the data management system will continue to be relevant and useful for many years to come. Above all,  great care has been taken  to ensure that the user interface is clear and simple to use. It is quite easy to find the exact note or password users need, making it very easy to search through users’ data. 

<h2>Main Features</h2>
1. User Authentication
  - Register and securely log in with username and password.
  - Masks password input with asterisks (*) for privacy.
2. Notes Manager
  - Add, view, and delete up to 100 notes.
  - Auto-save and load notes from a local file.
3. Password Manager
  - Add, view, and delete passwords for websites (includes website, username, and password).
  - Stores passwords in a secure format and retrieves them at login.
4. Persistent Storage
  - Notes stored in notes.txt
  - Passwords stored in passwords.txt
  - User credentials stored in user.txt

<h2>Structure</h2>
.
├── OOPD_Project.cpp       # Full application source code
├── notes.txt              # Stores personal notes (auto-created)
├── passwords.txt          # Stores passwords (auto-created)
├── user.txt               # Stores login credentials (auto-created)
└── README.md              # Project documentation

<h2>Tech Stack</h2>
Language: C++
Concepts Used:
  - File Handling
  - Class Templates
  - Structures
  - Loops & Conditionals
  - Basic Input Validation
  - Password Masking using getch()
  - Windows-only system("cls") and Sleep() for smooth UX

<h2>Sample Usage Flow</h2>
🟢 Launch Program

👤 No user? Create an account ✅

🔐 Login Page
Username: johndoe
Password: *****

✅ Login successful!

📋 Main Menu:
1. Enter Notes Manager
2. Enter Password Manager
3. Exit Program

📝 Notes Manager:
- Add your thoughts
- Delete unwanted notes
- Auto-save on exit

🔑 Password Manager:
- Store site logins
- Delete when not needed
- Auto-save on exit

<h2>Future Improvements</h2>
- Add encryption for stored passwords.
- Replace CLI with a GUI using Qt or a web version.
- Add timestamps and search functionality for notes.
- Introduce multi-user support and account recovery.

<h2>Contributions</h2>
Contributions and suggestions are always welcome! Ideal for students exploring object-oriented design and file handling.

<h2>License</h2>
This project is provided for educational purposes. Feel free to adapt it to your own needs.



