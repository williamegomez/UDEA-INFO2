#include <iostream>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>

using namespace std;

void codificar(string cod) {

}


int main()
{
    QSerialPort *arduino = new QSerialPort;
    arduino->setPortName("ttyACM0");
    arduino->open(QIODevice::ReadWrite);
    arduino->setDataBits(QSerialPort::Data8);
    arduino ->setBaudRate(QSerialPort::Baud115200);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    qDebug() << "Serial is" << arduino->isOpen() << arduino->isWritable();
    arduino->waitForReadyRead(1000);

    if (arduino->isOpen() && arduino->isWritable())
    {
        qDebug() << "Serial is open";
        QByteArray output;

        arduino->write("k");
        arduino->waitForBytesWritten(100);

        arduino->waitForReadyRead(1000);

        while(arduino->bytesAvailable()>0){

            if(arduino->bytesAvailable()>0){
                qDebug() << "Bytes por leer";
                string arrayS = string(arduino->read(100));
                //PEGAR CODIGO DE CODIFICACION

                cout << arrayS;
            }
            arduino->waitForReadyRead(1000);
        }
    } else {
        qDebug() << "Error opening";
    }
    return 0;
}
