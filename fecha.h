#ifndef FECHA_H
#define FECHA_H

#include <string>
#include <iostream>

class Fecha {
private:
    int m_dia;    
    int m_mes;  
    int m_anio;   
public:
    Fecha(int dia, int mes, int anio);
    Fecha(int dia, int mes);
    Fecha();

    bool operator==(const Fecha& otra) const;
    bool operator<(const Fecha& otra) const;
    friend std::ostream& operator<<(std::ostream& out, const Fecha& fecha);

    int getDia() const;    
    void setDia(int dia);
    int getMes() const;    
    void setMes(int mes);
    int getAnio() const;    
    void setAnio(int anio);
};

#endif