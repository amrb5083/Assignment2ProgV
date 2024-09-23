#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

 #define PRE_RELEASE
//#define STANDARD
struct STUDENT_DATA
{
	std::string firstName;
	std::string lastName;
	std::string email;
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
#ifdef PRE_RELEASE
	std::cout << "Currently running the Pre-release version" << std::endl;
	std::ifstream myFile("StudentData_Emails.txt");
#endif // PRE_RELEASE
#ifdef STANDARD
	std::cout << "Currently running the Standard version" << std::endl;
	std::ifstream myFile("StudentData.txt");
#endif // STANDARD


	std::vector<STUDENT_DATA> students;

	while (std::getline(myFile, text))
	{
		STUDENT_DATA student;
		size_t commaPos = text.find(',');

		if (commaPos != std::string::npos)
		{
			#ifdef STANDARD
			student.lastName = trim(text.substr(0, commaPos));
			student.firstName = trim(text.substr(commaPos + 2));
			#endif // STANDARD

			
			#ifdef PRE_RELEASE
			student.lastName = trim(text.substr(0, commaPos));
			student.firstName = trim(text.substr(commaPos + 2));
			student.email = trim(text.substr(commaPos + 3));
			#endif // PRE_RELEASE


			students.push_back(student);
		}
	}

	for (auto& student : students)
	{
#ifdef STANDARD
		std::cout << student.firstName << ", " << student.lastName << std::endl;
#endif // STANDARD

#ifdef PRE_RELEASE
		std::cout << student.firstName << ", " << student.lastName << ", " << student.email << std::endl;
#endif // PRE_RELEASE

	}

	myFile.close();
	return 1;
}
