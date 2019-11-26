//	Assignment Information	//
/**
  *	@dev_name Sherman Lee
  *
  *	@class CS 446
  *
  */

// 	Class Implementation File Information //
/**
  *	@file Simulator.cpp
  *
  *	@brief Implementation file for Simulator class
  *
  *	@details Implements methods of Simulator class
  *
  * @version 1.01
  *   Finalize and debug (Sep 7, 2019
  *
  *	@version 1.00
  *		Initial development and testing (Sep 3, 2019)
  *
  */

#include <iostream>
#include <string>
#include <fstream>
#include "Simulator.h"


istream &operator>>(istream &iStream, Simulator &sim)
{
  string temp, filepath, version, log_to, log_file;
  int monitor = 0, processor = 0, mouse = 0, hard_drive = 0, 
      keyboard = 0, memory = 0, printer = 0, scanner = 0, projector = 0;

  getline(iStream, temp);
  //The condition below ensures that the config file is a correct simulation file
  //This allows the program to know whether to continue parsing the file
  if ((temp.substr(0, temp.find(' '))) == "Start")
  {
    //Ensures the file is read through
    while (!iStream.eof())
    {
      //Obtains the line each iteration
      getline(iStream, temp);

      if ((temp.substr(0, temp.find(':'))) == "Version/Phase")
      {
        version = temp.substr(temp.find(':') + 2, temp.length());
      }

      else if ((temp.substr(0, temp.find(':'))) == "File Path")
      {
        filepath = temp.substr(temp.find(':') + 2, temp.length());
      }

      else if ((temp.substr(0, temp.find(':'))) == "Monitor display time {msec}")
      {
        monitor = stoi(temp.substr(temp.find(':') + 2, temp.length()));
      }

      else if ((temp.substr(0, temp.find(':'))) == "Processor cycle time {msec}")
      {
        processor = stoi(temp.substr(temp.find(':') + 2, temp.length()));
      }

      else if ((temp.substr(0, temp.find(':'))) == "Mouse cycle time {msec}")
      {
        mouse = stoi(temp.substr(temp.find(':') + 2, temp.length()));
      }

      else if ((temp.substr(0, temp.find(':'))) == "Hard drive cycle time {msec}")
      {
        hard_drive = stoi(temp.substr(temp.find(':') + 2, temp.length()));
      }

      else if ((temp.substr(0, temp.find(':'))) == "Keyboard cycle time {msec}")
      {
        keyboard = stoi(temp.substr(temp.find(':') + 2, temp.length()));
      }

      else if ((temp.substr(0, temp.find(':'))) == "Memory cycle time {msec}")
      {
        memory = stoi(temp.substr(temp.find(':') + 2, temp.length()));
      }

      else if ((temp.substr(0, temp.find(':'))) == "Printer cycle time {msec}")
      {
        printer = stoi(temp.substr(temp.find(':') + 2, temp.length()));
      }

      else if ((temp.substr(0, temp.find(':'))) == "Log")
      {
        log_to = temp.substr(temp.find(':') + 2, temp.length());
      }

      else if ((temp.substr(0, temp.find(':'))) == "Log File Path")
      {
        log_file = temp.substr(temp.find(':') + 2, temp.length());
      }

      else if ((temp.substr(0, temp.find(':'))) == "Projector cycle time {msec}")
      {
        projector = stoi(temp.substr(temp.find(':') + 2, temp.length()));
      }

      else if ((temp.substr(0, temp.find(':'))) == "Scanner cycle time {msec}")
      {
        scanner = stoi(temp.substr(temp.find(':') + 2, temp.length()));
      }

      else if ((temp.substr(0, temp.find(' '))) == "End")
      {
        cout << "...Configuration file successfully read..." << endl;
        break;
      }
      else
      {
        cout << "...Configuration file is improperly formatted..." << endl;
        exit(0);
      }
    }
  }
  else
  {
    cout << "...Configuration file is improperly formatted..." << endl;
    exit(0);
  }
  Simulator New(version, filepath, monitor, projector, processor, mouse, hard_drive,
                keyboard, memory, printer, scanner, log_to, log_file);
  sim = New;
}

