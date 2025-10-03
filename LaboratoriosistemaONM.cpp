#include <iostream>
#include <limits>
#include <cmath>   // Necesario para sqrt
#include <string>
using namespace std;

//Angela Daniela Parra Afanador ID: 000591076 
//Laboratorio Sistema ONM (Observatorio nacional de metorología) 

//Funciones 

// Ingreso de datos
void ingreso(double vector[12], string departamento) {
    cout << "  Ingreso de temperaturas - " << departamento << endl;

    for (int i = 0; i < 12; i++) {
        cout << "Mes " << i + 1 << " : ";
        cin >> vector[i];
    }
    cout << "-----------------------------------------" << endl;
}

// Promedio anual de un departamento
double promedio(double vector[12]) {
    double suma = 0;
    for (int i = 0; i < 12; i++) suma += vector[i];
    return suma / 12;
}

// Promedio nacional
double promNacional(double promeSan, double promeNar, double promeGua) {
    return (promeSan + promeNar + promeGua) / 3;
}

// Mes más caliente de un departamento
int MesMascaliente(double vector[12]) {
    double maxima = vector[0];
    int mes = 1;
    for (int i = 1; i < 12; i++) {
        if (vector[i] > maxima) {
            maxima = vector[i];
            mes = i + 1;
        }
    }
    return mes;
}

// Máximo de un departamento
double maximo(double vector[12]) {
    double maxima  = vector[0];
    for (int i = 1; i < 12; i++) {
        if (vector[i] > maxima ) maxima  = vector[i];
    }
    return maxima ;
}

// Promedio de los picos de cada departamento
double Promdepicios(double vecSan[12], double vecNar[12], double vecGua[12]) {
    double maxSa = maximo(vecSan);
    double maxNa = maximo(vecNar);
    double maxGua = maximo(vecGua);
    return (maxSa + maxNa + maxGua) / 3;
}

// Departamento con mayor promedio anual
string MayorProm(double promeSan, double promeNar, double promeGua) {
    if (promeSan > promeNar && promeSan > promeGua) return "Santander";
    else if (promeNar > promeSan && promeNar > promeGua) return "Nariño";
    else return "Guajira";
}

// Temperatura máxima anual global
void TempMaxAnual(double vecSan[12], double vecNar[12], double vecGua[12]) {
    double maxima = vecSan[0];
    int mes = 1;
    string departamento = "Santander";

    for (int i = 0; i < 12; i++) {
        if (vecSan[i] > maxima) {
            maxima = vecSan[i];
            mes = i + 1;
            departamento = "Santander";
        }
        if (vecNar[i] > maxima) {
            maxima = vecNar[i];
            mes = i + 1;
            departamento = "Nariño";
        }
        if (vecGua[i] > maxima) {
            maxima = vecGua[i];
            mes = i + 1;
            departamento = "Guajira";
        }
    }
    cout << "La temperatura maxima global fue de " << maxima << " en el mes " << mes
<< " en el departamento de " << departamento << endl;
}

// Desviación estándar
double DesviacionEstandar(double vector[12], double prom) {
    double suma = 0;
    for (int i = 0; i < 12; i++) {
        suma += (vector[i] - prom) * (vector[i] - prom);
    }
    return sqrt(suma / 12); // desviación estándar poblacional
}

//Lo que visualiza el usuario
int main() {
    double vecSan[12], vecNar[12], vecGua[12];

    // Ingreso de datos
    ingreso(vecSan, "Santander");
    ingreso(vecNar, "Nariño");
    ingreso(vecGua, "Guajira");

    // Promedios anuales
    double promeSan = promedio(vecSan);
    double promeNar = promedio(vecNar);
	double promeGua = promedio(vecGua);

	// Resultados

	cout << endl;

    cout << "----- Resultados -----" << endl; 
	cout << endl;
    cout << "Promedio anual Santander: " << promeSan << endl;
    cout << "Promedio anual Nariño:    " << promeNar << endl;
    cout << "Promedio anual Guajira:   " << promeGua << endl;

	cout << endl;

    cout << "Promedio nacional: " << promNacional(promeSan, promeNar, promeGua) << endl;
	cout << endl;

    // Mes más caliente por departamento
    cout << "Mes más caliente Santander: " << MesMascaliente(vecSan) << endl;
    cout << "Mes más caliente Nariño:    " << MesMascaliente(vecNar) << endl;
    cout << "Mes más caliente Guajira:   " << MesMascaliente(vecGua) << endl;

	cout << endl;

    // Departamento con mayor promedio
    cout << "Departamento con mayor promedio anual: "
        << MayorProm(promeSan, promeNar, promeGua) << endl;

	cout << endl;

    // Promedio de los picos
    cout << "Promedio de los picos: " << Promdepicios(vecSan, vecNar, vecGua) << endl;

    // Temperatura máxima global
	cout << endl;
    TempMaxAnual(vecSan, vecNar, vecGua);
	cout << endl;   

    // Desviaciones estándar
    cout << "Desviación estándar Santander: " << DesviacionEstandar(vecSan, promeSan) << endl;
    cout << "Desviación estándar Nariño:    " << DesviacionEstandar(vecNar, promeNar) << endl;
    cout << "Desviación estándar Guajira:   " << DesviacionEstandar(vecGua, promeGua) << endl;

    return 0;
}
