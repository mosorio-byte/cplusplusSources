#include <stdio.h>
#include <stdlib.h>

 int main()
{
	 int primero;
	 int segundo;
	 int c;

	 printf("El siguiente programa calcula la resta de dos numeros\n");

	 printf("Ingrese el primer valor:");
	 scanf("%d", &primero);

	 printf("Ingrese el segundo valor:");
	 scanf("%d", &segundo);

	 c = primero - segundo;

	 printf ("La resta es: %d\n", c);
	 system("pause");
 }
