#pragma once

#include <string>
#include <iostream>

class User
{
	private:
		std::string job;

	public:
		int cash;
		std::string name;

		User(std::string newName, std::string newJob, int newCash);
		std::string GetJob();
		void SetJob(std::string newJob);
};