#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
/* */
using namespace std;
struct Nodo{
int dato;
Nodo *siguiente;
};
int menu();
int insertarLista(Nodo *&lista,int); 
int mostrarLista(Nodo *);
int eliminarNodo(Nodo *&,int); 
int buscarLista(Nodo *,int);
Nodo *lista = NULL; 

int main(int argc, char** argv) {
menu();
getch(); 
return 0;
}
menu()	{	
  

int opc,dato,contador; 
contador=0;
do{ 
system("cls");      
cout<<"\t MENU \n";
cout<<"1.-Insertar una nueva cantidad.\n"; 
cout<<"2.-Mostrar la lista de cantidades.\n"; 
cout<<"3.-Localizar una cantidad.\n";
cout<<"4.-Eliminar una cantidad.\n"; 
cout<<"5.-Salir.\n";
cout<<"Que desea hacer: "; 
cin>>opc;
cout<<"\n";

switch(opc){
case 1:
cout<<"Digite el numero: ";
cin>>dato; 
insertarLista(lista,dato); 
cout<<"\n"; 
contador++;
system("pause"); 
break;

case 2:
mostrarLista(lista); 
cout<<"\n";
system("pause");
break;

case 3:
cout<<"\n Digite el numero que desea buscar: "; 
cin>>dato;
buscarLista(lista,dato); 
cout<<"\n";
system("pause");
break;

case 4:
	cout<< "\n Digite el dato a eliminar:";
	cin>> dato;
	eliminarNodo(lista,dato); 
	cout<<"\n";
contador--; 
system("pause"); 
break;

case 5: 
cout<<"\n Gracias"; 
cout<<"\n"; 
system("pause"); 
break;

default:
cout<<"\n Opcion no encontrada"; 
cout<<"\n";
system("pause"); 
break;
}

system("cls");
}
while(opc != 5 || contador == 100);
}
insertarLista(Nodo *&lista,int n)
{
Nodo *nuevo_nodo = new Nodo(); 
nuevo_nodo->dato = n;

Nodo *aux1 = lista; 
Nodo *aux2;

while((aux1 != NULL) && (aux1-> dato < n)){ 
aux2 = aux1;
aux1 = aux1->siguiente;
}


if(lista == aux1){ 
lista = nuevo_nodo;
}
else {
	aux2->siguiente = nuevo_nodo;
	
}
nuevo_nodo->siguiente = aux1; 
cout<<"\nElemento "<<n<<" inserta es correctamente\n";
}


mostrarLista(Nodo *lista){ 
Nodo *actual = new Nodo(); 
actual = lista;

while(actual != NULL){ 
cout<<actual->dato<<endl; 
actual =actual->siguiente;
}


}


buscarLista(Nodo *lista,int n){
bool band = false;

Nodo *actual = new Nodo(); 
actual = lista;

while((actual != NULL) && (actual->dato <=n)){ 
if(actual->dato==n){
band = true;
}
actual = actual->siguiente;
}


if(band == true){
cout<<"El dato "<<n<<" si se encuentra en la lista\n";
 
}
else{
cout<<"El dato "<<n<<" no se encuentra en la lista\n";

}
}

int eliminarNodo(Nodo * &lista,int n){
	if(lista != NULL){
		Nodo *aux_borrar; 
		Nodo *anterior = NULL;

aux_borrar = lista;


while((aux_borrar != NULL)&&(aux_borrar->dato != n)){ 
anterior = aux_borrar;
aux_borrar = aux_borrar->siguiente;
}


if(aux_borrar == NULL){
cout<<"El elemento no ha sido encontrado.\n";
}
else if(anterior == NULL){
lista = lista->siguiente; 
delete aux_borrar;
 
}
else{
anterior->siguiente = aux_borrar->siguiente; 
delete aux_borrar;
 
}

}

}
