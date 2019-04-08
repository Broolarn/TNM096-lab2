// lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <algorithm>

struct classRoom
{
	std::string name;

	std::string times[8];
	
	bool full;
};


int main()
{
	classRoom TP51 = { "TP51" };
	classRoom SP34 = { "SP34" };
	classRoom K3 = {"K3"};
	/*
	int am9 = 9;
	int am10 = 10;
	int am11 = 11;
	int pm12 = 12;	
	int pm1 = 13;
	int pm2 = 14;
	int pm3 = 15;
	int pm4 = 16;
	*/

	std::string Classes = "MT101 MT102 MT103 MT104 MT105 MT106 MT107 MT201 MT202 MT203 MT204 MT205 MT206 MT301 MT302 MT303 MT304 MT401 MT402 MT403 MT501 MT502";
	std::string arr[22];
	int i = 0;
	std::stringstream ssin(Classes);
	while (ssin.good()&& i < 22) {
		ssin >> arr[i];
		++i;
	}
	
	std::random_shuffle(std::begin(arr), std::end(arr));
	int classint = 0;
	int timeint = 0;
	for (i = 0; i < 22; i++) {
		std::cout << arr[i] << std::endl;
		
		
		if (classint% 3 == 0) { // delbart med 3 // 0,3,6,9
			TP51.times[timeint] = arr[i];
			//TP51
		}
		else if (classint % 3 == 1) { // 1 kvar // 1 ,4,7,10
			//SP34	
			SP34.times[timeint] = arr[i];
		}
		else { // 2 kvar // 2 ,5,8,11
			//K3
			K3.times[timeint] = arr[i];
			timeint++;
		}
		
		classint++;
	}

	std::cout << "      TP51, SP34, K3"<<std::endl;
	for(int l = 0; l < 8 ; l++)
		{
		if (l == 0)
			std::cout << (l + 9) << "    " << TP51.times[l] << "," << SP34.times[l] << "," << K3.times[l] << std::endl;
		
		else
			std::cout << (l + 9) << "   " << TP51.times[l] << "," << SP34.times[l] << "," << K3.times[l] << std::endl;

		}


    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
