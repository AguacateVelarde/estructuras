class Postre{
private:
  List<char*> ingredientes;
  char *nombre;
public:
  Postre( char[20]);
  Postre();
  void insertarIngrediente( char[20] );
  friend ostream& operator<<( ostream& os, const Postre& obj ){
    os << " Mi postre es: " << obj.nombre<< endl;
    os << "Mis ingredientes son: "<< endl;
    os << obj.ingredientes <<endl;
    return os;
  }
  void setNombre( char[] );
  friend bool operator==( const Postre& lvalue, const Postre& rvalue ){
    return string( lvalue.nombre ) == string( rvalue.nombre );
  }
  friend bool operator!=( const Postre& lvalue, const Postre& rvalue ){
    return string( lvalue.nombre ) != string ( rvalue.nombre ) ;
  }

};
