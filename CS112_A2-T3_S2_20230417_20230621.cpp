// ** FCAI-CU – CS112 - Structured Programming – 2024 - Assignment ( 2 ) - Task ( 3 ) **
// Last Modification Date: 13/03/2024
// Under supervision of  : Dr.Mohamed El-Ramly
// TA                    : Eng.Yomna Ismail Fathy
// File Name             : CS112_A2_T3_S2_20230417_20230621
// Purpose               : In this program we create a ( Rational Number Calculator ) that is capable of taking two rational numbers and an operation to perform on them.
// Authors               : Malak Mohamed Saad Fahmy Al-Aabiad       => ID: ( 20230417 )    => SECTION: S2     => FUNCTIONS:     ( Simplify, Addition, Subtraction, Main).
//                       : Mo'men Mohamed Mahmoud Mohamed Yosri     => ID: ( 20230621 )    => SECTION: S2     => FUNCTIONS:     ( Multiplication, Division             ).
// Emails                : malakkalaabiadd@gmail.com
//                       : momen.yosri@gmail.com

#include <iostream>
#include <string>
#include <cstdlib>
#include <numeric>
#include <regex>     // Regular expressions
#include <sstream>

using namespace std;

// Function to simplify fractions
void simplify(long long& numerator, long long& denominator) {
    int gcd_value = gcd(abs(numerator), abs(denominator));  // Calculate greatest common divisor
    numerator /= gcd_value;
    denominator /= gcd_value;
    // Check if the denominator is positive or not
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}

// Function to add two fractions or integer numbers
void addition(long long num1,long long num2, long long num3, long long num4) {
    long long numerator, denominator;
    // if denominators are equal
    if (num2 == num4) {
        numerator = (num1 + num3);
        denominator = num2;
        simplify(numerator, denominator);     // simplify the fraction
        // output the result
        if ( num2 == 1 && denominator == 1 && num4 == 1 ){
            cout << num1 <<  " + " << num3 << " = " << numerator << endl;
        } else if ( num2 != 1 && denominator != 1 && num4 == 1 ){
            cout << num1 <<  "/" << num2 << " + " << num3 << " = " << numerator << "/" << denominator << endl;
        } else if (num2 == 1 && denominator != 1 && num4 != 1){
            cout << num1 << " + " << num3 << "/" << num4 << " = " << numerator << "/" << denominator << endl;
        } else if (num2 != 1 && denominator == 1 && num4 != 1 ) {
            cout << num1 << "/" << num2 << " + " << num3 << "/" << num4 << " = " << numerator << endl;
        } else if (abs(numerator) > abs(denominator)){
            int whole = numerator / denominator;
            int remainder = abs(numerator) % abs(denominator);
            if ( num2 == 1 || num4 == 1) {
                cout << num1 << " + " << num3 << " = " << whole << " " << remainder << "/" << denominator << endl;
            } else if (num2 == 1 && denominator != 1 && num4 != 1){
                cout << num1 << " + " << num3 << "/" << num4 << " = " << whole << " " << remainder << "/" << denominator << endl;
            } else {
                cout << num1 << "/" << num2 << " + " << num3 << "/" << num4 << " = " << whole << " " << remainder << "/" << denominator << endl;
            }
        } else {
            cout << num1 << "/" << num2 << " + " << num3 << "/" << num4 << " = " << numerator << "/" << denominator << endl;
        }
    } // if denominators aren't equal
    else if (num2 != num4) {
        numerator = num1 * num4 + num2 * num3;   // cross multiply numerators
        denominator = num2 * num4;               // multiply denominators
        simplify(numerator, denominator);  // simplify the fraction
        // output the result
        if ( num2 == 1 && denominator == 1 && num4 == 1 ){
            cout << num1 <<  " + " << num3 << " = " << numerator << endl;
        } else if ( num2 != 1 && denominator != 1 && num4 == 1 ){
            cout << num1 <<  "/" << num2 << " + " << num3 << " = " << numerator << "/" << denominator << endl;
        } else if (num2 == 1 && denominator != 1 && num4 != 1){
            cout << num1 << " + " << num3 << "/" << num4 << " = " << numerator << "/" << denominator << endl;
        } else if (num2 != 1 && denominator == 1 && num4 != 1 ) {
            cout << num1 << "/" << num2 << " + " << num3 << "/" << num4 << " = " << numerator << endl;
        } else if (abs(numerator) > abs(denominator)){
            int whole = numerator / denominator;
            int remainder = abs(numerator) % abs(denominator);
            if ( num2 == 1 || num4 == 1){
                cout << num1 << " + " << num3 << " = " << whole << " " << remainder << "/" << denominator << endl;
            } else if (num2 == 1 && denominator != 1 && num4 != 1){
                cout << num1 << " + " << num3 << "/" << num4 << " = " << whole << " " << remainder << "/" << denominator << endl;
            }
            else{
                cout << num1 << "/" << num2 << " + " << num3 << "/" << num4 << " = " << whole << " " << remainder << "/" << denominator << endl;
            }
        } else {
            cout << num1 << "/" << num2 << " + " << num3 << "/" << num4 << " = " << numerator << "/" << denominator << endl;
        }
    }
}

