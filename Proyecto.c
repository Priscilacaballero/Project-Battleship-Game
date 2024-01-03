#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>

// definicion de variables de manera global para que puedan ser utilizadas en todas las funciones que incluye el programa o donde se necesiten su uso
int tablaj1[8][8];
int tablaj2[8][8];
int tiroj1[8][8];
int tiroj2[8][8];
int atinadoj1=0;
int atinadoj2=0;
int fallidoj1=0;
int fallidoj2=0;
int filafila=0;
int columnacolumna =0;
int i,j;
int barcos[5]= {2,2,3,3,4};
char orientacion[3];
char nombre_jug1[20];
char nombre_jug2[20];

//declaracion de funciones
void inicio();
void ingresarNombres();
void validarCoord();
void barcosJugador1();
void barcosJugador2();
void turnoJugador1();
void turnoJugador2();

//programa principal
int main()
{
    //declaracion de variables locales para el programa principal
    int repetir=1;
    int tottiros=0;
    //cambio del fondo de pantalla negro con letras balncas para evitar errores a la hora del cambio de color de acertados y fallidos
    system("COLOR 0F");
    inicio(); //llamado a la funcion de incio que contiene las instrucciones del juego
    getch();
    system("cls");
    ingresarNombres(); //llamado a la funcion para ingresar los nombres de los jugadores
    getch();
    system("cls");
    printf("%s Es tu turno de llenar el tablero de flota \n",nombre_jug1);
    barcosJugador1(); //llamado a la funcion para llenar el tablero de la flota del jugador 1
    printf("%s Asi quedo tu flota de barcos \n \n", nombre_jug1); //esta linea muestra el tablero de la flota del jugador 1 cuando termine de cargar sus barcos
    printf("Es el turno de %s de llenar su flota de barcos, entregale la computadora \n", nombre_jug2);
    printf(" (Pulsa cualquier boton para continuar) ");
    getch();
    system("cls");
    printf("%s Es tu turno de llenar el tablero de flota\n",nombre_jug2);
    barcosJugador2(); //llamado a la fucion para llenar el tablero de la flota del jugador 2
    printf(" \n %s Asi quedo tu flota de barcos \n \n", nombre_jug2);
    printf("Aqui comienza el juego \n");
    printf("%s Empezara, entregale la computadora \n", nombre_jug1);
    printf("\n (Pulsa cualquier boton para continuar) ");
    getch();
    system("cls");
    while (repetir=1) //estructura repetitiva para los turnos de los jugadores de tirar que termina cuando un jugador gane y la variable repetir sea 0
    {
        turnoJugador1(); // llamado a la funcion que permite realizar el disparo al jugador 1
        printf("\n Es el turno de %s entregale la computadora \n", nombre_jug2);
        printf(" (Pulsa cualquier boton para continuar) ");
        getch();
        system("cls");
        system("COLOR 0F"); // esta linea cambia el color del fondo a negro y las letras blancas porque si esta no se incluye la pantalla se queda del color de fallo o aciertos hasta el turno del otro jugador
        if (atinadoj1 == 14) // estructura condicional que permite imprimir que el jugador 1 gano cuando tenga 14 tiros atinados
        {
            printf("Felicidades %s GANASTE EL JUEGO!!\n", nombre_jug1);
            tottiros=atinadoj1+fallidoj1;
            printf("En total usted realizo %d tiros hasta ganar \n", tottiros); //esta linea imprime en total los tiros que se tuvieron que realizar para ganar
            printf(" (Pulse cualquier boton para finalizar el juego) ");
            getch();
            repetir = 0;

            return 0;
        }
        //este conjunto de lineas realiza lo mismo que el conjunto de lineas anterior, pero esta vez para el jugador 2
        turnoJugador2();
        printf("\n Es el turno de %s entregale la computadora \n", nombre_jug1);
        printf(" (Pulsa cualquier boton para continuar) ");
        getch();
        system("cls");
        system("COLOR 0F");
        if (atinadoj2 == 14)
        {
            printf("Felicidades %s GANASTE EL JUEGO!!\n", nombre_jug2);
            tottiros=atinadoj2+fallidoj2;
            printf("En total usted realizo %d tiros hasta ganar \n", tottiros);
            printf(" (Pulse cualquier boton para finalizar el juego) ");
            getch();
            repetir = 0;
            return 0;
        }
    }
}

