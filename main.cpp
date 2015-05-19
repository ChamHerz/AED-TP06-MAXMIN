#include <cstdlib>
#include <iostream>
#include <conio.h>	//Para getch y kbhit

#define KEY_ESC 27
#define KEY_UNO 49

/* Trabajo Practico TP3
Se pide un programa que pida ingresar numeros,
y cuando el usuario termine de ingresar le diga
cual es el mayor y menor. Ejercio 24 de la Guia

Alumno: Adriel CHAMBI
Algoritmos y estructura de datos
Ciclo Lectivo 2015
*/
using namespace std;

int TeclaPresionada(int KeyPress) {
    if (KeyPress == KEY_UNO) {
        cout<<"1"<<endl;
        return 1;
        }
    if (KeyPress == KEY_ESC) {
        cout<<"ESC"<<endl;
        return 99;
        }
}

int main(int argc, char *argv[])
{
	bool TerminoIngresarDatos = false;
	int ConjuntoNumeros[100];
	int CantNumeros = -1;
	int Opcion;
	
	while(TerminoIngresarDatos == false){
		//Menu Principal
		cout<<"Elige una Opcion"<<endl;
	    cout<<"===== === ======"<<endl<<endl;
	    cout<<"1.   - Agregar Numero Entero al Conjunto"<<endl;
	    cout<<"ESC. - Abandona"<<endl<<endl;
	    cout<<"Tu Respuesta es: ";
	    
	    // Ingreso de tecla
	    int tecla = 0;
	    do{
	       if(kbhit())
	           tecla = getch();
	    } while(tecla != KEY_UNO && tecla != KEY_ESC);
	    // Ingreso 1,2,3 o ESC
	    
	    Opcion = TeclaPresionada(tecla);
	    	    
	    if (Opcion == 99) {
	        //99 es escape, sale del programa
	        TerminoIngresarDatos = true;
	        }
	    if (Opcion == 1) {
	        //99 es escape, sale del programa
	        CantNumeros = CantNumeros + 1;
	        cout<<"Ingrese el Numero: ";
	        cin>>ConjuntoNumeros[CantNumeros];
	        }
	}
	
	if (CantNumeros == -1) {
		//No ingreso numeros
		return 0;
	}
	
	int Index = -1;
	int Mayor = ConjuntoNumeros[0];
	int Menor = ConjuntoNumeros[0];
	
	while (Index != CantNumeros){
		Index = Index + 1;
		if (ConjuntoNumeros[Index] >> Mayor) {
			Mayor = ConjuntoNumeros[Index];
		}
		if (ConjuntoNumeros[Index] << Menor) {
			Menor = ConjuntoNumeros[Index];
		}
	}
	
	cout<<endl<<endl<<"El mayor es: "<<Mayor;
	cout<<endl<<endl<<"El menor es: "<<Menor;
    
    cout<<endl<<endl<<"Gracias..."<<endl<<endl;
    system("PAUSE");
}
