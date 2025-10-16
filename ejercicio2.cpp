#include <iostream>
#include <iomanip>
using namespace std;

void leerMemoria(float** &A,int n){
    A=new float*[n];
    for(int i=0;i<n;i++){
        *(A+i)=new float[n];
    }   
}
void ingresarMatriz(float **A, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){                    
            cout<<"A["<<i<<"]["<<j<<"]= ";
            cin>>*(*(A+i)+j);
        }
    }
}    

void mostrarMatriz(float **A, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(4)<<*(*(A+i)+j)<<" ";
        }
        cout<<endl;
    }
}
void matrizTranspuesta(float **A,float **B,int n){
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(*(B+j)+i)=*(*(A+i)+j);
        }
     }
}
void multiplicarMatrices(float **A,float **B,float **C,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(*(C + i) + j) = 0.0f;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
            *(*(C+i)+j) += (*(*(A+i)+k)) * (*(*(B+k)+j));
             }  
          }
    }
}    
float trazaMatriz(float** matriz,int n){
    float suma=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
             suma+=*(*(matriz+i)+j);
            }
        }
    }
    return suma;
}

int main(){
    int n;
    float **A;//nuestra matriz original
    float **B;//almacena la matriz transpuesta
    float **C;//almacena el producto de A*B
    cout<<"N= ";
    cin>>n;
    leerMemoria(A,n);
    leerMemoria(B,n);
    ingresarMatriz(A,n);
    cout<<"Matriz A: "<<endl;
    mostrarMatriz(A,n);
    cout<<"Matriz Transpuesta(AT): "<<endl;
    matrizTranspuesta(A,B,n);
    mostrarMatriz(B,n);
    cout<<"Matriz inercia(A*AT): "<<endl;
    leerMemoria(C,n);
    multiplicarMatrices(A,B,C,n);
    mostrarMatriz(C,n);
    float traza=trazaMatriz(C,n);
    cout<<"La traza de la matriz inercia es: "<<traza<<endl;

    return 0;
}