//funcion que imprime las reglas del juego y tambien instrucciones
void inicio()
{
    printf("Bienvenido a Battleship, busca un contrincante y que empiece el juego! \n \n");
    printf("REGLAS: \n");
    printf("-Cada jugador debe ingresar 5 barcos, no menos, no mas \n");
    printf("-El que se ingrese como jugador 1 sera quien empiece a llenar su flota y atacar la flota enemiga \n");
    printf("-A la hora de empezar los ataques los jugadores se deben turnar para ingresar  las coordenada del ataque, no importa si el jugador atino al disparo, debe pasarle el turno al otro jugador\n");
    printf("-El jugador que atine a todas las coordenadas de los barcos enemigos ganara!! \n");
    printf("-En total para ganar usted debe haber acertado 14 disparos \n");
    printf("\n \n");
    printf("INDICACIONES: \n");
    printf("-Primero cada jugador ingresara su nombre \n");
    printf("\n");
    printf("-Segundo cada jugador llenara su tablero de flota: ingresar la direccion del barco si lo quiere horizontal(H) o vertical(V) \n");
    printf("Seguido de la orientacion se ingresa la fila y seguido la columna\n");
    printf("OJO: Los valores validos son de A1...A8 hasta H1...H8\n");
    printf("Procure ingresar valores entre ese rango de coordenadas\n");
    printf("Escriba la letra de la columna en MAYUSCULAS, de lo contrario tendra que volver a ingresarla correctamente \n");
    printf("Su flota de barcos se llenara con el numero 1 que indica la posicion en la que estan colocados sus barcos\n");
    printf("\n");
    printf("-Tercero cada jugador empezara a atacar la flota enemiga ingresando las coordenadas a las que desea disparar \n");
    printf("OJO: Cuando usted acierte un tiro le aparecera en el tablero de ataque el numero 7 y la pantalla se pondra de color verde \n");
    printf("Cuando falle aparecera un 8 y se le pondra la pantalla de color rojo\n");
    printf("\n");
    printf(" (Pulse cualquier boton para comenzar el juego) \n");
}

//funcion para ingresar los nombres de los 2 jugadores
void ingresarNombres()
{
    printf("Por favor ingrese el nombre para el jugador numero #1: \n");
    scanf("%s",&nombre_jug1);
    printf("\n");
    printf(" (Pulse cualquier boton para continuar) \n");
    getch();
    system("cls");
    printf("Por favor ingrese el nombre para el jugador numero #2: \n");
    scanf("%s",&nombre_jug2);
    printf("\n");
    printf(" (pulse cualquier boton para continuar) \n");
}

//funcion que valida las coordenadas que ingresan los dos jugadores
void validarCoord()
{
    //declaracion de variables locales de la funcion validarCoord
    int horizontal[8] = {1,2,3,4,5,6,7,8};
    char vertical[8] = {'A','B','C','D','E','F','G','H'};
    int fila = 0;
    char columna = 'Z';
    bool valido = false; //bool se utiliza para almacenar datos verdaderos o falsos
    //bloque de instrucciones
    printf("Ingrese las coordenadas de la columna y fila deseada pegada una de otra. (Si necesita un ejemplo: A3)\n");
    scanf(" %c %i", &columna, &fila);
    //Esta estructura repetitiva se encarga de verificar las coordenadas
    for (int i = 0; i < 8; i++)
    {
        if (fila == horizontal[i])
        {
            for (int j = 0; j < 8; j++)
            {
                if (columna == vertical[j])
                {
                    valido=true; //si las coordenadas ingresadas son validas se puede pasar al siguiente if
                }
            }
        }
    }
    //Esta estructura alternativa funciona para la conversion de las columnas ingresadas como letras a datos enteros
    if (valido)
    {
        filafila = fila-1;
        if (columna == 'A')
        {
            columnacolumna = 0;
        }
        else if (columna == 'B')
        {
            columnacolumna = 1;
        }
        else if (columna == 'C')
        {
            columnacolumna = 2;
        }
        else if (columna == 'D')
        {
            columnacolumna = 3;
        }
        else if (columna == 'E')
        {
            columnacolumna = 4;
        }
        else if (columna == 'F')
        {
            columnacolumna = 5;
        }
        else if (columna == 'G')
        {
            columnacolumna = 6;
        }
        else if (columna == 'H')
        {
            columnacolumna = 7;
        }
    }
    //Si las coordenadas ingresadas son incorrectas se imprime este mensaje apra que el ususario vuelva a intentar
    else
    {
        printf("Por favor ingrese un conjunto de coordenadas correcta. Vuelvalo a intentar\n");
        validarCoord(); //llamado a la funcion nuevamente para que el usuario vuelva a ingresar sus coordenadas y no se quede sin ingresar las coordenadas
    }
}

