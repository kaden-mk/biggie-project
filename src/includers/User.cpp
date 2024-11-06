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
    std::cout << "Current cash: " << cash << std::endl;
    cash += amount;
    std::cout << "Updated cash: " << cash << std::endl;

    jsonData["cash"] = cash;
}

User& User::GetUser() {
    static User instance;
    return instance;
}