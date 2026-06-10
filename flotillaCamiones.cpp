/******************************************************************************
⦁	Una empresa tiene una flotilla de máximo 100 camiones que realizan viajes al interior del país transportando mercaderías muy frágiles. Por esta razón, los directivos de la empresa han decidido otorgar una bonificación a todos los camioneros cuya cantidad de roturas en el último mes haya sido inferior a 20 unidades.
Para ello se cuenta con un archivo de Viajes sin orden y con repetición de camioneros, conteniendo : 
Nro. Leg. (5 car.), Cód. Pcia. (1..24), Cantidad de unidades rotas.
Únicamente tendrán derecho a la bonificación aquellos conductores que hayan realizado un mínimo de cuatro viajes.
El listado a emitir ordenado por cantidad de unidades rotas, -se deben emitir todos los camioneros con al menos un viaje realizado- deberá contener :
Listado de Camioneros ordenado por Cant. unid. rotas
		Nro. Leg.		Cant. Viajes		Cant. Unid. Rotas
		 X(5)   		                  999			9999
		 
		 Datos importantes :
		 Cantidad unidades rotas inferior a 20 unidades 
		 Minimo de 4 viajes realizados 
		 MAX CAMIONES = 100

*******************************************************************************/
#include <iostream>
#include<iomanip>
#include<fstream>

using namespace std;

typedef char str5[6];
typedef trCam tvrCam[MAX_CAMIONES + 1];
typedef unsigned short ushort;  //Numeros enteros postivos 

const int MAX_CAMIONES = 100;

//REGISTROS Uno para el archivo y otro para registros Camioneros 
struct trVia
{
    str5 cod_legajo;
    ushort cod_pcia;
    short cantUniRotas;
    
};

struct trCam
{
    str5 cod_legajo;
    short cantViajes;
    short cantUniRotas;
};



//PROTOTIPOS DE FUNCIONES  //Viajes txt 
void AcumViajes(tvrCam trVia, short &);
void IntCmb(trCam &elemento1, trCam &elemento2);
void OrdxBur(tvrCam vrCam, short card);
void Listado(tvrCam , short );
//FIN DE PROTOTIPOS 


bool LeeReg(ifstream &Via, trVia &rVia)
{
    //Lectura del archivo de texto 
    Via.get(rVia.cod_legajo,6);
    Via>> rVia.cod_pcia >> rVia.cantUniRotas;
    Via.ignore();
    return Via.good();
}

void IntCmb(trCam &elemento1, trCam &elemento2)
{
    trCam aux = elemento1;
    elemento1 = elemento2;
    elemento2 = aux;
}

short BusLinVect(tvrCam vrCam,str5 nLeg,short card)
{
    short i = 1;
    
    while(i<= card && strcmp(nLeg,vrCam[i].cod_legajo)!= 0)
    {
        i++;
    }
    return i;
}

//Como acumulas los viajes?
void AcumViajes(tvrCam trVia, short &)
{
    short posCam;
    
    posCam = BusLinVect(vrCam,rVia.cod_legajo,cCam);
    if(posCam > cCam)
    {
        cCam++;
        strcpy(vrCam[posCam].CodLeg ,rVia.CodLeg);
        vrCam[posCam].cantViajes = 0;
        vrCam[posCam].cantUniRotas = 0;
    }
    
    vrCam[posCam].cantViajes++;
    vrCam[posCam].cantUniRotas++;
    
}

void OrdxBur(tvrCam vrCam, short card)
{
    bool ordenado;  //Declara variable Ordenado 
    short k = 0;  //declara e inicializa k = 0 
    
    do
    {
        ordenado = true;
        k++;
        
        for(int i = 1; i<= card-k;i++)
        {
            if(vrCam[i].cantUniRotas > vrCam[i+1].cantUniRotas)
            {
                ordenado = false;
                IntCmb(vrCam[i], IntCmb[i+1]);
            }
        }
    }while(!ordenado);

}


int main()
{
    ifstream Viajes("Viajes.txt");
    trVia rViaje;
    trCam vrCamioneros;
    short canCam= 0;
    
    //Bucles dentro de bucles 
    while(LeeReg(Viajes,rViaje))
    AcumViajes(vrCamioneros, rViaje, canCam);
    ordListado(vrCamioneros,canCam);
    Viajes.close();
    
    return 0;
}
