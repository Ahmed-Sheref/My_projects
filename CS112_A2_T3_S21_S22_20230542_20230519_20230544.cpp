// Purpose: To perform arithmetic operations on rational numbers and display results as fractions and decimals.
// The algorithm of this code is below
// section => s21 , s22

// Author1: Ahmed Sheref Sayed    ID:20230542    Email:ahmedsheref2288@yahoo.com  
/*
  Menu from programming, Dividing a fraction into a numerator, a denominator, and Handle negative numbers
  Dealing with integers
  performing arithmetic => addition
*/

// Author2: Youssef Yasser El-sayed   ID:20230519  Email:yoyoyasso19@gmail.com
/*
  performing arithmetic =>  multiplication and division by fractions
*/ 

// Author3: Hassan Walid Hassan     ID:20230544    Email:hassan.moselhy22@gmail.com 
/*
  validation input
  performing arithmetic => subtraction
*/ 

// Version: 1.0
// Date: 17 March 2024


#include <iostream> 
#include <vector> 
#include <numeric> 
#include <regex>    

using namespace std;


// Function Declarations
// **************************************************************************************
string remove_spaces(string number); // Remove spaces from a string
bool check(const string& input); // Check if the input string matches the required format
string getValidInput(); // Get a valid input string from the user
// ***************************************************************************************

