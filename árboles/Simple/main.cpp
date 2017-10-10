#include "include.h"

int main(int argc, char const *argv[]) {
  ArbolBinario<int> arbolito;
	int op = 0;
	int argumento1 = 1, argumento2= 1;
		bool argumento3 = 0;
	char argumento3_cambio;
	int n;
	do{
		cout << "+---------------------------+"
			 << "\n       ARBOL BINARIO"
			 << "\n+---------------------------+"
			 << "\n 1. Agregar elemento"
			 << "\n 2. Recorrer arbol"
			 << "\n 3. Borrar datos"
			 << "\n 4. Salir"
			 << endl;
		cin>> op;

		switch(op){
		case 1:
			cout << "Inserta tu dato: ";
			cin >> argumento1;
			if(arbolito.arbolVacio()){
				cout << "Después de qué dato quiere agregarlo [Número]: ";
					cin >> argumento2;
				cout << "Lado derecho o izquierdo [d(derecho)/i(izquierdo)] ";
					cin >> argumento3_cambio;
					while(argumento3_cambio != 'd'&&argumento3_cambio != 'D'&&argumento3_cambio!= 'i'&& argumento3_cambio != 'I'){
						cout << "Dato incorrecto, intente otra vez: ";
						cin>> argumento3_cambio;
					}
				if(argumento3_cambio == 'd'|| argumento3_cambio == 'D')
					argumento3 = 1;
				if(argumento3_cambio == 'i'||argumento3_cambio == 'I')
					argumento3 = 0;
			}

			arbolito.insertar(argumento2, argumento1, argumento3);
			break;
		case 2:

			cout << "\n¿Qué tipo de recorrido desea?"
				<< "\n 1. PreOrden"
				<< "\n 2. inOrden"
				<< "\n 3. PosOrden"
				<< endl;
			cin >> n;
			while (n!=1&& n!=2&& n!=3){
				cout << "No existe esa opción, intente otra vez: ";
				cin >> n;
			}
			arbolito.recorrido(n);
			cout << endl;
			break;
		case 3:
			cout << "Agregue su dato a borrar: ";
			cin>> n;
			arbolito.borrar(n);
			break;
		case 4:
			op =-1;
			break;
		}
		cout << endl << endl;
	}while(op != -1);
	return 0; 
}
