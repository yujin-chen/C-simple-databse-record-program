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
//  DATE:        November 11, 2023
//
//  FILE:        llist.h
//
//  DESCRIPTION:
//   This header is to create data variable and variable type.
//
****************************************************************/

#ifndef LLIST_H
#define LLIST_H
#include "record.h"

using namespace std;

class llist
{
    private:
    record* start;
    char filename[20];
    int readfile();
    int writefile();
    void cleanup();

    public:
    llist();
    llist(char[]);
    ~llist();
    int addRecord(int, char[], char[]);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
    friend ostream& operator << (ostream&, const llist&);
    llist(llist&);
    llist& operator = (const llist&);
};

#endif
