#ifndef CITAMEDICA_H
#define CITAMEDICA_H

#include <string>
#include <iostream>
#include "paciente.h"
#include "medico.h"

class CitaMedica {
	private:
        int id;
        Paciente paciente;
        Medico medico;
        Fecha fecha;
        bool urgente;
	public:
		CitaMedica(int id,const Paciente &paciente,const Medico &medico, const Fecha &fecha,bool urgente);

		void mostrarCita() const;

                int getId();
                void setId(int id);
                Paciente getPaciente() const;
                void setPaciente(const Paciente &paciente);
                Medico getMedico() const;
                void setMedico(const Medico &medico);
                Fecha getFecha() const;
                void setFecha(const Fecha &fecha);
                bool getUrgente() const;
                void setUrgente(bool urgente);
};

void asignarCita(std::vector<CitaMedica *>& citas,int id,const Paciente &paciente,const Medico &medico, const Fecha &fecha,bool urgente);
bool compararCitas(const CitaMedica *cita1, const CitaMedica *cita2);
void ordenarCitasPorUrgenciaYFecha(std::vector<CitaMedica *>& citas);
void cancelarCita(std::vector<CitaMedica *>& citas, int id);
void modificarCita(std::vector<CitaMedica *>& citas, int id,const Fecha &fecha,bool urgente);
void mostrarCitas(const std::vector<CitaMedica*>& citas);

#endif