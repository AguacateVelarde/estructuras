#include <iostream>
using namespace std;

#include <fstream>
//#include "Lista.cpp"
#include "arbolBinarioBusqueda.cpp"
#include "item.cpp"




int main()
{
  ArbolBinBus<Item> diccionario;
  Item test;
  std::ifstream archivo( "palabras.txt", std::ifstream::in );
  //std::ifstream ifs ("test.txt", std::ifstream::in);


  //archivo.open();
  string palabraAlmacenada;
  char guardar[100];
  int cont = 0;
  string palabraEnviada;

  while ( !archivo.eof() ) {
    guardar[ cont ] = archivo.get();
	//cout << guardar[ cont ];

    if( guardar[ cont ] == char( 32 ) ){
		//cout << "Prueba";
      for( int i = 0; i< cont; i++){
        palabraEnviada += guardar[ i ];
      }
        test.setPalabra ( palabraEnviada );
        diccionario.InsertaNodoSinRep( diccionario.RegresaRaiz(), test );
      cont = 0;
    }else{


      cont++;
    }

  }


archivo.close();
  diccionario.Preorden( diccionario.RegresaRaiz() );
//  diccionario.InsertaNodoSinRep( diccionario.RegresaRaiz(), test );
// diccionario.InsertaNodoSinRep( diccionario.RegresaRaiz(), test2 );



  return 0;
}
