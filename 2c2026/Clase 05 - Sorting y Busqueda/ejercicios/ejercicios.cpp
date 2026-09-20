#include "ejercicios.h"
#include <algorithm>  // para std::swap

// ============================================================================
// Acá va TU código. Cada función tiene una cáscara con un "TODO": borrá el
// contenido de ejemplo y escribí la implementación.
//
// Los `(void)parametro;` que ves abajo están solo para que la cáscara
// compile sin advertencias antes de que la implementes. Cuando uses el
// parámetro en tu código, borrá la línea `(void)...` correspondiente.
// ============================================================================

// ============================================================================
// ALGORITMOS DE ORDENAMIENTO
// ============================================================================

// Ejercicio 1 — Bubble Sort
void bubbleSort(std::vector<int>& v)
{
    // TODO: implementar bubble sort.
    // Recordá:
    //   - Recorrer el vector comparando elementos adyacentes
    //   - Si v[j] > v[j+1], intercambiarlos
    //   - Optimización: si en una pasada no hubo intercambios, terminar
    size_t n = v.size();
    for (size_t i = 0; i + 1 < n; i++){
        bool huboswap = false;
        for (size_t j = 0; j < n - 1 - i; j++){
            if (v[j] > v[j + 1]){
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                huboswap = true;
            }
        }
        if(!huboswap){
            break;
        }
    }
}

// Ejercicio 2 — Insertion Sort
void insertionSort(std::vector<int>& v)
{
    // TODO: implementar insertion sort.
    // Recordá:
    //   - Para cada elemento desde la posición 1, "insertarlo" en la parte
    //     ya ordenada (posiciones 0 a i-1)
    //   - Desplazar hacia la derecha los elementos mayores
    size_t n = v.size();
    for (size_t i = 1; i < n; i++){
        int key = v[i];
        size_t j = i;
        while (j > 0 and v[j - 1] > key){
            v[j] = v[j - 1];
            j--;
        }
        v[j] = key;
    }
}

// Ejercicio 3 — Selection Sort
void selectionSort(std::vector<int>& v)
{
    // TODO: implementar selection sort.
    // Recordá:
    //   - Para cada posición i, buscar el mínimo en [i, n-1]
    //   - Intercambiar v[i] con v[indiceMinimo]
    size_t n = v.size();
    for (size_t i = 0; i + 1 < n; i++){
        size_t min = i;
        for (size_t j = i + 1; j < n; j++){
            if (v[j] < v[min]){
                min = j;
            }
        }
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}

// ============================================================================
// ALGORITMOS DE BÚSQUEDA
// ============================================================================

// Ejercicio 4 — Búsqueda Lineal
int busquedaLineal(const std::vector<int>& v, int buscado)
{
    // TODO: implementar búsqueda lineal.
    // Recorrer el vector y devolver el índice si encontrás el elemento.
    // Si llegás al final sin encontrarlo, devolver -1.
    size_t n = v.size();
    for (size_t i = 0; i < n; i++){
        if (v[i] == buscado){
            return static_cast<int>(i);
        }
    }
    return -1;
}

// Ejercicio 5 — Búsqueda Binaria (iterativa)
int busquedaBinaria(const std::vector<int>& v, int buscado)
{
    // TODO: implementar búsqueda binaria iterativa.
    // Recordá:
    //   - Mantener dos índices: izq y der
    //   - Calcular medio = izq + (der - izq) / 2
    //   - Comparar v[medio] con buscado y ajustar izq o der
    //   - Terminar cuando izq > der (no encontrado) o cuando encontrás
    // Precondición: el vector está ordenado.
    size_t n = v.size();
    if (n == 0){
        return -1;
    }
    size_t izq = 0;
    size_t der = n - 1;
    while (true){
        size_t mid = izq + (der - izq) / 2;
        if (v[mid] == buscado){
            return static_cast<int>(mid);
        }
        else if (v[mid] < buscado){
            izq = mid + 1;
        }
        else{
            if (mid == izq){
                break;  // no está: ya no se puede achicar más el rango
            }
            der = mid - 1;
        }
    }
    return -1;
}

// Ejercicio 6 — Búsqueda Binaria (recursiva)
int busquedaBinariaRec(const std::vector<int>& v, int buscado, int izq, int der)
{
    // TODO: implementar búsqueda binaria recursiva.
    // Caso base: izq > der => devolver -1 (no encontrado)
    // Caso recursivo: calcular medio, comparar, y llamar recursivamente
    //                 con el rango reducido.
    // Precondición: el vector está ordenado.
   if (izq > der){
        return -1;
    }
    int mid = izq + (der - izq) / 2;
    size_t midIdx = static_cast<size_t>(mid);
    if (v[midIdx] == buscado){
        return mid;
    }
    else if (v[midIdx] < buscado){
        return busquedaBinariaRec(v, buscado, mid + 1, der);
    }
    else{
        return busquedaBinariaRec(v, buscado, izq, mid - 1);
    }
}

// ============================================================================
// EJERCICIOS PROPUESTOS
// ============================================================================

// Propuesto 1 — Verificar si está ordenado
bool estaOrdenado(const std::vector<int>& v)
{
    // TODO: recorrer el vector y verificar que cada elemento sea <= al siguiente.
    // Un vector vacío o con un solo elemento se considera ordenado.
    size_t n = v.size();
    for (size_t i = 0; i + 1 < n; i++){
        if (v[i] > v[i + 1]){
            return false;
        }
    }
    return true;
}

// Propuesto 2 — Encontrar el mínimo
int indiceMinimo(const std::vector<int>& v)
{
    // TODO: recorrer el vector buscando el índice del elemento mínimo.
    // Precondición: el vector no está vacío.
    size_t n = v.size();
    int min = v[0];
    size_t pos = 0;
    for (size_t i = 1; i < n; i++){
        if (v[i] < min){
            min = v[i];
            pos = i;
        }
    }
    return static_cast<int>(pos);
}

// Propuesto 3 — Contar ocurrencias
int contarOcurrencias(const std::vector<int>& v, int buscado)
{
    // TODO: contar cuántas veces aparece buscado en el vector.
    int times = 0;
    size_t tam = v.size();
    for (size_t i = 0; i < tam; i++){
        if (v[i] == buscado){
            times++;
        }
    }
    return times;
}

// Propuesto 4 — Encontrar duplicados
bool tieneDuplicados(const std::vector<int>& v)
{
    // TODO: devolver true si hay algún elemento repetido.
    // Pista 1 (fuerza bruta): para cada elemento, buscar si aparece más adelante.
    // Pista 2 (más eficiente): ordenar una copia y buscar adyacentes iguales.
    std::vector<int> w = v;
    bubbleSort(w);
    size_t tam = w.size();
    for (size_t i = 0; i + 1 < tam; i++){
        if (w[i] == w[i + 1]){
            return true;
        }
    }
    return false;
}