// Main Function
// ***************************************************************************************
int main() 
{ 
  // >>>>>>>>>>>>>>>>>> (Part about Ahmed Sheref) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  cout << "\033[3;32m╭──────────────────────────────────────╮\033[0m" << endl;
  cout << "\033[3;32m│  Welcome to our Fraction calculator! │\033[0m" << endl;
  cout << "\033[3;32m╰──────────────────────────────────────╯\033[0m" << endl;
  cout << endl;

  // Main loop to keep the calculator running until the user chooses to exit
  while (true)
  {
    // Declare variables to store input operands and operators
    string num1_nem, num1_den, num2_nem,num2_den;
    char secound_obr;
    
    // Prompt user to start or exit the program
    cout << "\nWrite \"exit\" or \"2\" to finish the program\nEnter \"1\" or anything else to start the program\n";
    
    // Read user choice
    string choose; 
    cin >> choose; 
    cin.ignore(); 
    
    // Check if user wants to exit
    if (choose == "exit" || choose == "2")
    {
      cout << "Thank you for using the rational number calculator.\n";
      cout << "\033[3;31m  Exit... \033[0m" << endl;
      return 0;
    }
    
    // Get valid input from user
    
    // >>>>>>>>>>>>>>>>>> (Part about Hassan Walid) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    string number = getValidInput(); 
    string num_not_sp = remove_spaces(number); 
    // ****************** (End Part about Hassan Walid) ************************************

    // >>>>>>>>>>>>>>>>>> (Part about Ahmed Sheref) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    // Initialize variables for parsing
    vector<char> oprs; 
    int start = 0; //To specify the locations of the signs for dividing the numerator and denominator
    int i = 0;
    
    // Parse the first operand
    if (num_not_sp[0] == '-' || num_not_sp[0] == '+') // Check if the first character is a -ve or +ve
    {
      ++i; // Increment index To take into consideration 
    }
    bool sign = false; // Flag to indicate to read sign ve like -5 , +5
    for (; i < num_not_sp.size(); ++i)
    { 
      if (num_not_sp[i] == '+' || num_not_sp[i] == '-' || num_not_sp[i] == '*' || num_not_sp[i] == '/') 
      { // Check if an operator is encountered
        for (int j = 0; j < i; ++j) // Iterate through the characters before the operator
        {
          num1_nem += num_not_sp[j]; // Append characters to the numerator of the first operand
        }
        start = i + 1; // Set the starting index for the next operand
        if (num_not_sp[start] == '-' || num_not_sp[start] == '+') // Check if the next character is a sign
        {
          sign = true; // Set the sign flag to true
          start++; // Increment the index to skip the sign
        }
        break; // Exit the loop after processing the first operand
      }
    }

    
    // Handle denominator of first number
    // Check if the first number is without a division sign and it's a negative number
    if ((num_not_sp[start - 2]) != '/' && sign == true) 
    {
      oprs.push_back('/'); // Add division operator to the operators vector
      num1_den = "1"; // Set the denominator of the first number to 1
      oprs.push_back(num_not_sp[start - 1]); // Add the sign of the first number to the operators vector
    }
    // Check if the first number is with a division sign and it's not a negative number
    else if ((num_not_sp[start - 1]) != '/' && sign == false) 
    {
      oprs.push_back('/'); 
      num1_den = "1"; 
      oprs.push_back(num_not_sp[start - 1]);
    } 
    else 
    {
      for (int i = start; i < num_not_sp.size(); ++i) // Iterate through the remaining characters
      { 
        if (num_not_sp[i] == '+' || num_not_sp[i] == '-' || num_not_sp[i] == '*' || num_not_sp[i] == '/') 
        { // Check if an operator is encountered
          int j = (sign == true ? start - 1 : start); // Initialize the starting index for the denominator
          for (; j < i; ++j) // Iterate through characters to extract the denominator
          {
            num1_den += (num_not_sp[j]); // Append characters to the denominator of the first number
          }
          start = j + 1; // Update the starting index for the next operand
          secound_obr = num_not_sp[start - 1]; // Store the second operation or the second sign
          break; // Exit the loop after processing the denominator
        }
      }
    }

    
    // Parse the second operand
    for (int i = start - 1; i < num_not_sp.size(); ++i) // Iterate through the characters starting from the position of the first operator
    {
      if (num_not_sp[i+1] == '+' || num_not_sp[i+1] == '-' || num_not_sp[i+1] == '*' || num_not_sp[i+1] == '/') // Check if the next character is an operator
      {
        num2_nem += num_not_sp[i+1]; // Append the next character to the numerator of the second number
        start++; // Move the start index to the next character
      }
      if (num_not_sp[i] == '+' || num_not_sp[i] == '-' || num_not_sp[i] == '*' || num_not_sp[i] == '/') // Check if the current character is an operator
      {
        int j = start; // Initialize a new index variable for processing the denominator
        for (; isdigit(num_not_sp[j]); ++j) // Iterate through the characters to extract the denominator
        { 
          num2_nem += num_not_sp[j]; // Append the characters to the numerator of the second number
          if (num_not_sp[j + 1] == '\0') // If the end of the number is reached and it does not meet its division sign in the second number, set its denominator as one
          {
            num2_den = "1";
          }
        }
        start = j + 1; // Update the start index for the next iteration
        break; // Exit the loop after processing the denominator
      }
    }

    
    // Handle denominator of second number
    for (int i = start; i <= num_not_sp.size(); ++i) 
    {
      num2_den += num_not_sp[i];
    }

    // Variable to store the greatest common divisor
    int gc;  

    // Check if there are no operators present
    if (oprs.empty()) 
    {
      secound_obr = secound_obr;
    } 
    else 
    {
      secound_obr = oprs[1];
    }

    // Check if the denominator of the first number is empty (which means it's an integer)
    if (num1_den == "") 
    {
      gc = gcd(stoi(num1_nem), stoi(num2_nem));
      cout << "Result in Fraction: " << stod(num1_nem) / gc << '/' << stod(num2_nem) / gc;
      cout << " ==>> " << stod(num1_nem) / stod(num2_nem);
      continue;
    }

    // Check if the numerator of the second number is empty (which means it's a whole number)
    if (num2_nem == "") 
    {
      cout << num2_den;
      continue;
    }

    double mult_den;  // Variable to store the product of denominators
    double sum_nem;   // Variable to store the sum of numerators

    // Check if any denominator is zero to avoid division by zero
    if (num1_den == "0" || num2_den == "0")
    {
      cout << "\nError ==> There is a zero in one of the denominators\n\n"; // Print error message
      continue; // Skip to the next iteration
    }

    // Perform operations based on the second operator
    switch (secound_obr) 
    {
      case '+': // Addition operation
        mult_den = stod(num1_den) * stod(num2_den);  // Calculate the common denominator
        sum_nem = (stod(num1_den) * stod(num2_nem)) + (stod(num2_den) * stod(num1_nem)); // Calculate the sum of numerators
        gc = gcd(int(mult_den), int(sum_nem));  // Find the greatest common divisor
        cout << "Result in Fraction: " << sum_nem / gc << '/' << mult_den / gc; // Output the result as a fraction
        cout << " ==>> " << sum_nem / mult_den; // Output the result as a decimal
        break;
    // ******************** (End Part about Ahmed Sheref) ************************************
    // ******************** (Part about Hassan Walid ) ***************************************
      case '-': // Subtraction operation
        mult_den = stod(num1_den) * stod(num2_den); // Calculate the common denominator
        sum_nem = (stod(num2_den) * stod(num1_nem)) - (stod(num1_den) * stod(num2_nem)); // Calculate the difference of numerators
        gc = gcd(int(mult_den), int(sum_nem)); // Find the greatest common divisor
        cout << "Result in Fraction: " << sum_nem / gc << '/' << mult_den / gc; // Output the result as a fraction
        cout << " ==>> " << sum_nem / mult_den; // Output the result as a decimal
        break;
    // ******************** (End Part about Hassan Walid) ************************************
    // ******************** (Part about Youssef Yasser) **************************************
      case '*': // Multiplication operation
        mult_den = stod(num1_den) * stod(num2_den); // Calculate the new denominator
        sum_nem = (stod(num2_nem) * stod(num1_nem)); // Calculate the new numerator
        gc = gcd(int(mult_den), int(sum_nem)); // Find the greatest common divisor
        cout << "Result in Fraction: " << sum_nem / gc << '/' << mult_den / gc; // Output the result as a fraction
        cout << " ==>> " << sum_nem / mult_den; // Output the result as a decimal
        break;


      case '/': // Division operation
        mult_den = stod(num1_nem) * stod(num2_den); // Calculate the new denominator
        sum_nem = (stod(num1_den) * stod(num2_nem)); // Calculate the new numerator
        gc = gcd(int(mult_den), int(sum_nem)); // Find the greatest common divisor
        cout << "Result in Fraction: " << mult_den / gc << '/' << sum_nem / gc; // Output the result as a fraction
        cout << " ==>> " << mult_den / sum_nem; // Output the result as a decimal
        break;
      // ******************** (End Part about Youssef Yasser) ********************************
    }
    cout << "\n\n"; // Add newlines for clarity
  }
}


