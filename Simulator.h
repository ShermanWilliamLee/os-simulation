//	Assignment Information	//
/**
  *	@dev_name Sherman Lee
  *
  *	@class CS 446
  *
  */

// 	Class Head File Information //
/**
  *	@file Simulator.h
  *
  *	@brief Definition file for Simulator class
  *
  *	@details Specifies all members and methods of Simulator class
  *
  * @version 1.01
  *   Finalize and debug (Sep 7, 2019)
  *
  *	@version 1.00
  *		Initial development and testing (Sep 3, 2019)
  *
  */

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <fstream>

using namespace std;

class Simulator
{
  friend istream &operator>>(istream &iStream, Simulator &sim);

	public:
		Simulator();
    Simulator(string param_version, string param_file, int param_monitor, int param_projector,
              int param_processor, int param_mouse, int param_hard_drive, int param_keyboard,
              int param_memory, int param_printer, int param_scanner, string param_log_to,
              string param_log_file);
		Simulator(const Simulator &copy);
		~Simulator();

		Simulator &operator=(const Simulator &dupe);

    string getVersion();
    void setVersion(string param_version);
    string getFile();
    void setFile(string param_file);
    int getMonitor();
    void setMonitor(int param_monitor);
    int getProjector();
    void setProjector(int param_projector);
    int getProcessor();
    void setProcessor(int param_processor);
    int getMouse();
    void setMouse(int param_mouse);
    int getHardDrive();
    void setHardDrive(int param_hard_drive);
    int getKeyboard();
    void setKeyboard(int param_keyboard);
    int getMemory();
    void setMemory(int param_memory);
    int getPrinter();
    void setPrinter(int param_printer);
    int getScanner();
    void setScanner(int param_scanner);
    string getLogTo();
    void setLogTo(string param_log_to);
    string getLogFile();
    void setLogFile(string param_log_file);

	private:
    string version;
    string file_path;
    int monitor;
    int projector;
	  int processor;
	  int mouse;
	  int hard_drive;
	  int keyboard;
	  int memory;
	  int printer;
    int scanner;
    string log_to;
    string log_file;
};

#endif