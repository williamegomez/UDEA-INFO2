#include <iostream>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>

using namespace std;

int main()
{
    QSerialPort *arduino = new QSerialPort;
    arduino->setPortName("ttyACM1");
    arduino->open(QIODevice::ReadWrite);
    arduino->setDataBits(QSerialPort::Data8);
    arduino ->setBaudRate(QSerialPort::Baud9600);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    qDebug() << "Serial is" << arduino->isOpen() << arduino->isWritable();
    arduino->waitForReadyRead(1000);

    if (arduino->isOpen() && arduino->isWritable())
    {
        qDebug() << "Serial is open";
        QByteArray output;

        arduino->write("k\n");
        arduino->waitForBytesWritten(100);
        arduino->waitForReadyRead(100);

        if(arduino->bytesAvailable()>0){
            qDebug() << "Bytes por leer";
            qDebug() << arduino->read(10);
        }
    } else {
        qDebug() << "Error opening";
    }
    return 0;
}
