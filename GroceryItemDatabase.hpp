#pragma once

///////////////////////// TO-DO (1) //////////////////////////////
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>
#include <iomanip>
#include "GroceryItem.hpp"
/////////////////////// END-TO-DO (1) ////////////////////////////


// Singleton Design Pattern
class GroceryItemDatabase
{
  public:
    // Get a reference to the one and only instance of the database
    static GroceryItemDatabase & instance();

    // Locate and return a reference to a particular record
    GroceryItem * find( const std::string & upc );                              // Returns a pointer to the item in the database if
                                                                                // found, nullptr otherwise
    // Queries
    std::size_t size() const;                                                   // Returns the number of items in the database

  private:
    GroceryItemDatabase            ( const std::string & filename );

    GroceryItemDatabase            ( const GroceryItemDatabase & ) = delete;    // intentionally prohibit making copies
    GroceryItemDatabase & operator=( const GroceryItemDatabase & ) = delete;    // intentionally prohibit copy assignments

    ///////////////////////// TO-DO (2) //////////////////////////////
std::map<std::string, GroceryItem> _data;
    /////////////////////// END-TO-DO (2) ////////////////////////////
};