// Function to subtract two fractions or integer numbers
void subtraction(long long num1,long long num2, long long num3, long long num4){
    long long numerator, denominator;
    // if denominators are equal
    if (num2 == num4){
        numerator = (num1 - num3);
        denominator = num2;
        simplify(numerator, denominator);       // simplify the fraction
        // output the result
        if ( num2 == 1 && denominator == 1 && num4 == 1 ){
            cout << num1 <<  " - " << num3 << " = " << numerator << endl;
        } else if ( num2 != 1 && denominator != 1 && num4 == 1 ){
            cout << num1 <<  "/" << num2 << " - " << num3 << " = " << numerator << "/" << denominator << endl;
        } else if (num2 == 1 && denominator != 1 && num4 != 1){
            cout << num1 << " - " << num3 << "/" << num4 << " = " << numerator << "/" << denominator << endl;
        }
        else if (num2 != 1 && denominator == 1 && num4 != 1 ) {
            cout << num1 << "/" << num2 << " - " << num3 << "/" << num4 << " = " << numerator << endl;
        } else if (abs(numerator) > abs(denominator)){
            int whole = numerator / denominator;
            int remainder = abs(numerator) % abs(denominator);
            if ( num2 == 1 || num4 == 1){
                cout << num1 << " - " << num3 << " = " << whole << " " << remainder << "/" << denominator << endl;
            } else if (num2 == 1 && denominator != 1 && num4 != 1){
                cout << num1 << " - " << num3 << "/" << num4 << " = " << whole << " " << remainder << "/" << denominator << endl;
            }
            else{
                cout << num1 << "/" << num2 << " - " << num3 << "/" << num4 << " = " << whole << " " << remainder << "/" << denominator << endl;
            }
        } else {
            cout << num1 << "/" << num2 << " - " << num3 << "/" << num4 << " = " << numerator << "/" << denominator << endl;
        }
    } // if denominators aren't equal
    else if( num2 != num4 ) {
        numerator = num1 * num4 - num2 * num3;        // cross multiply numerators
        denominator = num2 * num4;                    // multiply denominators
        simplify(numerator, denominator);       // simplify the fraction
        // output the result
        if ( num2 == 1 && denominator == 1 && num4 == 1 ){
            cout << num1 <<  " - " << num3 << " = " << numerator << endl;
        } else if ( num2 != 1 && denominator != 1 && num4 == 1 ){
            cout << num1 <<  "/" << num2 << " - " << num3 << " = " << numerator << "/" << denominator << endl;
        } else if (num2 != 1 && denominator == 1 && num4 != 1 ) {
            cout << num1 << "/" << num2 << " - " << num3 << "/" << num4 << " = " << numerator << endl;
        } else if (num2 == 1 && denominator != 1 && num4 != 1){
            cout << num1 << " - " << num3 << "/" << num4 << " = " << numerator << "/" << denominator << endl;
        } else if (abs(numerator) > abs(denominator)){
            int whole = numerator / denominator;
            int remainder = abs(numerator) % abs(denominator);
            if ( num2 == 1 || num4 == 1){
                cout << num1 << " - " << num3 << " = " << whole << " " << remainder << "/" << denominator << endl;
            } else if (num2 == 1 && denominator != 1 && num4 != 1){
                cout << num1 << " - " << num3 << "/" << num4 << " = " << whole << " " << remainder << "/" << denominator << endl;
            }
            else{
                cout << num1 << "/" << num2 << " - " << num3 << "/" << num4 << " = " << whole << " " << remainder << "/" << denominator << endl;
            }
        } else {
            cout << num1 << "/" << num2 << " - " << num3 << "/" << num4 << " = " << numerator << "/" << denominator << endl;
        }
    }
}

