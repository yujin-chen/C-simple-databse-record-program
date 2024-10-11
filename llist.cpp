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
//  DATE:        November 25, 2023
//
//  FILE:        llist.cpp
//
//  DESCRIPTION: 
//   This cpp file will define method and function of the llist class.
//
******************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include "llist.h"
#include "record.h"

#ifdef DEBUG
#define DEBUG_MODE
#endif

/******************************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Will read the record datas saved in the textfile and add it
//                 to the heap.
//
//  Parameters:    No parameter.
//
//  Return values: 0: means the file exist.
//                 -1: means the file can't be opened.
//
*******************************************************************************/

int llist::readfile()
{
    int exist = 0;
    int moreRecord = 1;
    int accountNumber;
    char name[30];
    char address[50];
    char clearBuffer[80];
    struct record* current;
    struct record* before;
    #ifdef DEBUG_MODE
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\nOutput from debug mode:\n";
    std::cout << "Method name: readfile" << std::endl;
    std::cout << "\n-----------------------------------------" << std::endl;
    #endif
    std::ifstream text(filename);
    if (!text.is_open())
    {
        exist = -1;
    }
    else
    {
        while (moreRecord == 1)
        {
            if (text >> accountNumber)
            {
                moreRecord = 1;
            }
            else
            {
                moreRecord = 0;
            }
            if (moreRecord == 1)
            {
                text.getline(clearBuffer, 80);
                text.getline(name, 30);
                text.getline(address, 50, '$');
                if (start == NULL)
                {
                    current = new record;
                    start = current;
                    current -> accountno = accountNumber;
                    strcpy(current -> name, name);
                    strcpy(current -> address, address);
                    current -> next = NULL;
                }
                else
                {
                    before = current;
                    current = new record;
                    before -> next = current;
                    current -> accountno = accountNumber;
                    strcpy(current -> name, name);
                    strcpy(current -> address, address);
                    current -> next = NULL;
                }
            }
        }
        text.close();
    }
    return exist;
}

/******************************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Will write the record datas to the designated text file
//
//  Parameters:    No parameter.
//
//  Return values: 0: means the file exist.
//                 -1: means the file can't be opened.
//
*******************************************************************************/

int llist::writefile()
{
    struct record* current = start;
    int exist = -1;
    #ifdef DEBUG_MODE
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\nOutput from debug mode:\n";
    std::cout << "Method name: writefile" << std::endl;
    std::cout << "\n-----------------------------------------" << std::endl;
    #endif
    std::ofstream text("result.txt");
    if (!text.is_open())
    {
        exist = -1;
    }
    else
    {
        exist = 0;
        while (current != NULL)
        {
            text << current->accountno << "\n";
            text << current->name << "\n";
            text << current->address;
            text << "$\n";
            current = current -> next;
        }
        text.close();
    }
    return exist;
}

/******************************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   Will deallocate all records that is on the heap.
//
//  Parameters:    No parameter
//
//  Return values: No return values.
//
*******************************************************************************/

void  llist::cleanup()
{
    struct record* current;
    struct record* next;
    #ifdef DEBUG_MODE
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\nOutput from debug mode:\n";
    std::cout << "Method name: cleanup" << std::endl;
    std::cout << "\n-----------------------------------------" << std::endl;
    #endif
    if (start != NULL)
    {
        current = start;
        next = current  -> next;
        while (next != NULL)
        {
            delete current;
            current = next;
            next = next -> next;
        }
        delete current;
        start = NULL;
    }
}

/******************************************************************************
//
//  Function name: llist() constructor
//
//  DESCRIPTION:   Will const llist object
//
//  Parameters:    no parameters
//
//  Return values: No return value.
//
*******************************************************************************/

llist::llist()
{
    int result;
    start = NULL;
    strcpy(filename, "result.txt");
    result = readfile();
    #ifdef DEBUG_MODE
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\nOutput from debug mode:\n";
    std::cout << "Method name: llist constructor" << std::endl;
    std::cout << "\n-----------------------------------------" << std::endl;
    #endif
    if (result == -1)
    {
        std::cout << "Unable to read and import the data" << std::endl;
    }
    else
    {
        std::cout << "Successfully read and load the data" << std::endl;
    }
}

/******************************************************************************
//
//  Function name: llist()
//
//  DESCRIPTION:   Will create a llist object read the data in the file in the
//                 parameter. It is a overload constructor
//
//  Parameters:    userFilename (char []): file name of the text file you want 
//                                         it to read.
//
//  Return values: No return value.
//
*******************************************************************************/

