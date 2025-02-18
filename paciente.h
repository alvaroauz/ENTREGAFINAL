#ifndef PACIENTE_H
#define PACIENTE_H

#include "persona.h"
#include "fecha.h"
#include "registroClinico.h"
#include <vector>  

class Paciente : public Persona {
private:
    int telefono;
    std::string notas;
    Fecha fechaRegistro;
    std::vector<RegistroClinico> historialClinico;

public:
    Paciente(int id, const std::string& nombre, const std::string& direccion,
        int anioNacimiento, int telefono, const std::string& notas,
        const Fecha& fecha);
    Paciente();

    void generarReporte(const std::string& comentario) const override;
    void mostrarInformacion() const override;

    std::string getNotas() const;
    void setNotas(const std::string& notas);

    int getTelefono() const;
    void setTelefono(int telefono); 

    Fecha getFechaRegistro() const;
    void setFechaRegistro(const Fecha& fechaRegistro);

    void modificarDatosPersonales(const std::string& direccion, int edad,
        const std::string& notas, int telefono);
    void mostrarHistorial() const;
    void agregarRegistro(const RegistroClinico& registro);
    int numRegistros() const;
    std::vector<RegistroClinico> obtenerRegitrosClinicos() const;
};


void listarPorFechaRegistro(const std::vector<Paciente*>& pacientes,
    const Fecha& fecha);
void busquedaPorNombre(const std::vector<Paciente*>& pacientes,
    const std::string& nombre);
void busquedaPorId(const std::vector<Paciente*>& pacientes, int id);
void altaPaciente(std::vector<Paciente*>& pacientes, int id,
    const std::string& nombre, const std::string& direccion,
    int anioNacimiento, int telefono, const std::string& notas,
    const Fecha& fecha);
void bajaPaciente(std::vector<Paciente*>& pacientes, int id);
bool existePacienteId(const std::vector<Paciente*>& pacientes, int id);
void mostrarListaPacientes(const std::vector<Paciente*>& pacientes);

#endif