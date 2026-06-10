/*
Arbol binario:

Archivo de ventas con ABB
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

typedef struct tNodo *tTree;
typedef int tInfo;
typedef char str20[21];


struct tNodo
{
    tTree pIzq;
    tInfo info;
    tTree pDer;
};

struct tInfo
{
    int codArt,refArt;
};

struct tsVta
{
    int codArt, cant;
    float precioUni;
    str20 descrip;
};

bool ArbolVacio(tTree &Tree)
{
    return Tree == NULL;
}

void InsertarHoja(tTree &Tree, tTree pNodo)
{
    if(ArbolVacio(Tree))
    {
        Tree = pNodo;
    }
    else if(pNodo->info.codArt < Tree->info.codArt)
    InsertarHoja(Tree->pIzq, pNodo);

    else 
    InsertarHoja(Tree->pDer, pNodo);
}

void ListarInOrden(FILE **Vtas, tTree &Tree)
{
    tsVta rVta;

    if(!ArbolVacio(Tree))
    {
        ListarInOrden(Vtas,Tree->pIzq);
        fseek(*Vtas,Tree->info.refArt*sizeof(rVta), SEEK_SET);
        fread(&rVta, sizeof rVta, 1, *Vtas);
        cout<<rVta.codArt << ""<< rVta.cant << rVta.precioUni << ""<<rVta.descrip<< endl;
        ListarInOrden(Vtas, Tree->pDer);
    }
}

void Abrir(FILE ** Vtas)
{
    *Vtas = fopen("Ventas.dat","rb");
}


int main()
{
    FILE* Ventas;
    tsVta rVenta;
    tInfo rInfo;
    tTree ArbolBIN = NULL, pNodoNew;

    Abrir(&Ventas);
    while(fread(&rVenta, sizeof rVenta,1 , Ventas))
    {
        rInfo.codArt = rVenta.codArt;
        rInfo.refArt = ftell(Ventas)/sizeof(rVenta)-1;
        pNodoNew = new tNodo;
        pNodoNew ->info = rInfo;
        pNodoNew-> pIzq = pNodoNew->pDer = NULL;
        InsertarHoja(ArbolBIN,pNodoNew);
    }

    ListarInOrden(&Ventas, ArbolBIN);
    fclose(Ventas);
    
    return 0;
}