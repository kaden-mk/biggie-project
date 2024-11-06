#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <json/json.h>

class User
{
	private:
		std::string job;

	public:
		int cash;
		std::string name;
		Json::Value jsonData;

		User(std::string newName = "null", std::string newJob = "null", int newCash = 0);
		std::string GetJob();
		void SetJob(std::string newJob);
		void AddCash(int amount);

		static User& GetUser();
};