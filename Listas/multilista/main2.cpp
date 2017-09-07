#include"include.h"

int main(int argc, char const *argv[]) {
  List<Postre> misPostres;
  Postre insert;
  char* busca;
  char* ingrediente;
  int opc, opc_;

  do {
    busca = new char[20];
    ingrediente = new char[20];
    cout << " 1. Buscar postre e imprimir Ingredientes" << endl
          << "2. Buscar postre e insertar ingredientes "<< endl
          << "3. Dar alta de postres con sus ingredientes " << endl
          << "4. Dar de baja un postre con todos sus ingredientes "<< endl
          << "5. Salir"
    << endl;
    cin >> opc;
    switch ( opc ) {
      case 1:
      cout << "Inserte el nombre de su postre: ";
      cin >> busca;
      insert.setNombre( busca );
      cout << misPostres.found( insert ) -> getData();
      break;
      case 2:
      cout << "Inserte el nombre de su postre: ";
      cin >> busca;
      cout << "Su ingrediente a insertar: ";
      cin >> ingrediente;
      insert.setNombre( busca );
      misPostres.found( insert ) -> getData().insertarIngrediente( ingrediente );
      break;
      case 3:
      cout << "Inserte el nombre de su postre: ";
      cin >> busca;
      insert.setNombre( busca );
      do {
        cout << "1. Insertar ingrediente \n 2. Salir"<< endl;
        cin >> opc_;
        switch (opc_) {
          case 1:
          cout << "Su ingrediente a insertar: ";
          cin >> ingrediente;
          insert.insertarIngrediente( ingrediente );
          break;
          case 2:
          opc_ = -1;
          break;
        }
      } while( opc_ != -1 );
      misPostres.insertLast( insert );
      break;
      case 4:
      cout << "Inserte el nombre de su postre: ";
      cin >> busca;
      insert.setNombre( busca );
      misPostres.deleteNode( insert );

      break;
      case 5:
      opc = -1;
      break;

    }
  } while( opc != -1);
  return 0;
}