// Function to multiple two fractions or integer numbers
void multiplication(long long num1, long long num2, long long num3, long long num4) {
    long long numerator, denominator;
    numerator = num1 * num3;                          // multiply numerators
    denominator = num2 * num4;                        // multiply denominators
    simplify(numerator, denominator);           // simplify the fraction
    // output the result
    if (num2 == 1 && denominator == 1 && num4 == 1) {
        cout << num1 << " * " << num3 << " = " << numerator << endl;
    } else if (num2 != 1 && denominator != 1 && num4 == 1) {
        cout << num1 << "/" << num2 << " * " << num3 << " = " << numerator << "/" << denominator << endl;
    } else if (num2 == 1 && denominator != 1 && num4 != 1){
        cout << num1 << " * " << num3 << "/" << num4 << " = " << numerator << "/" << denominator << endl;
    } else if (num2 != 1 && denominator == 1 && num4 != 1) {
        cout << num1 << "/" << num2 << " * " << num3 << "/" << num4 << " = " << numerator << endl;
    } else if (num2 != 1 && denominator == 1 && num4 != 1) {
        cout << num1 << "/" << num2 << " * " << num3 << "/" << num4 << " = " << numerator << endl;
    } else if (abs(numerator) > abs(denominator)) {
        int whole = numerator / denominator;
        int remainder = abs(numerator) % abs(denominator);
        if ( num2 == 1 || num4 == 1){
            cout << num1 << " * " << num3 << " = " << whole << " " << remainder << "/" << denominator << endl;
        } else if (num2 == 1 && denominator != 1 && num4 != 1){
            cout << num1 << " * " << num3 << "/" << num4 << " = " << whole << " " << remainder << "/" << denominator << endl;
        }
        else{
            cout << num1 << "/" << num2 << " * " << num3 << "/" << num4 << " = " << whole << " " << remainder << "/" << denominator << endl;
        }
    } else {
        cout << num1 << "/" << num2 << " * " << num3 << "/" << num4 << " = " << numerator << "/" << denominator << endl;
    }
}

// Function to divide two fractions or integer numbers
void division(long long num1, long long num2, long long num3, long long num4) {
    long long numerator, denominator;
    if (num1 == 0 || num3 == 0){
        cout << "\nDivision by zero isn't allowed. Try again." << endl;     // Display error message
        return;
    }
    else{
        numerator = num1 * num4;
        denominator = num2 * num3;
        simplify(numerator, denominator);     // simplify the fraction
    }
    // output the result
    if ( num2 == 1 && denominator == 1 && num4 == 1 ){
        cout << num1 <<  " / " << num3 << " = " << numerator << endl;
    } else if ( num2 != 1 && denominator != 1 && num4 == 1 ){
        cout << num1 <<  "/" << num2 << " / " << num3 << " = " << numerator << "/" << denominator << endl;
    } else if (num2 == 1 && denominator != 1 && num4 != 1){
        cout << num1 << " / " << num3 << "/" << num4 << " = " << numerator << "/" << denominator << endl;
    } else if (num2 != 1 && denominator == 1 && num4 != 1 ) {
        cout << num1 << "/" << num2 << " / " << num3 << "/" << num4 << " = " << numerator << endl;
    } else if (abs(numerator) > abs(denominator)){
        long long whole = numerator / denominator;
        long long remainder = abs(numerator) % abs(denominator);
        if ( num2 == 1 || num4 == 1){
            cout << num1 << " / " << num3 << " = " << whole << " " << remainder << "/" << denominator << endl;
        } else if (num2 == 1 && denominator != 1 && num4 != 1){
            cout << num1 << " / " << num3 << "/" << num4 << " = " << whole << " " << remainder << "/" << denominator << endl;
        }
        else{
            cout << num1 << "/" << num2 << " / " << num3 << "/" << num4 << " = " << whole << " " << remainder << "/" << denominator << endl;
        }
    } else {
        cout << num1 << "/" << num2 << " / " << num3 << "/" << num4 << " = " << numerator << "/" << denominator << endl;
    }
}

// Structure to represent a fraction
struct Fraction {
    int numerator;     // Numerator of the fraction
    int denominator;   // Denominator of the fraction
};

