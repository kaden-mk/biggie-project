#include "User.h"
#include <vector>
#include <algorithm>

User RegisteredUser;

User::User(std::string newName, std::string newJob, int newCash)
{
	name = newName;
	SetJob(newJob);
	cash = newCash;

	RegisteredUser = *this;
}

std::string User::GetJob()
{
	return job;
}

void User::SetJob(std::string newJob)
{
	job = newJob;
}

void User::AddCash(int amount)
{
	cash += amount;
	jsonData["money"] = cash;
}

User User::GetUser()
{
	return RegisteredUser;
}
