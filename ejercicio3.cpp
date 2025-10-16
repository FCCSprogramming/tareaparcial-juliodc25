#include <iostream>
#include <iomanip>
using namespace std;

void leerDatos(int *id,float *valor,int n){
    for(int i=0;i<n;i++){
        cout<<"ID["<<i+1<<"]: ";
        cin>>*(id+i);
        cout<<"Valor["<<i+1<<"]: ";
        cin>>*(valor +i);
    }

}
void mostrarLista(int *id,float *valor,int n ){
    for(int i=0;i<n;i++){
        cout<<"("<<*(id+i)<<", "<<*(valor+i)<<")"<<endl;
    }
}void merge(int *id,float *valor, int inicio, int medio, int fin){
    int i = inicio;
    int j = medio +1; 
    int k = inicio;
    int temp1[100];
    float temp2[100];
    while(i<= medio && j<= fin){
        if(*(id+i)<=*(id+j)){
            temp1[k] = *(id+i);
            temp2[k] = *(valor+i);
            i++;
        }else{
            temp1[k] = *(id+j);
            temp2[k] = *(valor+j);
            j++;
        }
        k++;
    }
    while(i<= medio){
        temp1[k] = *(id+i);
        temp2[k] = *(valor+i);
        i++;
        k++;
    }
    while(j<= fin){
        temp1[k] = *(id+j);
        temp2[k] = *(valor+j);
        j++;
        k++;
    }
     for(int i = inicio; i<=fin; i++) {
        *(id+i) = temp1[i];
        *(valor+i) = temp2[i];
    }
}

void mergeSort(int *id,float *valor, int inicio, int fin){
     if (inicio <fin){
        int medio = (inicio+fin)/2;
        mergeSort(id,valor,inicio,medio);
        mergeSort(id,valor,medio+1,fin);
        merge(id,valor,inicio,medio,fin);
    }
}

void buscarMediciones(int *id,float *valor,int n,int medicion){
    cout<<"Resultados:"<<endl;
    for(int i=0;i<n;i++){
        if(*(id+i)==medicion){
            cout<<"("<<medicion<<", "<<*(valor+i)<<")"<<endl;
        }
    }
}


int main(){
    int n;
    int ID[n];
    float valor[n];
    int medicion;
    cout<<"Ingrese numero de mediciones: ";
    cin>>n;
    leerDatos(ID,valor,n);
    cout<<"Lista original:"<<endl;
    mostrarLista(ID,valor,n);
    cout<<"Lista ordenada por ID:"<<endl;
    mergeSort(ID,valor,0,n-1);
    mostrarLista(ID,valor,n);
    cout<<"Bucar mediciones del sensor ID = ";
    cin>>medicion;
    buscarMediciones(ID,valor,n,medicion);


    return 0;
}