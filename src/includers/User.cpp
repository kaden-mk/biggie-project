#include "User.h"
#include <vector>
#include <algorithm>

User::User(std::string newName, std::string newJob, int newCash)
{
	name = newName;
	SetJob(newJob);
	cash = newCash;
}

std::string User::GetJob()
{
	return job;
}

// pls somehow improve this by checking to see if a job exists, should be easy?

void User::SetJob(std::string newJob)
{
	job = newJob;
}