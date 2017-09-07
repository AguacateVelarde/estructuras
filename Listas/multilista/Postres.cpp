Postre::Postre( char nombre[20] ){
  this->nombre = nombre;
}
Postre::Postre( ){
  this->nombre = new char[20];
}
void Postre::insertarIngrediente( char data[20] ){
  ingredientes.insertFirst( data );
}

void Postre::setNombre( char nombre[] ){
  this -> nombre = nombre;
}
