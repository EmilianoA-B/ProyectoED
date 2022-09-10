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
void imprimir(struct pan datos[], int lp);
void menuOrdenar(int opc, struct pan datos[], int lp);
void buscar(struct pan datos[], int lp);
int agrega(struct pan datos[], int lp);
void insersionBinaria(int, struct pan datos[], int lp);
void InsBinCant(int, struct pan datos[], int lp);

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
                menuOrdenar(opc, datos, ultArr);
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

void menuOrdenar(int opc, struct pan datos[], int lp){
    cout<<"Ordenar:\n\n"<<
        "\t1. Alfabeticamente\n"<<
        "\t2. Por existencia\n"<<
        "\t3. Por precio (Mayor a menor)\n"<<
        "\t4. Por precio (Menos a mayor)\n\n"<<
        "0. Salir\n\n Selecciona la opcion: ";
    cin >> opc;
   while (opc > 4)
   {
        cout << "Selecciona una opcion correcta: ";
        cin >> opc;
   }
   
    
    insersionBinaria(opc, datos, lp);
}

void insersionBinaria(int opc, struct pan datos[], int lp){
	
	string minN, auxN;
        int auxC, minC, auxP, minP;
        int pos;
        cout << lp;
        for(int i = 0; i < lp; i++)
        {
            minN = datos[i].nombre;
            auxN = datos[i].nombre;
            minC = datos[i].cantidad;
            auxC = datos[i].cantidad;
            minP = datos[i].precio;
            minP = datos[i].precio;
            for(int j = i + 1; j <= lp; j ++)
            {
                switch (opc)
                {
                case 1:
                    if (datos[j].nombre < minN)
                    {
                        minN = datos[j].nombre;
                        minC = datos[j].cantidad;
                        minP = datos[j].precio;
                        pos = j;
                    }else{
                        break;
                    }
                    
                case 2:
                    if (datos[j].cantidad > minC)
                    {
                        minN = datos[j].nombre;
                        minC = datos[j].cantidad;
                        minP = datos[j].precio;
                        pos = j;
                    }
                    break;
                case 3:
                    if (datos[j].precio > minP)
                    {
                        minN = datos[j].nombre;
                        minC = datos[j].cantidad;
                        minP = datos[j].precio;
                        pos = j;
                    }
                    break;
                case 4:
                    if (datos[j].precio < minP)
                    {
                        minN = datos[j].nombre;
                        minC = datos[j].cantidad;
                        minP = datos[j].precio;
                        pos = j;
                    }
                    break;
                }
            }
            datos[pos].nombre = auxN;
            datos[i].nombre = minN;
            datos[pos].cantidad = auxC;
            datos[i].cantidad = minC;
            datos[pos].precio = auxP;
            datos[i].precio = minP;
            
        }
        cout << "Inventario ordenado por nombre\n\n";
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
    string nombres[10] = {"Concha\t", "Dona\t\t", "Bolillo\t","Cuernito\t","Oreja\t","Pan de muerto",
                        "Cuernito\t","Ojo de Buey\t","Polvoron\t","Mantecada\t"}; //los tabuladores son necesarios para la correcta impresion
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
        cout << "[" << i + 1 << "]  " << "\tNombre:    " << datos[i].nombre << "|";
        cout << "Existencia:    " << datos[i].cantidad <<"\t| ";
        cout << "Precio:    " << datos[i].precio << "\t|" <<endl;
    }
    cout << endl;
}