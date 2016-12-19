#include "p3.h"
#include "posn.h"
#include <iostream>
#include <vector>

using namespace NMEA;
using namespace std;

int main()
{
	vector<string> logVector;			
	logVector = p3a("log_files/p2_GLL.log");	

	/*
	cout << logVector.size() << endl;

	for (int i = 0; i < logVector.size(); i++)
	{
		cout << logVector[i] << endl;
	}
	*/

	// cout << p3d(logVector[0]) << endl;

	Posn obj = p3c(logVector[0]);
	cout << obj.lat() << ' ' << obj.lon() << endl;

	system("pause");
	return 0;
}