//funcion que permite cargar los barcos del jugador 1
void barcosJugador1()
{
    //En esta estructira repetitiva se inicia el tablero para que el jugador 1 coloque sus barcos
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tablaj1[i][j]=0;
        }
    }
    //En esta estructura repetitiva se visualiza el tablero de ataque
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tiroj1[i][j]=0;
        }
    }
    //En esta estructura repetitiva se imprime el tablero para ingresar los barcos
    printf("\n   A  B  C  D  E  F  G  H\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%i  ",i+1);
        for (int j = 0; j < 8; j++)
        {
            printf("%i  ",tablaj1[i][j]);
        }
        printf("\n");
    }

    //En esta estructura repetitiva se ingresan los ingresan los barcos con las coordenadas que el usuario desee
    for (int i = 0; i < 5; i++)
    {
        //bloque de instrucciones
        printf("A continuacion usted colocara un barco de tamano: %i\n",barcos[i]);
        printf("Ingrese (H) para orientacion Horizontal o (V) para oriencion Vertical\n");
        scanf("%2s",    &orientacion);
        //estructura altenativa si el usuario ingresa h de horizonal
        if (toupper(orientacion[0]) == 'H') //toupper en esta linea funciona para convertir la h minuscula en mayuscula
        {
            validarCoord(); //llamado a la funcion que valida las coordenas ingresadas por el usuario
            //estructura alternativa que valida la coordenada en la que el usuario quiere colocar su barco 2, si no cabe debe volver a ingresar otra coordenada
            if (barcos[i]==2)
            {
                if (columnacolumna==7)  // Si el usuario ingresa coordenadas con la columna 7 para el barco tamano 2 no se lo permite
                {
                    printf("El barco quedara fuera del marco (tablero) \n");
                    validarCoord(); //llamado nuevamnte a la funcion para ingresar una coordenada correcta
                }
                //posicion del barco en una coordenada valida
                tablaj1[filafila][columnacolumna]=1;
                tablaj1[filafila][columnacolumna+1]=1;
            }
            else if (barcos[i]==3) //En esta estructura alternativa ocurre lo mismo que en la anterior, solo que esta vez validando las posiciones del barco de tamano 3
            {
                if (columnacolumna==7 || columnacolumna==6)
                {
                    printf("El barco quedara fuera del marco (tablero) \n");
                    validarCoord();
                }
                //posicion del barco en una coordenada valida
                tablaj1[filafila][columnacolumna]=1;
                tablaj1[filafila][columnacolumna+1]=1;
                tablaj1[filafila][columnacolumna+2]=1;
            }
            else if (barcos[i]==4) //en esta estructura alternativa ocurre lo mismo que en la anterior, solo que esta vez validando las posicion del barco de tamano 4
            {
                if (columnacolumna==7 || columnacolumna==6 || columnacolumna == 5)
                {
                    printf("El barco quedara fuera del marco (tablero) \n");
                    validarCoord();
                }
                //posicion del barco en una coordenada valida
                tablaj1[filafila][columnacolumna]=1;
                tablaj1[filafila][columnacolumna+1]=1;
                tablaj1[filafila][columnacolumna+2]=1;
                tablaj1[filafila][columnacolumna+3]=1;
            }
        }
        else if (toupper(orientacion[0]) == 'V') // estructura alternativa si el usuario ingresa v de vertical
        {
            //en este conjunto de lineas ocurro lo mismo que arriba solo que en el caso de que el usuario elija orientacion vertical
            validarCoord();
            if (barcos[i]==2)
            {
                if (filafila==7)
                {
                    printf("El barco quedara fuera del marco (tablero) \n");
                    validarCoord();
                }
                tablaj1[filafila][columnacolumna]=1;
                tablaj1[filafila+1][columnacolumna]=1;
            }
            else if (barcos[i]==3)
            {
                if (filafila==7 || filafila==6)
                {
                    printf("El barco quedara fuera del marco (tablero) \n");
                    validarCoord();
                }
                tablaj1[filafila][columnacolumna]=1;
                tablaj1[filafila+1][columnacolumna]=1;
                tablaj1[filafila+2][columnacolumna]=1;
            }
            else if (barcos[i]==4)
            {
                if (filafila==7 || filafila==6 || filafila == 5)
                {
                    printf("El barco quedara fuera del marco (tablero) \n");
                    validarCoord();
                }
                tablaj1[filafila][columnacolumna]=1;
                tablaj1[filafila+1][columnacolumna]=1;
                tablaj1[filafila+2][columnacolumna]=1;
                tablaj1[filafila+3][columnacolumna]=1;
            }
        }



        //Visualizacion de donde el usuario ingreso el barco con las coordenadas deseadas
        printf("\n   A  B  C  D  E  F  G  H\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%i  ",i+1);
            for (int j = 0; j < 8; j++)
            {
                printf("%i  ",tablaj1[i][j]);
            }
            printf("\n");
        }
    }
}


