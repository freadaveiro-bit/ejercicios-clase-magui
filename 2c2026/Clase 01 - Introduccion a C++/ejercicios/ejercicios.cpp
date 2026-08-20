// ============================================================================
// Ingeniería en Inteligencia Artificial - Algoritmos y Estructura de Datos
// 2C 2026 | Docente: Ing. Magali Marijuan
// ============================================================================

#include "ejercicios.h"

// ============================================================================
// Acá va TU código. Cada función tiene una cáscara con un "TODO": borrá el
// contenido de ejemplo y escribí la implementación.
//
// Los `(void)parametro;` que ves abajo están solo para que la cáscara
// compile sin advertencias antes de que la implementes. Cuando uses el
// parámetro en tu código, borrá la línea `(void)...` correspondiente.
// ============================================================================


// Ejercicio 1 — Hola, C++
std::string saludo(const std::string &nombre, int edad) {
    // TODO: armar y devolver el saludo con el formato pedido.
    // std::cout << "Hola " << nombre << ", tenes " << edad << " anios" ; 
    return "Hola " + nombre + ", tenes " + std::to_string(edad) + " anios.";
}



// Ejercicio 2 — Par o impar
bool esPar(int numero) {
    if (numero % 2 == 0) {
        return true; 
    } else {
        return false;
    }
    // TODO: devolver true si numero es par.
  
}


// Ejercicio 3 — Tabla de multiplicar
std::vector<int> tablaDeMultiplicar(int n) {
    // TODO: llenar el vector con n*1, n*2, ..., n*10 y devolverlo.
    std::vector<int> resultados = {};
    for (int i = 1; i < 11; i ++ ) {
        resultados.push_back(n * i);
    } 
    return resultados;
}


// Ejercicio 4 — esPrimo
bool esPrimo(int n) {
    if (n > 2){
        if (n % 2 != 0){
            return true;
        }
        else{
            return false;
        }
        }
    else{
        return false;
    }
    }
    // TODO: determinar si n es primo.


// Ejercicio 5 — swap por referencia
void swap(int &a, int &b) {
    // TODO: intercambiar los valores de a y b.
    int temp = a;
    a = b;
    b = temp;
}


// Ejercicio 6 — Sobrecarga: maximo
int maximo(int a, int b) {
    // TODO: devolver el mayor entre a y b.
    if ( a > b) {
        return a;
    }
    else {
        return b;
    }
}

double maximo(double a, double b) {
    // TODO: devolver el mayor entre a y b.
     if ( a > b) {
        return a;
    }
    else {
        return b;
    }
}


// Ejercicio 7 — Promedio de un arreglo
double promedioArreglo(const int numeros[], int tamanio) {
    // TODO: sumar los elementos y dividir por tamanio (ojo con la división entera).
    double total = 0;
    for (int i = 0; i < tamanio; i++){
        total += numeros[i];
    }
    double promedio = total / tamanio; 
    return promedio;
}

// Ejercicio 8 — vector de notas
double promedio(const std::vector<double> &notas) {
    // TODO: devolver el promedio de las notas.
    double total = 0;
    size_t tamanio = notas.size(); 
    for (size_t i = 0; i < tamanio; i++){
        total += notas[i];
    }
    double promedio_not = total / static_cast<double>(tamanio);
    return promedio_not;
}

double maxima(const std::vector<double> &notas) {
    // TODO: devolver la nota más alta.
    double nota_max = 0;
    for (size_t i = 0; i < notas.size(); i++){
        if (nota_max < notas[i]){
            nota_max = notas[i];
        }
    }
    return nota_max;
}

// Ejercicio 9 — Contar vocales
int contarVocales(const std::string &texto) {
    // TODO: contar vocales sin distinguir mayúsculas de minúsculas.
    (void)texto;
    return 0;
}

// Propuesto 1 — invertir in-place
void invertir(std::vector<int> &v) {
    // TODO: invertir el orden de los elementos sin crear otro vector.
    (void)v;
}


// Propuesto 2 — contar palabras
int contarPalabras(const std::string &oracion) {
    // TODO: contar palabras separadas por un único espacio.
    (void)oracion;
    return 0;
}


// Ejercicio 10 — Clase Punto
Punto::Punto(double xInicial, double yInicial)
{
    // TODO: inicializar x e y con los valores recibidos.
    (void)xInicial;
    (void)yInicial;
}

double Punto::distanciaAlOrigen() const
{
    // TODO: devolver la distancia entre este punto y el origen (0, 0).
    return 0.0;
}

double Punto::distanciaA(const Punto &otro) const
{
    // TODO: devolver la distancia entre este punto y "otro".
    (void)otro;
    return 0.0;
}

// Ejercicio 11 — Clase Rectangulo
Rectangulo::Rectangulo(double baseInicial, double alturaInicial)
{
    // TODO: inicializar base y altura con los valores recibidos.
    (void)baseInicial;
    (void)alturaInicial;
}

double Rectangulo::area() const
{
    // TODO: devolver el área del rectángulo (base * altura).
    return 0.0;
}

double Rectangulo::perimetro() const
{
    // TODO: devolver el perímetro del rectángulo (2 * (base + altura)).
    return 0.0;
}

bool Rectangulo::esCuadrado() const
{
    // TODO: devolver true si el rectángulo es un cuadrado (base == altura).
    return false;
}
