#include "include.h"

int main(int argc, char const *argv[]) {
  Hash test( 5 );
  test.insert( 6 );
  test.insert( 4 );
  test.insert( 1 );
  test.insert( 68 );
  test.insert( 5 );
  test.insert( 0 );

  test.show();
  return 0;
}
