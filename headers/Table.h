#ifndef DATABASES_TABLE_H
#define DATABASES_TABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "FuncDepen.h"
#include <set>

class Table {
/*
 * Table class represents a database relation
 *
 */
public:
    //constructors
    Table();
    Table(std::string attr, std::string key);

    // Getters
    std::string getAttr() const;
    std::string getKey() const;
    int         getNbrFD() const;
    std::vector<FuncDepen>   getFD() const;

    std::string notInLeft
            ()   const;

    std::string concatenateLeft
            () const;

    // function to generate the set of minimal keys
    std::set<std::string>    keyGen() const;

    int  checkNF
            (std::string);                 //Returns in wich normal form is the relation
    bool check2NF
            (std::string key);             //to check if the relation is in the 2nd Normal Form
    bool check3NF
            (std::string key);             //to check if the relation is in the 3rd Normal Form

    std::vector<Table> deco2fn(std::string key);
    std::vector<Table> deco3fn(std::string key);

private:
    std::string _attributes;
    std::string _key;
    int         _nbrAttributes;
    int         _nbrFunctDepen;

    std::vector<FuncDepen> _fds;

    std::string concatenateRight
            ()   const;
    std::string notInRight
            ()   const;
    std::string format
            (std::string&) const;
    std::string closure
            (std::string const&) const;
    int  search
            (std::string a, std::string b);//How many chars in b does exist in a

};


std::ostream& operator<<( std::ostream& flux, Table const& table );
bool operator==( Table const& a, Table const& b );
bool notContains(std::vector<Table> to, Table a);

#endif //DATABASES_TABLE_H