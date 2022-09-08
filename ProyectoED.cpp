#include <iostream>

using namespace std;

struct pan{
    int cantidad;
    float precio;
    string nombre;
};

void menu();
int incializarArreglo(struct pan datos[]);
void agregarDatos(struct pan datos[]);
void ordenarArreglo(struct pan datos[]);
void buscar(struct pan datos[]);
void imprimir(struct pan datos[]);

int main(){
    int ultArr;
    pan datos[50];
    ultArr = incializarArreglo(datos);

    while(1){
        int opc;
        cin>>opc;
        switch(opc){
            case 1: //Agregar

            break;

            case 2: //Venta

            break;

            case 3: //Ordenar

            break;

            case 4: //Buscar

            break;

            default:
            cout<< "Eleccion incorrecta"<<endl;
        }
    }
}

void menu(){
    cout<<"Panaderia\n\n"<<endl;
}

int incializarArreglo(struct pan datos[]){    
    string nombres[10] = {"Concha", "Dona", "Bolillo","Cuernito","Oreja","Pan de muerto"}; 
    int i;
    for (i = 0; i <= 10; i++)
    {
        datos[i].precio = 1 + rand()%20;
        datos[i].cantidad = 1+rand()%80;
        datos[i].nombre = nombres[i];
    }
    return i;
}

void imprimir(struct pan datos[]){
    for(int i = 0; i < 10; i++){
        cout << "Nombre: " << datos[i].nombre << " ";
        cout << "Existencia: " << datos[i].cantidad <<" ";
        cout << "Precio: " << datos[i].precio << " " <<endl;
    }
}