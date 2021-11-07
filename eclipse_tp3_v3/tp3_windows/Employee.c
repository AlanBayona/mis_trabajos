#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Employee.h"




Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
	Employee* this = employee_new();

	if(!employee_setNombre(this, nombre) && !employee_setAltura(this, altura) && !employee_setId(this,id))
	{
		return this;
	}
	employee_delete(this);
	return NULL;
}

void employee_delete(Employee* this)
{
	free(this);
}

int employee_setId(Employee* this,int id)
{
	int deteccion= -1;
	if(this!=NULL && id>0 && isValidNumero(id))
	{
		deteccion=0;
		this->id=id;
	}
	return deteccion;
}


int employee_getId(Employee* this,int* id)
{
	int deteccion=-1;
	if(this!=NULL && id>0)
	{
		deteccion=0;
		id=this->id;
	}
	return deteccion;
}


int employee_setNombre(Employee* this,char* nombre)
{
	int deteccion=-1;
	if(this!=NULL && nombre!=NULL && isValidarNombre(nombre))
	{
		deteccion=0;
		strcpy(this->nombre, nombre);
	}
	return deteccion;
}


int employee_getNombre(Employee* this,char* nombre)
{
	int deteccion=-1;
	if(this !=NULL && nombre!=NULL)
	{
		deteccion=0;
		strcpy(nombre, this->nombre);
	}
	return deteccion;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int deteccion=-1;
	if(this!=NULL && horasTrabajadas>=0 && isValidarNumero(horasTrabajadas))
	{
		deteccion=0;
		this->horasTrabajadas=horasTrabajadas;
	}
	return deteccion;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int deteccion=-1;
	if(this!=NULL && horasTrabajadas>=0)
	{
		deteccion=0;
		horasTrabajadas=this->horasTrabajadas;
	}
	return deteccion;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int deteccion=-1;
	if(this!=NULL && sueldo>=0 && isValidarNumero(sueldo))
	{
		deteccion=0;
		this->sueldo=sueldo;
	}
	return deteccion;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int deteccion=-1;
	if(this!=NULL && sueldo>0)
	{
		deteccion=0;
		sueldo=this->sueldo;
	}
	return deteccion;
}


