Hash::Hash( int size ){
  this -> size = size;
  table = new int [size];
  for (int i = 0; i < size; i++) {
    table[ i ] = -1;
  }
  cont = 0;
}
int Hash::hashFunction( int data ){
  return data % size;
}
int Hash::insert( int data ){
  int index = hashFunction ( data );


  if( table[ index ] == -1 ){
    table[ index ] = data;
    cont++;
  }else if( cont < size ){
    while( table [ index ] != -1)
      index++;
    table[ index ] = data;
    cont++;
  }else{
    cout  << "Te pasaste, knarl" << endl;
  }
}
void Hash::show( ){
  for(int i=0; i<size; i++){
    cout << search( table[ i ] ) << ". " << table[ i ] << endl;
  }
  cout << endl;
}


int Hash::search( int dato ){
  return hashFunction( dato );
}
