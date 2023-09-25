#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo* cha;
    Nodo* rda;
};

Nodo* creNo(int);

void insertar(Nodo*&, int);
void pre(Nodo*);
void ino(Nodo*);
void pos(Nodo*);
void buscar(Nodo*, int valor);
Nodo* encontrarMinimo(Nodo*);
Nodo* eliminar(Nodo*&, int);
Nodo* arb = NULL;

Nodo* creNo(int x) {
    Nodo* nue = new Nodo();
    nue->dato = x;
    nue->cha = NULL;
    nue->rda = NULL;

    return nue;
}

int main() {
    int dato, op;

    do {
        cout << "\t.:MENU:. \n";
        cout << "\n 1. Insertar un nuevo dato\n";
        cout << "\n 2. Preorden\n";
        cout << "\n 3. Inorden\n";
        cout << "\n 4. Posorden\n";
        cout << "\n 5. Eliminar\n";
        cout << "\n 6. Salir\n";

        cin >> op;

        switch (op) {
        case 1:
            cout << "\nDigite un numero: ";
            cin >> dato;
            insertar(arb, dato);
            cout << "\n";
            system("pause");
            break;
        case 2:
            cout << "\n Imprimiendo en Preorden";
            pre(arb);
            cout << "\n";
            break;
        case 3:
            cout << "\n Imprimiendo en Inorden";
            ino(arb);
            cout << "\n";
            break;
        case 4:
            cout << "\n Imprimiendo en Posorden";
            pos(arb);
            cout << "\n";
            break;
        case 5:
            cout << "\nDigite el valor a eliminar: ";
            cin >> dato;
            arb = eliminar(arb, dato);
            cout << "Nodo eliminado." << endl;
            cout << "\n";
            system("pause");
            break;
        }

    } while (op != 6);
    getch();
    return 0;
}

void pre(Nodo* arb) {
    if (arb != NULL) {
        printf("%d,", arb->dato);
        pre(arb->rda);
        pre(arb->cha);
    }
}

void ino(Nodo* arb) {
    if (arb != NULL) {
        ino(arb->rda);
        printf("%d,", arb->dato);
        ino(arb->cha);
    }
}

void pos(Nodo* arb) {
    if (arb != NULL) {
        pos(arb->rda);
        pos(arb->cha);
        printf("%d,", arb->dato);
    }
}

void buscar(Nodo* arb, int valor) {
    if (arb == NULL) {
        return;
    } else {
        if (valor == arb->dato) {
            return;
        } else {
            if (valor < arb->dato) {
                return buscar(arb->rda, valor);
            } else {
                return buscar(arb->cha, valor);
            }
        }
    }
}

void insertar(Nodo*& arb, int x) {
    if (arb == NULL) {
        Nodo* nue = creNo(x);
        arb = nue;
    } else {
        int raiz = arb->dato;
        if (x < raiz) {
            insertar(arb->rda, x);
        } else {
            insertar(arb->cha, x);
        }
    }
}

Nodo* encontrarMinimo(Nodo* nodo) {
    while (nodo->cha != NULL) {
        nodo = nodo->cha;
    }
    return nodo;
}

Nodo* eliminar(Nodo*& arb, int valor) {
    if (arb == NULL) {
        return arb;
    }

    if (valor < arb->dato) {
        arb->rda = eliminar(arb->rda, valor);
    } else if (valor > arb->dato) {
        arb->cha = eliminar(arb->cha, valor);
    } else {
        if (arb->rda == NULL) {
            Nodo* temp = arb->cha;
            delete arb;
            return temp;
        } else if (arb->cha == NULL) {
            Nodo* temp = arb->rda;
            delete arb;
            return temp;
        }

        Nodo* temp = encontrarMinimo(arb->cha);
        arb->dato = temp->dato;
        arb->cha = eliminar(arb->cha, temp->dato);
    }
    return arb;
}
