#include <iostream>
#include "Arbol/ArbolBinarioAVL.h"
using namespace std;

/*Imagina que trabajas en una tienda que vende una variedad de productos. Cada producto tiene un código único que lo identifica y necesitas gestionar el inventario utilizando un árbol AVL para asegurarte de que el sistema esté optimizado y balanceado. Los productos se identifican únicamente por su código, y no hay productos duplicados en el inventario.
Opciones del menú:
1.	Agregar producto: Inserta un nuevo código de producto en el sistema.
2.	Eliminar producto: Elimina un código de producto del sistema.
3.	Buscar producto: Verifica si un código de producto existe en el inventario.
4.	Mostrar inventario: Imprime el árbol AVL de productos para mostrar su estructura balanceada.
5.	Salir: Finaliza el programa.
*/

void menu() {
    cout << "\n---MENU DE OPCIONES---" << endl;
    cout << "1. Agregar producto." << endl;
    cout << "2. Eliminar producto." << endl;
    cout << "3. Buscar producto." << endl;
    cout << "4. Mostrar inventario." << endl;
    cout << "5. Salir." << endl;
    cout << "Ingrese una opcion: ";
}

int main() {
    ArbolBinarioAVL<int> arbol;
    int opcion, codigo;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el codigo del producto: ";
            cin >> codigo;
            try {
                arbol.put(codigo);
                cout << "Codigo agregado correctamente." << endl;
            } catch (int e) {
                cerr << "Error, el codigo ya existe o es invalido." << endl;
            }
            break;
            case 2:
                cout << "Ingrese el codigo del producto a eliminar: ";
            cin >> codigo;
            try {
                arbol.remove(codigo);
                cout << "Codigo eliminado correctamente." << endl;
            } catch (int e) {
                cerr << "Error, el codigo no existe o es invalido." << endl;
            }
            break;
            case 3:
                cout << "Ingrese el codigo del producto a buscar: ";
            cin >> codigo;
            try {
                if (arbol.search(codigo)) {
                    cout << "Producto " << codigo << " encontrado en el arbol." << endl;
                }
            } catch (int e) {
                cerr << "Error, el codigo es invalido o no existe." << endl;
            }
            break;
            case 4:
                cout << "Arbol AVL:" << endl;
            arbol.print();
            break;
            case 5:
                cout << "Saliendo del programa..." << endl;
            break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}
