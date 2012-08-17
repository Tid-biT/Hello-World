/**************************************************************************//**
* @file str.cpp
* @brief A program to test in-place swapping 
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_BUF_SIZE 125

int debug = 0;  ///< How verbose to make the dubug information

int init_count = 1;  ///< Initial count to start summing
int final_count = 75;  ///< Final count to end summing
int one_over = 1;  ///< Sum the values 1/x

/* --------------------------------------------------------------------------*/
/**                                    DisplayUsage
* @brief Inform the user of how this program operates and what options are available
* 
* @param argc
* @param argv
* @return Exit program with -1
*/
void DisplayUsage(int argc, char **argv)
{
	printf("USAGE %s [-D lvl] [-i initial] [-f final]\n", argv[0]);
	exit(-1);
}


/* --------------------------------------------------------------------------*/
/**                                    ParseHyphenArguments
* @brief Interpret the hyphenated arguments given on the command line
* 
* @param argc - number of arguments from the command line
* @param argv - the array of argument strings
* @param free_args - the minimum number of arguments that are not to be parsed
* @return number of arguments parsed 
*/
int ParseHyphenArguments(int argc, char **argv, int free_args)
{
	int args_used = 0;
	int total_args_used = 0;

	while (argc>free_args && argv[1][0]=='-') // go through each arg until there is only some left or the arg does not start with a hyphen 
	{
		args_used = 0; // how many arguments from the command line have been read for the current hyphen option
		if (!strcmp(argv[1],"-D") && argc>2) {
			debug = atoi(argv[2]);
			args_used = 2;
		}
		if (!strcmp(argv[1],"-i") && argc>2) {
			init_count = atoi(argv[2]);
			args_used = 2;
		}
		if (!strcmp(argv[1],"-f") && argc>2) {
			final_count = atoi(argv[2]);
			args_used = 2;
		}

		if (args_used==0) // if no arguments have been read then the usage is incorrect
			DisplayUsage(argc,argv);

		total_args_used += args_used; // keep track of how many arguments have been read
		argc -= args_used; // reduce the arg count
		argv += args_used; // move on to the next arg value
	}

	return total_args_used;
}

/* --------------------------------------------------------------------------*/
/**                                    Summation
* @brief Sum a sequence
* 
* @return 0 if successful
*/
int Summation()
{
	float f = 0.0;

	for (int i=init_count; i<=final_count; i++)
	{
		if (one_over)
			f += (float) (1.0 / (float) i);
		else
			f += (float) i;
	}

	printf("sum = %f\n", f);
	return 0;
}


/* --------------------------------------------------------------------------*/
/**                                    main
* @brief Start of the program
* 
* @param argc - number of arguments from the command line
* @param argv - the array of argument strings
* @return 0 if ok
*/
int main(int argc, char **argv)
{
	int i;
	int args_used = 0;

	// Check command line options
	args_used = ParseHyphenArguments(argc, argv, 1);
	argc -= args_used; // reduce the arg count
	argv += args_used; // move on to the next arg value

	Summation();
	printf("\n");

	return 0;
}
