#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

int main(){

    QSerialPort serial;
    serial.setPortName("ttyUSB0"); //Poner el nombre del puerto, probablemente no sea COM3

    if(serial.open(QIODevice::ReadWrite)){
        //Ahora el puerto seria está abierto
        if(!serial.setBaudRate(QSerialPort::Baud9600)) //Configurar la tasa de baudios
            qDebug()<<serial.errorString();

        if(!serial.setDataBits(QSerialPort::Data8))
            qDebug()<<serial.errorString();

        if(!serial.setParity(QSerialPort::NoParity))
            qDebug()<<serial.errorString();

        if(!serial.setStopBits(QSerialPort::OneStop))
            qDebug()<<serial.errorString();

        if(!serial.setFlowControl(QSerialPort::NoFlowControl))
            qDebug()<<serial.errorString();

        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        //Sincrona

        serial.waitForReadyRead(3000);
        serial.write("k\n");  //Enviar un caracter a Arduino para saber que debe iniciar la transmisión
        char message[1024];   //Número máximo de caracteres
        int l = 0;
        if(serial.waitForReadyRead(10000)){
            //Data was returned
            l = serial.readLine(message,100); //Leer toda la línea que envía arduino
            qDebug()<<"Response: "<<message;
        }else{
            //No data
            qDebug()<<"Time out";
        }

        serial.close();
    }else{
        qDebug()<<"Serial COM3 not opened. Error: "<<serial.errorString();
    }
    return 0;
}
