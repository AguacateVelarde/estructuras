class Hash{
private:
  int *table;
  int size;
  int cont;
public:
  Hash( int );
  int hashFunction( int );
  int insert( int );
  void show( void );
  int search( int );

};
