#include "fecha.h"
#include <iostream>
#include <iomanip> 

Fecha::Fecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

Fecha::Fecha(int dia, int mes) {
    this->dia = dia;
    this->mes = mes;
    this->anio = 2025;
}

Fecha::Fecha() {
    this->dia = 0;
    this->mes = 0;
    this->anio = 2025;
}

bool Fecha::operator==(const Fecha& fecha) const {
    return (this->dia == fecha.dia && 
            this->mes == fecha.mes && 
            this->anio == fecha.anio);
}

bool Fecha::operator<(const Fecha& fecha) const { 
    if (this->anio < fecha.anio) {
        return true;
    }
    else if (this->anio == fecha.anio) {
        if (this->mes < fecha.mes) {
            return true;
        }
        else if (this->mes == fecha.mes) {
            if (this->dia < fecha.dia) {
                return true;
            }
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Fecha& fecha) {
    out << std::setw(2) << std::setfill('0') << fecha.dia << "/"
        << std::setw(2) << std::setfill('0') << fecha.mes << "/"
        << fecha.anio;
    return out;
}

int Fecha::getDia() {
    return this->dia;
}

void Fecha::setDia(int dia) {
    this->dia = dia;
}

int Fecha::getMes() {
    return this->mes;
}

void Fecha::setMes(int mes) {
    this->mes = mes;
}

int Fecha::getAnio() {
    return this->anio;
}

void Fecha::setAnio(int anio) {
    this->anio = anio;
}