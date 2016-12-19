/*
 * p3.h
 *
 *  Created on: 4/11/2015
 *      Author: dlynazmi
 */


/*
 * p3.h
 * 2013 version - GLL sentences with minimum number of satelites with default parameter
 *      Author:rbh
 */

#ifndef P3_H_
#define P3_H_
#include <string>
#include <vector>
#include "posn.h"
using namespace P3;
//namespace P3
//{
    namespace NMEA
    {


        /* p3a processes a logfile (passed as string parameter logFilename)
         * and generates a std::vector of std::string where each element is a non-empty
         * line from the logfile
         * The logfile may contain a number of empty lines in any position
         *
         * The order of the vector elements must be the same as that of the file
         */
        std::vector<std::string> p3a(const std::string & logFilename);


        /* p3b returns true for a matching NMEA sentence (1st parameter) when the
         * sentence type in the first field matches the second parameter
         *
         *false otherwise
         */
        bool p3b(const std::string & sentence, const std::string & typeToMatch);


        /* p3c generates the p3::Posn object represented by its (NMEA) sentence parameter
         *
         */
        Posn p3c(const std::string & sentence);


        /* p3d returns the checksum of the sentence which is calculated by byte-wise XOR
         * reduction of the character codes of the sentence elements
         *
         */
        unsigned p3d(const std::string & sentence);
    }

//} //namespace





#endif /* P3_H_ */