//Funcion que permite cargar los barcos del jugador 2
void barcosJugador2() //en esta funcion ocurre exactamente lo mismo que en la anterior, solo que esta vez ocurre para el jugador 2
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tablaj2[i][j]=0;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tiroj2[i][j]=0;
        }
    }
    printf("\n   A  B  C  D  E  F  G  H\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%i  ",i+1);
        for (int j = 0; j < 8; j++)
        {
            printf("%i  ",tablaj2[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 5; i++)
    {
        //bloque de instrucciones
        printf("A continuacion usted colocara un barco de tamano: %i\n",barcos[i]);
        printf("Ingrese (H) para orientacion Horizontal o (V) para oriencion Vertical:\n");
        scanf("%2s",    &orientacion);

        //en esta linea se verifica la orientacion horizontal si el usuario ingresa la h
        if (toupper(orientacion[0]) == 'H')  //toupper funcina para convertir las letras minusculas en mayusculas
        {
            validarCoord(); // llamado a la funcion para validar las coordenadas ingresadas por el usuario

            //estructura alternativa para asegurarse de que las coordenadas ingresadas por el usuario no provoque que el barco quede fuera del marco del tablero

            if (barcos[i]==2) //verificacion para los barcos tamano 2
            {
                if (columnacolumna==7)
                {
                    printf("El barco quedara fuera del marco (tablero) \n");
                    validarCoord();
                }
                tablaj2[filafila][columnacolumna]=1;
                tablaj2[filafila][columnacolumna+1]=1;
            }
            else if (barcos[i]==3) //verificacion para los barcos tamano 3
            {
                if (columnacolumna==7 || columnacolumna==6)
                {
                    printf("El barco quedara fuera del marco (tablero) \n");
                    validarCoord();
                }
                tablaj2[filafila][columnacolumna]=1;
                tablaj2[filafila][columnacolumna+1]=1;
                tablaj2[filafila][columnacolumna+2]=1;
            }
            else if (barcos[i]==4) //verificacion para los barcos tamano 4
            {
                if (columnacolumna==7 || columnacolumna==6 || columnacolumna == 5)
                {
                    printf("El barco quedara fuera del marco (tablero) \n");
                    validarCoord();
                }
                tablaj2[filafila][columnacolumna]=1;
                tablaj2[filafila][columnacolumna+1]=1;
                tablaj2[filafila][columnacolumna+2]=1;
                tablaj2[filafila][columnacolumna+3]=1;
            }
        }
        else if (toupper(orientacion[0]) == 'V') //en esta linea se verifica la orientacion vertical si el usuario ingresa la v
        {
            //llamado a la funcion que valida las coordenadas ingresadas por el usuario
            validarCoord();

            if (barcos[i]==2) //verificacion de barcos tamano 2
            {
                if (filafila==7)
                {
                    printf("El barco quedara fuera del marco (tablero) \n");
                    validarCoord();
                }
                tablaj2[filafila][columnacolumna]=1;
                tablaj2[filafila+1][columnacolumna]=1;
            }
            else if (barcos[i]==3) //verificacion de barcos tamano 3
            {
                if (filafila==7 || filafila==6)
                {
                    printf("El barco quedara fuera del marco (tablero) \n");
                    validarCoord();
                }
                tablaj2[filafila][columnacolumna]=1;
                tablaj2[filafila+1][columnacolumna]=1;
                tablaj2[filafila+2][columnacolumna]=1;
            }
            else if (barcos[i]==4) //verificacion de barcos tamano 4
            {
                if (filafila==7 || filafila==6 || filafila == 5)
                {
                    printf("El barco quedara fuera del marco (tablero) \n");
                    validarCoord();
                }
                tablaj2[filafila][columnacolumna]=1;
                tablaj2[filafila+1][columnacolumna]=1;
                tablaj2[filafila+2][columnacolumna]=1;
                tablaj2[filafila+3][columnacolumna]=1;
            }
        }
        //impresion del tablero de la flota del usuario para saber como esta quedando su flota
        printf("\n   A  B  C  D  E  F  G  H\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%i  ",i+1);
            for (int j = 0; j < 8; j++)
            {
                printf("%i  ",tablaj2[i][j]);
            }
            printf("\n");
        }
    }
}

