#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Inputs.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int deteccion=-1;
	int idAux;
	char nombreAux[64];
	int horasTrabajadasAux;
	int sueldoAux;
	Employee* empleadoAux=employee_new();
	if(pArrayListEmployee!=NULL && empleadoAux!=NULL)
	{
			if(pedir_NumeroTexto(&nombreAux, "Ingrese el nombre del empleado ingresado\n", "Error", 1)==0)
			{
				if(pedirTipoInt(&horasTrabajadasAux, "Ingrese las hora del trabajas por el empleado\n ", "Error al pedir horas\n", 1)==0)
				{
					if(pedirTipoInt(&sueldoAux, "Ingrese el sueldo del empleado\n", "Error al ingresar sueldo", 1, 37000, 1)==0)
					{
						idAux=crearId();
						if(employee_setNombre(empleadoAux, nombreAux)==0 && employee_setHorasTrabajadas(empleadoAux, horasTrabajadasAux)==0 && employee_setId(empleadoAux, idAux)==0)
						{
							deteccion=ll_add(pArrayListEmployee, empleadoAux);
						}
						else
						{
							puts("Error en la funcion controller_addEmployee");
						}
					}
				}
			}

	}



    return deteccion;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int deteccion;
	int index;
	int opcion;
	if(pArrayListEmployee!=NULL && pedirTipoInt(&index, "Ingrese la posicion del empleado que desee modificar\n", "\nError en la funcion editEmployee\n", 0, pArrayListEmployee->size, 1)==0)
	{
		Employee* empleadoAux=ll_get(pArrayListEmployee, index);

		switch(opcion)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
		}
	}






    return deteccion;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}





int controller_editElementEmployee()
{

}
