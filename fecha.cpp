#include "fecha.h"
#include <iostream>
#include <iomanip> 

Fecha::Fecha(int dia, int mes, int anio) {
    m_dia = dia;
    m_mes = mes;
    m_anio = anio;
}

Fecha::Fecha(int dia, int mes) {
    m_dia = dia;
    m_mes = mes;
    m_anio = 2025;
}

Fecha::Fecha() {
    m_dia = 0;
    m_mes = 0;
    m_anio = 2025;
}

bool Fecha::operator==(const Fecha& otra) const {
    return (m_dia == otra.m_dia &&
        m_mes == otra.m_mes &&
        m_anio == otra.m_anio);
}

bool Fecha::operator<(const Fecha& otra) const {
    if (m_anio < otra.m_anio) {
        return true;
    }
    else if (m_anio == otra.m_anio) {
        if (m_mes < otra.m_mes) {
            return true;
        }
        else if (m_mes == otra.m_mes) {
            if (m_dia < otra.m_dia) {
                return true;
            }
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Fecha& fecha) {
    out << std::setw(2) << std::setfill('0') << fecha.m_dia << "/"
        << std::setw(2) << std::setfill('0') << fecha.m_mes << "/"
        << fecha.m_anio;
    return out;
}

int Fecha::getDia() const {
    return m_dia;
}

void Fecha::setDia(int dia) {
    m_dia = dia;
}

int Fecha::getMes() const {
    return m_mes;
}

void Fecha::setMes(int mes) {
    m_mes = mes;
}

int Fecha::getAnio() const {
    return m_anio;
}

void Fecha::setAnio(int anio) {
    m_anio = anio;
}