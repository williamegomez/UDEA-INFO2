#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <vector>
#include <iostream>

using namespace std;

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
//        serial.write("k\n");  //Enviar un caracter a Arduino para saber que debe iniciar la transmisión
//        char message[1024];   //Número máximo de caracteres
//        int l = 0;
//        if(serial.waitForReadyRead(100)){
//            //Data was returned
//            l = serial.readLine(message,100); //Leer toda la línea que envía arduino
//            qDebug()<<"Response: "<<message;
//        }else{
//            //No data
//            qDebug()<<"Time out";
//        }
        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        //Asincrona
        bool leyendo = false;
        char data;
        int l = 0;
        vector<int> v;

        while(1){
            if(serial.waitForReadyRead(150)){
                //Data was returned
                l = serial.read(&data,1);
                qDebug()<<"Response: "<< data;

                if (data == '-' && leyendo == true){
                   break;
                }
                if(leyendo == true){
                    v.push_back(data);
                }
                if (data == '-'){
                    leyendo = true;
                }
            }else{
                //No data
                qDebug()<<"Time out";
            }
        }

        cout << endl;

        for(int i=0; i<v.size(); i++){
            cout << char(v[i]);
        }
        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        serial.close();
    }else{
        qDebug()<<"Serial COM3 not opened. Error: "<<serial.errorString();
    }
    return 0;
}
