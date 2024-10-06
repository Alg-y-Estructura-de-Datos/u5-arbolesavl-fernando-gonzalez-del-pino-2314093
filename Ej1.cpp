#include <iostream>
#include "Arbol/ArbolBinarioAVL.h"
using namespace std;

/*Un almacén necesita gestionar su inventario de productos. Cada producto tiene un número único de identificación (ID), y el sistema debe mantener el inventario organizado para realizar búsquedas rápidas de productos y permitir actualizaciones del stock.
Utilizar un árbol AVL para almacenar los IDs de los productos. El árbol debe mantenerse balanceado para garantizar búsquedas rápidas.
Crear un sistema con un menú que permita gestionar las siguientes opciones:
1.	Insertar un código de producto.
2.	Eliminar un código de producto.
3.	Buscar un producto por código.
4.	Imprimir el árbol (mostrando su estructura balanceada).
5.	Salir del programa.
*/

void menu() {
    cout << "\n---MENU DE OPCIONES---" << endl;
    cout << "1. Insertar un codigo de producto." << endl;
    cout << "2. Eliminar un codigo de producto." << endl;
    cout << "3. Buscar un producto por codigo." << endl;
    cout << "4. Imprimir el arbol (mostrando su estructura balanceada)." << endl;
    cout << "5. Salir del programa." << endl;
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
                    cout << "Codigo insertado correctamente." << endl;
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
                        cout << "El codigo " << codigo << " existe en el arbol." << endl;
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
