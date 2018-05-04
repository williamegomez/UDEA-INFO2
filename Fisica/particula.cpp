#include "particula.h"
#include <iostream>

using namespace std;

float Particula::getPX() const
{
    return pX;
}

void Particula::setPX(float value)
{
    pX = value;
}

float Particula::getPY() const
{
    return pY;
}

void Particula::setPY(float value)
{
    pY = value;
}

float Particula::getVX() const
{
    return vX;
}

void Particula::setVX(float value)
{
    vX = value;
}

float Particula::getVY() const
{
    return vY;
}

void Particula::setVY(float value)
{
    vY = value;
}

float Particula::getAX() const
{
    return aX;
}

void Particula::setAX(float value)
{
    aX = value;
}

float Particula::getAY() const
{
    return aY;
}

void Particula::setAY(float value)
{
    aY = value;
}

void Particula::setAcceleration(float ax, float ay)
{
    this->setAX(ax);
    this->setAY(ay);
}

void Particula::updatePosition(float delta)
{
    this->setVX(this->getVX() + this->getAX()*delta);
    this->setVY(this->getVY() + this->getAY()*delta);

    this->setPX(this->getPX() + this->getVX()*delta + this->getAX()*delta*delta/2.0);
    this->setPY(this->getPY() + this->getVY()*delta + this->getAY()*delta*delta/2.0);
}

void Particula::printCurrentPosition()
{
    cout << this->getPX() << " ; " << this->getPY() << endl;
}

Particula::Particula()
{

}

Particula::Particula(float x0, float y0, float vx0, float vy0)
{
    this->setPX(x0);
    this->setPY(y0);
    this->setVX(vx0);
    this->setVY(vy0);
}
