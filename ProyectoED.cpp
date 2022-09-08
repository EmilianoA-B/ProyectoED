#include <iostream>
#include <string>

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
void imprimir(struct pan datos[], int lp);
void ordenar(struct pan datos[], int lp);
void buscar(struct pan datos[], int lp);
int agrega(struct pan datos[], int lp);

int main(){
    int ultArr;
    pan datos[50];
    ultArr = incializarArreglo(datos);

    while(1){
        int opc;
        menu();
        cin>>opc;
        switch(opc){
            case 1:
                ultArr=agrega(datos,ultArr);
            break;

            case 2: //Venta

            break;

            case 3: //Ordenar

            break;

            case 4: //Buscar

            break;
            
            case 5: //Imprimir
                imprimir(datos,ultArr);
            break;

            default:
            cout<< "Eleccion incorrecta"<<endl;
        }
    }
}

void menu(){
    cout<<"Panaderia\n\n"<<
        "\t1. Agregar\n"<<
        "\t2. Vender\n"<<
        "\t3. Ordenar\n"<<
        "\t4. Buscar\n"<<
        "\t5. Imprimir inventario\n\n"<<
        "0. Salir\n\n Selecciona la opcion: "<<endl;
    }

int incializarArreglo(struct pan datos[]){    
    string nombres[10] = {"Concha", "Dona", "Bolillo","Cuernito","Oreja","Pan de muerto","Cuernito","Ojo de Buey","Polvoron","Mantecada"}; 
    int i;
    for (i = 0; i < 10; i++)
    {
        datos[i].precio = 1 + rand()%20;
        datos[i].cantidad = 1+rand()%80;
        datos[i].nombre = nombres[i];
    }
    return i;
}

int agrega(struct pan datos[], int lp){
    int opc, cantidad;
    float precio;
    string nombre;
    cout<<"Ingresa el nombre"<<endl;
    cin.ignore();
    getline(cin,nombre);
    datos[lp].nombre = nombre;
    cout<<"Ingresa el stock"<<endl;
    cin>>cantidad;
    datos[lp].cantidad = cantidad;
    cout<<"Ingresa el precio"<<endl;
    cin>>precio;
    datos[lp].precio = precio;
    cout<<"Quieres agregar otro item?\n\t1.Si \t2.No"<<endl;
    cin>> opc;
    lp++;
    if(opc == 1){
         agrega(datos,lp); 
    }
    return lp;
}

void imprimir(struct pan datos[], int lp){
    for(int i = 0; i <lp; i++){
        cout << "Nombre: " << datos[i].nombre << "\t|";
        cout << "Existencia: " << datos[i].cantidad <<"\t| ";
        cout << "Precio: " << datos[i].precio << "\t|" <<endl;
    }
}