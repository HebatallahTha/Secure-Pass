#include <iostream>
#include <vector>
#include <string>
#include <regex>
//turning in
class UserPasswordManager 
{
public:
    bool validPass;
    std::string currentPass;
    std::vector<std::string> oldPass;
    int upperOffset;
    int lowerOffset;
    int digitOffset;
    std::string encryptedPassword;
//create your offset names here so its easier to get
    void createPassword() 
	{
        std::cout << "\nPlease enter your password: ";
        getline(std::cin, currentPass);
        validPass = validatePassword();
        
             // bool verified=false;
             //std::cout<<"\nLength in main: "<<currentPass.size();
       //verified=validatePassword(currentPass);


    }

    bool validatePassword() 
	{
        std::regex passwordPattern{"(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])(?=.*[^A-Za-z0-9]).{8,}"};
//use the regex ms peterson helped me with
        while (!std::regex_match(currentPass, passwordPattern)) 
		{
            std::cout << "\nInvalid password\n";
            std::cout << "\nPlease enter your password: ";
            getline(std::cin, currentPass);
        }

        for ( auto &pass : oldPass) 
		{ //use the address here 
            if (currentPass == pass) 
			{
                std::cout << "\nPassword has already been used.";
                return false; //basically saying your wrong
                
//                std::cout<<"\nPlease enter your password: ";
//      getline(std::cin,currentPass);
            }
        }

        return true; //saying your right
    }

////    bool validatePassword()
//    {
//
//     std::regex passwordPattern
//       {
//            "(?=.*[A-Z])"          
//            "(?=.*[a-z])"         
//            "(?=.*[0-9])"          
//            "(?=.*[^A-Za-z0-9])"   
//            ".{8,}"                
//           }; //use the regex ms susan peterson showed
//
//    while (!std::regex_match(currentPass, passwordPattern))
//        {
//            std::cout << "Invalid password\n";
//            std::cout << "Please enter your password: ";
//            getline(std::cin, currentPass);
//        }
//
////         while (std::regex_match(currentPass, passwordPattern))
////        {
////            std::cout << " Password created \n";
////            break;
////        }
//
//
//      for (auto validPass : oldPass)
//    {
//        if (currentPass == validPass)
//        {
//            std::cout << "\nPassword has already been used.";
//            return false;
//
//             std::cout<<"\nPlease enter your password: ";
//      getline(std::cin,currentPass);
//
//        }
//    }
//
//    oldPass.push_back(currentPass);
//
//    return true;
//      } //done finally regx and bool
//
//      std::string encryptPassword()
//      {
//        //using the ascii chart
////        	srand(time(0));
////			
////			int number= (rand() % 100 )+1;
////			
////			setNum(number); kinda like the rand
//        int randomUpper;
//        std::string rand=currentPass;                                //change to char and ints
//        for (auto randU : currentPass)
//          {
//          	//std::cout<<"\nRandom Upper in for: "<<int(randU);
//            if (std::isupper(randU))
//            {
//              randomUpper=  (int(randU) %26+1);
//              
//              int encryptedNum;
//			  encryptedNum+=64+(randomUpper-90);
//			  if(encryptedNum>90)
//			  {
//			  	encryptedNum=65+randomUpper;
//			  }
//            }
//
//          } 
//           std::cout<<"\nRandom encryptedNum Uppercase in the if: "<<randomUpper;
//
//        
//		int randomLower;
//        
//		for (auto randL : currentPass)
//        {
//        	//std::cout<<"\nRandom Lower in for: "<<int(randL);
//
//          if (std::islower(randL))
//          {
//              randomLower= ( int(randL) %26+1);
//             int encryptedNum;
//			 encryptedNum+=96+(randomLower-122);
//			 
//			if(encryptedNum>122)
//			  {
//			  	encryptedNum=97+randomLower;
//			  }
//
//          }
//
//        }
//                     std::cout<<"\nRandom encryptedNum Lowercase int the if: "<<randomLower;
//
//
//         int randomDigit;
//
//        for (auto randD : currentPass)
//        {
//        	//std::cout<<"\nRandom Digit in for: "<<int(randD);
//
//          if (std::isdigit(randD))
//          {
//                randomDigit= (int(randD) %9+0);
//                 int encryptedNum;
//				 encryptedNum+=47+(randomDigit-57);
//			if(encryptedNum>57)
//			  {
//			  	encryptedNum=48+randomDigit;
//			  }
//                  
//          }
//
//        }
//        std::cout<<"\nRandom  encryptedNum Digit in the if: "<<randomDigit;
//		
////		std::cout<<"\nRandom Uppercase: "<<randomUpper;
////        std::cout<<"\nRandom Lowercase: "<<randomLower;
////        std::cout<<"\nRandom Digit: "<<randomDigit;
////		 
//		 std::cout<<"\nEncrypted Final Password: "<<randomUpper<<" "<<randomLower<<" - "<<randomDigit;
//        return 0;
//      }



