#include "User.h"
#include <iostream>

User::User(std::string newName, std::string newJob, int newCash)
    : name(newName), job(newJob), cash(newCash) {}

std::string User::GetJob() {
    return job;
}

void User::SetJob(std::string newJob) {
    job = newJob;
}

void User::AddCash(int amount) {
    cash += amount;
    jsonData["cash"] = cash;
}