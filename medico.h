#ifndef MEDICO_H
#define MEDICO_H

#include "persona.h"
#include<vector>

class Medico : public Persona {
private:
    std::string especialidad;
    bool disponible;
public:
    Medico(int id, const std::string& nombre, const std::string& direccion, int anioNacimiento,const std::string &especialidad ,bool disponible);  // Constructor
    Medico();
	void generarReporte(const std::string &comentario)const override;
	void mostrarInformacion()const override;

    std::string getEspecialidad() const;

    void setEspecialidad(const std::string &especialidad);

    bool getDisponible() const;

    void setDisponibilidad(bool disponible);

};

void altaMedico(std::vector<Medico *>& medicos,int id, const std::string& nombre, const std::string& direccion, int anioNacimiento,const std::string &especialidad,bool disponible);
void bajaMedico(std::vector<Medico *>& medicos, int id);
void listarPorEspecialidad(const std::vector<Medico *>& medicos, const std::string& especialidad);
void listarPorDisponibilidad(const std::vector<Medico *>& medicos);
bool existeMedicoId(const std::vector<Medico *>& medicos, int id);
void mostrarListaMedicos(const std::vector<Medico *>& medicos);

#endif