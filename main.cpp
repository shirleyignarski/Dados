#include<stdlib.h>
#include<iostream>
using namespace std;
#include "rlutil.h"
#include "funciones.h"
#include <time.h>
#include<windows.h>

int main(void){
    srand(time(NULL));
    int i;
    char opc;
    const int nomTAM = 30;
    char nom[nomTAM];
    char nom1[nomTAM];
    char nom2[nomTAM];
    int cantRondas=0;
    int contRondas=1;
    int puntAcu=0;
    int puntAcu1=0;
    int puntAcu2=0;
    int dados[5];
    int puntosAp;
    int puntosAp1;
    int puntosAp2;
    int puntPart=0;
    int puntPart1=0;
    int puntPart2=0;
    int dadoMaxAnt;
    int puntosTiroPuntaje;
    int cantRondasPerdidas=0;
    int cantRondasCon0=0;
    bool hayMaximo=false;
    int puntMax;
    char nomMax[nomTAM];

    while(true){
        rlutil::cls();
        gotoxy(25,2);
        rlutil::setColor(15);
        for(i=1;i<70;i++)cout<<(char)205;
        gotoxy(25,2);
        cout<<(char)201;
        gotoxy(94,2);
        cout<<(char)187;

        for(i=3;i<19;i++){
            gotoxy(25,i);
            cout<<(char)186;

        }
        for(i=3;i<19;i++){
            gotoxy(94,i);
            cout<<(char)186;
        }

        rlutil::setBackgroundColor(5);
        gotoxy(53,5);
        cout<<"MENU DE INICIO"<<endl;
        rlutil::setBackgroundColor(0);
        gotoxy(26,7);
        for(i=1;i<69;i++)cout<<(char)205;
        gotoxy(25,7);
        cout<<(char)204;
        gotoxy(94,7);
        cout<<(char)185;
        gotoxy(50,9);
        cout << "A - Juego nuevo 1 jugador";
        gotoxy(50,11);
        cout << "B - Juevo nuevo 2 jugadores";
        gotoxy(50, 13);
        cout << "C - Modo Simulado";
        gotoxy(50,15);
        cout<<"D - Puntacion mas alta";
        gotoxy(50,17);
        cout<<"S - Salir del juego";
        gotoxy(25,19);
        for(i=1;i<70;i++)cout<<(char)205;
        gotoxy(25,19);
        cout<<(char)200;
        gotoxy(94,19);
        cout<<(char)188;
        gotoxy(50, 22);
        cout << "Ingresar opcion: ";
        cin >> opc;
        switch(opc){
            case 'A':
            case 'a':
            system("color 0D");
            rlutil::cls();
            recuadro();
            gotoxy(31,11);
            rlutil::setColor(14);
            cout<<"Ingresar nombre: ";
            rlutil::setColor(15);
            cin>>nom;
            gotoxy(31,13);
            pedirRondas(cantRondas);
            rlutil::cls();

            for(contRondas=1;contRondas<=cantRondas;contRondas++){
                    system("color 0D");
                recuadro();
                gotoxy(31,12);
                rlutil::setColor(14);
                cout<<"Ingresar cantidad de puntos a apostar: ";
                rlutil::setColor(15);
                cin>>puntosAp;
                rlutil::cls();
                recuadroJuego(nom, contRondas, puntPart);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 1:"<<endl;
                dadosAleatorios(dados,5,6);
                mostrarDados(dados,5);
                dadoMaxAnt=calculosDados(dados,5,puntAcu);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();

                system("color 0D");
                recuadroJuego(nom, contRondas, puntPart);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 2:"<<endl;
                dadosAleatorios(dados,4,6);
                mostrarDados(dados,4);
                dadoMaxAnt=calculosDados(dados,4,puntAcu);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();

                system("color 0D");
                recuadroJuego(nom, contRondas, puntPart);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 3:"<<endl;
                dadosAleatorios(dados,3,6);
                mostrarDados(dados,3);
                dadoMaxAnt=calculosDados(dados,3,puntAcu);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();

                recuadroJuego(nom, contRondas, puntPart);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 4:"<<endl;
                dadosAleatorios(dados,2,6);
                mostrarDados(dados,2);
                dadoMaxAnt=calculosDados(dados,2,puntAcu);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();

                recuadroJuego(nom, contRondas, puntPart);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 5:"<<endl;
                dadosAleatorios(dados,1,6);
                mostrarDados(dados,1);
                dadoMaxAnt=calculosDados(dados,1,puntAcu);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                system("color 0D");

                if(tieneTiroDePuntaje(puntAcu)){
                    recuadroJuego(nom, contRondas, puntPart);
                    recuadroTiroDePuntaje();
                    rlutil::setColor(15);
                    gotoxy(1,3);
                    cout<<"Tenes tiro de puntaje porque tienes mas de 20 puntos ("<<puntAcu<<" puntos)"<<endl;
                    puntosTiroPuntaje=hacerTiroDePuntaje(puntosAp,puntAcu);
                    puntPart+=puntosTiroPuntaje;
                    if(puntosTiroPuntaje==0){
                        cantRondasCon0++;
                    }
                    gotoxy(51,18);
                    cout<<"Ganaste "<<puntosTiroPuntaje<<" puntos extra"<<endl;
                    gotoxy(1,30);
                    system("pause");
                }
                else{
                    system("color 0D");
                    recuadroJuego(nom, contRondas, puntPart);
                    gotoxy(30,13);
                    rlutil::setColor(12);
                    cout<<"No entraste al tiro de puntaje y perdiste "<<puntosAp<<" puntos"<<endl;
                    cantRondasPerdidas++;
                    puntPart-=puntosAp;
                    gotoxy(1,30);
                    rlutil::setColor(15);
                    system("pause");
                }
                puntAcu=0;
                rlutil::cls();
            }
            recuadroFinal();
            system("color 0D");
            rlutil::setColor(15);
            gotoxy(32,10);
            cout<<nom<<" terminaste la partida con: "<<puntPart<<" puntos"<<endl;
            gotoxy(32,14);
            cout<<"Cantidad de rondas sin ganar puntos: "<<cantRondasCon0<<endl;
            gotoxy(32,18);
            cout<<"Cantidad de rondas con perdida de puntos: "<<cantRondasPerdidas<<endl;
            verificarMaximo(puntPart,nom,puntMax,nomMax,nomTAM,hayMaximo);
            cantRondasPerdidas=0;
            puntPart=0;
            cantRondasCon0=0;
            gotoxy(1,30);
            system("pause");
            break;

            case 'B':
            case 'b':
            rlutil::cls();
             system("color 0D");
            recuadro();
            gotoxy(31,10);
            rlutil::setColor(14);
            cout<<"Ingresar nombre del primer jugador: ";
            rlutil::setColor(15);
            cin>>nom1;
            gotoxy(31,12);
            rlutil::setColor(14);
            cout<<"Ingresar nombre del segundo jugador: ";
            rlutil::setColor(15);
            cin>>nom2;
            gotoxy(31,14);
            pedirRondas(cantRondas);
            rlutil::cls();
             system("color 0D");
            for(contRondas=1;contRondas<=cantRondas;contRondas++){
                recuadro();
                gotoxy(31,11);
                rlutil::setColor(14);
                cout<<"Ingresa la cantidad que va a apostar "<<nom1<<": ";
                rlutil::setColor(15);
                cin>>puntosAp1;
                gotoxy(31,13);
                rlutil::setColor(14);
                cout<<"Ingresa la cantidad que va a apostar "<<nom2<<": ";
                rlutil::setColor(15);
                cin>>puntosAp2;
                rlutil::cls();
                 system("color 0D");

                recuadroJuego(nom1, contRondas, puntPart1);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 1:"<<endl;
                dadosAleatorios(dados,5,6);
                mostrarDados(dados,5);
                dadoMaxAnt=calculosDados(dados,5,puntAcu1);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                system("color 0D");

                recuadroJuego(nom1, contRondas, puntPart1);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 2:"<<endl;
                dadosAleatorios(dados,4,6);
                mostrarDados(dados,4);
                dadoMaxAnt=calculosDados(dados,4,puntAcu1);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");

                recuadroJuego(nom1, contRondas, puntPart1);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 3:"<<endl;
                dadosAleatorios(dados,3,6);
                mostrarDados(dados,3);
                dadoMaxAnt=calculosDados(dados,3,puntAcu1);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");

                recuadroJuego(nom1, contRondas, puntPart1);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 4:"<<endl;
                dadosAleatorios(dados,2,6);
                mostrarDados(dados,2);
                dadoMaxAnt=calculosDados(dados,2,puntAcu1);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");

                recuadroJuego(nom1, contRondas, puntPart1);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 5:"<<endl;
                dadosAleatorios(dados,1,6);
                mostrarDados(dados,1);
                dadoMaxAnt=calculosDados(dados,1,puntAcu1);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");

                if(tieneTiroDePuntaje(puntAcu1)){
                    recuadroJuego(nom1, contRondas, puntPart1);
                    recuadroTiroDePuntaje();
                    rlutil::setColor(15);
                    gotoxy(1,3);
                    cout<<"Tenes tiro de puntaje porque tienes mas de 20 puntos ("<<puntAcu1<<" puntos)"<<endl;
                    puntosTiroPuntaje=hacerTiroDePuntaje(puntosAp1,puntAcu1);
                    puntPart1+=puntosTiroPuntaje;
                    gotoxy(51,18);
                    cout<<"Ganaste "<<puntosTiroPuntaje<<" puntos extra"<<endl;
                    system("pause");
                }
                else{
                    recuadroJuego(nom1, contRondas, puntPart1);
                    gotoxy(30,13);
                    rlutil::setColor(12);
                    cout<<"No entraste al tiro de puntaje y perdiste "<<puntosAp1<<" puntos"<<endl;
                    puntPart1-=puntosAp1;
                    rlutil::setBackgroundColor(15);
                    gotoxy(1,30);
                    system("pause");
                }
                puntAcu1=0;
                rlutil::cls();
                 system("color 0D");

                recuadroJuego(nom2, contRondas, puntPart2);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 1:"<<endl;
                dadosAleatorios(dados,5,6);
                mostrarDados(dados,5);
                dadoMaxAnt=calculosDados(dados,5,puntAcu2);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");

                recuadroJuego(nom2, contRondas, puntPart2);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 2:"<<endl;
                dadosAleatorios(dados,4,6);
                mostrarDados(dados,4);
                dadoMaxAnt=calculosDados(dados,4,puntAcu2);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");

                recuadroJuego(nom2, contRondas, puntPart2);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 3:"<<endl;
                dadosAleatorios(dados,3,6);
                mostrarDados(dados,3);
                dadoMaxAnt=calculosDados(dados,3,puntAcu2);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");

                recuadroJuego(nom2, contRondas, puntPart2);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 4:"<<endl;
                dadosAleatorios(dados,2,6);
                mostrarDados(dados,2);
                dadoMaxAnt=calculosDados(dados,2,puntAcu2);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");

                recuadroJuego(nom2, contRondas, puntPart2);
                recuadroJuego2();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 5:"<<endl;
                dadosAleatorios(dados,1,6);
                mostrarDados(dados,1);
                dadoMaxAnt=calculosDados(dados,1,puntAcu2);
                gotoxy(1,14);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");
                if(tieneTiroDePuntaje(puntAcu2)){
                    recuadroJuego(nom2, contRondas, puntPart2);
                    recuadroTiroDePuntaje();
                    rlutil::setColor(15);
                    gotoxy(1,3);
                    cout<<"Tenes tiro de puntaje porque tienes mas de 20 puntos ("<<puntAcu2<<" puntos)"<<endl;
                    puntosTiroPuntaje=hacerTiroDePuntaje(puntosAp2,puntAcu2);
                    puntPart2+=puntosTiroPuntaje;
                    gotoxy(51,18);
                    cout<<"Ganaste "<<puntosTiroPuntaje<<" puntos extra"<<endl;
                    system("pause");
                }
                else{
                    recuadroJuego(nom2, contRondas, puntPart2);
                    gotoxy(30,13);
                    rlutil::setColor(12);
                    cout<<"No entraste al tiro de puntaje y perdiste "<<puntosAp2<<" puntos"<<endl;
                    puntPart2-=puntosAp2;
                    rlutil::setBackgroundColor(15);
                    gotoxy(1,30);
                    system("pause");
                }
                puntAcu2=0;
                rlutil::cls();
                 system("color 0D");
            }
            recuadroD();
            rlutil::setColor(15);
            gotoxy(32,10);
            verificarGanador(puntPart1,puntPart2, nom1, nom2);
            verificarMaximo(puntPart1,nom1,puntMax,nomMax,nomTAM,hayMaximo);
            verificarMaximo(puntPart2,nom2,puntMax,nomMax,nomTAM,hayMaximo);
            puntPart1=0;
            puntPart2=0;
            gotoxy(1,30);
            system("pause");
            rlutil::cls();
             system("color 0D");
            break;

            case 'C':
            case 'c':
            rlutil::cls();
             system("color 0D");
            recuadro();
            gotoxy(31,11);
            rlutil::setColor(14);
            cout<<"Ingresar nombre: ";
            rlutil::setColor(15);
            cin>>nom;
            gotoxy(31,13);
            pedirRondas(cantRondas);
            rlutil::cls();
            for(contRondas=1;contRondas<=cantRondas;contRondas++){
                recuadro();
                gotoxy(31,12);
                rlutil::setColor(14);
                cout<<"Ingresar cantidad de puntos a apostar: ";
                rlutil::setColor(15);
                cin>>puntosAp;
                rlutil::cls();
                 system("color 0D");
                recuadroJuego(nom, contRondas, puntPart);
                recuadroModoSimulado();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 1:"<<endl;
                ingresarDados(dados,5);
                dadoMaxAnt=calculosDados(dados,5,puntAcu);
                gotoxy(1,21);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");

                recuadroJuego(nom, contRondas, puntPart);
                recuadroModoSimulado();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 2:"<<endl;
                ingresarDados(dados,4);
                dadoMaxAnt=calculosDados(dados,4,puntAcu);
                gotoxy(1,21);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");

                recuadroJuego(nom, contRondas, puntPart);
                recuadroModoSimulado();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 3:"<<endl;
                ingresarDados(dados,3);
                dadoMaxAnt=calculosDados(dados,3,puntAcu);
                gotoxy(1,21);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");

                recuadroJuego(nom, contRondas, puntPart);
                recuadroModoSimulado();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 4:"<<endl;
                ingresarDados(dados,2);
                dadoMaxAnt=calculosDados(dados,2,puntAcu);
                gotoxy(1,21);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");

                recuadroJuego(nom, contRondas, puntPart);
                recuadroModoSimulado();
                rlutil::setColor(15);
                gotoxy(1,5);
                cout<<"Tirada 5:"<<endl;
                ingresarDados(dados,1);
                dadoMaxAnt=calculosDados(dados,1,puntAcu);
                gotoxy(1,21);
                cout<<"Dado maximo: "<<dadoMaxAnt<<endl;
                gotoxy(1,30);
                system("pause");
                rlutil::cls();
                 system("color 0D");

                if(tieneTiroDePuntaje(puntAcu)){
                    recuadroJuego(nom, contRondas, puntPart);
                    recuadroTiroDePuntaje();
                    rlutil::setColor(15);
                    gotoxy(1,3);
                    cout<<"Tenes tiro de puntaje porque tienes mas de 20 puntos ("<<puntAcu<<" puntos)"<<endl;
                    puntosTiroPuntaje=hacerTiroDePuntajeModoSimu(puntosAp,puntAcu);
                    puntPart+=puntosTiroPuntaje;
                    if(puntosTiroPuntaje==0){
                        cantRondasCon0++;
                    }
                    gotoxy(51,18);
                    cout<<"Ganaste "<<puntosTiroPuntaje<<" puntos extra"<<endl;
                    gotoxy(1,30);
                    system("pause");
                }
                else{
                    recuadroJuego(nom, contRondas, puntPart);
                    gotoxy(30,13);
                    rlutil::setColor(12);
                    cout<<"No entraste al tiro de puntaje y perdiste "<<puntosAp<<" puntos"<<endl;
                    cantRondasPerdidas++;
                    puntPart-=puntosAp;
                    gotoxy(1,30);
                    rlutil::setColor(15);
                    system("pause");
                }
                puntAcu=0;
                rlutil::cls();
                 system("color 0D");
            }
            recuadroFinal();
            rlutil::setColor(15);
            gotoxy(32,10);
            cout<<nom<<" terminaste la partida con: "<<puntPart<<" puntos"<<endl;
            gotoxy(32,14);
            cout<<"Cantidad de rondas sin ganar puntos: "<<cantRondasCon0<<endl;
            gotoxy(32,18);
            cout<<"Cantidad de rondas con perdida de puntos: "<<cantRondasPerdidas<<endl;
            cantRondasPerdidas=0;
            puntPart=0;
            cantRondasCon0=0;
            gotoxy(1,30);
            system("pause");
            break;

            case 'D':
            case 'd':
            rlutil::cls();
             system("color 0D");
            if(!hayMaximo){
                recuadroD();
                gotoxy(45,14);
                rlutil::setColor(15);
                cout<<"Todavia no se jugo una partida"<<endl;
            }
            else{
                recuadroD();
                gotoxy(33,14);
                rlutil::setColor(15);
                cout<<"La persona que mas puntos hizo fue "<<nomMax<<" con "<<puntMax<<" puntos"<<endl;
            }
            gotoxy(1,30);
            system("pause");
            break;

            case 'S':
            case 's':
            return 0;
            break;
            default:
            gotoxy(50, 29);
            rlutil::setColor(15);
            cout << "Opcion de menu invalida"<<endl;
            system("pause");
            break;
        }
    }
    gotoxy(1,30);
    system("pause");
}