    void calculateOffsets() 
	{
        upperOffset = 0;
        lowerOffset = 0;
        digitOffset = 0;
        
        //initialize all offsets to 0 change then name from randU..to offsets so I dont make the mistake I did w pizza
		//use a letter like c or p instead of the long names change after so you dont ruin the code you wrote so far
		//use c so you know its char and not string heba
        for (auto c : currentPass) 
		{
            if (std::isupper(c))
			{
                upperOffset += (c - 'A' + 1) % 26;
                //like the rand function im basically using the uppercase letter as my charectar and then using the ascii val for the uppercase a the 26 sine the amount of letters in the alpha use similar logic for the lowercase and digit special chars arent gonna change she said
            } 
			else if (std::islower(c)) 
			{
                lowerOffset += (c - 'a' + 1) % 26;
            } 
			else if (std::isdigit(c)) 
			{
                digitOffset += (c - '0') % 10; //since we dont need to do the +1 like the ones for upper and lower just manually add it so you get the right offsts
            }
        }
    }

void encryptPassword() 
{
    int upperSum = 0, lowerSum = 0, digitSum = 0;
//inizilize to 0
    encryptedPassword = " "; //inizilze oto a blank

    for (auto c : currentPass)
	 {
    	//use the isalpha since you need it to be a charectar so if its sm else like a didgit it wont do those ifs
        if (std::isalpha(c)) 
		{
            if (std::isupper(c)) 
			{
                upperSum += int(c); //use the int() to find the ascii values
            } 
			
			if (std::islower(c))  
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
	//kinda copying what you did in your calculate offsets


    encryptedPassword += std::to_string(upperOffset);
    encryptedPassword += std::to_string(lowerOffset);
    encryptedPassword += std::to_string(digitOffset);
	//basuically forcibng it to accepot the digits using the to_string
    for (auto c : currentPass) 
	{
        if (std::isalpha(c)) 
		{
            if (std::isupper(c)) 
			{
                char encryptedChar = ((c - 'A' + upperOffset) % 26) + 'A';
                encryptedPassword += encryptedChar;
                //use what you did above
            } 
			
			if (std::islower(c))  

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
            encryptedPassword += c; //this is for the special charectar since it wont be changed
        }
    }
}





public:
	
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

    void changePassword() 
	
	{
		std::cout<<"\nEnter the encrypted password below!";
        createPassword();
        if (validPass) 
		
		{
            oldPass.push_back(encryptedPassword); //add to vector
            std::cout << "\nPassword was successfully changed";
            //encryptPassword();
        } 
		
		else 
		
		{
            std::cout << "\nPassword was not changed";
        }
    }

    bool verifyPassword(std::string passwordToVerify) //send in a passtoverify so it uses the one entered from main :D
	{
		
        std::string encryptedToVerify = passwordToVerify; //again remember to inizilize I think I didnt do this for the midterm but Im not sure
		for(auto passwordToVerify: encryptedToVerify  )
		{
			//std::cout<<"\nIn the for loop for verify password func: ";
			
			//std::cout<<"\nEncrypted password in the verifiying func: "<<encryptedPassword;
        //std::cout<<"\nEncrypted password to verify in the verifiying func: "<<encryptedToVerify;
        encryptedPassword.erase(std::remove_if(encryptedPassword.begin(), encryptedPassword.end(), ::isspace),
        encryptedPassword.end()); //it wasnt working bc of the space so use this thing to erase a blank space from a string
			if(encryptedPassword  == encryptedToVerify)
			{
				//std::cout<<"\nIn dot compare equal Encrypted password in the verifiying func: "<<encryptedPassword;
        //std::cout<<"\nEncrypted password to verify in the verifiying func: "<<encryptedToVerify;
				//std::cout<<"\nIn the veryify:  VERIDUEF"<<encryptedToVerify;
				//std::cout<<"\nIn the veryify:  VERIDUEF"<<encryptedPassword;
				return true;
			}
			
			else
				//if(encryptedPassword!= encryptedToVerify)
			{
				//std::cout<<"\nIn dot compare NOT equal Encrypted password in the verifiying func: "<<encryptedPassword;
        //std::cout<<"\nEncrypted password to verify in the verifiying func: "<<encryptedToVerify;
				//std::cout<<"\nIn the veryify: NOT VERIDUEF "<<encryptedToVerify;
				//std::cout<<"\nIn the veryify: NOT VERIDUEF "<<encryptedPassword;
				return false;
			}
			
			
		}
		
//        encryptedToVerify += std::to_string(upperOffset);
//        encryptedToVerify += std::to_string(lowerOffset);
//        encryptedToVerify += std::to_string(digitOffset);
	
		
        
//        std::cout<<"\nEncrypted password in the verifiying func: "<<encryptedPassword;
//        std::cout<<"\nEncrypted password to verify in the verifiying func: "<<encryptedToVerify;
//		
       
//		if (encryptedPassword == encryptedToVerify)
//		{
//			return true; //finally just returing the encrypted pass and the  ==
//    	}
//    	
//    	if (encryptedPassword != encryptedToVerify)
//		{
//			return false; //finally just returing the encrypted pass and the  ==
//    	}
//    	
        //return encryptedPassword == encryptedToVerify; //finally just returing the encrypted pass and the  ==
    }
}; //UserPasswordManager END class

int main() 
{
    UserPasswordManager userManager;
//create the object
    userManager.changePassword();

    std::string passwordToVerify;
    

    std::cout << "\nEnter the password to verify: ";
    std::getline(std::cin, passwordToVerify);

    if (userManager.verifyPassword(passwordToVerify)) 
	{ 
        std::cout << "\nPassword verified successfully.\n";
        //std::cout<<"\nPassword in the if userMAna: "<<passwordToVerify;
    } 
	
	else 
	
	{
		//std::cout<<"The pass?"<<userManager.verifyPassword(passwordToVerify);
        std::cout << "\nInvalid password.\n";
        //std::cout<<"\nPassword in the if userMAna: "<<passwordToVerify;
    }

    return 0;
}
