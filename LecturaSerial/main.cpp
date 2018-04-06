#include <iostream>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>
using namespace std;

int main()
{
    QSerialPort serial;

    serial.setPortName("ttyACM0"); //Poner el nombre del puerto, probablemente no sea COM3

    if(serial.open(QIODevice::ReadWrite)){
        serial.setBaudRate(QSerialPort::Baud9600); //Configurar la tasa de baudios

        char data;
        int l = 0;


        while(1){
            cout <<"Bytes of serial: "<<serial.bytesAvailable() << endl;
            serial.write("k\n");
            serial.waitForBytesWritten(1000);
            serial.waitForReadyRead(1000);

            while(serial.bytesAvailable()>0){
                serial.waitForReadyRead(1000);
                serial.read(&data,1);
                cout << data;
            }
            cout << endl;
        }

    }
    else{
        cout << "Error al abrir el puerto";
    }
    return 0;
}
