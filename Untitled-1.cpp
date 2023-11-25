#include <iostream>

using namespace std;

struct Contacto {
    int numero;
    string nombre;
    Contacto* siguiente;
};

void agregarContacto(Contacto** pila, int numero) {
    Contacto* nuevoContacto = new Contacto;
    nuevoContacto->numero = numero;
    nuevoContacto->siguiente = *pila;

    // Aquí verifico si el número ya existe en la pila
    Contacto* actual = *pila;
    Contacto* anterior = nullptr;
    while (actual != nullptr && actual->numero != numero) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual != nullptr) {
        if (anterior != nullptr) {
            anterior->siguiente = actual->siguiente;
            nuevoContacto->nombre = actual->nombre; // Asigna el nombre del contacto existente
            delete actual; // Liberar memoria del contacto existente
        } else {
            *pila = actual->siguiente;
            nuevoContacto->nombre = actual->nombre; // Asigna el nombre del contacto existente
            delete actual; // Liberar memoria del contacto existente
        }
    } else {
        cout << "Ingrese el nombre del contacto: ";
        cin >> nuevoContacto->nombre;
    }

    *pila = nuevoContacto;
}

void extraerContacto(Contacto** pila) {
    if (*pila == nullptr) {
        cout << "La pila está vacía" << endl;
        return;
    }

    Contacto* contactoAEliminar = *pila;
    *pila = (*pila)->siguiente;

    cout << "Contacto eliminado: " << contactoAEliminar->nombre << " (" << contactoAEliminar->numero << ")" << endl;

    delete contactoAEliminar; // Liberar memoria del contacto eliminado
}

int main() {
    Contacto* pila = nullptr;

    int opcion = 0;

    while (opcion != 3) {
        cout << "1. Agregar contacto" << endl;
        cout << "2. Extraer contacto" << endl;
        cout << "3. Salir" << endl;

        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                int numero;
                cout << "Ingrese el número del contacto: ";
                cin >> numero;
                agregarContacto(&pila, numero);
                break;

            case 2:
                extraerContacto(&pila);
                break;

            case 3:
                break;

            default:
                cout << "Opción inválida... Intenta de nuevo" << endl;
                break;
        }
    }

    return 0;
}