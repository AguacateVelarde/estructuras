#include <iostream>
using namespace std;
#include "Lista.cpp"
class Item{
private:
  string palabra;
  Lista<int> posiciones;

public:
  Item( string );
  Item( ){}
  void insertarPosicion ( int );
  void setPalabra( string );
  
  friend bool operator<( const Item I1, const Item I2 ){
    return I1.palabra < I2.palabra;
  }
  friend bool operator>( const Item I1, const Item I2 ){
    return I1.palabra > I2.palabra;
  }
  friend ostream& operator<<( ostream& o, const Item & obj ){
	  //return o<< obj.palabra << "\t" << endl;
    return o<< obj.palabra << "\t" << endl;//obj.posiciones.ImprimeRecursivo( obj.posiciones.RegresaPrimero() );
  }
};


Item::Item( string palabra  ){
  this -> palabra = palabra;
}

void Item::insertarPosicion( int posicion ){
  posiciones.InsertaFinal(  posicion );
}

void Item::setPalabra( string palabra ){
  this -> palabra = palabra;
}
