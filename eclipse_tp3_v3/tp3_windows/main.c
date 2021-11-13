#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	pedirTipoInt(&option, "\tMENU\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n\n\t10. SALIR.", "ERROR en el pedir.", 1, 10, 1);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
         //   	int controller_editEmployee(LinkedList* pArrayListEmployee);
            	break;
            case 5:
           // 	int controller_removeEmployee(LinkedList* pArrayListEmployee);
            	break;
            case 6:
            //	int controller_ListEmployee(LinkedList* pArrayListEmployee);
            	break;
            case 7:
            //	int controller_sortEmployee(LinkedList* pArrayListEmployee);
            	break;
            case 8:
            //	int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
            	break;
            case 9:
            //	int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
            	break;
            case 10:
            	puts("Adios.");
            	break;
        }
    }while(option != 10);
    return 0;
}




//funciones del tp 4
/*
static Node* getNode(LinkedList* this, int nodeInex)
{
	Node* nodoAuxiliar=NULL;
	if(this!=NULL && nodeIndex >0 ll_len(this)> nodeIndex)
	{
		nodoAuxiliar=this->pFisrtNode; // estoy dando el index de la posicion cero, del likendList
		for(index =1; index < )
		{
			nodoAuxiliar=nodoAuxiliar->pNextNode; //aca ahora tiene la direccion actual, y ahi sera remplazado al sig del campo que esta ahi. Osea recorre asi todo
		}
	}

	return nodoAuxiliar;
}




static int addNode(likedList* this, int nodeIndex, void* pEklem)
{
	Node* nodoAuxiliar;
	int returnAux=-1
	Node* pNodo=(Node*)malloc

	if(pNodo=NULL){
		if(nodeIndex==0)
		{
			this->NextNode=nodoAuxiliar->fistNode;
			this_zFistNode=nodoAuxilar;
			this->size++;
		}
		else if(nodeIndex==this)
		{

		}
		else
		{
			Node* nodeoAuxiliar=getNode();
		}
	}

}





*/






