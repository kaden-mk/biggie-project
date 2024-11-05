#include "Job.h"
#include <functional>
#include <random>
#include <iostream>

std::vector<Job> Job::RegisteredJobs;

Job::Job(std::string newName, std::string realName, int newMinWage, int newMaxWage)
    : name(newName), realName(realName), wageMin(newMinWage), wageMax(newMaxWage)
{
    RegisterJob(*this);
}

// this is supposed to give you a random amount depending on the job's minWage and maxWage
int Job::GetJobWageByName(const std::string& jobName)
{
    auto it = std::find_if(RegisteredJobs.begin(), RegisteredJobs.end(),
        [&jobName](const Job& job) {
            return job.name == jobName;
        });

    if (it != RegisteredJobs.end()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(it->wageMin, it->wageMax);

        return dis(gen);
    }

    return 0;
}

void Job::RegisterJob(const Job& job)
{
    RegisteredJobs.push_back(job);
}

bool Job::IsJobRegistered(const std::string& jobName)
{
    // no idea how to improve this, dont wanna use chatgpt
    auto it = std::find_if(RegisteredJobs.begin(), RegisteredJobs.end(),
        [&jobName](const Job& job) {
            return job.name == jobName;
        });

    if (it != RegisteredJobs.end())
        return true;

    return false;
}

void Job::StartWork(const std::string& jobName)
{
    auto it = std::find_if(RegisteredJobs.begin(), RegisteredJobs.end(),
        [&jobName](const Job& job) {
            return job.name == jobName;
        });

    if (it != RegisteredJobs.end()) {
        it->StartWorkFunction();
    }
    else {
        std::cout << "Job not found: " << jobName << std::endl;
    }
}

void Job::SetStartWorkFunction(const std::function<void()>& function)
{
    StartWorkFunction = function;
}