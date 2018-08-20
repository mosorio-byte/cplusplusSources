// DESARROLLADO POR:
// Nombre, carnet
// Nombre, carnet
// Nombre, carnet

#define _CRT_SECURE_NO_DEPRECATE
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

// La representacion de la imagen
typedef struct img
{
	int ancho;
	int alto;
	unsigned char *informacion;
} Imagen;


// Funcion que carga el bmp en la estructura Imagen
void cargarBMP24 (Imagen * imagen, char * nomArchivoEntrada);

// Funcion que guarda el contenido de la estructura imagen en un archivo binario
void guardarBMP24 (Imagen * imagen, char * nomArchivoSalida);

//Funcion que inserta un mensaje en la imagen usando n bits por Byte
void insertarMensaje(Imagen * img , char mensaje[], int n);

//Funcion que lee un mensaje de una imagen dando la longitud del mensaje y el numero de bits por byte usados
void leerMensaje(Imagen * img, char msg[], int l, int n);

unsigned char searchBitinByte(unsigned char Byte,int  bit);

unsigned char sacarInfoByte(unsigned char mensaje[],int Byte,int n);

unsigned char sacarNbits(unsigned char mensaje[],int bitPos,int n);

void writeByte(unsigned char *Byte, int posbit, unsigned char bit);

// Programa principal
// NO MODIFICAR
int main(int argc, char* argv[]) {
	Imagen *img = (Imagen *) malloc (sizeof (Imagen));
	char msg[10000];
    char op[2];
	int num;
	int l;
	int i;
	int n;
	char nomArch1 [256] = "";

	if (argc != 2) {
		printf ("Faltan argumentos - Debe ser un archivo\n");
		system("pause");
		return -1;
	}

	strcat (nomArch1, argv[1]);
	printf(nomArch1);
	// Cargar los datos
	cargarBMP24 (img, nomArch1);

	printf("Indique la accion\n\t1) insertar mensaje\n\t2) leer mensaje\n\n");

	gets(op);

    if(op[0] == '1') {
        printf("ingrese el mensaje a insertar\n");

        gets(msg);

        printf("longitud mensaje: %d\n",strlen(msg));

        num=0;
        printf("ingrese el numero de bits por Byte\n");
        scanf("%d",&num);

        insertarMensaje(img,msg,num);

        guardarBMP24 (img, nomArch1);

        printf("mensaje insertado\n");
    } else if(op[0] =='2') {
        printf("ingrese la longitud del mensaje insertado\n");

        scanf("%d",&l);

        printf("ingrese el numero de bits por Byte\n");
        scanf("%d",&n);

        for(i=0;i<l;i++) {
            msg[i]=0;
        }

        leerMensaje(img,msg, l, n);

        msg[l]=0;

        printf("el mensaje es: %s\n",msg);
    } else {
		printf("%s","Hubo un error al cargar el archivo\n");
	}
	system ("pause");
	return 0;
}

/**
* Inserta un mensaje, de a n bits por componente de color, en la imagen apuntada por img
* parametro img Apuntador a una imagen en cuyos pixeles se almacenará el mensaje.
* parametro mensaje Apuntador a una cadena de caracteres con el mensaje.
* parametro n Cantidad de bits del mensaje que se almacenarán en cada componente de color de cada pixel. 0 < n <= 8.
*/

void insertarMensaje( Imagen * img , char mensaje[], int n ) {
	//TODO  Desarrollar completo en C
	guardarBMP24(img, "Test_modificado.bmp");
}

