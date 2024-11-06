#pragma once

#include <string>
#include <iostream>
#include <json/json.h>

class User
{
	private:
		std::string job;

	public:
		int cash;
		std::string name;
		Json::Value jsonData;

		User(std::string newName, std::string newJob, int newCash);
		std::string GetJob();
		void SetJob(std::string newJob);
		void AddCash(int amount);

		static User GetUser();
};