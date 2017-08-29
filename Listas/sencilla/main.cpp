#include"include.h"

int main(int argc, char const *argv[]) {
  List<int> test;

  test.insertFirst( 3 );
  test.insertFirst( 13 );
  test.insertFirst( 10 );

  cout << "Lista 1: " << endl;
  test.show();
  cout << endl;



  test.insertLast( 32 );
  test.insertLast( 4 );

  cout << "Lista 2: " << endl;
  test.show();
  cout << endl;

  test.deleteNode( 32 );
  test.deleteNode( 10 );
  test.deleteNode( 4 );

  cout << "Lista 3: " << endl;
  test.show();
  cout << endl;

  /*test.deleteFirst();


  test.deleteLast();

  cout << "Lista 5: " << endl;
  test.show();
  cout << endl; */

  test.insertAfterBy( 4, 7 );

  cout << "Lista 4: " << endl;
  test.show();
  cout << endl;
  return 0;
}
