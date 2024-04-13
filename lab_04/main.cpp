//������� 1

//#include <iostream>
//#include <vector>
//#include <ctime>
//
//#define ERROR01 "ENRER: ���������� ������� ��������� 10000"
//#define ERROR02 "ENRER: ������������ ��������"
//
//int randomNumberFunction(int iMIN, int iMAX);
//
//int main() {
//
//	setlocale(LC_ALL, "ru");
//	srand((unsigned)time(NULL));
//
//	int amountProducts;
//
//	std::vector<int> check;
//
//	try
//	{
//		std::cout << "������� ���������� �������:";
//		std::cin >> amountProducts;
//
//		if (amountProducts > 10000) { throw std::exception(ERROR01); }
//		if (amountProducts <= 0) { throw std::exception(ERROR02); }
//
//	}
//	catch (const std::exception& ex)
//	{
//		std::cout << ex.what() << std::endl;
//	}
//
//
//	for (int i = 0; i < amountProducts; i++)
//	{
//		check.push_back(randomNumberFunction(1, 100));
//	}
//
//	std::cout << "���� �� ������:";
//	for (auto products : check)
//	{
//		std::cout << products << ' ';
//	}
//	std::cout << std::endl;
//
//
//	std::vector<int> final�heck;
//	int idMax{}, idMin{}, id{};
//
//	while (!check.empty())
//	{
//		id = 0;
//		idMin = 0;
//		idMax = 0;
//
//		for (auto products : check)
//		{
//			if (check.at(idMax) < products)
//			{
//				idMax = id;
//			}
//			++id;
//		}
//
//		final�heck.push_back(check.at(idMax));
//		check.erase(check.begin() + idMax);
//		id = 0;
//
//		if (check.empty()) { break; }
//
//		for (auto products : check)
//		{
//			if (check.at(idMin) > products)
//			{
//				idMin = id;
//			}
//			++id;
//		}
//
//		final�heck.push_back(check.at(idMin));
//		check.erase(check.begin() + idMin);
//	}
//
//	std::cout << "������� ���������� �������:";
//	for (auto products : final�heck)
//	{
//		std::cout << products << ' ';
//	}
//	std::cout << std::endl;
//
//	int maxCheck{};
//
//	for (int i = 0; i < final�heck.size(); )
//	{
//		maxCheck += final�heck.at(i);
//		i += 2;
//	}
//
//	std::cout << "����� ������������� ����: " << maxCheck << std::endl;
//
//	return 0;
//}
//
//int randomNumberFunction(int iMIN, int iMAX) {
//
//	int number = (int)(((double)rand() / (double)RAND_MAX) * (iMAX - iMIN) + iMIN);
//	return number;
//}

// ������� 2

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define ERROR01 "ENRER: ���������� ���������� ��������� 10000"
#define ERROR02 "ENRER: ������������ ��������"

int randomNumberFunction(int iMIN, int iMAX);
void sortBubble(std::vector<int>& list);

void creationDegrees(const int& value, std::vector<int>& DegreeID, std::vector<int>& participants);

struct person
{
	int id;
	int points;
};

int main() {

	setlocale(LC_ALL, "ru");

	int numberParticipants{};

	try
	{
		std::cout << "������� ����� ��������� ���������:";
		std::cin >> numberParticipants;

		if (numberParticipants > 10000) { throw std::exception(ERROR01); }
		if (numberParticipants <= 0) { throw std::exception(ERROR02); }

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::vector<int> participants, firstDegreeID, secondDegreeID, thirdDegreeID;
	

	for (int i = 0; i < numberParticipants; i++)
	{
		participants.push_back(randomNumberFunction(1, 100));
	}

	std::cout << "���������� ���������� ���������: ";
	for (auto person : participants)
	{
		std::cout << person << ' ';
	}
	std::cout << std::endl;

	std::vector<int> maxPoints = participants;

	for (int i = 0; i < maxPoints.size(); ++i) {
		for (int j = i + 1; j < maxPoints.size(); ) {
			if (maxPoints[i] == maxPoints[j]) {
				maxPoints.erase(maxPoints.begin() + j);
			}
			else {
				++j;
			}
		}
	}

	sortBubble(maxPoints);
	
	while (maxPoints.size() != 3) { maxPoints.pop_back(); }
	
	creationDegrees(maxPoints.at(0), firstDegreeID, participants);
	creationDegrees(maxPoints.at(1), secondDegreeID, participants);
	creationDegrees(maxPoints.at(2), thirdDegreeID, participants);

	std::cout << "---------���������� ���������---------" << std::endl;
	std::cout << "����� ���������� �������:" << firstDegreeID.size() + secondDegreeID.size() + thirdDegreeID.size() << std::endl;
	std::cout << "���������� �������� ������ �������:" << firstDegreeID.size() << std::endl;
	std::cout << "ID �����, ������� �������� ������ ������ �������: ";
	for (auto persone : firstDegreeID) { std::cout << persone + 1 << ' '; }
	std::cout << "( " << maxPoints.at(0) << " )" << std::endl;
	std::cout << "���������� �������� ������ �������:" << secondDegreeID.size() << std::endl;
	std::cout << "ID �����, ������� �������� ������ ������ �������: ";
	for (auto persone : secondDegreeID) { std::cout << persone + 1 << ' '; }
	std::cout << "( " << maxPoints.at(1) << " )" << std::endl;
	std::cout << "���������� �������� ������ �������:" << thirdDegreeID.size() << std::endl;
	std::cout << "ID �����, ������� �������� ������ ������ �������: ";
	for (auto persone : thirdDegreeID) { std::cout << persone + 1 << ' '; }
	std::cout << "( " << maxPoints.at(2) << " )" << std::endl;

	return 0;
}

int randomNumberFunction(int iMIN, int iMAX) {

	int number = (int)(((double)rand() / (double)RAND_MAX) * (iMAX - iMIN) + iMIN);
	return number;
}

void sortBubble(std::vector<int>& list) {

	int n = list.size();
	bool swapped;

	for (int i = 0; i < n - 1; ++i) {
		swapped = false;
		for (int j = 0; j < n - i - 1; ++j) {
			if (list[j] < list[j + 1]) {
				std::swap(list[j], list[j + 1]);
				swapped = true;
			}
		}
		
		if (!swapped) {
			break;
		}
	}
}

void creationDegrees(const int& value, std::vector<int>& DegreeID, std::vector<int>& participants)
{
	for (int i = 0; i < participants.size(); i++)
	{
		if (participants.at(i) == value)
		{
			DegreeID.push_back(i);
		}
	}

}