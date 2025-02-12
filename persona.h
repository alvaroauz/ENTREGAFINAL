#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

const int ANIO_ACTUAL = 2025;

//clase basica abstracta
class Persona {
	protected:
        int id;
		std::string nombre;
		int edad;
		std::string direccion;
		int anioNacimiento;
	public:
		Persona(int id, const std::string& nombre, const std::string& direccion, int anioNacimiento);
        Persona();

		//metodo para calcular la edad de la persona 
		void calcularEdad();

		//metodo abstracto para mostrar historial
		virtual void generarReporte(const std::string &comentario)const = 0;  //metodo puro

		virtual void mostrarInformacion()const; 

        //getters y setters
        void setId(int id);

        int getId() const;

        void setNombre(const std::string &nombre);

        std::string getNombre() const;

        void setEdad(int edad);

        int getEdad() const;

        void setDireccion(const std::string &direccion);

        std::string getDireccion() const;

        void setAnioNacimiento(int anioNacimiento);

        int getAnioNacimiento() const;

};

#endif