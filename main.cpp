#include <iostream>
#include<list>
#include<vector>


using namespace std;

const int SALIR = 2;
//Definimos nuestro vector de integers como Lista
typedef vector<int> Lista;

Lista ordenarLista(Lista lstDeNumeros);


int main()
{
    Lista lstNums;
    int opcion = -1;

    while(opcion != SALIR){
        int num;

        cout<<"Teclee un numero :";
        cin >>num;

        lstNums.push_back(num);

        cout<<"Desea continuar capturando numeros [1= SI | 2 = NO] :";
        cin>>opcion;

    }

    cout<<"\n\n  Numeros capturados "<<lstNums.size()<<endl;

    //Obtener la lista de numeros ordenados.
    lstNums = ordenarLista(lstNums);

    cout<<"[";

    for(int idx = 0;idx<lstNums.size();idx++){
        cout<<lstNums[idx]<<",";
    }

    cout<<"]"<<endl;



    return 0;
}

Lista ordenarLista(Lista lstDeNumeros){
    int tempNum;
    bool requiereReOrdenar = false;

    if(lstDeNumeros.size() > 1){
        for(int idx = 0,nextIdx = idx+1;(idx<=lstDeNumeros.size() && nextIdx < lstDeNumeros.size() );idx++,nextIdx=idx+1){

            if(lstDeNumeros[idx] >= lstDeNumeros[nextIdx]){
                tempNum = lstDeNumeros[nextIdx];

                //Intercambiar valores
                lstDeNumeros.at(nextIdx) = lstDeNumeros[idx];
                lstDeNumeros.at(idx) = tempNum;

                //Indicar que requiere de una reordenacion
                requiereReOrdenar = true;

            }

        }
    }

    if(requiereReOrdenar){
        //Realizar una repasada hasta que que ya no se requiera reordenar la lista
        lstDeNumeros = ordenarLista(lstDeNumeros);
    }

    //Retornar la lista de numeros ordenados
    return lstDeNumeros;
}
