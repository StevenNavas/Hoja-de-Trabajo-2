/*
Ejercicio # 2:
En la Pizzeria "Gran sabor" se tienen las siguientes ofertas:
Por la compra de una pizza grande (Q80.00), recibe un descuento de 10%
Por la compra de una pizza familiar (Q115.00), recibe un descuento de 15%
Por la compra de una pizza fiesta(Q100.00), recibe un descuento de 20%

Solicitar el tipo de pizza, el precio unitario y hallar el precio a pagar.

Grabar los datos a un archivo y mostrar el total global de la venta del dia y
determinar el total de lo vendido por producto, mostrando tambien el porcentaje
con relacion al total.*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;
struct pizza{
	string tipo;
	float precio_unitario;
	float descuento;
	float precio_total;

};
void mp();
void leer_archivo();
void grabar_archivo();
int main(){
	mp();
}

void mp(){ // menu principal
	int resp;
	//string nombrearchivo;
	//cout<<"Indique nombre de archivo: ";
	//getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Bienvenidos a pizzería El Gran Sabor "<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar pedido "<<"\n";
		cout<<" 2 - Mostrar totales "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		
		if (resp==1){		
			system("CLS");
			grabar_archivo();			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}

void grabar_archivo(){
	//variables basadas en la estructura
	int resp;
	int tipo_pizza;
	float unitario;
	float desc;
	float total;
	fflush(stdin);
	
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Pizza Grande "<<"\n";
		cout<<" 2 - Pizza Familiar "<<"\n";
		cout<<" 3 - Pizza Fiesta"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		
		if (resp==1){	
			tipo_pizza = resp;
			unitario = 80;
			desc = 0.1;
			total = unitario *(1-desc);	
		}
		else if (resp==2){
			tipo_pizza = resp;
			unitario = 115;
			desc = 0.15;
			total = unitario *(1-desc);
		}			
		else if (resp==3){
			tipo_pizza = resp;
			unitario = 100;
			desc = 0.2;
			total = unitario *(1-desc);
		}
	
	ofstream archivo; //leer archivo 
	archivo.open("pizza.txt",ios::app);
		
	//archivo.open(na.c_str(),ios::app);
	archivo<<tipo_pizza<<"\t"<<unitario<<"\t"<<desc<<"\t"<<total<<endl;
	archivo.close();
}
void leer_archivo(){
	ifstream archivo; //leer archivo 
	archivo.open("pizza.txt",ios::in);
	int lineas,i=0;
	string s,linea;
	float total_venta=0.00;	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1); //break;
	}
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	pizza recordset[lineas];
	
	archivo.open("pizza.txt",ios::in);
		if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	/*Leer datos del archivo*/
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        //cout<<"i: "<<i;
        archivo>>recordset[i].tipo>>recordset[i].precio_unitario>>recordset[i].descuento>>recordset[i].precio_total;
    }
    archivo.close(); 
    for(int i = 0; i < lineas; i++){
    	cout<<recordset[i].tipo<<" "<<recordset[i].precio_unitario<<" "<<recordset[i].descuento<<" "<<recordset[i].precio_total<<endl;
    	total_venta+=recordset[i].precio_total;
	}
	cout<<"Sumatorial total: "<<total_venta;
	system("PAUSE");
}
