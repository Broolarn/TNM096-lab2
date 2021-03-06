// lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <random>

struct classRoom
{
	std::string name;

	std::string times[8];
	
	bool full;
};
struct currstate {
	classRoom myClassRooms[3];
	int conflicts;
	int preferences;
};
/*
def min_conflicts(csp, max_steps=100000):
	"""Solve a CSP by stochastic hillclimbing on the number of conflicts."""
	# Generate a complete assignment for all vars (probably with conflicts)
	csp.current = current = {}
	for var in csp.vars:
		val = min_conflicts_value(csp, var, current)
		csp.assign(var, val, current)
	# Now repeatedly choose a random conflicted variable and change it
	step=0
	for i in range(max_steps):
		step=step +1
		conflicted = csp.conflicted_vars(current)
		if not conflicted:
			print "solved with nr. iterations: ", step
			return current
		var = random.choice(conflicted)
		val = min_conflicts_value(csp, var, current)
		csp.assign(var, val, current)
	return None


	def min_conflicts_value(csp, var, current):
	"""Return the value that will give var the least number of conflicts.
	If there is a tie, choose at random."""
	return argmin_random_tie(csp.domains[var],
							 lambda val: csp.nconflicts(var, val, current))

	def nconflicts(self, var, val, assignment):
		"""The number of conflicts, as recorded with each assignment.
		Count conflicts in row and in up, down diagonals. If there
		is a queen there, it can't conflict with itself, so subtract 3."""
		n = len(self.vars)
		c = self.rows[val] + self.downs[var+val] + self.ups[var-val+n-1]
		if assignment.get(var, None) == val:
			c -= 3
		return c

*/
int nrofconflicts(currstate state)
{
	int i = 0;
	int rooms = 0;
	for (int m = 0; m < 8; m++) {
		//for (int n = 0; n < 3; n++) {
		rooms = m * 3;
		if (rooms < 21)
		{
			if (state.myClassRooms[0].times[m][2] == state.myClassRooms[1].times[m][2])
				i++;
			if (state.myClassRooms[0].times[m][2] == state.myClassRooms[2].times[m][2])
				i++;
			if (state.myClassRooms[1].times[m][2] == state.myClassRooms[2].times[m][2])
				i++;

		}
	}
	return i;
}
int nrofpreferences(currstate state) {
	int i = 0;
	int rooms = 0;
	char temp = 'M';
	for (int m = 0; m < 3; m++) {
		
		if (state.myClassRooms[m].times[0][0] == 'M')
			i++;
		if (state.myClassRooms[m].times[3][0] == 'M')
			i++;
		if (state.myClassRooms[m].times[7][0] == 'M')
			i++;
		if (state.myClassRooms[m].times[5][2] == '5')
			i++;
		if (state.myClassRooms[m].times[6][2] == '5')
			i++;

	}
	return i;
}

currstate min_conflicts(currstate csp,int max_steps = 100000) {
	
	currstate newState = csp;
	bool better = false;
	std::string temp;
	std::string temp2;
	int newConflict;
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 3; ++j)
		{
			temp2 = newState.myClassRooms[j].times[i];
			for (int m = 0; m < 8; ++m)
			{
				if (better) {
					better = false;
					break;
				}
					
				for (int n = 0; n < 3; ++n)
				{
					temp = newState.myClassRooms[n].times[m];
					
					newState.myClassRooms[n].times[m] = temp2;
					newState.myClassRooms[j].times[i] = temp;
					newConflict = nrofconflicts(newState);
					if (newConflict < csp.conflicts) {
						newState.conflicts = newConflict;
						csp = newState;
						better = true;
						break;
					}

					newState.myClassRooms[n].times[m] = temp;
					newState.myClassRooms[j].times[i] = temp2;
					// spara båda str värden

					// kollar 1 ändrade raden 

					// andra ändrade raden 

					// lägg till / ta bort fel i statet

					// byt tillbaka 

					// nästa iteration i loopen 
				}
			}

		}
	return csp;
};
currstate task4(currstate csp, int maxiterations = 100) {
	currstate bestyet = csp;
	currstate randstate;
	std::cout << "PREFERENCES"  << std::endl;

	for (int i = 0; i < maxiterations; i++)
	{
		randstate = csp;
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(std::begin(randstate.myClassRooms[0].times), std::end(randstate.myClassRooms[0].times), g);
		std::shuffle(std::begin(randstate.myClassRooms[1].times), std::end(randstate.myClassRooms[1].times), g);
		std::shuffle(std::begin(randstate.myClassRooms[2].times), std::end(randstate.myClassRooms[2].times), g);


		currstate newState = min_conflicts(randstate);
		newState.preferences = nrofpreferences(newState);
		if (newState.preferences < bestyet.preferences)
		{
			std::cout << newState.preferences << std::endl;
			bestyet = newState;
		}
			

	}
	return bestyet;

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
	std::string arr[24];
	int i = 0;
	std::stringstream ssin(Classes);
	while (ssin.good()&& i < 22) {
		ssin >> arr[i];
		++i;
	}
	arr[22] = "     ";
	arr[23] = "     ";

	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(std::begin(arr), std::end(arr),g);
	int classint = 0;
	int timeint = 0;
	for (i = 0; i < 24; i++) {
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


	currstate startstate = {TP51,SP34,K3};


	int nrc = nrofconflicts(startstate);
	startstate.conflicts = nrc;
	startstate.preferences = nrofpreferences(startstate);

	std::cout << startstate.conflicts << std::endl;
	std::cout << startstate.preferences << std::endl;
	currstate answer = min_conflicts(startstate);
	

	std::cout << "      TP51, SP34, K3"<<std::endl;
	for(int l = 0; l < 8 ; l++)
		{
		if (l == 0)
			std::cout << (l + 9) << "    " << answer.myClassRooms[0].times[l] << "," << answer.myClassRooms[1].times[l] << "," << answer.myClassRooms[2].times[l] << std::endl;
		
		else
			std::cout << (l + 9) << "   " << answer.myClassRooms[0].times[l] << "," << answer.myClassRooms[1].times[l] << "," << answer.myClassRooms[2].times[l] << std::endl;

		}

	std::cout << answer.conflicts << std::endl;

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
