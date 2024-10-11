/*****************************************************************
//
//  NAME:        Yujin Chen
//
//  HOMEWORK:    project2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Novermber 25, 2023
//
//  FILE:        user_interface.cpp
//
//  DESCRIPTION: 
//   This program will set up the user_interface
//   for the database. 
//
******************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include "llist.h"

/******************************************************************
//
//  Function name: main
//
//  Description:   This function will run the 
//                 user interface.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char *[]) : An array of arguments passed
//                                   to the program.
//
//  Return values: 0: means success
//
*******************************************************************/

int main(int argc, char* argv[])
{
    int end = 0;
    int valid = 0;
    int accountNumber;
    char input[20];
    char name[30];
    char clearBuffer[80];
    char address[50];
    int result = 2;
    char character;
    int read = 1;
    int size = 50;
    int i = 0;
    llist list;

    while (end == 0)
    {
        std::cout << "\nThis is an database user-interface\n" << std::endl;
        std::cout << "\nPlease choose one of the following menu option that you would like";
        std::cout << " to proceed by the type menu option at the bottom:\n" << std::endl;
        std::cout << "  Menu Option   Description" << std::endl;
        std::cout << "  add:          add a new record in the database" << std::endl;
        std::cout << "  printall:     Print all records in the database" << std::endl;
        std::cout << "  find:         Find record(s) with a specified account number" << std::endl;
        std::cout << "  delete:       Delete existing record(s) from the database";
        std::cout << " using the account number as a key" << std::endl;
        std::cout << "  quit:         Quit the program" << std::endl;
        std::cout << "\nplease enter here: ";
        std::cin >> input;
        std::cin.getline(clearBuffer, 80);

        if (strlen(input) < 4 && input[0] == 'a')
        {
            if (strcmp(input, "a") == 0 || strcmp(input, "ad") == 0 || strcmp(input, "add") == 0)
            {
                std::cout << "\n******************************************";
                std::cout << "**************************************" << std::endl;
                std::cout << "\n To add a new record to the database,";
                std::cout << " Please follow the instruction below\n" << std::endl;
                std::cout << "please enter your name: ";
                std::cin.getline(name, 30);
                valid = 0;
                while (valid == 0)
                {
                    std::cout << "\nPlease enter the account number you ";
                    std::cout << " want to create and add to the record: ";
                    std::cin >> accountNumber;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.getline(clearBuffer, 80);
                        std::cout << "\nThe input is invalid, please enter";
                        std::cout << " a valid integer" << std::endl;
                    }
                    else
                    {
                        if (accountNumber <= 0)
                        {
                            std::cout << "\nThe input is either 0 or negative integer\n";
                            std::cout << "Please enter an positive integer" << std::endl;
                        }
                        else
                        {
                            valid = 1;
                        }
                    }
                }
                std::cin.getline(clearBuffer, 80);
                std::cout << "\nPlease enter your address below and type";
                std::cout << " dollar sign '$' end of your address: " << std::endl;
                while (read == 1)
                {
                    if ( i != size - 1)
                    {
                        character = std::cin.get();
                        if ( character == '$')
                        {
                            read = 0;
                        }
                        else
                        {
                            address[i] = character;
                            i++;
                        }
                    }
                    else
                    {
                        read = 0;
                        std::cin.getline(clearBuffer, 80);
                    }
                }
                address[i] = '\0';
                i = 0;
                read = 1;
                result = list.addRecord(accountNumber, name, address);
                if (result == -1)
                {
                    std::cout << "\nThere is already a record associated with the account number";
                    std::cout << ". The record will not be added\n" << std::endl;
                }
                else
                {
                    std::cout << "Your information will be added into the database." << std::endl;
                }
                std::cout << "\n******************************************";
                std::cout << "**************************************" << std::endl;
            }
            else
            {
                std::cout << "\ninvalid option, please enter an valid option from menu option\n";
            }
        }
        else if (strlen(input) < 5 && input[0] == 'q')
        {
            if (strcmp(input, "q") == 0 || strcmp(input, "qu") == 0 ||\
                strcmp(input, "qui") == 0 || strcmp(input, "quit") == 0)
            {
                std::cout << "\n******************************************";
                std::cout << "**************************************" << std::endl;
                end = 1;
                std::cout << "\nThank you for using the program,";
                std::cout << "Your session will now be terminated\n" << std::endl;
                std::cout << "\n******************************************";
                std::cout << "**************************************" << std::endl;
            }
            else
            {
                std::cout << "\ninvalid option, please enter an valid option from menu option\n";
            }
        }
        else if (strlen(input) < 5 && input[0] == 'f')
        {
            if (strcmp(input, "f") == 0 || strcmp(input, "fi") == 0 ||\
                strcmp(input, "fin") == 0 || strcmp(input, "find") == 0)
            {
                std::cout << "\n******************************************";
                std::cout << "**************************************" << std::endl;
                std::cout << "\nTo find your record, please";
                std::cout << " following the instruction below\n";
                valid = 0;
                while (valid == 0)
                {
                    std::cout << "\nPlease enter the account number you ";
                    std::cout << " want to create and add to the record: ";
                    std::cin >> accountNumber;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.getline(clearBuffer, 80);
                        std::cout << "\nThe input is invalid, please";
                        std::cout << " enter a valid integer" << std::endl;
                    }
                    else
                    {
                        if (accountNumber <= 0)
                        {
                            std::cout << "\nThe input is either 0 or negative integer\n";
                            std::cout << "Please enter an positive integer" << std::endl;
                        }
                        else
                        {
                            valid = 1;
                        }
                    }
                }
                std::cout << "\nThank you for enter your account number\n";
                result = list.findRecord(accountNumber);
                if (result == 0)
                {
                    std::cout << "\nThe record is found, printed above\n";
                }
                else
                {
                    std::cout << "\nRecord not found, no record is associated";
                    std::cout << " with account number entered\n";
                }
                std::cout << "\n******************************************";
                std::cout << "**************************************" << std::endl;
            }
            else
            {
                std::cout << "\ninvalid option, please enter an valid option from menu option\n";
            }
        }
        else if (strlen(input) < 7 && input[0] == 'd')
        {
            if (strcmp(input, "d") == 0 || strcmp(input, "de") == 0 || strcmp(input, "del") == 0 ||\
                strcmp(input, "dele") == 0 || strcmp(input, "delet") == 0\
                || strcmp(input, "delete") == 0)
            {
                std::cout << "\n******************************************";
                std::cout << "**************************************" << std::endl;
                std::cout << "\nTo delete a record, please follow";
                std::cout << " the instruction below" << std::endl;
                valid = 0;
                while (valid == 0)
                {
                    std::cout << "\nPlease enter the account number you ";
                    std::cout << " want to be deleted from the database: ";
                    std::cin >> accountNumber;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.getline(clearBuffer, 80);
                        std::cout << "\nThe input is invalid, please";
                        std::cout << " enter a valid integer" << std::endl;
                    }
                    else
                    {
                        if (accountNumber <= 0)
                        {
                            std::cout << "\nThe input is either 0 or negative integer\n";
                            std::cout << "Please enter an positive integer" << std::endl;
                        }
                        else
                        {
                            valid = 1;
                        }
                    }
                }
                std::cout << "\nThank you for entering your account number\n";
                result = list.deleteRecord(accountNumber);
                if (result == 0)
                {
                    std::cout << "\nRecord found, we will delete the record";
                    std::cout << " associated with this account number\n";
                }
                else
                {
                    std::cout << "\nNo record deleted because the account does not exist\n";
                }
                std::cout << "\n******************************************";
                std::cout << "**************************************" << std::endl;
            }
            else
            {
                std::cout << "\ninvalid option, please enter an valid option from menu option\n";
            }
        }
        else if (strlen(input) < 9 && input[0] == 'p')
        {
            if (strcmp(input, "p") == 0 || strcmp(input, "pr") == 0 ||\
                strcmp(input, "pri") == 0 ||\
                strcmp(input, "prin") == 0 || strcmp(input, "print") == 0 ||\
                strcmp(input, "printa") == 0\
                || strcmp(input, "printal") == 0 || strcmp(input, "printall") == 0)
            {
                std::cout << "\n******************************************";
                std::cout << "**************************************" << std::endl;
                std::cout << "\nThe records will be printed\n\n";
                list.printAllRecords();
                std::cout << "\n******************************************";
                std::cout << "**************************************" << std::endl;
            }
            else
            {
                std::cout << "\ninvalid option, please enter an valid option from menu option\n";
            }
        }
        else
        {
            std::cout << "\ninvalid option, please enter an valid option from menu option\n";
        }
    }

    return 0;
}
