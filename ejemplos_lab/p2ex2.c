#include sstdio.h>
10 Us unarcor
Este programa crea un apuntador de tipo entero y modifica la información a través del mismo.
*/
int main () {
short a = 5, b = 10;
short *apEnt;
apEnt • &a;

printf("a = %i\n", a);
b = *apEnt;
printf("b = %i //*apEnt\n", b);
b = *apEnt+1;
printf("b = %i //*apEnt+1\n", b);
printf("a = %i //*apEnt = 0\n" , a);
return 0;