Simulator::Simulator()
{
  version.clear();
  file_path.clear();
  monitor = 0;
  projector = 0;
  processor = 0;
  mouse = 0;
  hard_drive = 0;
  keyboard = 0;
  memory = 0;
  printer = 0;
  scanner = 0;
  log_to.clear();
  log_file.clear();
}

Simulator::Simulator(string param_version, string param_file, int param_monitor, int param_projector,
              int param_processor, int param_mouse, int param_hard_drive, int param_keyboard,
              int param_memory, int param_printer, int param_scanner, string param_log_to,
              string param_log_file)
{
  version = param_version;
  file_path = param_file;
  monitor = param_monitor;
  projector = param_projector;
  processor = param_processor;
  mouse = param_mouse;
  hard_drive = param_hard_drive;
  keyboard = param_keyboard;
  memory = param_memory;
  printer = param_printer;
  scanner = param_scanner;
  log_to = param_log_to;
  log_file = param_log_file;
}

Simulator::Simulator(const Simulator &copy)
{
  version = copy.version;
  file_path = copy.file_path;
  monitor = copy.monitor;
  projector = copy.projector;
  processor = copy.processor;
  mouse = copy.mouse;
  hard_drive = copy.hard_drive;
  keyboard = copy.keyboard;
  memory = copy.memory;
  printer = copy.printer;
  scanner = copy.scanner;
  log_to = copy.log_to;
  log_file = copy.log_file;
}

Simulator::~Simulator()
{}

Simulator &Simulator::operator=(const Simulator &dupe)
{
  version = dupe.version;
  file_path = dupe.file_path;
  monitor = dupe.monitor;
  projector = dupe.projector;
  processor = dupe.processor;
  mouse = dupe.mouse;
  hard_drive = dupe.hard_drive;
  keyboard = dupe.keyboard;
  memory = dupe.memory;
  printer = dupe.printer;
  scanner = dupe.scanner;
  log_to = dupe.log_to;
  log_file = dupe.log_file;
}

string Simulator::getVersion()
{
  return version;
}

void Simulator::setVersion(string param_version)
{
  version = param_version;
}

string Simulator::getFile()
{
  return file_path;
}

void Simulator::setFile(string param_file)
{
  file_path = param_file;
}

int Simulator::getMonitor()
{
  return monitor;
}

void Simulator::setMonitor(int param_monitor)
{
  monitor = param_monitor;
}

int Simulator::getProjector()
{
  return projector;
}

void Simulator::setProjector(int param_projector)
{
  projector = param_projector;
}

int Simulator::getProcessor()
{
  return processor;
}

void Simulator::setProcessor(int param_processor)
{
  processor = param_processor;
}

int Simulator::getMouse()
{
  return mouse;
}

void Simulator::setMouse(int param_mouse)
{
  mouse = param_mouse;
}

int Simulator::getHardDrive()
{
  return hard_drive;
}

void Simulator::setHardDrive(int param_hard_drive)
{
  hard_drive = param_hard_drive;
}

int Simulator::getKeyboard()
{
  return keyboard;
}

void Simulator::setKeyboard(int param_keyboard)
{
  keyboard = param_keyboard;
}

int Simulator::getMemory()
{
  return memory;
}

void Simulator::setMemory(int param_memory)
{
  memory = param_memory;
}

int Simulator::getPrinter()
{
  return printer;
}

void Simulator::setPrinter(int param_printer)
{
  printer = param_printer;
}

int Simulator::getScanner()
{
  return scanner;
}

void Simulator::setScanner(int param_scanner)
{
  scanner = param_scanner;
}

string Simulator::getLogTo()
{
  return log_to;
}

void Simulator::setLogTo(string param_log_to)
{
  log_to = param_log_to;
}

string Simulator::getLogFile()
{
  return log_file;
}

void Simulator::setLogFile(string param_log_file)
{
  log_file = param_log_file;
}