llist::llist(char userFilename[])
{
    int result;
    strcpy(filename, userFilename);
    #ifdef DEBUG_MODE
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\nOutput from debug mode:\n";
    std::cout << "Method name: llist overloading constructor" << std::endl;
    std::cout << "Filename: " << filename << std::endl;
    std::cout << "\n-----------------------------------------" << std::endl;
    #endif
    result = readfile();
    if (result == -1)
    {
        std::cout << "Unable to read and import the data" << std::endl;
    }
    else
    {
        std::cout << "Successfully read and load the data" << std::endl;
    }
}

/******************************************************************************
//
//  Function name: ~llist()
//
//  DESCRIPTION:   Will deallocate everything. Call writefile and cleanup.
//                 Delete the object.
//
//  Parameters:    no parameters
//
//  Return values: No return value.
//
*******************************************************************************/

llist::~llist()
{
    int result;
    #ifdef DEBUG_MODE
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\nOutput from debug mode:\n";
    std::cout << "Method name: descructor" << std::endl;
    std::cout << "\n-----------------------------------------" << std::endl;
    #endif
    result = writefile();
    if (result == -1)
    {
        std::cout << "Unable to write the data to the designated file" << std::endl;
    }
    else
    {
        std::cout << "Successfully write the data to the designated file" << std::endl;
    }
    cleanup();
}

/******************************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Add record to the database.
//
//  Parameters:    accountNumber (int) : Account number customer want.
//                 name (char []) : Name of customer.
//                 address (char []) : Customer's address.
//
//  Return values: 0: means successfully added the record.
//                 -1: means unable to add the record.
//
*******************************************************************************/

int llist::addRecord(int accountNumber, char name[], char address[])
{
    int exist = 0;
    int stop = 0;
    struct record* temp;
    struct record* current;
    struct record* after;
    current = start;
    #ifdef DEBUG_MODE
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\nOutput from debug mode:\n";
    std::cout << "Method name: addRecord\n";
    std::cout << "Name: "<< name << std::endl;
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Address:\n" << address << std::endl;
    std::cout << "\n-----------------------------------------" << std::endl;
    #endif
    if (start != NULL)
    {
        while (current -> next != NULL)
        {
            if (current -> accountno == accountNumber)
            {
                exist = -1;
                stop = 1;
            }
            current = current -> next;
        }
        if (current -> accountno == accountNumber)
        {
            exist = -1;
        }
        current = start;
    }

    if (exist == 0)
    {
        temp = new record;
        temp -> accountno = accountNumber;
        strcpy(temp -> name, name);
        strcpy(temp -> address, address);
        temp -> next = NULL;

        if (start == NULL)
        {
            start = temp;
            stop = 1;
        }

        while (stop == 0)
        {
            if (accountNumber > start -> accountno)
            {
                temp -> next = start;
                start = temp;
                stop = 1;
            }
            else if (current -> next == NULL && accountNumber < current -> accountno)
            {
                temp -> next = current -> next;
                current -> next = temp;
                stop = 1;
            }
            else
            {
                after = current -> next;
                if (after != NULL && accountNumber > after -> accountno)
                {
                    temp -> next = current -> next;
                    current -> next = temp;
                    stop = 1;
                }
                else
                {
                    current = current -> next;
                }
            }
        }
    }
    return exist;
}

/******************************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Will find and print the record associated with the account
//                 number provided.
//
//  Parameters:    accountNumber (int) : Account number customer provided.
//
//  Return values: 0: means found and printed the record.
//                 -1: means unable to find the record associated with account
//                     number.
//
*******************************************************************************/

int llist::findRecord(int accountNumber)
{
    int exist = -1;
    struct record* current = start;
    #ifdef DEBUG_MODE
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\nOutput from debug mode:\n";
    std::cout << "Method name: find record" << std::endl;
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "\n-----------------------------------------" << std::endl;
    #endif
    while (current != NULL)
    {
        if (current -> accountno == accountNumber)
        {
            std::cout << "\n--------------------------------------------\n";
            std::cout << "Account Number: " << current -> accountno << std::endl;
            std::cout << "Name: " << current -> name << std::endl;
            std::cout << "Address: " << current -> address << std::endl;
            std::cout << "\n--------------------------------------------\n";
            exist = 0;
        }
        current = current -> next;
    }
    return exist;
}

/******************************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   Will print all the records in the database.
//
//  Parameters:    No parameters.
//
//  Return values: No return value.
//
*******************************************************************************/

