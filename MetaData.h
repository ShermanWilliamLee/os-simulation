//	Assignment Information	//
/**
  *	@dev_name Sherman Lee
  *
  *	@class CS 446
  *
  */

// 	Class Head File Information //
/**
  *	@file MetaData.h
  *
  *	@brief Definition file for MetaData class
  *
  *	@details Specifies all members and methods of MetaData class
  *
  * @version 1.01
  *   Finalize and debug (Sep 7, 2019
  *
  *	@version 1.00
  *		Initial development and testing (Sep 3, 2019)
  *
  */

#ifndef METADATA_H
#define METADATA_H

#include <queue>

using namespace std;

class MetaData
{
  friend istream &operator>>(istream &iStream, MetaData &meta);

  public:
    MetaData();
    ~MetaData();

    bool empty();
    string showFront();

    void pushValue(int value);
    int popValue();
    void pushName(string name);
    string popName();

  private:
    queue <int> meta_value;
    queue <string> meta_name;

};

#endif