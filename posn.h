/*
 * posn.h
 *
 *  Created on: 4/11/2015
 *      Author: dlynazmi
 */



/*
 * posn.h - p3 version
 *
 *  cut down from gpxp.h
 *      Author: rbh
 */

#ifndef POSN_H_
#define POSN_H_
#include <string>

namespace P3
{

    typedef double angle;
    typedef unsigned seconds;
    typedef double metres;
    typedef double speed;


    class Posn
    {
            //v1.0
    public:
        Posn(const std::string & latSt, const std::string & lonSt,
             const std::string & eleSt = "0");
        Posn(angle lat, angle lon, angle ele = 0.0);
        metres distanceTo(const Posn &) const;
        std::string toString(bool includeElevation = true) const;
        angle lat() const;
        angle lon() const;
        angle ele() const;
        std::string eleAsString() const;

        bool isSamePlaceAs(const Posn &, const unsigned & maxSeparation) const;

    private:
        angle lat_;
        angle lon_;
        metres ele_;
        Posn()
        {
        }
        ; //default c'tor not available

    };

    metres distanceBetween(const Posn &, const Posn &);

    angle ArcInRadians( const Posn &, const Posn & );

} // namespace P3




#endif /* POSN_H_ */
