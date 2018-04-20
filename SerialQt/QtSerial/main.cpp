#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <iostream>

using namespace std;

int main(){

    QSerialPort serial;
    serial.setPortName("ttyACM0"); //Poner el nombre del puerto, probablemente no sea COM3

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

        while(1){
        serial.write("k");  //Enviar un caracter a Arduino para saber que debe iniciar la transmisión
        char message[1024];   //Número máximo de caracteres

      //  cout << serial.readLine(message,100); //Leer toda la línea que envía arduino
}
        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        //Asincrona
//        char flat = 1;
//        char data;
//        int l = 0;
//        while(flat){
//            if(serial.waitForReadyRead(150)){
//                //Data was returned
//                l = serial.read(&data,1);
//                qDebug()<<"Response: "<<data;
//                if(data == 'k') flat = 0; //Finalice transmisión si recibe algo conocido, en este caso un char 'k'
//            }else{
//                //No data
//                qDebug()<<"Time out";
//            }
//        }
//        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//        serial.close();
    }else{
        qDebug()<<"Serial COM3 not opened. Error: "<<serial.errorString();
    }
    return 0;
}
