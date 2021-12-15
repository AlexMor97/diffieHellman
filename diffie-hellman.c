#include <stdlib.h>
#include <stdio.h>  // Para inputs y outputs
#include<time.h>

// Módulo 'p'=761 de un número 'b' elevado a una potencia 'e'
int mod_exp(int b, int e, int p) {
    int i,x,power;
    x = 1;
    power = b % p;

    for(i=0;i<8*sizeof(int);i++) {
        // Si el último bit de la variable 'e' es igual a 1, sacamos el modulo de x*power
        if(e & 1){
            x = (x*power)%p;
        }
        // Movemos un bit a la derecha (dividimos entre 2 la variable e)
        e >>= 1;
        power = (power*power)%p;
    }
    return x;
}

int main() {
    // Números públicos
    int p = 761;
    int raizPrimitiva = 6;


    srand (time(NULL)); // Inicializamos el generador de números aleatorios de C
    int randomx = rand(); // Obtenemos un número aleatorio entre 0 y un valor muy grande
    printf("Nuestro numero random: %d", randomx);

    int X = 160; // El módulo del número que le vamos a mandar a nuestr@ compañer@
    int Y; // El módulo del número que nos ha mandado nuestr@ compañer@

    X = mod_exp(raizPrimitiva, randomx, p);
    printf("\nEnviale el numero X: %d a tu compañer@", X);

    printf("\nDime el numero Y que te ha dado tu compañer@\n");
    scanf("%d", &Y);

    int K = mod_exp(Y,randomx,p); // Nuestra clave, hayada como Y elevado a x modulo p
    printf("\nLa clave obtenida es %d\n", K);

    return 0;
}

