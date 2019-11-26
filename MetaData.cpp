//  Assignment Information  //
/**
  * @dev_name Sherman Lee
  *
  * @class CS 446
  *
  */

//  Class Implementation File Information //
/**
  * @file MetaData.cpp
  *
  * @brief Implementation file for MetaData class
  *
  * @details Implements methods of MetaData class
  *
  * @version 1.01
  *   Finalize and debug (Sep 7, 2019
  *
  * @version 1.00
  *     Initial development and testing (Sep 3, 2019)
  *
  */

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <stack>
#include "MetaData.h"

istream &operator>>(istream &iStream, MetaData &meta)
{
    string temp;
    stack <int> system;
    stack <int> application;
    getline(iStream, temp);
    //Checks to ensure the metadata file has started
    if ((temp.substr(0, temp.find(' '))) == "Start")
    {
        getline(iStream, temp);

        while (!iStream.eof())
        {
            if ((temp.substr(0, temp.find('}'))) == "S{begin")
            {
                //Pushes a value to verify for later if system finishes
                system.push(1);
                //Removes first section of the line
                temp.erase(0, temp.find(';') + 2);
            }    
            else if ((temp.substr(0, temp.find('}'))) == "A{begin")
            {
                //Pushes a value to verify for later if application finishes
                application.push(1);
                //Removes first section of the line
                temp.erase(0, temp.find(';') + 2);
            }       
            else if ((temp.substr(0, temp.find('}'))) == "P{run")
            {
                //Parses and pushes process_run value to value queue
                meta.pushValue(stoi(temp.substr(temp.find('}') + 1, temp.find(';'))));
                //Removes first section of the line
                temp.erase(0, temp.find(';') + 2);
                //Pushes name of process_run to name queue
                meta.pushName("process_run");
            }  
            else if ((temp.substr(0, temp.find('}'))) == "M{allocate")
            {
                //Parses and pushes memory_allocate value to value queue
                meta.pushValue(stoi(temp.substr(temp.find('}') + 1, temp.find(';'))));
                //Removes first section of the line
                temp.erase(0, temp.find(';') + 2);
                //Pushes name of memory_allocate to name queue
                meta.pushName("memory_allocate");
            }    
            else if ((temp.substr(0, temp.find('}'))) == "O{monitor")
            {
                //Parses and pushes output_monitor value to value queue
                meta.pushValue(stoi(temp.substr(temp.find('}') + 1, temp.find(';'))));
                //Removes first section of the line
                temp.erase(0, temp.find(';') + 2);
                //Pushes name of output_monitor to name queue
                meta.pushName("output_monitor");
            }
            else if ((temp.substr(0, temp.find('}'))) == "I{hard drive")
            {
                //Parses and pushes input_harddrive value to value queue
                meta.pushValue(stoi(temp.substr(temp.find('}') + 1, temp.find(';'))));
                //Removes first section of the line
                temp.erase(0, temp.find(';') + 2);
                //Pushes name of input_harddrive to name queue
                meta.pushName("input_harddrive");
            }
            else if ((temp.substr(0, temp.find('}'))) == "I{mouse")
            {
                //Parses and pushes input_mouse value to value queue
                meta.pushValue(stoi(temp.substr(temp.find('}') + 1, temp.find(';'))));
                //Removes first section of the line
                temp.erase(0, temp.find(';') + 2);
                //Pushes name of input_mouse to name queue
                meta.pushName("input_mouse");
            }  
            else if ((temp.substr(0, temp.find('}'))) == "O{printer")
            {
                //Parses and pushes output_printer value to value queue
                meta.pushValue(stoi(temp.substr(temp.find('}') + 1, temp.find(';'))));
                //Removes first section of the line
                temp.erase(0, temp.find(';') + 2);
                //Pushes name of output_printer to name queue
                meta.pushName("output_printer");
            }  
            else if ((temp.substr(0, temp.find('}'))) == "I{keyboard")
            {
                //Parses and pushes input_keyboard value to value queue
                meta.pushValue(stoi(temp.substr(temp.find('}') + 1, temp.find(';'))));
                //Removes first section of the line
                temp.erase(0, temp.find(';') + 2);
                //Pushes name of input_keyboard to name queue
                meta.pushName("input_keyboard");
            }
            else if ((temp.substr(0, temp.find('}'))) == "O{hard drive")
            {
                //Parses and pushes output_harddrive value to value queue
                meta.pushValue(stoi(temp.substr(temp.find('}') + 1, temp.find(';'))));
                //Removes first section of the line
                temp.erase(0, temp.find(';') + 2);
                //Pushes name of output_harddrive to name queue
                meta.pushName("output_harddrive");
            }  
            else if ((temp.substr(0, temp.find('}'))) == "M{block")
            {
                //Parses and pushes memory_block value to value queue
                meta.pushValue(stoi(temp.substr(temp.find('}') + 1, temp.find(';'))));
                //Removes first section of the line
                temp.erase(0, temp.find(';') + 2);
                //Pushes name of memory_block to name queue
                meta.pushName("memory_block");
            }
            else if ((temp.substr(0, temp.find('}'))) == "A{finish")
            {
                if (!application.empty())
                {
                    //Removes to verify the completion of an application
                    application.pop();
                    //Removes first section of the line
                    temp.erase(0, temp.find(';') + 2);
                }
                else
                {
                    cout << "...Meta Data File improperly formatted..." << endl;
                    exit(0);
                }
            }  
            else if ((temp.substr(0, temp.find('}'))) == "S{finish")
            {
                if (!system.empty())
                {
                    //Removes to verify the completion of the system
                    system.pop();
                    //Removes first section of the line
                    temp.erase(0, temp.find('.') + 2);
                    break;
                }
                else
                {
                    cout << "...Meta Data File improperly formatted..." << endl;
                    exit(0);
                }
            }
            else
            {
                if (temp.empty())
                {
                    getline(iStream, temp);
                }
                else
                {
                    cout << "...Meta Data File improperly formatted..." << endl;
                    exit(0);
                }
            } 
        }

        getline(iStream, temp);
        if ((temp.substr(0, temp.find(' '))) == "End")
        {
            cout << "...Meta Data file successfully read..." << endl;   
        }
    }
    else
    {
        cout << "...Meta Data File improperly formatted..." << endl;
        exit(0);
    }
}

MetaData::MetaData()
{}

MetaData::~MetaData()
{
        while (!meta_value.empty())
        {
            meta_value.pop();
        }
        while (!meta_name.empty())
        {
            meta_name.pop();
        }
}

bool MetaData::empty()
{
    if (meta_value.empty() && meta_name.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

string MetaData::showFront()
{
    return meta_name.front();
}

void MetaData::pushValue(int value)
{
    meta_value.push(value);
}

int MetaData::popValue()
{
    int temp_value;
    temp_value = meta_value.front();
    meta_value.pop();
    return temp_value;
}

void MetaData::pushName(string name)
{
    meta_name.push(name);
}

string MetaData::popName()
{
    string temp_name;
    temp_name = meta_name.front();
    meta_name.pop();
    return temp_name;
}

