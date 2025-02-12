#ifndef REGISTROCLINICO_H
#define REGISTROCLINICO_H

#include <string>
#include <iostream>
#include "fecha.h"

class RegistroClinico {
private:
    Fecha fecha;
    std::string diagnostico;
    std::string tratamiento;
    std::string observaciones;

public:
    RegistroClinico(const Fecha &fecha, std::string diagnostico, std::string tratamiento, std::string observaciones);
    RegistroClinico();

    void mostrarRegistro() const;

    Fecha getFecha() const;
    void setFecha(const Fecha &fecha);
    std::string getDiagnostico() const;
    void setDiagnostico(const std::string &diagnostico);
    std::string getTratamiento() const;
    void setTratamiento(const std::string &tratamiento);
    std::string getObservaciones() const;
    void setObservaciones(const std::string &observaciones);
};

#endif