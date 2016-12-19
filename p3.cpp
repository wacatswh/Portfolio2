/*
 * p3.cpp
 *
 *  Created on: 4/11/2015
 *      Author: dlynazmi
 */

#ifndef P3_CPP_
#define P3_CPP_
#include <string>
#include <fstream>
#include <vector>
#include "posn.h"
#include "p3.h"

using namespace P3;
using namespace std;
namespace NMEA
{



    /* p3a processes a logfile (passed as string parameter logFilename)
     * and generates a std::vector of std::string where each element is a non-empty
     * The order of the vector elements must be the same as that of the file
     */
    std::vector<std::string> p3a(const std::string & logFilename){
    	std::ifstream logFile(logFilename);	
		std::string sentence;
		std::vector<std::string> logVec;

		while(logFile)
		{
			logFile >> sentence;
			if(p3b(sentence, "GPGLL"))
				logVec.push_back(sentence);
		}
	
		return logVec;
    }


    /* p3b returns true for a matching NMEA sentence (1st parameter) when the
     * sentence type in the first field matches the second parameter
     *
     *false otherwise
     */
    bool  p3b(const std::string & sentence, const std::string & typeToMatch){
		// return true if both parameters match, otherwise false
		return (sentence.find(typeToMatch) != std::string::npos);
    }

    /* p3c generates the p3::Posn object represented by its (NMEA) sentence parameter
     *
     */
    Posn p3c(const std::string & sentence){
		string lat, lon, token;
		string tempSentence = sentence; // copy sentence into temp
		char delimiter = ',';


		if (p3b(tempSentence, "GPGLL"))
		{
			int tokenFlag = 0;
			size_t pos = 0;

			while ((pos = tempSentence.find(delimiter)) != std::string::npos)
			{
				token = tempSentence.substr(0, pos);

				if (tokenFlag == 1)
					lat = token;

				if (tokenFlag == 3)
					lon = token;

				tempSentence.erase(0, pos + 1);
				tokenFlag++;
			}
		}

		Posn objPosn(lat, lon);
		return objPosn;
    }


    /* p3d returns the checksum of the sentence which is calculated by byte-wise XOR
     * reduction of the character codes of the sentence elements
     *
     */
    unsigned p3d(const std::string & sentence){
		unsigned checksum = 0;
		unsigned start = sentence.find('$');
		unsigned end = sentence.find('*');
		string checkSentence = sentence.substr(++start, --end); // substring between delimiter

		for (int i = 0; i < checkSentence.length(); i++)
			checksum ^= checkSentence[i]; // XOR every character in checkSentence into checksum

		return checksum; // return checksum in unsigned int form
    }

} //namespace


#endif /* p3_CPP_ */