/**
* Extrae un mensaje de tama–o l, guardado de a n bits por componente de color, de la imagen apuntada por img
* parametro img Apuntador a una imagen que tiene almacenado el mensaje en sus pixeles.
* parametro msg Apuntador a una cadena de caracteres donde se depositará el mensaje.
* parametro l Tama–o en bytes del mensaje almacenado en la imagen.
* parametro n Cantidad de bits del mensaje que se almacenan en cada componente de color de cada pixel. 0 < n <= 8.
*/
void leerMensaje( Imagen * img, char msg[], int l, int n ) {
    //TODO  Desarrollar completo en C
    int ResiduoPaquete = 0;
    unsigned int numBitsBuscar  = l * 8;
    int numPaquetes    = numBitsBuscar / n;
    int numBitsResiduo = numBitsBuscar % n;
    if(numBitsResiduo > 0 ){ResiduoPaquete = 1;}
	unsigned char * desempaquetados;
	desempaquetados = (char*) malloc (l * 8);
	if (desempaquetados == NULL) exit(1);

    int i;
    for(i = 0; i < numPaquetes + ResiduoPaquete ; i++){  //for desde 0 hasta la longitud del mensaje en bytes (caracteres)
        desempaquetados[i] = sacarInfoByte(img->informacion, i, n); //funcion que saca los bits de la imagen y los guarda en arreglo msg de caracteres
        //printf("informacion:%d\n",img->informacion[i]);
    }
    //en desempaquetados quedan guardados los trozos de bits del mensaje, no completos.

    //Empaquetar el mensaje
    int k, j, t = 0 , t1 = n;
    int numBit;
    unsigned char bit;
    unsigned char Byte = 0;

    for(k = 0; k < l; k++){ // Número de Caracteres 
        numBit = 8;
        for(i = t; i < numPaquetes + ResiduoPaquete ; i++){ //Numero de bits modificados 
                for(j = t1-1; j >= 0 ; j--){
                    bit = searchBitinByte(desempaquetados[i], j);
                    writeByte(&Byte, numBit - 1, bit);	//guardando en bytes los bits relacionados 
                    numBit--;
					//printf("bit: %d\n", bit);
                    if(numBit == 0) break;
                }
                if(numBit == 0) break;
        }
        if(numBit == 0 && j != 0){
            t1 = j;					 // Seguir la busqueda de bits desde esta locación en un Byte
        }else{
            t1 = n;				  	// Reseteo la busqueda de bits desde esta la locacion N donde comienzan los bits de datos
        }
        //printf("Byte: %d\n",Byte);        
        if (i == t){t++;} // Incremento del paquete de dato (byte inconcluso) 
        else{ t = i + 1;} // Aumento de un paquete cuando se finaliza en él
		msg[k] = Byte;	  // Se guarda el caracter empaquetado (finalizado)
        Byte = 0;		  // reseteo de byte (caracter finalizado)
    }    
    //msg esta indexado como puntero, así que está funcion no retorna nada.
}

unsigned char searchBitinByte(unsigned char Byte, int bit){
    return (Byte >> bit) & 0x1;
}
void writeByte(unsigned char *Byte, int posbit, unsigned char bit){
    if(bit == 1) {
        *Byte |= (1 << posbit);
    }else{
        *Byte &= ~(1 << posbit);
    }
}
unsigned char sacarInfoByte( unsigned char secuencia[], int bitpos, int n ) {
    unsigned char mascara = 0; //incializa la mascara para selecionar los bits
    int i;
    for (i=0; i < n; i++){
        mascara = (mascara << 1) ^ 0x01; // Creando la mascara para la Cantidad de bits que se desea extraer.
    }
    unsigned char byte = secuencia[bitpos] & mascara; //saca los bits que se necesitan y fija en 0 los que no se miran.
	//printf("informacion : %d\n",  secuencia[bitpos]); //imprime en codigo ascci decimal la informacion leida.

	return byte;
}

/**
* Extrae n bits a partir del bit que se encuentra en la posici—n bitpos en la secuencia de bytes que
* se pasan como parámetro
* parametro secuencia Apuntador a una secuencia de bytes.
* parametro n Cantidad de bits que se desea extraer. 0 < n <= 8.
* parametro bitpos Posición del bit desde donde se extraerán los bits. 0 <= n < 8*longitud de la secuencia
* retorno Los n bits solicitados almacenados en los bits menos significativos de un unsigned char
*/
unsigned char sacarNByte( unsigned char secuencia[], int bitpos, int n ) {
    unsigned char mascara = 0; //incializa la mascara para selecionar los bits
    int i;
    for (i=0; i < n; i++){
        mascara = (mascara << 1) ^ 0x01; // Creando la mascara para la Cantidad de bits que se desea extraer.
    }
    unsigned char byte = secuencia[bitpos] & mascara; //saca los bits que se necesitan y fija en 0 los que no se miran.
	printf("informacion : %d\n", byte); //imprime en codigo ascci decimal la informacion leida.

	return byte;
}
// Lee un archivo en formato BMP y lo almacena en la estructura img
// NO MODIFICAR
void cargarBMP24 (Imagen * imagen, char * nomArchivoEntrada) {
	// bmpDataOffset almacena la posición inicial de los datos de la imagen. Las otras almacenan el alto y el ancho
	// en pixeles respectivamente
	int bmpDataOffset, bmpHeight, bmpWidth;
	int y;
	int x;
	int	residuo;

	FILE *bitmapFile;
	bitmapFile = fopen (nomArchivoEntrada, "rb");
	if (bitmapFile == NULL) {
		printf ("No ha sido posible cargar el archivo: %s\n", nomArchivoEntrada);
		exit (-1);
	}

	fseek (bitmapFile, 10, SEEK_SET); // 10 es la posición del campo "Bitmap Data Offset" del bmp
	fread (&bmpDataOffset, sizeof (int), 1, bitmapFile);

	fseek (bitmapFile, 18, SEEK_SET); // 18 es la posición del campo "height" del bmp
	fread (&bmpWidth, sizeof (int), 1, bitmapFile);
	bmpWidth = bmpWidth*3;

	fseek (bitmapFile, 22, SEEK_SET); // 22 es la posición del campo "width" del bmp
	fread (&bmpHeight, sizeof (int), 1, bitmapFile);

	residuo = (4 - (bmpWidth) % 4)&3; // Se debe calcular los bits residuales del bmp, que surjen al almacenar en palabras de 32 bits

	imagen -> ancho = bmpWidth;
	imagen -> alto = bmpHeight;
	imagen -> informacion = (unsigned char *) calloc (bmpWidth * bmpHeight, sizeof (unsigned char));

	fseek (bitmapFile, bmpDataOffset, SEEK_SET); // Se ubica el puntero del archivo al comienzo de los datos

	for (y = 0; y < bmpHeight; y++)	 {
		for ( x= 0; x < bmpWidth; x++)  {
			int pos = y * bmpWidth + x;
			fread (&imagen -> informacion [pos], sizeof(unsigned char ), 1, bitmapFile);
		}
		fseek(bitmapFile, residuo, SEEK_CUR); // Se omite el residuo en los datos
	}
	fclose (bitmapFile);
}