// funcion que controla el turno de ataque para el jugador 1
void turnoJugador1()
{
    //impresion del tablero de la flota de barcos del jugador 1
    printf(" %s Es tu turno de atacar! \n", nombre_jug1);
    printf("Asi se encuentra tu flota de barcos: \n");
    printf("\n   A  B  C  D  E  F  G  H\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%i  ",i+1);
        for (int j = 0; j < 8; j++)
        {
            printf("%i  ",tablaj1[i][j]);
        }
        printf("\n");
    }
    //impresion del tablero de ataques realizados por el jugador 1
    printf("\n");
    printf("Asi se encuentra el tablero de disparos a la flota de barcos de %s \n ", nombre_jug2);
    printf("\n   A  B  C  D  E  F  G  H\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%i  ",i+1);
        for (int j = 0; j < 8; j++)
        {
            printf("%i  ",tiroj1[i][j]);
        }
        printf("\n");
    }
    printf(" \n A continuacion ingrese las coordenadas a la que desea atacar a %s \n", nombre_jug2);
    validarCoord(); //llamado de la funcion que valida la entrada de coordenadas que ingresara el usuario
    if (tablaj2[filafila][columnacolumna]==1 && tiroj1[filafila][columnacolumna]==0) //Estructura alternativa que verifica que en la coordenada ingresada por el usuario hay partes del barco (1) o si no hay (0)
    {
        atinadoj1 = atinadoj1+1; //contador para los tiros que ha atinado el jugador 1
        system("COLOR 2F"); //cambio de color de pantalla a verde con letras blancas indicando que atino al disparo
        printf("%s LE ATINASTE AL DISPARO! \n", nombre_jug1);
        tiroj1[filafila][columnacolumna]=7; //impresion del numero 7 en el tablero que indica que ha sido destruido una parte del barco oponente
    }
    else if (tiroj1[filafila][columnacolumna]==7 || tiroj1[filafila][columnacolumna]==8) //Estructura alternativa que verifica si el usuario ya ha disparado a la coordenada disparada
    {
        printf("Usted ya disparo en esta coordenada, Vuelva a disparar (procura que no hayas tirado en esta coordenada anteriormente) \n");
        turnoJugador1(); //Llamado nuevamnete a la funcion turnoJugador1 para que el usuario ingrese otra coordenada
    }
    else
    {
        fallidoj1 = fallidoj1+1; //contador para los tiros que ha fallado el jugador 1
        system("COLOR 4F"); //cambio de color de pantalla a rojo con letras blancas indicando que ha fallado al disparo
        printf("%s Le fallaste al disparo \n", nombre_jug1);
        tiroj1[filafila][columnacolumna]=8; //impresion del numero 8 en el tablero que indica que ha sido fallado el tiro
    }
}

// funcion que controla el turno de ataque para el jugador 2
void turnoJugador2() //en esta funcion ocurre exactamente lo mismo que en la anterior, solo que esta vez ocurre para el jugador 2
{
    printf(" %s Es tu turno de atacar! \n", nombre_jug2);
    printf("Asi se encuentra tu flota de barcos por ahora: \n ");
    printf("\n   A  B  C  D  E  F  G  H\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%i  ",i+1);
        for (int j = 0; j < 8; j++)
        {
            printf("%i  ",tablaj2[i][j]);
        }
        printf("\n");
    }
    printf("Asi se encuentra el tablero de disparos a la flota de barcos de %s \n ", nombre_jug1);
    printf("\n   A  B  C  D  E  F  G  H\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%i  ",i+1);
        for (int j = 0; j < 8; j++)
        {
            printf("%i  ",tiroj2[i][j]);
        }
        printf("\n");
    }
    printf("A continuacion ingrese las coordenadas a la que desea atacar a %s \n", nombre_jug1);
    validarCoord();
    if (tablaj1[filafila][columnacolumna]==1 && tiroj2[filafila][columnacolumna]==0)
    {
        atinadoj2 = atinadoj2+1;
        system("COLOR 2F");
        printf("%s LE ATINASTE AL DISPARO! \n", nombre_jug2);
        tiroj2[filafila][filafila]=7;
    }
    else if (tiroj2[filafila][columnacolumna]==7||tiroj2[filafila][columnacolumna]==8)
    {
        printf("Usted ya disparo en esta coordenada, Vuelva a disparar (procura que no hayas tirado en esta coordenada anteriormente) \n");
        turnoJugador2();
    }
    else
    {
        fallidoj2 = fallidoj2+1;
        system("COLOR 4F");
        printf("%s Le fallaste al disparo \n", nombre_jug2);
        tiroj2[filafila][columnacolumna]=8;
    }
}


