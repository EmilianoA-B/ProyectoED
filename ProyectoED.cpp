#include <iostream>
#include <string>

using namespace std;

struct pan{
    int cantidad ;
    float precio;
    string nombre;
};

struct panV: pan{
    static float total;
};

float panV::total = 0;

void menu();
int incializarArreglo(struct pan datos[]);
void agregarDatos(struct pan datos[]);
void imprimir(struct pan datos[], int lp);
void menuOrdenar(int opc, struct pan datos[], int lp);
void buscar(struct pan datos[], int lp);
int agrega(struct pan datos[], int lp);
void insersionBinaria(int, struct pan datos[], int lp);
void InsBinCant(int, struct pan datos[], int lp); // Esta para que sirve?
int vender(struct pan datos[], struct panV carrito[], int lp,int carLp);
void ticket(struct panV carrito[], int carLp);

int main(){
    int ultArr, ultCarr = 0;
    pan datos[20]; panV carrito[10];
    ultArr = incializarArreglo(datos);

    while(1){
        int opc;
        menu();
        cin>>opc;
        switch(opc){

            case 0:
            exit(0);
            
            case 1:
                ultArr=agrega(datos,ultArr);
            break;

            case 2: //Venta
                ultCarr = vender(datos, carrito, ultArr, ultCarr);
            break;

            case 3: //Ordenar
                menuOrdenar(opc, datos, ultArr);
            break;

            case 4: //Buscar

            break;
            
            case 5: //Imprimir
                imprimir(datos,ultArr);
            break;

            case 6: //Imprimir ticket
                ticket(carrito,ultCarr);
            break;

            default:
            cout<< "Eleccion incorrecta"<<endl;
        }
    }
}

int vender(struct pan datos[],struct panV carrito[],int lp, int carLp){
    int elecc = 0, exisElec = 0;
    if(carLp < 10){
        cout << "¿Que desea ordenar?"<<endl;
        imprimir(datos, lp);
        cout<<endl;
        cin>>elecc;
        if(elecc > lp + 1 || elecc <= 0){
            while(elecc > lp + 1 || elecc <= 0){
                cout<<"Elige una opcion correcta: "<<endl;
                cin>>elecc;
            }
        }
        cout<<"¿Cuantos panes quiere?"<<endl;
        cin>>exisElec;

        datos[elecc-1].cantidad = datos[elecc-1].cantidad - exisElec; // Resta de la existencia actual
        //Agrega items al carrito
        carrito[carLp].nombre = datos[elecc-1].nombre; 
        carrito[carLp].cantidad = exisElec;
        carrito[carLp].precio = exisElec * datos[elecc-1].precio;
        panV::total = carrito[carLp].precio + panV::total;

        carLp++; //Ultimo indice del arreglo carrito
        
        cout<<"¿Quiere agregar mas? \n\n 1. Si 2. No"<<endl;
        elecc = 0;
        cin>>elecc;
        if(elecc == 1){
            vender(datos,carrito,lp,carLp);
        }
        return carLp;
    }else{
        cout<<"Tu carrito esta lleno!"<<endl;
    }
    return carLp;
}

void ticket(struct panV carrito[], int carLp){
   
    if(carLp > 0 && carLp < 10){
        cout<<"     TICKET      \n"<<endl;
        for(int i = 0;i < carLp; i++){
            cout<<"["<<i +1<<"] - " << carrito[i].nombre << "  x  "<<carrito[i].cantidad << " -   "<<carrito[i].precio<<"$"<<endl;
        }
        cout<<"\nTotal: "<<panV::total<<"$\n"<<endl;
    }else{
        cout << "Tu carrito esta vacio!" <<endl;
    }
}

void menuOrdenar(int opc, struct pan datos[], int lp){
    cout<<"Ordenar:\n\n"<<
        "\t1. Alfabeticamente\n"<<
        "\t2. Por existencia\n"<<
        "\t3. Por precio (Mayor a menor)\n"<<
        "\t4. Por precio (Menos a mayor)\n\n"<<
        "0. Salir\n\nSelecciona la opcion: ";
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
        int pos=0;
        for(int i = 0; i < lp; i++)
        {
            minN = datos[i].nombre;
            auxN = datos[i].nombre;
            minC = datos[i].cantidad;
            auxC = datos[i].cantidad;
            minP = datos[i].precio;
            auxP = datos[i].precio;
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
        cout << "Inventario ordenado\n\n";
}


void menu(){
    cout<<"Panaderia\n\n"<<
        "\t1. Agregar\n"<<
        "\t2. Vender\n"<<
        "\t3. Ordenar\n"<<
        "\t4. Buscar\n"<<
        "\t5. Imprimir inventario\n"<<
        "\t6. Ticket\n\n"<<
        "0. Salir\n\n Selecciona la opcion: "<<endl;
    }

int incializarArreglo(struct pan datos[]){    
    string nombres[10] = {"Concha\t", "Dona\t\t", "Bolillo\t","Baguette\t","Oreja\t","Pan de muerto",
                        "Cuernito\t","Ojo de Buey\t","Polvoron\t","Mantecada\t"}; //Los tabuladores son necesarios para la correcta impresion
    int i;
    for (i = 0; i < 10; i++)
    {
        datos[i].precio = 1 + rand()%20;
        datos[i].cantidad = 1+rand()%80;
        datos[i].nombre = nombres[i];
    }
    return i-1;
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
    for(int i = 0; i <=lp; i++){
        cout << "[" << i + 1 << "]  " << "\tNombre:    " << datos[i].nombre << "|";
        cout << "Existencia:    " << datos[i].cantidad <<"\t| ";
        cout << "Precio:    " << datos[i].precio << "\t|" <<endl;
    }
    cout << endl;
}