// Esta funcion se encarga de guardar una estructura de Imagen con formato de 24 bits (formato destino) en un archivo binario
// con formato BMP de Windows.
// NO MODIFICAR
void guardarBMP24 (Imagen * imagen, char * nomArchivoSalida) {
	unsigned char bfType[2];
	unsigned int bfSize, bfReserved, bfOffBits, biSize, biWidth, biHeight, biCompression, biSizeImage, biXPelsPerMeter, biYPelsPerMeter, biClrUsed, biClrImportant;
	unsigned short biPlanes, biBitCount;
	FILE * archivoSalida;
	int y, x;
	int relleno = 0;

	int residuo = (4 - (imagen->ancho) % 4)&3; // Se debe calcular los bits residuales del bmp, que quedan al forzar en palabras de 32 bits


	bfType[2];       // Tipo de Bitmap
	bfType[0] = 'B';
	bfType[1] = 'M';
	bfSize = 54 + imagen -> alto * ((imagen -> ancho)/3) * sizeof (unsigned char);       // Tamanio total del archivo en bytes
	bfReserved = 0;   // Reservado para uso no especificados
	bfOffBits = 54;    // Tamanio total del encabezado
	biSize = 40;      // Tamanio del encabezado de informacion del bitmap
	biWidth = (imagen -> ancho)/3;     // Ancho en pixeles del bitmap
	biHeight = imagen -> alto;    // Alto en pixeles del bitmap
	biPlanes = 1;    // Numero de planos
	biBitCount = 24;  // Bits por pixel (1,4,8,16,24 or 32)
	biCompression = 0;   // Tipo de compresion
	biSizeImage = imagen -> alto * imagen -> ancho;   // Tamanio de la imagen (sin ecabezado) en bits
	biXPelsPerMeter = 2835; // Resolucion del display objetivo en coordenada x
	biYPelsPerMeter = 2835; // Resolucion del display objetivo en coordenada y
	biClrUsed = 0;       // Numero de colores usados (solo para bitmaps con paleta)
	biClrImportant = 0;  // Numero de colores importantes (solo para bitmaps con paleta)

	archivoSalida = fopen (nomArchivoSalida, "w+b"); // Archivo donde se va a escribir el bitmap
	if (archivoSalida == 0) {
		printf ("No ha sido posible crear el archivo: %s\n", nomArchivoSalida);
		exit (-1);
	}

	fwrite (bfType, sizeof(char), 2, archivoSalida); // Se debe escribir todo el encabezado en el archivo. En total 54 bytes.
	fwrite (&bfSize, sizeof(int), 1, archivoSalida);
	fwrite (&bfReserved, sizeof(int), 1, archivoSalida);
	fwrite (&bfOffBits, sizeof(int), 1, archivoSalida);
	fwrite (&biSize, sizeof(int), 1, archivoSalida);
	fwrite (&biWidth, sizeof(int), 1, archivoSalida);
	fwrite (&biHeight, sizeof(int), 1, archivoSalida);
	fwrite (&biPlanes, sizeof(short), 1, archivoSalida);
	fwrite (&biBitCount, sizeof(short), 1, archivoSalida);
	fwrite (&biCompression, sizeof(int), 1, archivoSalida);
	fwrite (&biSizeImage, sizeof(int), 1, archivoSalida);
	fwrite (&biXPelsPerMeter, sizeof(int), 1, archivoSalida);
	fwrite (&biYPelsPerMeter, sizeof(int), 1, archivoSalida);
	fwrite (&biClrUsed, sizeof(int), 1, archivoSalida);
	fwrite (&biClrImportant, sizeof(int), 1, archivoSalida);

	// Se escriben en el archivo los datos RGB de la imagen.
	for (y = 0; y < imagen -> alto; y++) {
		for (x = 0; x < imagen -> ancho; x++) {
			int pos = y * imagen -> ancho + x;
			fwrite (&imagen -> informacion[pos], sizeof(unsigned char), 1, archivoSalida);
		}
	    fwrite(&relleno, sizeof(unsigned char), residuo, archivoSalida);
	}
	fclose(archivoSalida);
}
