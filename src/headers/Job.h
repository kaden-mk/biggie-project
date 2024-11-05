#pragma once

#include <vector>
#include <string>
#include <functional>

class Job
{
	private:
		std::string name;
		std::string realName;
		int wageMin;
		int wageMax;

		std::function<void()> StartWorkFunction;

		static std::vector<Job> RegisteredJobs;
	public:
		Job(std::string newName, std::string realName, int newMinWage, int newMaxWage);

		static int GetJobWageByName(const std::string& jobName);
		static void RegisterJob(const Job& job);
		static bool IsJobRegistered(const std::string& jobName);
		static void StartWork(const std::string& jobName);

		void SetStartWorkFunction(const std::function<void()>& func);

};