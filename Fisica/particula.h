#ifndef PARTICULA_H
#define PARTICULA_H


class Particula
{
private:
    float pX, pY, vX, vY, aX, aY;

public:
    Particula();
    Particula(float x0 = 0, float y0 = 0, float vx0 = 0, float vy0= 0);
    float getPX() const;
    void setPX(float value);
    float getPY() const;
    void setPY(float value);
    float getVX() const;
    void setVX(float value);
    float getVY() const;
    void setVY(float value);
    float getAX() const;
    void setAX(float value);
    float getAY() const;
    void setAY(float value);

    void setAcceleration(float ax, float ay);

    void updatePosition(float delta);

    void printCurrentPosition();
};

#endif // PARTICULA_H
