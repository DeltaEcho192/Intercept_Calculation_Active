//Created By DeltaEcho192 on 26/03/2019

//This Program Calculates the Missile adjustment angle, when the heading and the velocity of the target Changes.

#include <cmath>
#include <iostream>

using namespace std;

inline double VelAndHeadChange(double oldHeading, double oldMissileAng,double headingChange, double DistanceLeftOrignal, double oldDirectDist,double oldspeed, double newspeed)
{

    double B = 0;
    double E = 0;
    double h = 0;
    double a = 0;
    double I = 0;
    double G = 0;
    double b = 0;
    double timeleft = 0;
    double m = 0;
    double q = 0;
    double j = 0;
    double g = 0;
    double M = 0;
    double output = 0;
    double pi = 3.1415;

    //Calculates the remaining angle in orignal Triangle
    B = pi - (oldMissileAng + oldHeading);
    //Calculates the remaining angle in second Triangle.
    E = pi - (headingChange + B);
    //Further Away length where target will intercept path.
    h = (DistanceLeftOrignal / sin(E)) * sin(headingChange);
    //Closer length where target will intercept path.
    a = oldDirectDist - h;
    //Angle Calulation of third outside triangle.
    I = asin((sin(E)/oldDirectDist) * a);
    //Calculates the Anlge to new intercept point fromm orignal heading.
    G = pi - (I + E);
    //Length after target intercepts orignal path to new intercept point.
    g = (oldDirectDist/sin(E)) * sin(G);
    //Distance before the intercept line.
    b = (h/sin(headingChange)) * sin(B);
    timeleft = (b + g) / oldspeed;
    //The distance that is lost or gained by the speed change.
    m = newspeed * timeleft;
    //Calculation Varible
    q = g-m;
    //Direct Distance to new Intercept point.
    j = sqrt((pow(a,2)+pow(q,2)) - (2 * a * q * cos(E)));
    //The Ofset angle of by the Speed Change.
    M = asin((sin(I)/j * m));

    if(oldspeed > newspeed)
    {
        output = G - M;
    }
    else
    {
        output = G + m;
    }

    return output;
    


}