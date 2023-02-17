#include <iostream>

using namespace std;

struct DatosPersona{
	string CI, nom, ape, calleP, calleS, numCasa;
};

struct DatosVehiculo{
	int tipo, aCompra;
	string numPlaca, color, marca, modelo;
};

struct TDA_Datos{
	DatosPersona datosP;
	DatosVehiculo datosV;
};

struct Nodo{
	TDA_Datos datos;
	Nodo *sig;
};

void insertarUltimo(Nodo *& lista,  TDA_Datos d) {
	Nodo *nuevo_nodo = new Nodo();
	Nodo *aux;
	
	nuevo_nodo->datos = d;
	nuevo_nodo->sig = NULL;
	
	if(lista == NULL){
	    lista = nuevo_nodo;
	}
	else{
		aux = lista; 
		while(aux->sig != NULL){ 
		    aux = aux->sig;  
    	}
	    aux->sig = nuevo_nodo; 
    }

}  


void imprimirLista(Nodo *lista, int aCons){
	cout << "Listado de vehículos matriculados, comprados en el: " << aCons<< endl;
	while(lista!=NULL){
		if(lista->datos.datosV.aCompra == aCons){
			if(lista->datos.datosV.tipo == 1){
				cout << "Motocicleta - ";
			} else if(lista->datos.datosV.tipo == 2){
				cout << "Auto - ";
			} else if (lista->datos.datosV.tipo == 3){
				cout << "Camioneta - ";
			}
			cout << lista->datos.datosV.numPlaca << " - " << lista->datos.datosV.marca << " - " << lista->datos.datosV.modelo << endl;
		}
		lista = lista -> sig;
	}
}



int main(){
	Nodo *lista = NULL;
	TDA_Datos d;
	char sn;
	int aCons;
	
	
	do{
	cout << "Ingresar datos de matriculacion vehicular: " << endl;
	cout << "Ingresar Datos Personales: " << endl;
	cout << "Cedula: " ; cin >> d.datosP.CI;
	cout << "Nombre: "; cin >> d.datosP.nom;
	cout << "Apellido: "; cin >> d.datosP.ape;
	cout << "Direccion: " << endl;
	cout << "Calle Principal: "; cin >> d.datosP.calleP;
	cout << "Calle Secundaria: "; cin >> d.datosP.calleS;
	cout << "Numero de casa: "; cin >> d.datosP.numCasa;
	cout << "-----------------------------------------------------" <<  endl;
	cout << "Ingresar Datos del Vehiculo: " << endl;
	cout << "Tipo de vehiculo (1.Motocicleta 2.Auto 3.Camioneta) " << endl;
	do{
		cin >> d.datosV.tipo;
	} while((d.datosV.tipo < 1 ) || (d.datosV.tipo > 3));
	cout << "Numero de Placa: "; cin >> d.datosV.numPlaca;
	cout << "Color del Vehiculo: "; cin >> d.datosV.color;
	cout << "Marca: "; cin >> d.datosV.marca;
	cout << "Modelo: "; cin >> d.datosV.modelo;
	cout << "Anio: "; cin >> d.datosV.aCompra;
	
	insertarUltimo(*&lista, d);
	
	cout << "Si desea ingresar otro dato ingrese 'S', caso contrario 'N'" << endl;
	cin >> sn;
	}while(sn == 's'||sn == 'S');
	
	cout << "\n-----------------------------------------------------------------\n";
	
	cout << "Ingrese el anio que desee consultar: "; cin >> aCons;
	
	imprimirLista(lista, aCons);
	
	return 0;
}