// Function to parse a fraction from a string
Fraction parse_fraction(const string& fractionStr) {
    Fraction fraction;    // Create a fraction object
    istringstream iss(fractionStr);  // Create a string stream from the input string
    char delimiter;                      // Define a delimiter character
    iss >> fraction.numerator >> delimiter >> fraction.denominator;   // Extract numerator and denominator
    return fraction;      // Return the parsed fraction
}

// The main function for the calculator
int main() {
    // Variable to store user's choice
    string choice;
    // Display welcome message to the user
    cout << "\n** Welcome to Rational Number Calculator **";
    cout << "\n+----+----+----+----+----+----+----+----+----+";
    cout << "\nIn this program we create a rational number calculator that is capable of "
            "\ntaking two rational numbers and an operation to perform on them.";
    cout << "\n+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+" << endl;
    // Main loop to keep the program running until the user choose to exit the calculator
    while (true) {
        string equation;  // Valiable to store the equation which entered by the user
        cout << "\nPlease, enter a rational number operations in the format (1st frac. operation 2nd frac.) don't forget spaces to separate fractions from sign( or exit ): ";
        getline(cin, equation);

        // Check if the user wants to exit the program
        if (equation == "exit") {
            // Display exit message
            cout << "\nExiting program...";
            cout << "\nThank you for using the rational number calculator." << endl;
            exit(0);
        }
        // Define a regular expression pattern to validate the input equation
        regex pattern("^\\s*([+-]?\\d+\\s*(?:/\\s*[+-]?\\d+)?|[+-]?\\d+\\s*/\\s*[+-]?\\d+)\\s*([+\\-*/])\\s([+-]?\\d+\\s*(?:/\\s*[+-]?\\d+)?|[+-]?\\d+\\s*/\\s*[+-]?\\d+)\\s*$");
        // Check if the input equation matches the pattern
        if (!regex_match(equation, pattern)) {
            cout << "\nInvalid operand. Try again." << endl;  // if not display error message
            continue;
        }
        // Parse the input equation
        istringstream iss(equation);
        string fraction1_str, operation, fraction2_str;
        iss >> fraction1_str >> operation >> fraction2_str;
        int num1, num2 = 1, num3, num4 = 1;

        Fraction fraction1 = parse_fraction(fraction1_str);
        Fraction fraction2 = parse_fraction(fraction2_str);

        num1 = fraction1.numerator;

        // Check if the first fraction has a denominator
        if (fraction1_str.find('/') != string::npos) {
            num2 = fraction1.denominator;
        }
        // Check if the second fraction has a denominator
        if (fraction2_str.find('/') != string::npos) {
            num4 = fraction2.denominator;
        }
         num3 = fraction2.numerator;

        // Check for division by zero
        if (num2 == 0 || num4 == 0) {
            cout << "\nDivision by zero isn't allowed. Try again." << endl;     // Display error message
            continue;
        }

        // Calculate the selected operation based on the user's choice
        if (operation == "+") {
            // Call the addition function
            addition(num1, num2, num3, num4);
        } else if (operation == "-") {
            // Call the subtraction function
            subtraction(num1, num2, num3, num4);
        } else if (operation == "*") {
            // Call the multiplication function
            multiplication(num1, num2, num3, num4);
        } else if (operation == "/") {
            // Call the division function
            division(num1, num2, num3, num4);
        } else {
            cout << "\nInvalid operation. Try again." << endl;                  // Display error message
            continue;
        }
    }
}

/*

1 . Include necessary libraries in cpp for input/output (iostream), string manipulation (String), and mathematical operations.
2 . Define a function to simplify fractions by finding their greatest common divisor (gcd).
3 . Define functions for addition, subtraction, multiplication, and division of fractions and integer numbers.
4 . Define a data structure to represent fractions.
5 . Define a function to parse a string into a fraction.
6 . Define the main function of the calculator.
7 . Display a welcome message and instructions for using the rational number calculator.
8 . Start a while true loop to ask the user for input.
9 . Read the user's input equation.
10. Check if the user wants to exit the program.
11. Validate the input format using a regular expression (regex).
12. Parse the input equation into two fractions and an operation.
13. Check for division by zero.
14. Calculate the selected operation on the fractions.
15. Display the result in formats depending on the operands.
16. End of loop.

*/