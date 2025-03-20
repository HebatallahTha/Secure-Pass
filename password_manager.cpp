#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>  // For std::remove_if

// Class to manage user passwords (create, validate, encrypt, and verify)
class UserPasswordManager 
{
public:
    bool validPass;                    // Flag to indicate if the password is valid
    std::string currentPass;            // Stores the current password
    std::vector<std::string> oldPass;   // Stores old passwords
    int upperOffset;                   // Uppercase letter offset
    int lowerOffset;                   // Lowercase letter offset
    int digitOffset;                   // Digit offset
    std::string encryptedPassword;     // Stores the encrypted password

    // Function to create a new password
    void createPassword() 
    {
        std::cout << "\nPlease enter your password: ";
        getline(std::cin, currentPass);
        validPass = validatePassword();
    }

    // Function to validate the password based on specific criteria (length, characters, etc.)
    bool validatePassword() 
    {
        std::regex passwordPattern{"(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])(?=.*[^A-Za-z0-9]).{8,}"};
        while (!std::regex_match(currentPass, passwordPattern)) 
        {
            std::cout << "\nInvalid password\n";
            std::cout << "\nPlease enter your password: ";
            getline(std::cin, currentPass);
        }

        for (auto &pass : oldPass) 
        {
            if (currentPass == pass) 
            {
                std::cout << "\nPassword has already been used.";
                return false;
            }
        }

        return true;
    }

    // Function to calculate the offsets for uppercase, lowercase, and digits
    void calculateOffsets() 
    {
        upperOffset = 0;
        lowerOffset = 0;
        digitOffset = 0;

        for (auto c : currentPass) 
        {
            if (std::isupper(c)) 
            {
                upperOffset += (c - 'A' + 1) % 26;
            } 
            else if (std::islower(c)) 
            {
                lowerOffset += (c - 'a' + 1) % 26;
            } 
            else if (std::isdigit(c)) 
            {
                digitOffset += (c - '0') % 10;
            }
        }
    }

    // Function to encrypt the password using calculated offsets
    void encryptPassword() 
    {
        int upperSum = 0, lowerSum = 0, digitSum = 0;
        encryptedPassword = " "; // Initialize with a blank space

        for (auto c : currentPass) 
        {
            if (std::isalpha(c)) 
            {
                if (std::isupper(c)) 
                {
                    upperSum += int(c);
                } 
                else if (std::islower(c))  
                {
                    lowerSum += int(c);
                }
            } 
            else if (std::isdigit(c)) 
            {
                digitSum += int(c);
            }
        }

        int upperOffset = (upperSum % 26) + 1;
        int lowerOffset = (lowerSum % 26) + 1;
        int digitOffset = digitSum % 10;

        encryptedPassword += std::to_string(upperOffset);
        encryptedPassword += std::to_string(lowerOffset);
        encryptedPassword += std::to_string(digitOffset);

        // Encrypt characters based on their types
        for (auto c : currentPass) 
        {
            if (std::isalpha(c)) 
            {
                if (std::isupper(c)) 
                {
                    char encryptedChar = ((c - 'A' + upperOffset) % 26) + 'A';
                    encryptedPassword += encryptedChar;
                } 
                else if (std::islower(c))  
                {
                    char encryptedChar = ((c - 'a' + lowerOffset) % 26) + 'a';
                    encryptedPassword += encryptedChar;
                }
            } 
            else if (std::isdigit(c)) 
            {
                char encryptedChar = ((c - '0' + digitOffset) % 10) + '0';
                encryptedPassword += encryptedChar;
            } 
            else 
            {
                encryptedPassword += c; // For special characters
            }
        }
    }

    // Constructor to initialize the object and create the password
    UserPasswordManager() 
    {
        createPassword();

        if (validPass) 
        {
            std::cout << "\nPassword Created";
            encryptPassword();
            std::cout << "\nEncrypted Password: " << encryptedPassword;
        } 
        else 
        {
            std::cout << "\nPassword could not be created";
        }
    }

    // Function to change the password
    void changePassword() 
    {
        std::cout << "\nEnter the encrypted password below!";
        createPassword();
        if (validPass) 
        {
            oldPass.push_back(encryptedPassword); // Add the encrypted password to oldPass vector
            std::cout << "\nPassword was successfully changed";
        } 
        else 
        {
            std::cout << "\nPassword was not changed";
        }
    }

    // Function to verify the password
    bool verifyPassword(std::string passwordToVerify) 
    {
        std::string encryptedToVerify = passwordToVerify;
        encryptedPassword.erase(std::remove_if(encryptedPassword.begin(), encryptedPassword.end(), ::isspace), encryptedPassword.end());

        if (encryptedPassword == encryptedToVerify)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main() 
{
    UserPasswordManager userManager; // Create a UserPasswordManager object
    userManager.changePassword();    // Change the password

    std::string passwordToVerify;
    std::cout << "\nEnter the password to verify: ";
    getline(std::cin, passwordToVerify);

    if (userManager.verifyPassword(passwordToVerify)) 
    {
        std::cout << "\nPassword Verified!";
    } 
    else 
    {
        std::cout << "\nPassword Verification Failed!";
    }

    return 0;
}
