# User Password Manager

## Overview
The **User Password Manager** is a C++ program designed to help users create, validate, and encrypt passwords securely. It enforces strong password policies and prevents the reuse of previously used passwords.

## Features
- **Password Creation**: Users are prompted to create a password.
- **Validation**: The password must contain at least:
  - One uppercase letter
  - One lowercase letter
  - One digit
  - One special character
  - A minimum length of 8 characters
- **History Check**: Prevents the reuse of previously used passwords.
- **Offset Calculation**: Computes offsets based on ASCII values.
- **Encryption**: Generates an encrypted version of the password using offset calculations.

## How It Works
1. The user is prompted to enter a password.
2. The password is validated using a regex pattern.
3. If valid, the password is encrypted based on ASCII offsets.
4. The encrypted password is displayed.
5. Users can change their password by entering a new valid password.

## Code Structure
### Classes
- `UserPasswordManager`
  - `createPassword()`: Prompts the user to enter a password.
  - `validatePassword()`: Ensures the password meets security requirements.
  - `calculateOffsets()`: Computes ASCII-based offsets for encryption.
  - `encryptPassword()`: Uses offsets to encrypt the password.
  - `changePassword()`: Allows the user to update their password.

## Technologies Used
- **C++ STL**: `vector`, `string`, `iostream`, `regex`

## Example Usage
```cpp
UserPasswordManager manager;
```
When executed, the program will prompt the user to create a password, validate it, and display the encrypted password.

## Future Enhancements
- Implement salting and hashing for improved security.
- Store encrypted passwords in a file or database.
- Add a user authentication system.

## Author
**Heba**
