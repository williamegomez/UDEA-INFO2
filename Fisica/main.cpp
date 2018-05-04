#include <iostream>
#include "particula.h"
#include "math.h"

using namespace std;

float distanceBetweenParticles(Particula particulax,Particula particulay) {
    return sqrt(pow(particulax.getPX()-particulay.getPX(),2)+pow(particulax.getPY()-particulay.getPY(),2));
}

int main()
{
    Particula particula1(0,10);
    Particula particula2(20,10);

    particula1.printCurrentPosition();

    float deltat = 0.1;
    for(int i=0; i<100; i++){
        float tiempo = deltat*i;

        float distance = distanceBetweenParticles(particula1,particula2);

        float F12 = 10 * distance12;
        float F21 = 10 * distance21;
        float F13 = 10 * distance13;
        float F31 = 10 * distance31;

        particula1.setAcceleration(0,(F21 + F31)/particula1.getMasa());

        particula1.updatePosition(deltat);
        particula2.updatePosition(deltat);
        particula3.updatePosition(deltat);

        particula1.printCurrentPosition();
    }

    return 0;
}
