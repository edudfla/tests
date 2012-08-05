#include <stdlib.h>
#include <stdio.h>
 
int main( int argc, const char * * argv, const char * * envp )
{
       unsigned long n_max = 256;
       if( 2 <= argc ) {
             char * s;
             n_max = strtoul( argv [ 1 ], & s, 0 );
             if( ( '\0' != ( * s ) ) || ( 256 > n_max ) ) {
                    n_max = 256;
             }
       }
       unsigned char * b = ( unsigned char * ) calloc( n_max / 8 + 1, 1 );
       if( ( unsigned char * ) NULL != b ) {
             unsigned long i = 4, j = 2;
             while( i < n_max ) {
                    /*
                    printf( "i = %u, j = %u\n", i, j );
                    */
                    while( i < n_max ) {
                           b [ i >> 3 ] |= ( 1 << ( i & 7 ) );
                           i += j;
                    }
                    i = j + 1;
                    while( ( i < n_max ) && ( 0 != ( b [ i >> 3 ] & ( 1 << ( i & 7 ) ) ) ) ) {
                           i ++;
                    }
                    j = i;
                    i += i;
             }
             /*
             i = 0;
             j = ( ( n_max / 8 ) + 1 );
             while( i < j ) {
                    printf( "%02X", b [ i ] );
                    i ++;
             }
             printf( "\n" );
             */
             i = 0;
             while( i < n_max ) {
                    if( 0 == ( b [ i >> 3 ] & ( 1 << ( i & 7 ) ) ) ) {
                           printf( "%u\n", i );
                    }
                    i ++;
             }
             free( b );
       }
       return 0;
}

