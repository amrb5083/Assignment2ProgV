#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

struct STUDENT_DATA
{
	std::string firstName;
	std::string lastName;
};

std::string trim(const std::string& str) {
	size_t first = str.find_first_not_of(' ');
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}
int main()
{
	// read from file 
	std::string text;
	std::ifstream myFile("StudentData.txt");

	std::vector<STUDENT_DATA> students;

	while (std::getline(myFile, text))
	{
		STUDENT_DATA student;
		size_t commaPos = text.find(',');

		if (commaPos != std::string::npos)
		{
			student.lastName = trim(text.substr(0, commaPos));
			student.firstName = trim(text.substr(commaPos + 2));

			students.push_back(student);
		}
	}

	for (auto& student : students)
	{
		std::cout << student.firstName << ", " << student.lastName << std::endl;
	}

	myFile.close();
	return 1;
}
