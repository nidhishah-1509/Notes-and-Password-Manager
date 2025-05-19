<h1>Notes and Password Manager</h1>
<h2>Introduction</h2>
Keeping track of a never-ending list of passwords and sensitive data in this modern digital world can be difficult, and potentially risky for a user’s security. <br> <br>

To overcome this difficulty, a Password and Notes Manager has been created, by leveraging the power of object-oriented programming (OOP) concepts. This methodology cultivates a logical and modular design, guaranteeing that every constituent operates autonomously while exhibiting smooth interoperability. This results in a number of important advantages. The security of the users’  data is the top priority in the Password and Notes Manager. It uses strong encryption techniques to prevent unauthorized access to the users’ private data. Because users’ passwords and notes are protected by top-notch security safeguards, one can keep them with total confidence. <br> <br>

But not only security, but inherent flexibility are its main advantages. The Password and Notes Manager is easily customizable to meet changing requirements by design. The system is designed to easily integrate new features and functionalities without interfering with existing ones, as one’s data management needs change. This guarantees that the data management system will continue to be relevant and useful for many years to come. Above all,  great care has been taken  to ensure that the user interface is clear and simple to use. It is quite easy to find the exact note or password users need, making it very easy to search through users’ data.  <br> <br>

<h2>Main Features</h2>
1. User Authentication <br>
    - Register and securely log in with username and password. <br>
    - Masks password input with asterisks (*) for privacy. <br>
2. Notes Manager <br>
    - Add, view, and delete up to 100 notes.<br>
    - Auto-save and load notes from a local file.<br>
3. Password Manager<br>
    - Add, view, and delete passwords for websites (includes website, username, and password).<br>
    - Stores passwords in a secure format and retrieves them at login.<br>
4. Persistent Storage<br>
    - Notes stored in notes.txt<br>
    - Passwords stored in passwords.txt<br>
    - User credentials stored in user.txt<br>

<h2>Structure</h2>
.<br>
├── OOPD_Project.cpp       # Full application source code <br>
├── notes.txt              # Stores personal notes (auto-created)<br>
├── passwords.txt          # Stores passwords (auto-created)<br>
├── user.txt               # Stores login credentials (auto-created)<br>
└── README.md              # Project documentation<br>

<h2>Tech Stack</h2>
Language: C++ <br>
Concepts Used: <br>
  - File Handling<br>
  - Class Templates<br>
  - Structures<br>
  - Loops & Conditionals<br>
  - Basic Input Validation<br>
  - Password Masking using getch()<br>
  - Windows-only system("cls") and Sleep() for smooth UX<br>

<h2>Sample Usage Flow</h2>
Launch Program <br>

No user? Create an account <br>

Login Page<br>
Username: johndoe<br>
Password: *****<br>

Login successful!<br>

Main Menu:<br>
1. Enter Notes Manager<br>
2. Enter Password Manager<br>
3. Exit Program<br>

Notes Manager:<br>
1. Add your thoughts<br>
2. Delete unwanted notes<br>
3. Auto-save on exit<br>

Password Manager:<br>
1. Store site logins<br>
2. Delete when not needed<br>
3. Auto-save on exit<br>

<h2>Future Improvements</h2>
- Add encryption for stored passwords.<br>
- Replace CLI with a GUI using Qt or a web version.<br>
- Add timestamps and search functionality for notes.<br>
- Introduce multi-user support and account recovery.<br>

<h2>Contributions</h2>
Contributions and suggestions are always welcome! Ideal for students exploring object-oriented design and file handling.<br>

<h2>License</h2>
This project is provided for educational purposes. Feel free to adapt it to your own needs.<br>



