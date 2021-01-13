#define _USE_MATH_DEFINES //this is needed for the visual studio compile to allow you to use M_PI
#include <iostream>
#include <cmath>
//cmath includes the trig function and the arc trig functions.
//You can get more information about it here:
//http://www.cplusplus.com/reference/cmath/

using std::cout;
using std::cin;
using std::endl;

int main()
{
    /*
     * So we are going to enter two sides and an angle that is between them.
     * Then we will apply the law of cosines to compute the third side.
     * Once we have the third side we will compute the remaining missing
     * two angles using the law of sines.
     */

    double sideA, sideB, sideC; //these will be the sides.  Note they are doubles
    double angleC, angleA, angleB; //these will be the angles related to the sides.
    //Also note they are doubles


    /*
     * Law of sines has to have valid sides and angles, we can make that assumption
     * We are not going to worry about the ambiguous case where 2 triangles can be 
     * formed from the sides and angles given.  This case occurs when the height of
     * the triangle is less than the two given sides.  For right now, that's not 
     * what we are after and it's okay to skip that concern.
     */

    cout << "Enter a value for the first side: ";
    cin >> sideA;
    cout << "Enter a value for the adjacent side: ";
    cin >> sideB;
    cout << "Enter the angle between the two sides (in degrees): ";
    cin >> angleC;

    //Law of cosines goes here
	
	double convertFactor;
	convertFactor = M_PI / 180.0;
	sideC = sqrt( pow( sideA, 2.0 ) + pow( sideB, 2.0 ) - ( 2 * sideA * sideB * cos( angleC * convertFactor ) ) );

    //Now we know the third side...find the other angels using Law of Sines
	
	angleA = asin( ( sin(angleC * convertFactor) * sideA ) / sideC ) / convertFactor;
	angleB = asin( ( sin(angleC * convertFactor) * sideB ) / sideC ) / convertFactor;
	

    //Here's where we will do the output of our answers.
    cout << "Side A: " << sideA << endl;
    cout << "Side B: " << sideB << endl;
    cout << "Side C: " << sideC << endl;
    cout << "Angle A: " << angleA << endl;
    cout << "Angle B: " << angleB << endl;
    cout << "Angle C: " << angleC << endl;

}