void llist::printAllRecords()
{
    #ifdef DEBUG_MODE
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\nOutput from debug mode:\n";
    std::cout << "Method name: printall record" << std::endl;
    std::cout << "\n-----------------------------------------" << std::endl;
    #endif
    struct record* current = start;
    if (start  == NULL)
    {
        std::cout << "There are no record in the database";
    }
    else
    {
        while (current != NULL)
        {
            std::cout << "\n--------------------------------------------\n";
            std::cout << "Account Number: " <<  current -> accountno << std::endl;
            std::cout << "Name: " << current -> name << std::endl;
            std::cout << "Address:\n" << current -> address << std::endl;
            std::cout << "\n--------------------------------------------\n";
            current = current -> next;
        }
    }
}

/******************************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   Will delete the record associated with the account number
//                 customer provided.
//
//  Parameters:    accountNumber (int): Account Number customer provided.
//
//  Return values: 0: Means the record exist and successfully delete the record.
//                 -1: means no record associated with the account number so
//                     unable to delete the record.
//
*******************************************************************************/

int llist::deleteRecord(int accountNumber)
{
    int exist = -1;
    struct record* current;
    struct record* after;
    struct record* beforeExistLocation;
    #ifdef DEBUG_MODE
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\nOutput from debug mode:\n";
    std::cout << "Method name: delete record" << std::endl;
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "\n-----------------------------------------" << std::endl;
    #endif
    if (start  == NULL)
    {
        exist = -1;
    }
    else
    {
        current = start;
        after = current -> next;
        if (current -> accountno == accountNumber)
        {
            start  = after;
            delete current;
            exist = 0;
        }
        else
        {
            while (after != NULL)
            {
                if (after -> accountno == accountNumber)
                {
                    exist = 0;
                    beforeExistLocation = current;
                    current = current -> next;
                    after = current -> next;
                    beforeExistLocation -> next = after;
                    delete current;
                }
                if (after != NULL)
                {
                    current = current -> next;
                    after = current -> next;
                }
            }
        }
    }
    return exist;
}

/******************************************************************************
//
//  Function name: << overload
//
//  DESCRIPTION:   Will print all records in the database.
//
//  Parameters:    output (ostream&): The name of the output stream.
//                 llist (const llist&) : The object that you want it to print
//                                        all records.
//
//  Return values: Will return the stream named output.
//
*******************************************************************************/

ostream& operator<<(ostream& output, const llist& list)
{
    record* current = list.start;
    #ifdef DEBUG_MODE
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\nOutput from debug mode:\n";
    std::cout << "Function name: << overload" << std::endl;
    std::cout << "\n-----------------------------------------" << std::endl;
    #endif
    while (current != NULL)
    {
        output << "\n--------------------------------------------\n";
        output << "Account Number: " << current -> accountno << "\n";
        output << "Name : " << current -> name << "\n";
        output << "Address: \n" << current -> address << "\n";
        output << "\n--------------------------------------------\n";
        current = current -> next;
    }
    return output;
}

/******************************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   Will copy data of the object that called this method
//                 to another llist object.
//
//  Parameters:    otherList (llist&) : The object that the data will copied to.
//
//  Return values: No return value.
//
*******************************************************************************/

llist::llist(llist& otherList)
{
    record* current = this -> start;
    #ifdef DEBUG_MODE
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\nOutput from debug mode:\n";
    std::cout << "Method name: Copy constructor" << std::endl;
    std::cout << "\n-----------------------------------------" << std::endl;
    #endif
    while (current != NULL)
    {
        otherList.addRecord(current -> accountno, current -> name, current -> address);
        current = current -> next;
    }
}

/******************************************************************************
//
//  Function name: llist = assignment
//
//  DESCRIPTION:   Will assign data of the object in parameter to the object
//                 called this method.
//
//  Parameters:    sourceList (const llist&) : the records in this object to be
//                                             added to the object called this
//                                             method.
//                                             
//
//  Return values: return the llist pointer.
//
*******************************************************************************/

llist& llist::operator = (const llist& sourceList)
{
    record* current = this -> start;
    #ifdef DEBUG_MODE
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\nOutput from debug mode:\n";
    std::cout << "Method name: Overload assignment" << std::endl;
    std::cout << "\n-----------------------------------------" << std::endl;
    #endif
    while (current != NULL)
    {
        this -> addRecord(current -> accountno, current -> name, current -> address);
        current = current -> next;
    }
    return *this;
}
