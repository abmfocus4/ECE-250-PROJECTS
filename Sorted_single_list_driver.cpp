#include <iostream>
#include <cstring>
#include "Tester.h"
#include "Sorted_single_list_tester.h"
#include "Single_node_tester.h"

int main( int argc, char *argv[] ) {
	if ( argc > 2 ) {
		std::cerr << "Expecting at most one command-line argument" << std::endl;

		return -1;
	}

	std::cout << "Starting Test Run" << std::endl;

	if ( argc == 1 || !std::strcmp( argv[1], "int" ) ) {
		if ( argc == 1 ) {
			std::cerr << "Expecting a command-line argument of either 'int' or 'double', but got none; using 'int' by default." << std::endl;
		}

		Sorted_single_list_tester<int> tester;

		tester.run();
	} else if ( !std::strcmp( argv[1], "double" ) ) {
		Sorted_single_list_tester<double> tester;

		tester.run();
	}

	std::cout << "Finishing Test Run" << std::endl;

	return 0;
}
