#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED


#endif


int controller_loadFromText(char* path , LinkedList* pArrayListArcade);
//int controller_loadFromBinary(char* path , LinkedList* pArrayListArcade);
int controller_addArcade(LinkedList* pArrayListArcade);
int controller_editArcade(LinkedList* pArrayListArcade);
int controller_removeArcade(LinkedList* pArrayListArcade);
int controller_removeArcade(LinkedList* pArrayListArcade);
int controller_sortArcade(LinkedList* pArrayListArcade);
int controller_saveAsText(char* path , LinkedList* pArrayListArcade);
//int controller_saveAsBinary(char* path , LinkedList* pArrayListArcade);


