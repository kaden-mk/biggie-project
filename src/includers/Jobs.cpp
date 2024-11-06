#include <Job.h>
#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
#include <json/json.h>
#include <User.h>

// registers every job, alongside their data and all that blabbering.
// this is meant to be a huge script sooooo

// structs

// for janitor
struct JanitorLocation {
	std::string name;
	int payment;
	int duration;
};

// arrays

std::string locations[20] = {
	"FBI Office",
	"Company Headquarters",
	"Bathrooms",
	"School",
	"Hospital",
	"Police Station",
	"University Library",
	"Shopping Mall",
	"Airport Terminal",
	"City Park",
	"Subway Station",
	"Movie Theater",
	"Amusement Park",
	"Hotel Lobby",
	"Concert Hall",
	"Sports Stadium",
	"Convention Center",
	"Train Station",
	"Museum",
	"The Moon"
};

static void runJobRegistration() {
	std::srand(static_cast<unsigned>(std::time(0)));

	// job registration

	Job jan("jan", "Janitor", 75, 125);
	jan.SetStartWorkFunction([]() {
		/*
			The idea for janitor is very simple.
			You get 3 different locations, each of them giving you a random payment amount.
			The higher the payment amount, the longer the duration is.
			There should be a neat balance between every location.
			For example, it could go from 50 to 100 to 125 and they would all have very different duration lengths
		*/

		std::cout << "Where would you like to work?\n";

		int numLocations = sizeof(locations) / sizeof(locations[0]);
		int input;
		std::vector<JanitorLocation> locationsSelected;

		for (int i = 1; i < 4; ++i) {
			int randomIndex = std::rand() % numLocations;

			JanitorLocation selectedLocation;
			selectedLocation.name = locations[randomIndex];
			selectedLocation.payment = Job::GetJobWageByName("jan");
			selectedLocation.duration = static_cast<int>(selectedLocation.payment * 0.25);

			locationsSelected.push_back(selectedLocation);

			std::cout << i << ". " << selectedLocation.name
				<< ": Income: $" << selectedLocation.payment
				<< ", Duration: " << selectedLocation.duration
				<< " seconds.\n";
		}

		while (true) {
			std::cout << "Enter which location you would like to choose.\n";
			std::cin >> input;

			// checks to see if the input is from 1-3 aka the amount of locations the person is able to choose

			if (input >= 1 && input <= 3) {
				JanitorLocation location = locationsSelected[input - 1];

				std::cout << "You selected the location: '" << location.name << "'.\n";

				int duration = location.duration;

				// loops through the duration, updates every second

				for (int i = 0; i < duration; ++i) {
					int progress = (i + 1) * 100 / duration;
					std::cout << "\rProgress: [" << std::string(progress, '#') << std::string(100 - progress, ' ') << "] " << progress << "%";

					Sleep(1000);

					std::cout.flush();
				}

				std::cout << "\nJob successfully finished! You earned: $" << location.payment << std::endl;

				// give money time!!
				User& user = User::GetUser();
				user.AddCash(location.payment);

				break;
			}
			else {
				std::cout << "Invalid selection. Please enter a number between 1 and 3.\n";
			}
		}
	});
	Job::RegisterJob(jan);

	return;
}