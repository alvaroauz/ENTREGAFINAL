#include "registroClinico.h"

RegistroClinico::RegistroClinico(const Fecha &fecha, std::string diagnostico, std::string tratamiento, std::string observaciones) {
    this->fecha = fecha;
    this->diagnostico = diagnostico;
    this->tratamiento = tratamiento;
    this->observaciones = observaciones;
}

RegistroClinico::RegistroClinico() {
    this->diagnostico = "-";
    this->tratamiento = "-";
    this->observaciones = "-";
}

void RegistroClinico::mostrarRegistro() const {
    std::cout << "Fecha: " << this->fecha << "\n";
    std::cout << "Diagnóstico: " << this->diagnostico << "\n";
    std::cout << "Tratamiento: " << this->tratamiento << "\n";
    std::cout << "Observaciones: " << this->observaciones << "\n";
}

Fecha RegistroClinico::getFecha() const {
    return this->fecha;
}

void RegistroClinico::setFecha(const Fecha &fecha) {
    this->fecha = fecha;
}

std::string RegistroClinico::getDiagnostico() const {
    return this->diagnostico;
}

void RegistroClinico::setDiagnostico(const std::string &diagnostico) {
    this->diagnostico = diagnostico;
}

std::string RegistroClinico::getTratamiento() const {
    return this->tratamiento;
}

void RegistroClinico::setTratamiento(const std::string &tratamiento) {
    this->tratamiento = tratamiento;
}

std::string RegistroClinico::getObservaciones() const {
    return this->observaciones;
}

void RegistroClinico::setObservaciones(const std::string &observaciones) {
    this->observaciones = observaciones;
}