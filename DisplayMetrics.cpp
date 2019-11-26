//	Assignment Information	//
/**
  *	@dev_name Sherman Lee
  *
  *	@class CS 446
  *
  */

// 	Program Information	//
/**
  *	@file DisplayMetrics.cpp
  *
  *	@brief
  *
  *	@details Reads in configuration files to display metrics
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
#include "MetaData.h"

using namespace std;

void writeToTerminal(Simulator sim, MetaData meta);
ostream writeToLog(ostream &oStream, Simulator sim, MetaData meta);

int main(int argc, char* argv[])
{

	if (argc > 1)
	{
		string verify = argv[1];

		if (verify.substr(verify.find('.'), verify.size()) == ".conf")
		{
			//Read in configuration file data
			Simulator config;
			MetaData data;
			ifstream iStream_config;
			iStream_config.open(argv[1]);
			iStream_config >> config;
			iStream_config.close();

			verify = config.getFile();

			if (verify.substr(verify.find('.'), verify.size()) == ".mdf")
			{
				//Read in meta data file
				ifstream iStream_meta;
				iStream_meta.open(config.getFile());
				iStream_meta >> data;
				iStream_meta.close();

				cout << endl;

				ofstream oStream;
				oStream.open(config.getLogFile());
				if (config.getLogTo() == "Log to File")
				{
					writeToLog(oStream, config, data);
				}
				else if (config.getLogTo() == "Log to Monitor")
				{
					writeToTerminal(config, data);
				}
				else
				{
					writeToTerminal(config, data);
					writeToLog(oStream, config, data);
				}
				oStream.close();
			}
			else
			{
				cout << "...Invalid meta data file name..." << endl;
			}
		}
		else
		{
			cout << "...Invalid configuration file name..." << endl;
		}		
	}
	else
	{
		cout << "...Improper call to executable..." << endl;
		exit(0);
	}
}

void writeToTerminal(Simulator sim, MetaData meta)
{
	cout << "Configuration File Data" << endl
			<< "Monitor = " << sim.getMonitor() << " ms/cycle" << endl
			<< "Projector = " << sim.getProjector() << " ms/cycle" << endl
			<< "Processor = " << sim.getProcessor() << " ms/cycle" << endl
			<< "Mouse = " << sim.getMouse() << " ms/cycle" << endl
			<< "Hard Drive = " << sim.getHardDrive() << " ms/cycle" << endl
			<< "Keyboard = " << sim.getKeyboard() << " ms/cycle" << endl
			<< "Memory = " << sim.getMemory() << " ms/cycle" << endl
			<< "Printer = " << sim.getPrinter() << " ms/cycle" << endl
			<< "Scanner = " << sim.getScanner() << " ms/cycle" << endl;
	if (sim.getLogTo() == "Log to Both")
	{
		cout << "Logged to: monitor and " << sim.getLogFile() << endl;
	}
	else if (sim.getLogTo() == "Log to File")
	{
		cout << "Logged to: " << sim.getLogFile() << endl;	
	}
	else
	{
		cout << "Logged to: monitor" << endl;
	}

	cout << endl;

	int temp_value;
	cout << "Meta-Data Metrics" << endl;
	while (!meta.empty())
	{
		if (meta.showFront() == "process_run")
		{
			meta.popName();
			temp_value = meta.popValue();
			cout << "P{run}" << temp_value << " - " << temp_value * sim.getProcessor() << " ms" << endl;
		}
		else if (meta.showFront() == "memory_allocate")
		{
			meta.popName();
			temp_value = meta.popValue();
			cout << "M{allocate}" << temp_value << " - " << temp_value * sim.getMemory() << " ms" << endl;
		}
		else if (meta.showFront() == "output_monitor")
		{
			meta.popName();
			temp_value = meta.popValue();
			cout << "O{monitor}" << temp_value << " - " << temp_value * sim.getMonitor() << " ms" << endl;
		}
		else if (meta.showFront() == "input_harddrive")
		{
			meta.popName();
			temp_value = meta.popValue();
			cout << "I{hard drive}" << temp_value << " - " << temp_value * sim.getHardDrive() << " ms" << endl;
		}
		else if (meta.showFront() == "input_mouse")
		{
			meta.popName();
			temp_value = meta.popValue();
			cout << "I{mouse}" << temp_value << " - " << temp_value * sim.getMouse() << " ms" << endl;
		}
		else if (meta.showFront() == "output_printer")
		{
			meta.popName();
			temp_value = meta.popValue();
			cout << "O{printer}" << temp_value << " - " << temp_value * sim.getPrinter() << " ms" << endl;
		}
		else if (meta.showFront() == "input_keyboard")
		{
			meta.popName();
			temp_value = meta.popValue();
			cout << "I{keyboard}" << temp_value << " - " << temp_value * sim.getKeyboard() << " ms" << endl;
		}
		else if (meta.showFront() == "output_harddrive")
		{
			meta.popName();
			temp_value = meta.popValue();
			cout << "O{hard drive}" << temp_value << " - " << temp_value * sim.getHardDrive() << " ms" << endl;
		}
		else if (meta.showFront() == "memory_block")
		{
			meta.popName();
			temp_value = meta.popValue();
			cout << "M{block}" << temp_value << " - " << temp_value * sim.getMemory() << " ms" << endl;
		}
	}

}

ostream writeToLog(ostream &oStream, Simulator sim, MetaData meta)
{
	oStream << "Configuration File Data" << endl
			<< "Monitor = " << sim.getMonitor() << " ms/cycle" << endl
			<< "Projector = " << sim.getProjector() << " ms/cycle" << endl
			<< "Processor = " << sim.getProcessor() << " ms/cycle" << endl
			<< "Mouse = " << sim.getMouse() << " ms/cycle" << endl
			<< "Hard Drive = " << sim.getHardDrive() << " ms/cycle" << endl
			<< "Keyboard = " << sim.getKeyboard() << " ms/cycle" << endl
			<< "Memory = " << sim.getMemory() << " ms/cycle" << endl
			<< "Printer = " << sim.getPrinter() << " ms/cycle" << endl
			<< "Scanner = " << sim.getScanner() << " ms/cycle" << endl;
	if (sim.getLogTo() == "Log to Both")
	{
		oStream << "Logged to: monitor and " << sim.getLogFile() << endl;
	}
	else if (sim.getLogTo() == "Log to File")
	{
		oStream << "Logged to: " << sim.getLogFile() << endl;	
	}
	else
	{
		oStream << "Logged to: monitor" << endl;
	}

	oStream << endl;

	int temp_value;
	oStream << "Meta-Data Metrics" << endl;
	while (!meta.empty())
	{
		if (meta.showFront() == "process_run")
		{
			meta.popName();
			temp_value = meta.popValue();
			oStream << "P{run}" << temp_value << " - " << temp_value * sim.getProcessor() << " ms" << endl;
		}
		else if (meta.showFront() == "memory_allocate")
		{
			meta.popName();
			temp_value = meta.popValue();
			oStream << "M{allocate}" << temp_value << " - " << temp_value * sim.getMemory() << " ms" << endl;
		}
		else if (meta.showFront() == "output_monitor")
		{
			meta.popName();
			temp_value = meta.popValue();
			oStream << "O{monitor}" << temp_value << " - " << temp_value * sim.getMonitor() << " ms" << endl;
		}
		else if (meta.showFront() == "input_harddrive")
		{
			meta.popName();
			temp_value = meta.popValue();
			oStream << "I{hard drive}" << temp_value << " - " << temp_value * sim.getHardDrive() << " ms" << endl;
		}
		else if (meta.showFront() == "input_mouse")
		{
			meta.popName();
			temp_value = meta.popValue();
			oStream << "I{mouse}" << temp_value << " - " << temp_value * sim.getMouse() << " ms" << endl;
		}
		else if (meta.showFront() == "output_printer")
		{
			meta.popName();
			temp_value = meta.popValue();
			oStream << "O{printer}" << temp_value << " - " << temp_value * sim.getPrinter() << " ms" << endl;
		}
		else if (meta.showFront() == "input_keyboard")
		{
			meta.popName();
			temp_value = meta.popValue();
			oStream << "I{keyboard}" << temp_value << " - " << temp_value * sim.getKeyboard() << " ms" << endl;
		}
		else if (meta.showFront() == "memory_allocate")
		{
			meta.popName();
			temp_value = meta.popValue();
			oStream << "M{allocate}" << temp_value << " - " << temp_value * sim.getMemory() << " ms" << endl;
		}
		else if (meta.showFront() == "output_harddrive")
		{
			meta.popName();
			temp_value = meta.popValue();
			oStream << "O{hard drive}" << temp_value << " - " << temp_value * sim.getHardDrive() << " ms" << endl;
		}
		else if (meta.showFront() == "memory_block")
		{
			meta.popName();
			temp_value = meta.popValue();
			oStream << "M{block}" << temp_value << " - " << temp_value * sim.getMemory() << " ms" << endl;
		}
	}
}