// Function Definitions
// *******************************************************************************************

// Function to remove spaces from a string
string remove_spaces(string number) 
{
  string remove_s; 
  for (char ch : number) 
  {
    if (!isspace(ch)) 
    {
      remove_s += ch;
    }
  }
  return remove_s; 
}

// Function to check if the input string matches the required format
bool check(const string& input) 
{ 
  // Regular expression pattern to match the required format
  regex pattern("^(?!.*[a-z]\\s*/).*\\s*-?\\d+\\s*(?:/\\s*-?\\d+)?\\s*[+\\-*/]\\s*-?\\d+\\s*(?:/\\s*-?\\d+)?\\s*$");
  return regex_search(input, pattern); 
}

// Function to get a valid input string from the user
string getValidInput() 
{
  string input; 
  cout << "Enter a rational number operation: "; 
  getline(cin, input); 
  if (!check(input)) 
  {
    cout << "Invalid input format. Please try again.\n"; 
    input = getValidInput(); 
  }
  return input;
}


// ****************** Algorithm for this program *********************************************
/*
Welcome Message:
- Display a welcome message for the user.
Main Loop:
- Prompt the user to start or exit the program.
- If the user chooses to exit, display a farewell message and terminate the program.
- If the user chooses to start:
- Proceed with input processing.
Input Processing:
- Ask the user to input a rational number operation.
- Ensure that the input format matches the required pattern.
- Remove any spaces from the input string.
Parsing First Operand:
- Extract the first operand from the input string.
- Handle cases where the first operand is negative.
Parsing Second Operand:
- Extract the second operand from the input string.
- Handle cases where the second operand is negative.
Handling Denominators && numerator:
- Extract denominators && numerator for both operands.
Perform Arithmetic Operations:
- Check for division by zero errors.
- Based on the second operator (+, -, *, /), perform the corresponding arithmetic operation.
- Calculate the result both as a fraction and a decimal.
Output Results:
- Display the result of the arithmetic operation as a fraction and a decimal.
Repeat:
- Repeat the main loop until the user chooses to exit.
Functions:
- remove_spaces: Remove spaces from a string.
- check: Va
*/