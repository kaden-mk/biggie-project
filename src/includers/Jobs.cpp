#include <Job.h>
#include <iostream>

// registers every job, alongside their data and all that blabbering.
// this is meant to be a huge script sooooo

void runJobRegistration() {
	Job jan("jan", "Janitor", 50, 125);

	std::cout << "test";

	jan.SetStartWorkFunction([]() {
		std::cout << "Janitor starts cleaning..." << std::endl;
	});

	return;
}