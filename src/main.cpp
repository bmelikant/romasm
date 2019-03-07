#include <iostream>
#include <string>
#include <map>

#include <error.h>

using namespace std;

// define the type for command callbacks
using usage_callback_t = void(*)();
using command_callback_t = void(*)(int args_count, char *arguments[]);

// function prototypes
void do_command(int arg_count, char *arguments[]);
void test_command(int args_count, char *arguments[]);

void print_usage(string command);
void program_usage();
void unsupported_usage();

static const map<string,usage_callback_t> usage_map = {
	{ "program", program_usage },
	{ "unsupported", unsupported_usage }
};

static const map<string,command_callback_t> command_map = {
	{ "test", test_command }
};

/**
 * @fn do_command(): run a command from the command line
 * This function will take the argument count and the arguments passed
 * in to the main function and run the given command. This leaves the main
 * function as basically a blank stub to this function
 * @param arg_count the number of arguments as received from the command line
 * @param arguments an array of char pointers that will be used to determine the command to run
 * @return nothing. when an exit command is received, exit(exit_code) will be called
 */
void do_command(int args_count, char *arguments[]) {
	if (args_count < 1 || command_map.find(arguments[0]) == command_map.end()) {
		print_usage("unsupported");
	} else {
		// we found the processing function above, so now we can just defer to the processing function
		command_callback_t processing_fn = command_map.at(arguments[0]);
		// point to the first argument and process
		processing_fn(args_count-1, arguments+1);
		cout << endl;
		exit(0);
	}
}

void print_usage(string command) {
	// if the command can't be found, print the program usage
	if (usage_map.find(command) == usage_map.end()) {
		print_usage("program");
	} else {
		usage_callback_t usage_fn = usage_map.at(command);
		usage_fn();
	}
}

/**
 * @fn print_usage(): print help information for the given command
 * If no command is passed into this function, the program will print
 * usage data for the program itself
 */

int main(int argc, char *argv[]) {
	do_command(argc-1,argv+1);
	return 0;
}

/**
 * @fn program_usage(): display usage data for the software
 * @return nothing. Exits with error code
 */
void program_usage() {
	fatal("no action specified", "romasm action [args]");
}

/**
 * @fn program_usage(): display usage data for the software
 * @return nothing. Exits with error code
 */
void unsupported_usage() {
	fatal("the specified action is not supported", "type romasm help for a list of available actions");
}

/**
 * @fn test_command(): command to test the parsing of command line arguments
 * this function should be removed for non-debug builds, but I am leaving it in
 * for debug builds so I can test new features
 */
void test_command(int args_count, char *arguments[]) {
	cout << "Hi, I am a test command!" << endl;
}