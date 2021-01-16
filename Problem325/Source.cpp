// This problem was asked by Jane Street.
//
// The United States uses the imperial system of weightsand measures, which means that there are many different, seemingly arbitrary units to measure distance.
// There are 12 inches in a foot, 3 feet in a yard, 22 yards in a chain, and so on.
//
// Create a data structure that can efficiently convert a certain quantity of one unit to the correct amount of any other unit.
// You should also allow for additional units to be added to the system.

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

enum class Units
{
	Inch=1,
	Centimeter=2,
	Foot=3,
	Yard=4,
	Chain=5
};

// extendible factors map - can be stored in db, file etc.
std::map<Units, float> UnitToInchFactors =
{
	{Units::Inch, 1.00f},
	{Units::Centimeter, 1.00 / 2.54}, //cm for fun :)
	{Units::Foot, 12.00f}, //12 inches in a foot
	{Units::Yard, 3.00 * 12.00f}, //3 feet in a yard
	{Units::Chain, 22.00 * 3.00 * 12.00f}, //22 yards in a chain
};

class Solution
{
private:
	
public:
	float Solve(float number, Units sourceUnit, Units destinationUnit)
	{
		return number * UnitToInchFactors[sourceUnit]/UnitToInchFactors[destinationUnit];
	}
};

int main()
{
	Solution solution;
	auto result = solution.Solve(12, Units::Inch, Units::Foot);	
	return 0;
}
