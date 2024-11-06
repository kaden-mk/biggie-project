#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <json/json.h>

#include "User.h"
#include "Job.h"
#include "Jobs.cpp"

int main()
{
	User user("NULL", "Unemployed", 100);
	bool admin = false;

	std::filesystem::path dir = "data/profile";

	// wow very long code of checking if a directory exists and admin :p
	if (!std::filesystem::exists(dir))
	{
		std::string name;

		std::cout << "Welcome!\n";
		std::cout << "What is your name: ";
		std::cin >> name;

		if (name == "admin")
		{
			// this is used for debugging, and there will be an admin panel or something like that
			std::string password;

			std::cout << "If you really are an admin, what's the password buckoo.\n";
			std::cin >> password;

			if (password != "SigmaMeal")
				return 1;
		}

		// creates directories
		std::cout << "Creating directories\n";
		std::filesystem::create_directories(dir);
		
		std::ofstream file("data/profile/profile.json");
		if (!file.is_open()) {
			std::cerr << "Error creating profile file.\n";
			return 1;
		}

		// default data
		Json::Value json;
		json["name"] = name;
		json["job"] = "jan";
		json["cash"] = 100;

		file << json;

		file.close();
	}

	std::ifstream profile("data/profile/profile.json");
	if (!profile.is_open()) {
		std::cerr << "Error opening profile file.\n";
		return 1;
	}
	
	Json::Value jsonData;
	profile >> jsonData;

	user.jsonData = jsonData;

	admin = jsonData["name"].asString() == "admin";

	std::cout << "Welcome " << jsonData["name"].asString() << std::endl;

	bool exited = true;

	runJobRegistration();

	// main game, do i have any idea on how to make this look better? nope.
	while (exited)
	{
		int input;

		std::cout << "What would you like to do?\n";
		std::cout << "1. Work, 2. Find a new job, 3. Exit\n";
		std::cin >> input;

		switch (input)
		{
			case 1:
			{
				/*
					Plan: use a job class and like create dynamic work styles for every place.
					Inside the userdata, it'll add a +1 once you finish your job.
					Allowing you to apply for better jobs and get higher wages.
					There can be random events with your job allowing you to make a huge amount of money if like a special guest comes in or whatever.
				*/

				std::string jobName = user.jsonData["job"].asString();

				// this will probably be confusing for people that didnt apply for janitor yet but oh well
				if (!Job::IsJobRegistered(jobName)) {
					std::cout << "This job isn't registered!\n";
					break;
				}
					
				Job::StartWork(jobName);

				break;
			}

			case 2:
				{
					/*
						Plan: You have to have progressed with certain elements in a specific job to be able to unlock another job.
						Also it will cost money depending on the job.
						The starter job is janitor, costing 100 dollars, and generates 75-150 every session or whatever of working.
					*/

					break;
				}
			case 3:
				exited = false;
				break;
		}
	}
	
	profile.close();

	return 0;
}