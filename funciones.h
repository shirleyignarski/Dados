#include<stdlib.h>
#include<iostream>
using namespace std;
#include "rlutil.h"
#include <time.h>

void pedirRondas(int& cantRondas){
    rlutil::setColor(14);
    cout<<"Ingresar cantidad de rondas a jugar: ";
    rlutil::setColor(15);
    cin>>cantRondas;
}

void recuadro (){
    int i;
    rlutil::setColor(3);
    gotoxy(30,8);
    for(i=1;i<60;i++)cout<<(char)205;
    gotoxy(30,8);
    cout<<(char)201;
    gotoxy(30,9);
    for(i=9;i<16;i++){
    gotoxy(30,i);
    cout<<(char)186;}
        gotoxy(30,16);
    for(i=1;i<60;i++)cout<<(char)205;
    gotoxy(30,16);
    cout<<(char)200;
    gotoxy(30,9);
    for(i=9;i<16;i++){
    gotoxy(89,i);
    cout<<(char)186;}
    gotoxy(89,8);
    cout<<(char)187;
    gotoxy(89,16);
    cout<<(char)188;

}

void recuadroJuego(char nombre[30] , int contRondas , int puntAcu){
    int i;
    rlutil::setColor(15);
    gotoxy(25,1);
    cout<<"TURNO DE "<<nombre<<"\t"<<(char)179<<(char)179<<"\t"<<" RONDA N"<<(char)248<<contRondas<<"\t"<<(char)179<<(char)179<<"\t"<<" PUNTAJE ACUMULADO: "<<puntAcu<<endl;
    gotoxy(0,6);
    rlutil::setColor(5);
    for(i=1;i<121;i++)cout<<(char)249;
    cout<<""<<endl;
}

void dadosAleatorios(int v[],int tam,int limite){
    int i;
    for(i=0;i<tam;i++){
        v[i] = (rand()%limite)+1;
    }
}

void mostrarDados(int v[],int tam){
    int i;
    gotoxy(4,10);
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
    cout<<""<<endl;
}

int calculosDados(int v[],int tam, int& acumulador){
    int i;
    int dadoMax = 0;
    for(i=0;i<tam;i++){
        if(v[i]>dadoMax){
            dadoMax=v[i];
        }
    }
    acumulador = acumulador + dadoMax;
    return dadoMax;
}

bool tieneTiroDePuntaje(int puntos){
    if(puntos>=20){
        return true;
    }
    else{
        return false;
    }
}

int hacerTiroDePuntaje(int puntosApostados, int puntosAcumulados){
    int generadorDePuntos;
    int contadorNumerosIgualesAlGenerador=0;
    int puntajeGanado;
    int dados[5];

    if(puntosAcumulados>=20 and puntosAcumulados<=24){
        generadorDePuntos=(puntosAcumulados%20)+1;
    }
    else{
        generadorDePuntos=6;
    }

    dadosAleatorios(dados,5,6);
    gotoxy(1,6);
    cout<<"Tirada de puntaje:"<<endl;
    mostrarDados(dados,5);

    for(int i=0;i<5;i++){
        if(dados[i]==generadorDePuntos){
            contadorNumerosIgualesAlGenerador++;
        }
    }
    puntajeGanado=contadorNumerosIgualesAlGenerador*puntosApostados;
    return puntajeGanado;
}


void recuadroJuego2(){
    int i;
    gotoxy(1,4);
    for(i=1;i<12;i++)cout<<(char)205;
    gotoxy(12,4);
    cout<<(char)187;
    gotoxy(12,5);
    cout<<(char)186;
    gotoxy(12,6);
    cout<<(char)186;
    gotoxy(12,6);
    cout<<(char)188;
    gotoxy(1,6);
    for(i=1;i<12;i++)cout<<(char)205;
    cout<<""<<endl;

    gotoxy(1,13);
    for(i=1;i<15;i++)cout<<(char)205;
    gotoxy(15,13);
    cout<<(char)187;
    gotoxy(15,14);
    cout<<(char)186;
    gotoxy(15,15);
    cout<<(char)186;
    gotoxy(15,15);
    cout<<(char)188;
    gotoxy(1,15);
    for(i=1;i<15;i++)cout<<(char)205;
    cout<<""<<endl;
}


