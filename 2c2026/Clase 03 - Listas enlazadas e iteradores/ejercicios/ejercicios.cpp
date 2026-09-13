#include "ejercicios.h"

// ============================================================================
// Acá va TU código. Cada función tiene una cáscara con un "TODO": borrá el
// contenido de ejemplo y escribí la implementación.
//
// Los `(void)parametro;` que ves abajo están solo para que la cáscara
// compile sin advertencias antes de que la implementes. Cuando uses el
// parámetro en tu código, borrá la línea `(void)...` correspondiente.
// ============================================================================

// Constructor: inicializa una lista vacía
ListaSimple::ListaSimple()
    : primero(nullptr), ultimo(nullptr), largo(0)
{
    // El constructor ya está implementado usando la lista de inicialización.
    // No hace falta que modifiques nada acá.
}

// Destructor: libera todos los nodos
ListaSimple::~ListaSimple()
{
    // TODO: recorrer la lista y liberar cada nodo con delete.
    // Recordá guardar el puntero al siguiente ANTES de hacer delete del actual.
    // Al final, primero, ultimo y largo deberían quedar en su estado inicial
    // (aunque técnicamente no importa porque el objeto se destruye).
    (void)ultimo;  // Silencia warning hasta que implementes las funciones
    Nodo *actual = primero;
    while (actual != nullptr){
        Nodo *siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

// Devuelve true si la lista está vacía
bool ListaSimple::vacia() const
{
    // Ya está implementado: la lista está vacía si no tiene primer elemento.
    Nodo *actual = primero;
    if (actual == nullptr){
        return true;
    }
    return false;
}
// Devuelve la cantidad de elementos
size_t ListaSimple::tamanio() const
{
    // Ya está implementado: devolvemos el contador.
    size_t contador = 0;
    Nodo *actual = primero;
    while (actual != nullptr){
        actual = actual->siguiente;
        contador++;
    }
    return contador;
}

// Ejercicio 1 — Insertar al inicio
void ListaSimple::insertarAlInicio(int valor)
{
    // TODO: crear un nuevo nodo y ponerlo al principio de la lista.
    // Casos a considerar:
    //   - La lista estaba vacía (hay que actualizar también `ultimo`)
    //   - La lista ya tenía elementos
    Nodo* nuevo = new Nodo(valor, primero);
    primero = nuevo;
    if (ultimo == nullptr) {   // la lista estaba vacía
        ultimo = nuevo;
    }
    largo++;
}

// Ejercicio 2 — Insertar al final
void ListaSimple::insertarAlFinal(int valor)
{
    // TODO: crear un nuevo nodo y ponerlo al final de la lista.
    // Casos a considerar:
    //   - La lista estaba vacía (hay que actualizar también `primero`)
    //   - La lista ya tenía elementos
    Nodo* nuevo = new Nodo(valor, nullptr);
    if (ultimo == nullptr) {   // la lista estaba vacía
        primero = nuevo;
    } else {
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;
    largo++;
}

// Ejercicio 3 — Buscar un elemento
bool ListaSimple::buscar(int valor) const
{
    // TODO: recorrer la lista buscando el valor.
    // Devolver true si lo encontrás, false si llegás al final sin encontrarlo.
    Nodo *actual = primero;
    while (actual != nullptr){
        if (actual->dato == valor){
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

// Ejercicio 4 — Obtener el primer elemento
int &ListaSimple::frente()
{
    // TODO: devolver el dato del primer nodo.
    // Precondición: la lista no está vacía.
    return primero->dato; 
}

const int &ListaSimple::frente() const
{
    // TODO: versión const de frente()
    return primero->dato;
}

// Ejercicio 5 — Obtener el último elemento
int &ListaSimple::final()
{
    // TODO: devolver el dato del último nodo.
    // Precondición: la lista no está vacía.
    return ultimo->dato;
}

const int &ListaSimple::final() const
{
    // TODO: versión const de final()
    return ultimo->dato;
}

// Ejercicio 6 — Eliminar el primer elemento
void ListaSimple::eliminarPrimero()
{
    // TODO: eliminar el primer nodo y liberar su memoria.
    // Casos a considerar:
    //   - La lista tenía un solo elemento (queda vacía)
    //   - La lista tenía más de un elemento
    // Precondición: la lista no está vacía.
    if (largo == 1){
        delete primero;
        primero = nullptr;
        ultimo = nullptr;
        largo--;
    }
    else{
        Nodo *temp = primero->siguiente;
    delete primero;
    primero = temp;
    largo--;
    }
}

// Ejercicio 7 — Eliminar por valor
bool ListaSimple::eliminar(int valor)
{
    // TODO: buscar el primer nodo con el valor dado y eliminarlo.
    // Devolver true si lo encontraste y eliminaste, false si no estaba.
    // Casos a considerar:
    //   - El valor está en el primer nodo
    //   - El valor está en el último nodo
    //   - El valor está en un nodo del medio
    //   - El valor no está en la lista
    //   - La lista tiene un solo elemento y es el que hay que eliminar
    Nodo *anterior = nullptr;
    Nodo *actual = primero;

    while (actual != nullptr and actual->dato != valor){
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == nullptr){
        return false;
    }
    if (anterior == nullptr){
        primero = actual->siguiente;
    }
    else {
        anterior->siguiente = actual->siguiente;
    }
    if (actual == ultimo){
        ultimo = anterior;
    }
    delete actual;
    largo--;
    return true;
}

// Ejercicio 8 — Obtener elemento en posición i
int &ListaSimple::operator[](size_t i)
{
    // TODO: recorrer la lista hasta la posición i y devolver el dato.
    // Precondición: i < tamanio()
    size_t vuelta = 0;
    Nodo *actual = primero;
    static int dummy = 0; 
    while (actual != nullptr){
        if (vuelta == i){
            return actual->dato;
        }
        actual = actual->siguiente;
        vuelta++;
    }
    return dummy;
}

const int &ListaSimple::operator[](size_t i) const
{
    // TODO: versión const de operator[]
    size_t vuelta = 0;
    Nodo *actual = primero;
    static int dummy = 0; 
    while (actual != nullptr){
        if (vuelta == i){
            return actual->dato;
        }
        actual = actual->siguiente;
        vuelta++;
    }
    return dummy;
}
// Propuesto 1 — Insertar en posición
void ListaSimple::insertarEnPosicion(size_t i, int valor)
{
    // TODO: insertar un nuevo nodo en la posición i.
    // Si i == 0, es insertarAlInicio.
    // Si i == tamanio(), es insertarAlFinal.
    // Precondición: i <= tamanio()
    if (i == 0){
        insertarAlInicio(valor);
    }
    else if (i == tamanio()){
        insertarAlFinal(valor);
    }
    else{
        Nodo *actual = primero;
        Nodo *anterior = nullptr;
        Nodo *nuevo = new Nodo (valor, nullptr);
        size_t vueltas = 0;
        while (vueltas != i){
            anterior = actual;
            actual = actual->siguiente;
            vueltas++;
        }
        nuevo->siguiente = actual;
        anterior->siguiente = nuevo;
    }
}

// Propuesto 2 — Invertir la lista
void ListaSimple::invertir()
{
    // TODO: invertir el orden de los nodos in-place.
    // Pista: recorrer la lista cambiando los punteros `siguiente` para que
    // apunten al nodo anterior. Vas a necesitar 3 punteros auxiliares.
    Nodo *anterior = nullptr;
    Nodo *actual = primero;
    while (actual != nullptr){
        Nodo *siguiente = actual->siguiente;
        actual->siguiente = anterior;
        anterior = actual;
        actual = siguiente;
    }
    Nodo *temp = primero;
    primero = anterior;
    ultimo =  temp;
}
