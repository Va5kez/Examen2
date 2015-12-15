#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Pista.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;

//Escribe los datos del objeto pista (dado) en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias pistas en un solo archivo
void escribir(string nombre_archivo, Pista*pista, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);//ios::in
    if(!out.is_open())
    {
        out.open(nombre_archivo.c_str());
    }
    out.seekp(posicion*30);
    out.write((char*)pista->autor.c_str(),20);
    out.write((char*)&pista->fecha,4);
    out.write((char*)&pista->duracion,4);
    out.write(&pista->categoria,1);
    out.write((char*)&pista->es_buena,1);
    out.close();
}

//Devuelve una pista previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias pistas de un solo archivo
Pista* leer(string nombre_archivo, int posicion)
{
    char autor[20];
    int fecha, duracion;
    char categoria;
    bool es_buena;
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*30);
    in.read((char*)autor,20);
    in.read((char*)&fecha,4);
    in.read((char*)&duracion,4);
    in.read(&categoria,1);
    in.read((char*)&es_buena, 1);

    Pista *pista = new Pista(autor,fecha,duracion,categoria,es_buena);

    return pista;
}
//Devuelve la cantidad de pistas almacenadas en el archivo con nombre_archivo que su atributo es_buena sea igual a true
int contarBuenas(string nombre_archivos)
{
    return 1;
}

//Devuelve la cantidad de numeros repetidos
//Nota: NO devuelve la cantidad de repeticiones
int contarRepetidos(multiset<int> mi_set)
{
    return -1;
}

//Devuelve true solo si c (dado) existe en a (dado) o en b (dado)
bool existe(queue<char> a, stack<char> b, char c)
{
    while(!a.empty())
    {
        if(c==a.front())
            return true;
        else
        {
            a.pop();
        }
    }

    while(!b.empty())
    {
        if(c==b.top())
            return true;
        else
        {
            b.pop();
        }
    }
    return false;
}

//Devuelve la llave asociada a valor (dado) en mi_mapa (dado)
string getKey(map<string,string>mi_mapa, string valor)
{
    for(map<string,string>::iterator tem=mi_mapa.begin(); tem!=mi_mapa.end(); tem++)
    {
        if(valor.compare(tem->second) == 0){
            return tem->first;
        }
    }
    return "";
}

//Establece en NULL el hijo izquerdo e hijo derecho del nodo cuyo valor es igual a valor (dado)
void cortarDecendencia(NodoBinario* raiz,int valor)
{
    if(raiz!=NULL){
        if(raiz->valor == valor)
        {
            raiz->hijo_izquierdo = NULL;
            raiz->hijo_derecho= NULL;
        }
        else
        {
            cortarDecendencia(raiz->hijo_izquierdo, valor);
            cortarDecendencia(raiz->hijo_derecho, valor);
        }
    }

}

//Devuelve la profundidad a donde se encuentra el valor buscado (dado)
int getProfundidad(NodoBinario* raiz,int buscado)
{
    contador=1;
    if(raiz!=NULL){
        if(raiz->valor == buscado)
            return contador;
        else{

        }
        }
    return 1;
}

//Establece en false todos los bits de byte (dado) excepto los ultimos dos
char borrar2Bits(char byte)
{
    char falso = 252, fin = byte&falso;
    return fin;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