void recuadroFinal(){
    int i;
    rlutil::setColor(5);
    gotoxy(30,8);
    for(i=1;i<60;i++)cout<<(char)205;
    gotoxy(30,8);
    cout<<(char)201;
    gotoxy(30,9);
    for(i=9;i<20;i++){
    gotoxy(30,i);
    cout<<(char)186;}
    gotoxy(30,20);
    for(i=1;i<60;i++)cout<<(char)205;
    gotoxy(30,20);
    cout<<(char)200;
    gotoxy(30,9);
    for(i=9;i<20;i++){
    gotoxy(89,i);
    cout<<(char)186;}
    gotoxy(89,8);
    cout<<(char)187;
    gotoxy(89,20);
    cout<<(char)188;
}
void recuadroTiroDePuntaje(){
    int i;
    gotoxy(1,4);
    rlutil::setColor(5);
    for(i=1;i<121;i++)cout<<(char)249;

    gotoxy(1,5);
    for(i=1;i<20;i++)cout<<(char)205;
    gotoxy(20,5);
    cout<<(char)187;
    gotoxy(20,6);
    cout<<(char)186;
    gotoxy(20,7);
    cout<<(char)186;
    gotoxy(20,7);
    cout<<(char)188;
    gotoxy(1,7);
    for(i=1;i<20;i++)cout<<(char)205;
    cout<<""<<endl;
    gotoxy(50,17);
    for(i=1;i<25;i++)cout<<(char)205;
    gotoxy(74,17);
    cout<<(char)187;
    gotoxy(74,18);
    cout<<(char)186;
    gotoxy(74,19);
    cout<<(char)186;
    gotoxy(74,19);
    cout<<(char)188;
    gotoxy(50,17);
    cout<<(char)201;
    gotoxy(50,19);
    for(i=1;i<25;i++)cout<<(char)205;
    gotoxy(50,18);
    cout<<(char)186;
    gotoxy(50,19);
    cout<<(char)186;
    gotoxy(50,19);
    cout<<(char)200;

    cout<<""<<endl;



}

void ingresarDados(int v[],int tam){
    gotoxy(1,8);
    for(int i=0;i<tam;i++){
        cout<<"Ingresa el "<<i+1<<" dado: ";
        cin>>v[i];
        cout<<""<<endl;
    }
}
void recuadroModoSimulado(){
    int i;
    gotoxy(1,4);
    for(i=1;i<12;i++)cout<<(char)205;
    gotoxy(12,4);
    cout<<(char)187;
    gotoxy(12,5);
    cout<<(char)186;
    gotoxy(12,6);
    cout<<(char)186;
    gotoxy(12,6);
    cout<<(char)188;
    gotoxy(1,6);
    for(i=1;i<12;i++)cout<<(char)205;
    cout<<""<<endl;

    gotoxy(1,20);
    for(i=1;i<15;i++)cout<<(char)205;
    gotoxy(15,20);
    cout<<(char)187;
    gotoxy(15,21);
    cout<<(char)186;
    gotoxy(15,22);
    cout<<(char)186;
    gotoxy(15,22);
    cout<<(char)188;
    gotoxy(1,22);
    for(i=1;i<15;i++)cout<<(char)205;
    cout<<""<<endl;
}

int hacerTiroDePuntajeModoSimu(int puntosApostados, int puntosAcumulados){
    int generadorDePuntos;
    int contadorNumerosIgualesAlGenerador=0;
    int puntajeGanado;
    int dados[5];

    if(puntosAcumulados>=20 and puntosAcumulados<=24){
        generadorDePuntos=(puntosAcumulados%20)+1;
    }
    else{
        generadorDePuntos=6;
    }

    gotoxy(1,6);
    cout<<"Tirada de puntaje:"<<endl;
    ingresarDados(dados,5);

    for(int i=0;i<5;i++){
        if(dados[i]==generadorDePuntos){
            contadorNumerosIgualesAlGenerador++;
        }
    }
    puntajeGanado=contadorNumerosIgualesAlGenerador*puntosApostados;
    return puntajeGanado;
}

void copiarNombre(char nombre[], char nombreMax[],int tamNom){
    for(int i=0;i<tamNom;i++){
        nombreMax[i]=nombre[i];
    }
}

void verificarMaximo(int puntosPartida,char nombre[], int& puntosMax, char nombreMax[],int tamNom,bool& hayMaximo){
    if(puntosPartida>puntosMax || !hayMaximo){
        puntosMax=puntosPartida;
        copiarNombre(nombre,nombreMax,tamNom);
        hayMaximo=true;
    }
}
void recuadroD(){
    int i;
    rlutil::setColor(13);
    gotoxy(30,12);
    for(i=1;i<60;i++)cout<<(char)205;
    gotoxy(30,12);
    cout<<(char)201;
    gotoxy(30,13);
    for(i=13;i<16;i++){
    gotoxy(30,i);
    cout<<(char)186;}
        gotoxy(30,16);
    for(i=1;i<60;i++)cout<<(char)205;
    gotoxy(30,16);
    cout<<(char)200;
    gotoxy(30,13);
    for(i=13;i<16;i++){
    gotoxy(89,i);
    cout<<(char)186;}
    gotoxy(89,12);
    cout<<(char)187;
    gotoxy(89,16);
    cout<<(char)188;
}

void verificarGanador(int puntos1,int puntos2, char nombre1[],char nombre2[]){
    if(puntos1>puntos2){
            gotoxy(45,14);
        cout<<"Gana "<<nombre1<<" con "<<puntos1<<" puntos";
    }
    else if(puntos2>puntos1){
        gotoxy(45,14);
        cout<<"Gana "<<nombre2<<" con "<<puntos2<<" puntos";
    }else{
    gotoxy(45,14);
    cout<<"Hubo empate"<<endl;
    }
}
