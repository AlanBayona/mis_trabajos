#ifndef arcade_H_INCLUDED
#define arcade_H_INCLUDED
typedef struct
{
    char nacionalidad[63];
    char nombreSalon[63];
    char juego[63];
    int sonido;//1 estereo && 0 mono
    int cantidadDeJugadores;
    int cant_maximaDeFichas;
    int id;
}Arcade;

Arcade* arcade_new();
Arcade* arcade_newParametros(char* idStr,char* nombreSalonStr,char* nacionalidadStr,char* juegoStr, char* sonidoStr, char* cantJugadoresStr, char* cantFichasStr);
void arcade_delete(Arcade* this);

int arcade_setId(Arcade* this,int id);
int arcade_getId(Arcade* this,int* id);

int arcade_setNombreSalon(Arcade* this,char* nombreSalon);
int arcade_getNombreSalon(Arcade* this,char* nombreSalon);

int arcade_setCantDeJugadores(Arcade* this,int cantJugadores);
int arcade_getCantDeJugadores(Arcade* this,int* cantJugadores);

int arcade_setCantDeFichas(Arcade* this,int cant_maxFichas);
int arcade_getCantDeFichas(Arcade* this,int* cant_maxFichas);

int arcade_setNacionalidad(Arcade* this,char* nacionalidad);
int arcade_getNacionalidad(Arcade* this,char* nacionalidad);

int arcade_setJuego(Arcade* this,char* nombreDejuego);
int arcade_setJuego(Arcade* this,char* nombreDeJuego);

int arcade_setSonido(Arcade* this,int sonido);
int arcade_getSonido(Arcade* this,int* sonido);





int OrdenarPorNombre(void* arcadeAnterior, void* arcadePosterior);
//int OrdenarPorSueldo(void* empleadoAnterior, void* empleadoPosterior);
//int OrdenarPorHora(void* empleadoAnterior, void* empleadoPosterior);


#endif // employee_H_INCLUDED
