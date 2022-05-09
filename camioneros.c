-o camioneros camioneros.c -I /usr/include/postgresql/ -lpq
//-------------------------------------------------------------------
//Notas:
//1.-editar las funciones de tiendas, se agrego el campo de nombre_tienda
//2.-en la base de datos se cambió el nombre de envios por "paquetes", editar eso en el codigo al igual que el nombre de variables
//________________________________________________________________________________
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <libpq-fe.h>
#include <mpi.h> 

//---------------------------------variables globales-------------------------------------------------------------------------                                              
PGconn *bd;  // Variable que almacena la conexion con una BDs en postgres
PGresult *resultado; //variables para consultas
PGresult *ress;
int i,j,fila,columna;
int res, opc, op; //variable para las respuestas del menú
char cadena[1000],busqid[1000];;//variable(s) para las funciones de psql
//-----------------------------------------------------------------------------------------------------
//FUNCIONES   UWU  
void conexion();
void menu_principal();
void menu_camiones();
    void alta_camiones();
    void baja_camiones();
    void Consulta_camiones();
    void modifica_camiones();
void menu_viajes();
    void alta_viajes();
    void baja_viajes();
    void Consulta_viajes();
    void modifica_viajes();
void menu_tiendas();
    void alta_tiendas();
    void baja_tiendas();
    void Consulta_tiendas();
    void modifica_tiendas();
void menu_paquetes();
    void alta_paquetes();
    void baja_paquetes();
    void Consulta_paquetes();
    void modifica_paquetes();
void menu_entregas();
    void alta_entregas();
    void baja_entregas();
    void Consulta_entregas();
    void modifica_entregas();

void menu_consultas();
    void tiendas_camiones_paquetes();
    void paquetes_por_placa();
    void tiendas_paquetes_de_peso_mayor_250();
    void paquetes_por_tienda();
    void consulta_viajes_mas_Ntienda();
    void consulta_paquetesVM1300();
    void consulta_camionCapacidad_Sup();
    void consulta_mes_menos_viajes();
    void consulta_mes_mas_viajes();
    void consulta_reportefinal();


//----------------------------------------------------------------------------------------------------------
void conexion()
{
    //(ip_servidor,puerto_postgres,NULL,NULL,BDs,Usuario,contraseña)
	bd=PQsetdbLogin("localhost","5433",NULL,NULL,"camioneros","postgres","1");
}//fin metodo de conexion
//-------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[]){       
//Variables MPI


MPI_Init(&argc,&argv);

menu_principal();
MPI_Finalize();
return 0;
}//mando llamar la funcion del menu principal
    
    
//return 0;
//fin main-----------------------------------------------------------------------------------------------------

void empty_stdin() // limpiar el buffer
{
    int s;
    do
    {
        s = getchar();
    } while (s != '\n' && s != EOF);
}//fin limpiar el buffer---------------------------------------------------------------- 

//fin funcion menu_pricipal----------------------------------------------------------------------------------------
void menu_principal(){
    int id;
    //Proceso principal
    double tmpinic = 0.0; //Inicializador del contador
    double tmpfin;        //Finalizador del contador

    //Procesos secundarios
    double tmpinic1 = 0.0;//Incio 1
    double tmpfin1;       //Final 1
    double tmpinic2 = 0.0;//Incio 2
    double tmpfin2;       //Final 2
    double tmpinic3 = 0.0;//Incio 3
    double tmpfin3;       //Final 3
    double tmpinic4 = 0.0;//Incio 4
    double tmpfin4;       //Final 4
    double tmpinic5 = 0.0;//Incio 5
    double tmpfin5;       //Final 5
    double tmpinic6 = 0.0;//Incio 6
    double tmpfin6;       //Final 6

if(id == 0);
    {
    tmpinic = MPI_Wtime();
    
   setbuf(stdin,NULL); // Limpiar
   printf("\n       Bienvenido al administrador de provisiones 'Perez hermanos'  \t\t\n");
    
    do
    {
    // Menu principal*****************************************************************************************************
    printf("+========================================================================+\n");   
    printf("|                            Menu principal                              |\n");
    printf("+========================================================================+\n");
    printf("|                    seleccione una opcion del menu:                     |\n");  
    printf("|                                 |                                      |\n");
    printf("| 1.-Opciones para camiones       |     2.-Opciones para viajes          |\n");
    printf("|                                 |                                      |\n");
    printf("| 3.-Opciones para tiendas        |     4.-Opciones para paquetes        |\n");
    printf("|                                 |                                      |\n");
    printf("| 5.-Opciones para entregas       |     6.-Consultas                     |\n");
    printf("|                                 |                                      |\n");
    printf("| 7.-Salir                        |                                      |\n");
    printf("|                                 |                                      |\n");
    printf("+========================================================================+\n");  
    printf(">> ");
    scanf("%d", &res);//scaneo la respuesta ingresada por el usuario
    system("clear");//limpio la pantalla
    printf("\n");//menu_viajes();//mando llamar a la funcion del menu viajes
       
        switch (res)
        {
        case 1:
            tmpinic1 = MPI_Wtime();
            menu_camiones();//mando llamar a la funcion del menu de camiones
            tmpfin1= MPI_Wtime();
            break;

        case 2:
            tmpinic2 = MPI_Wtime();
            menu_viajes();//mando llamar a la funcion del menu viajes
            tmpfin2= MPI_Wtime();
            break;

        case 3:
            tmpinic3 = MPI_Wtime();
            menu_tiendas();//mando llamar a la funcion del menu tiendas
            tmpfin3= MPI_Wtime();
            break;

        case 4:
            tmpfin4 = MPI_Wtime();
            menu_paquetes();//mando llamar a la funcion del menu paquetes
            tmpfin4= MPI_Wtime();
            break;
        
        case 5:
            tmpinic5 = MPI_Wtime();
            menu_entregas();//mando llamar a la funcion del menu entregas
            tmpfin5= MPI_Wtime();
            break;

        case 6:
            tmpinic6=MPI_Wtime();
            menu_consultas();
            tmpfin6= MPI_Wtime();
            break;

        case 7:
            printf("saliendo...\n\n\n");
            break;

        default:printf("\n Error, esta opción no está disponible, ingrese una opción válida\n");
        }

    } while (res != 7); 
    }
    tmpfin = MPI_Wtime();

    fprintf(stdout, "\n TIEMPO DE USO GENERAL: %f\n, TIEMPO DE USO DE LAS OPCIONES DE CAMIONES:  %f\n, TIEMPO DE USO DE LAS OPCIONES DE VIAJES: %f\n, TIEMPO DE USO DE LAS OPCIONES PARA TIENDAS : %f\n, TIEMPO DE USO DE LAS OPCIONES PARA PAQUETES %f \n, TIEMPO DE USO DE LAS OPCIONES PARA ENTREGAS : %f\n, TIEMPO DE USO DE LAS CONSULTAS: %f\n: ", tmpfin-tmpinic, tmpfin1-tmpinic1, tmpfin2-tmpinic2, tmpfin3-tmpinic3, tmpfin4-tmpinic4, tmpfin5-tmpinic5, tmpfin6-tmpinic6);

}
void menu_camiones()//funcion para el menu de camiones
{   //MPI Inicializador secundario 1
    int id1;
    MPI_Comm_rank (MPI_COMM_WORLD,& id1 ) ;
    
    if(id1 == 0);
    {
    
    do{
    printf("+==========================================================================+\n");   
    printf("|                          Opciones de camiones                            |\n");
    printf("+==========================================================================+\n");
    printf("|                    seleccione una opcion del menu:                       |\n");  
    printf("|                                                                          |\n");
	printf("| 1.-Alta                2.-Baja                  3.-Consulta              |\n");
    printf("|                                                                          |\n");
    printf("| 4.-Modificacion        5.-Regresar                                       |\n");
    printf("|                                                                          |\n");
	printf("+==========================================================================+\n");  
    printf(">> ");
    scanf("%d", &res);//scaneo la respuesta ingresada por el usuario
    system("clear");//limpio la pantalla
    printf("\n");
       
        switch (res)
        {
        case 1:
            alta_camiones(); //mando a llamar la funcion que da alta camiones
            break;

        case 2:
            baja_camiones(); //mando a llamar la funcion de baja (delete) de camiones
            break;

        case 3:
            Consulta_camiones();//mando llamar la funcion de consulta (select) de camiones
            break;
        case 4:
            modifica_camiones();//mando llamar la función de modificación de autos (update)
            break;
        case 5:
            printf("\nregresando al menu principal...\n\n\n");
            break;

        default:printf("seleccione una opción correcta\n");
        }
    } while (res != 5); 
    }
            
}//fin menu camiones-----------------------------------------------------------------------------------------

void alta_camiones()//funcion para alta(insert)
{
    ExecStatusType status;
    //datos de la base de datos en varchar y enteros
    char idcamion[10], almacen_salida[10], modelo[10], placa[10], conductor[40];
    float volcamion, pesocamion;

    conexion();//mando llamar la funcion conexión
        if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
        {
        //printf("Conexion exitosa\n\n\n");
        printf("+==========================================================================+\n"); 
        printf("|                  insercion de datos a la tabla camiones                  |\n");
        printf("+==========================================================================+\n"); 
        printf("ingrese el almacen de salida (ax): \n");
        scanf("%s", almacen_salida);
        printf("ingrese el id (cx): \n");
        scanf("%s", idcamion);
        empty_stdin();//limpio el buffer
        printf("ingrese el modelo: \n");
        scanf("%s",modelo);
        empty_stdin();//limpio el buffer
        printf("ingrese la placa(4): \n");
        scanf("%s",placa);
        empty_stdin();//limpio el buffer
        printf("ingrese el volumen: \n");
        scanf("%f", &volcamion);
        empty_stdin();//limpio el buffer
        printf("ingrese el peso: \n");
        scanf("%f", &pesocamion);
        empty_stdin();//limpio el buffer
        printf("ingrese el nombre del conductor: \n");
        scanf("%s", conductor);
        empty_stdin();//limpio el buffer
        //ingreso la insturcción de postgresql
       // printf("%s, %s, %s, %d , %d, %s \n");
        sprintf(cadena,"insert into camiones values('%s','%s', '%s', '%s', %.2f,  %.2f, '%s');",almacen_salida,idcamion, modelo, placa,volcamion,pesocamion, conductor);
        resultado = PQexec(bd, cadena);
        system("clear");
            if (resultado != NULL)
            {
                printf("\n\n¡El camion se agrego correctamente! \n");
            }
            else
            {
                printf("hay datos no permitidos o ingresados incorrectamente");
            }

        }else//si no hace la conexion
        {
            printf("Conexion fallida :(\n");
        }

}//fin de la funcion alta de camiones-------------------------------------------------------------

void baja_camiones()//funcion para dar de baja (delete)
{
    ExecStatusType status;
    char placa[10]; // variable para guardar y hacer la consulta de la placa
    conexion();
    if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
    {
        //printf("Conexion exitosa\n\n\n");
        printf("+==========================================================================+\n"); 
        printf("|               Eliminacion de datos de la tabla Camiones                  |\n");
        printf("+==========================================================================+\n"); 
        Consulta_camiones();//mando llamar la consulta para verificar  que clientes hay registrados y saber cual se va a eliminar
        printf("ingrese la placa del auto que dese dar de baja: \n");
        printf(">> ");
        scanf("%s",placa);
        //validar si este cliente existe.
        sprintf(busqid,"select * from camiones where placa = '%s'", placa );
		resultado = PQexec(bd, busqid);
            if(PQntuples (resultado)== 0)
            {
                printf("¡este camion no existe el la base de datos! :(\n\n\n");

            }else
            {
        
                sprintf(cadena, "delete from camiones where placa = '%s';",placa);
                printf("%s\n",cadena);
                resultado = PQexec(bd, cadena);
                if (resultado != NULL)
                {
                    printf("\n\n¡El camión se elimino correctamente! \n\n\n");
                }
                else
                {
                    printf("hay datos no permitidos o ingresados incorrectamente\n\n\n");
                }
            }

    }else//si no hace la conexion
    {
        printf("Conexion fallida :(\n\n\n");
    }

}//fin funcion baja camiones---------------------------------------------------------------------------------

void Consulta_camiones()
{
    conexion();
        if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
        {
            sprintf(cadena,"select * from camiones");
		    resultado = PQexec(bd, cadena);
           
		    if(resultado != NULL)
            {
                printf("==========================================================================\n");
                printf("|                           Consulta de autos                            |\n");
                printf("| Almacen |  ID  |Modelo |Placa |Volumen | Peso |Nombre del conductor    | \n");
                printf("==========================================================================\n");
                fila=PQntuples(resultado);
                columna=PQnfields(resultado);
                
                for (i = 0; i < fila ; i++)
                {
                        for (j = 0; j < columna; j++)
                        {
                                
                                printf("%s\t",PQgetvalue(resultado,i,j));
                               
				        }
                
				printf("\n\n\n");
			   }
               printf("==========================================================================\n\n\n");
            }

        }else//si no hace la conexion
        {
            printf("conexion fallida :( \n\n\n");
        }
    

}//fin consulta camiones--------------------------------------------------------------------------------------------

void modifica_camiones()
{
    ExecStatusType status;
    //datos de la basae de datos en varchar y enteros
    float volcamion, pesocamion;
    char idcamion[10], almacen_salida[10], modelo[10], placa[10],conductor[40], placanew[10];

    conexion();
        if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
        {
            //printf("Conexion exitosa\n\n\n");
            printf("+==========================================================================+\n"); 
            printf("|                Modificacion de datos de la tabla camiones                |\n");
            printf("+==========================================================================+\n"); 
            Consulta_camiones();//mando llamar la consulta para verificar la placa y datos del auto
            printf("ingrese la placa del camion que desea editar: \n");
            printf(">> ");
            scanf("%s",placa);
            //validar si este auto existe.
            sprintf(busqid,"select * from camiones where placa = '%s' ", placa );
            printf("%s\n",busqid);
            resultado = PQexec(bd, busqid);
            char resp;
                if(PQntuples (resultado)== 0)
                {
                    printf("\nesta placa no se encuentra en el registro :(\n\n\n");
                }else
                {
                    //mando llamar la funcion de consulta de camiones para conocer el cual se va a editar
                    Consulta_camiones();
                do{//menu de seleccion a editar***************************************************************************
                    printf("+==========================================================================+\n");   
                    printf("|                        Menu de edicion de autos                          |\n");
                    printf("+==========================================================================+\n");
                    printf("|                  seleccione el campo que desea editar:                   |\n");  
                    printf("|                                                                          |\n");
                    printf("| 1.-ID del camion         2.-Modelo              3.-Placa                 |\n");
                    printf("|                                                                          |\n");
                    printf("| 4.-Volumen               5.-Peso                6.-Conductor             |\n");
                    printf("|                                                                          |\n");
                    printf("| 7.-Almacen               8.-Regresar                                     |\n");
                    printf("|                                                                          |\n");
                    printf("+==========================================================================+\n");  
                    printf(">> ");
                    scanf("%d",&op);
                    system("clear");//limpio la pantalla
                    printf("\n");

                        switch (op)
                        {
                        case 1://editar id
                        printf("ingrese el nuevo id: \n");
                        scanf("%s",idcamion);
                        sprintf(cadena,"update camiones set id_camion='%s' where placa='%s';",idcamion , placa);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                       
                        break;

                        case 2://editar modelo
                        printf("ingrese el nuevo modelo: \n");
                        scanf("%s",modelo);
                        sprintf(cadena,"update camiones set modelo='%s' where placa='%s';",modelo , placa);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                            
                            break;

                        case 3://editar placa
                        printf("ingrese la nueva placa: \n");
                        scanf("%s",placanew);
                        sprintf(cadena,"update camiones set placa='%s' where placa='%s';",placanew , placa);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                            
                            break;

                        case 4:// editar volumen
                        printf("ingrese el nuevo volumen: \n");
                        scanf("%f",&volcamion);
                        sprintf(cadena,"update camiones set vol_camion =%f where placa='%s';",volcamion, placa);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                            break;

                        case 5://editar peso
                        printf("ingrese el nuevo peso: \n");
                        scanf("%f",&pesocamion);
                        sprintf(cadena,"update camiones set peso_camion =%f where placa='%s';",pesocamion, placa);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                            break;

                        case 6://editar conductor
                        printf("ingrese el nuevo conductor: \n");
                        scanf("%s",conductor);
                        sprintf(cadena,"update camiones set conductor='%s' where placa='%s';",conductor, placa);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");

                            break;

                        case 7:
                        printf("ingrese el nuevo almacen de salida: \n");
                        scanf("%s",almacen_salida);
                        sprintf(cadena,"update camiones set almacen_salida='%s' where placa='%s';",almacen_salida , placa);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                            break;
                        
                        case 8:
                        printf("Regresando al menu anterior... \n\n\n");
                            break;                

                        default:
                            printf("No existe acción para la opción seleccionada.\n\n");
                        }//fin switch
                    } while (op !=8);
                }

    }
    else
    {
        printf("error al conectar :( \n\n\n");
    }
    

}//fin modifica camiones-------------------------------------------------------------------------------

void menu_viajes()//menú para opciones de viajes
{
    
    int id1;
    MPI_Comm_rank (MPI_COMM_WORLD,& id1 ) ;
    
    //MPI Inicializador secundario 2
        if(id1 == 0);
    {
    
    do
    {
    printf("+==========================================================================+\n");   
    printf("|                           Opciones de viajes                             |\n");
    printf("+==========================================================================+\n");
    printf("|                    seleccione una opcion del menu:                       |\n");  
    printf("|                                                                          |\n");
	printf("| 1.-Alta                2.-Baja                  3.-Consulta              |\n");
    printf("|                                                                          |\n");
    printf("| 4.-Modificacion        5.-Regresar                                       |\n");
    printf("|                                                                          |\n");
	printf("+==========================================================================+\n");  
    printf(">> ");
    scanf("%d", &res);//scaneo la respuesta ingresada por el usuario
    system("clear");//limpio la pantalla
    printf("\n");
       
        switch (res)
        {
        case 1:
            alta_viajes(); //mando a llamar la funcion que da alta 
            break;

        case 2:
            baja_viajes(); //mando a llamar la funcion de baja (delete) 
            break;

        case 3:
            Consulta_viajes();//mando llamar la funcion de consulta (select) 
            break;
        case 4:
            modifica_viajes();//mando llamar la función de modificaciónx (update)
            break;
        case 5:
            printf("\nregresando al menu principal...\n\n\n");
            break;

        default:printf("seleccione una opción correcta\n");
        }
    } while (res != 5);
     }

}//fin menu viajes-------------------------------------------------------------------------------------

void alta_viajes()
{
    ExecStatusType status;
    //datos de la base de datos en varchar y enteros
    char id_camion[10], num_viaje[10];

    conexion();//mando llamar la funcion conexión
        if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
        {
        //printf("Conexion exitosa\n\n\n");
        printf("+==========================================================================+\n"); 
        printf("|                  Insercion de datos a la tabla viajes                    |\n");
        printf("+==========================================================================+\n"); 
        Consulta_camiones();//muestra la consulta de camiones para verificar los que está disponibles
        printf("ingrese el id del camion que hace este viaje(cx): \n");
        scanf("%s", id_camion);
        empty_stdin();//limpio el buffer
        printf("ingrese el numero de este viaje: \n");
        scanf("%s",num_viaje);
        
        sprintf(cadena,"insert into viajes values('%s','%s');",id_camion, num_viaje);
        resultado = PQexec(bd, cadena);
        system("clear");
            if (resultado != NULL)
            {
                printf("\n\n¡El viaje se agrego correctamente! \n");
            }
            else
            {
                printf("hay datos no permitidos o ingresados incorrectamente");
            }

        }else//si no hace la conexion
        {
            printf("Conexion fallida :(\n");
        }
}//fin insercion de viajes---------------------------------------------------------------------------------------

void baja_viajes()
{
    ExecStatusType status;
    char num_viaje[10]; // variable para guardar y hacer la consulta de la placa
    conexion();
    if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
    {
        //printf("Conexion exitosa\n\n\n");
        printf("+==========================================================================+\n"); 
        printf("|               Eliminacion de datos de la tabla camiones                  |\n");
        printf("+==========================================================================+\n"); 
        Consulta_viajes();//mando llamar la consulta para verificar  que clientes hay registrados y saber cual se va a eliminar
        printf("ingrese el numero al cual desea dar de baja: \n");
        printf(">> ");
        scanf("%s",num_viaje);
        //validar si este viaje existe
        sprintf(busqid,"select * from viajes where num_viaje = '%s'", num_viaje );
		resultado = PQexec(bd, busqid);
            if(PQntuples (resultado)== 0)
            {
                printf("¡este viaje no existe el la base de datos! :(\n\n\n");

            }else
            {
        
                sprintf(cadena, "delete from viajes where num_viaje = '%s';",num_viaje);
                printf("%s\n",cadena);
                resultado = PQexec(bd, cadena);
                if (resultado != NULL)
                {
                    printf("\n\n¡El viaje se elimino correctamente! \n\n\n");
                }
                else
                {
                    printf("hay datos no permitidos o ingresados incorrectamente\n\n\n");
                }
            }

    }else//si no hace la conexion
    {
        printf("Conexion fallida :(\n\n\n");
    }

}//fin funcion de baja viajes--------------------------------------------------------------------------------------------

void Consulta_viajes()
{
        conexion();
        if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
        {
            sprintf(cadena,"select * from viajes");//consulta de la tabla viajes;
		    resultado = PQexec(bd, cadena);
           
		    if(resultado != NULL)
            {
                printf("================================================================\n");
                printf("|                     Consulta de viajes                       |\n");
                printf("| Vehiculo asignado | Numero de viaje                          | \n"); 
                printf("================================================================\n");
                fila=PQntuples(resultado);
                columna=PQnfields(resultado);
                
                for (i = 0; i < fila ; i++)
                {
                        for (j = 0; j < columna; j++)
                        {
                                
                                printf("%s\t",PQgetvalue(resultado,i,j));
                               
				        }
                
				printf("\n\n\n");
			   }
               printf("================================================================\n\n\n");
            }

        }else//si no hace la cnoexion
        {
            printf("conexion fallida :( \n\n\n");
        }
    
}//fin de consulta de vaijes---------------------------------------------------------------------------

void modifica_viajes()//funcion para editar viajes (update)
{
    ExecStatusType status;
    //datos de la basae de datos en varchar 
    char idcamion[10], num_viaje[10], viajenew[10];

    conexion();
        if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
        {
            //printf("Conexion exitosa\n\n\n");
            printf("+==========================================================================+\n"); 
            printf("|                Modificacion de datos de la tabla viajes                  |\n");
            printf("+==========================================================================+\n"); 
            Consulta_viajes();//mando llamar la consulta para verificar la placa y datos 
            printf("Ingrese el numero de viaje que desea editar: \n");
            printf(">> ");
            scanf("%s",num_viaje);
            //validar si este auto existe.
            sprintf(busqid,"select * from viajes where num_viaje = '%s' ", num_viaje );
            printf("%s\n",busqid);
            resultado = PQexec(bd, busqid);
            char resp;
                if(PQntuples (resultado)== 0)
                {
                    printf("\neste viaje no se encuentra en el registro :(\n\n\n");
                }else
                {
                    //mando llamar la funcion de consulta para conocer el cual se va a editar
                    Consulta_viajes();
                do{//menu de seleccion a editar***************************************************************************
                    printf("+==========================================================================+\n");   
                    printf("|                        Menu de edicion de viajes                         |\n");
                    printf("+==========================================================================+\n");
                    printf("|                  seleccione el campo que desea editar:                   |\n");  
                    printf("|                                                                          |\n");
                    printf("| 1.-ID del camion         2.-Numero del viaje        3.-Regresar          |\n");
                    printf("|                                                                          |\n");
                    printf("+==========================================================================+\n");  
                    printf(">> ");
                    scanf("%d",&op);
                    system("clear");//limpio la pantalla
                    printf("\n");

                        switch (op)
                        {
                        case 1://editar id
                        printf("ingrese el nuevo id: \n");
                        scanf("%s",idcamion);
                        sprintf(cadena,"update viajes set id_camion='%s' where num_viaje='%s';",idcamion , num_viaje);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                       
                        break;

                        case 2://editar numero de viaje
                        printf("ingrese el nuevo numero de viaje: \n");
                        scanf("%s",viajenew);
                        sprintf(cadena,"update viajes set num_viaje='%s' where num_viaje='%s';",viajenew , num_viaje);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                            
                            break;

                        case 3:
                        printf("Regresando al menu anterior... \n\n\n");
                        
                            
                            break;

                        
                        default:
                            printf("No existe acción para la opción seleccionada.\n\n");
                        }//fin switch
                    } while (op !=3);
                }

    }
    else
    {
        printf("error al conectar :( \n\n\n");
    }
}//fin edicion dela tabla viajes-------------------------------------------------------------------------------

void menu_tiendas()
{
    int id1;
    MPI_Comm_rank (MPI_COMM_WORLD,& id1 ) ;
    
    if (id1==0);
    {
    

     do
    {
    printf("+==========================================================================+\n");   
    printf("|                           Opciones de tiendas                            |\n");
    printf("+==========================================================================+\n");
    printf("|                    seleccione una opcion del menu:                       |\n");  
    printf("|                                                                          |\n");
	printf("| 1.-Alta                2.-Baja                  3.-Consulta              |\n");
    printf("|                                                                          |\n");
    printf("| 4.-Modificacion        5.-Regresar                                       |\n");
    printf("|                                                                          |\n");
	printf("+==========================================================================+\n");  
    printf(">> ");
    scanf("%d", &res);//scaneo la respuesta ingresada por el usuario
    system("clear");//limpio la pantalla
    printf("\n");
       
        switch (res)
        {
        case 1:
            alta_tiendas(); //mando a llamar la funcion que da alta 
            break;

        case 2:
            baja_tiendas(); //mando a llamar la funcion de baja (delete) 
            break;

        case 3:
            Consulta_tiendas();//mando llamar la funcion de consulta (select) 
            break;
        case 4:
            modifica_tiendas();//mando llamar la función de modificación de (update)
            break;
        case 5:
            printf("\nregresando al menu principal...\n\n\n");
            break;

        default:printf("seleccione una opción correcta\n");
        }
    } while (res != 5); 
    }
            
}//fin menu de tiendas-----------------------------------------------------------------------------------------

void alta_tiendas()
{
    ExecStatusType status;
    //datos de la base de datos en varchar y enteros
    char tie_destino[30], direc_tienda[30],tel_tienda[12];
   

    conexion();//mando llamar la funcion conexión
        if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
        {
        //printf("Conexion exitosa\n\n\n");
        printf("+==========================================================================+\n"); 
        printf("|                  Insercion de datos a la tabla tiendas                   |\n");
        printf("+==========================================================================+\n"); 
        printf("ingrese el id de la tienda (tx): \n");
        scanf("%s", tie_destino);
        empty_stdin();//limpio el buffer
        printf("ingrese la ciudad donde se ubica la tienda: \n");
        scanf("%s",direc_tienda);
        empty_stdin();//limpio el buffer
        printf("ingrese el telefono de la tienda: \n");
        scanf("%s",tel_tienda);
        
        sprintf(cadena,"insert into tiendas values('%s','%s', '%s');",tie_destino,direc_tienda,tel_tienda);
        resultado = PQexec(bd, cadena);
        system("clear");
            if (resultado != NULL)
            {
                printf("\n\n¡la tienda se agrego correctamente! \n");
            }
            else
            {
                printf("hay datos no permitidos o ingresados incorrectamente");
            }

        }else//si no hace la conexion
        {
            printf("Conexion fallida :(\n");
        }

}//fin de la funcion de alta de tiendas

void Consulta_tiendas()
{
        conexion();
        if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
        {
            sprintf(cadena,"select * from tiendas");//consulta de la tabla viajes;
		    resultado = PQexec(bd, cadena);
           
		    if(resultado != NULL)
            {
                printf("================================================================\n");
                printf("|                     Consulta de tiendas                      |\n");
                printf("| ID | Ciudad | Teléfono                                       | \n"); 
                printf("================================================================\n");
                fila=PQntuples(resultado);
                columna=PQnfields(resultado);
                
                for (i = 0; i < fila ; i++)
                {
                        for (j = 0; j < columna; j++)
                        {
                                
                                printf("%s\t",PQgetvalue(resultado,i,j));
                               
				        }
                
				printf("\n\n\n");
			   }
               printf("================================================================\n\n\n");
            }

        }else//si no hace la conexion
        {
            printf("conexion fallida :( \n\n\n");
        }
}//fin consulta de tiendas-----------------------------------------------------------------------------------

void baja_tiendas()
{
ExecStatusType status;
    char tie_destino[10]; // variable para guardar y hacer la consulta de la placa
    conexion();
    if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
    {
        //printf("Conexion exitosa\n\n\n");
        printf("+==========================================================================+\n"); 
        printf("|               Eliminacion de datos de la tabla tiendas                  |\n");
        printf("+==========================================================================+\n"); 
        Consulta_tiendas();
        printf("ingrese el id de la tienda que desea eliminar: \n");
        printf(">> ");
        scanf("%s",tie_destino);
        //validar si esta tienda
        sprintf(busqid,"select * from tiendas where tie_destino = '%s'",tie_destino);
		resultado = PQexec(bd, busqid);
            if(PQntuples (resultado)== 0)
            {
                printf("¡esta tienda NO existe el la base de datos! :(\n\n\n");

            }else
            {
        
                sprintf(cadena, "delete from tiendas where tie_destino = '%s';",tie_destino);
                printf("%s\n",cadena);
                resultado = PQexec(bd, cadena);
                if (resultado != NULL)
                {
                    printf("\n\n¡la tienda elimino correctamente! \n\n\n");
                }
                else
                {
                    printf("Hay datos no permitidos o ingresados incorrectamente\n\n\n");
                }
            }
    }
}//fin de la funcion para baja de tiendas------------------------------------------------------------------

void modifica_tiendas()
{
ExecStatusType status;
    //datos de la basae de datos en varchar 
    char tie_destino[10],direc_tienda[30],tel_tienda[30] , idnuevo[10];

    conexion();
        if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
        {
            //printf("Conexion exitosa\n\n\n");
            printf("+==========================================================================+\n"); 
            printf("|                Modificacion de datos de la tabla tiendas                 |\n");
            printf("+==========================================================================+\n"); 
            Consulta_tiendas();//mando llamar la consulta para verificar la placa y datos 
            printf("ingrese el ID de la tienda que desea editar: \n");
            printf(">> ");
            scanf("%s",tie_destino);
            //validar si esta tienda  existe.
            sprintf(busqid,"select * from tiendas where tie_destino = '%s' ", tie_destino );
            printf("%s\n",busqid);
            resultado = PQexec(bd, busqid);
            char resp;
                if(PQntuples (resultado)== 0)
                {
                    printf("\nesta tienda no se encuentra en el registro :(\n\n\n");
                }else
                {
                    //mando llamar la funcion de consulta para conocer el cual se va a editar
                    Consulta_tiendas();
                do{//menu de seleccion a editar***************************************************************************
                    printf("+==========================================================================+\n");   
                    printf("|                        Menu de edicion de tiendas                        |\n");
                    printf("+==========================================================================+\n");
                    printf("|                  seleccione el campo que desea editar:                   |\n");  
                    printf("|                                                                          |\n");
                    printf("|       1.-ID       2.-Ciudad       3.-Télefono      4.-Regresar           |\n");
                    printf("|                                                                          |\n");
                    printf("+==========================================================================+\n");  
                    printf(">> ");
                    scanf("%d",&op);
                    system("clear");//limpio la pantalla
                    printf("\n");

                        switch (op)
                        {
                        case 1://editar id
                        printf("Ingrese el nuevo ID: \n");
                        scanf("%s",idnuevo);
                        sprintf(cadena,"update tiendas set tie_destino='%s' where tie_destino='%s';",idnuevo, tie_destino);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                       
                        break;

                        case 2://editar ciudad
                        printf("ingrese la nueva ciudad: \n");
                        scanf("%s",direc_tienda);
                        sprintf(cadena,"update tiendas set direc_tienda='%s' where tie_destino='%s';",direc_tienda , tie_destino);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                            
                            break;

                        case 3://editar telefono
                        printf("ingrese el nuevo telefono: \n");
                        scanf("%s",tel_tienda);
                        sprintf(cadena,"update tiendas set tel_tienda='%s' where tie_destino='%s';",tel_tienda , tie_destino);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                        
                        
                            break;

                        case 4:
                        printf("Regresando al menu anterior... \n\n\n");
                            break;

                        
                        default:
                            printf("No existe acción para la opción seleccionada.\n\n");
                        }//fin switch
                    } while (op !=4);
                }
        }
}//fin modidfica tiendas

void menu_paquetes(){ 
    //MPI Inicializador
    int id1;
    MPI_Comm_rank (MPI_COMM_WORLD,& id1 ) ;
    if(id1==0);
    {
    

     do
    {
    printf("+==========================================================================+\n");   
    printf("|                           Opciones de paquetes                           |\n");
    printf("+==========================================================================+\n");
    printf("|                    seleccione una opcion del menu:                       |\n");  
    printf("|                                                                          |\n");
    printf("| 1.-Alta                2.-Baja                  3.-Consulta              |\n");
    printf("|                                                                          |\n");
    printf("| 4.-Modificacion        5.-Regresar                                       |\n");
    printf("|                                                                          |\n");
    printf("+==========================================================================+\n");  
    printf(">> ");
    scanf("%d", &res);//scaneo la respuesta ingresada por el usuario
    system("clear");//limpio la pantalla
    printf("\n");
       
        switch (res)
        {
        case 1:
            alta_paquetes(); //mando a llamar la funcion que da alta 
            break;
        case 2:
            baja_paquetes(); //mando a llamar la funcion de baja (delete) 
            break;
        case 3:
            Consulta_paquetes();//mando llamar la funcion de consulta (select) 
            break;
        case 4:
            modifica_paquetes();//mando llamar la función de modificación de (update)
            break;
        case 5:
            printf("\nRegresando al menu principal...\n\n\n");
            break;

        default:printf("Seleccione una opción correcta porfavor\n");
        }
    } while (res != 5); 
    }


}//fin menu de paquetes---------------
void alta_paquetes(){
    ExecStatusType status;
    //datos de la base de datos en varchar y enteros
    char num_paquete[30];
    float vol_paquete, peso_paquete;
    conexion();//mando llamar la funcion conexión
        if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
        {
        //printf("Conexion exitosa\n\n\n");
        printf("+==========================================================================+\n"); 
        printf("|                  insercion de datos a la tabla paquetes                  |\n");
        printf("+==========================================================================+\n"); 
        printf("Ingrese el numero de paquete:" );
        scanf("%s", num_paquete);
        empty_stdin();//limpio el buffer
        printf("Ingrese el volumen del paquete: ");
        scanf("%f",&vol_paquete);
        empty_stdin();//limpio el buffer
        printf("Ingrese el peso del paquete: ");
        scanf("%f",&peso_paquete);
        
        sprintf(cadena,"Insert into paquetes values('%s','%.2f', '%.2f');",num_paquete,vol_paquete,peso_paquete);
        resultado = PQexec(bd, cadena);
        system("clear");
            if (resultado != NULL)
            {
                printf("\n\n¡El paquete se agrego correctamente! \n");
            }
            else
            {
                printf("hay datos no permitidos o ingresados incorrectamente");
            }

        }else//si no hace la conexion
        {
            printf("Conexion fallida :(\n");
        }
}

void baja_paquetes(){
    ExecStatusType status;
    char num_paquete[10]; // variable para guardar y hacer la consulta de la placa
    conexion();
    if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
    {
        //printf("Conexion exitosa\n\n\n");
        printf("+==========================================================================+\n"); 
        printf("|               Eliminacion de datos de la tabla paquetes                  |\n");
        printf("+==========================================================================+\n"); 
        Consulta_paquetes();
        printf("ingrese el numero de paquete que desea eliminar: \n");
        printf(">> ");
        scanf("%s",num_paquete);
        //validar si esta tienda
        sprintf(busqid,"select * from paquetes where num_paquete = '%s'",num_paquete);
        resultado = PQexec(bd, busqid);
            if(PQntuples (resultado)== 0)
            {
                printf("¡esta tienda NO existe el la base de datos! :(\n\n\n");

            }else
            {
        
                sprintf(cadena, "delete from paquetes where num_paquete = '%s';",num_paquete);
                printf("%s\n",cadena);
                resultado = PQexec(bd, cadena);
                if (resultado != NULL)
                {
                    printf("\n\n¡Paquete eliminado correctamente! \n\n\n");
                }
                else
                {
                    printf("Hay datos no permitidos o ingresados incorrectamente\n\n\n");
                }
            }
}
}

void Consulta_paquetes(){
     conexion();
        if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
        {
            sprintf(cadena,"select * from paquetes");//consulta de la tabla viajes;
            resultado = PQexec(bd, cadena);
           
            if(resultado != NULL)
            {
                printf("================================================================\n");
                printf("|                     Consulta de paquetes                     |\n");
                printf("| Numero ID | Volumen | Peso                                   | \n"); 
                printf("================================================================\n");
                fila=PQntuples(resultado);
                columna=PQnfields(resultado);
                
                for (i = 0; i < fila ; i++)
                {
                        for (j = 0; j < columna; j++)
                        {
                                
                                printf("%s\t\t",PQgetvalue(resultado,i,j));
                               
                        }
                
                printf("\n\n\n");
               }
               printf("================================================================\n\n\n");
            }

        }else//si no hace la cnoexion
        {
            printf("conexion fallida :( \n\n\n");
        }
}

void modifica_paquetes(){
    ExecStatusType status;
    //datos de la basae de datos en varchar 
    char num_paquete[10], num_paquete_new[10];
    float vol_paquete_new,peso_paquete_new,vol_paquete, peso_paquete; 

    conexion();
        if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
        {
            //printf("Conexion exitosa\n\n\n");
            printf("+==========================================================================+\n"); 
            printf("|                Modificacion de datos de la tabla paquetes                |\n");
            printf("+==========================================================================+\n"); 
            Consulta_paquetes();//mando llamar la consulta paquetes para mostrar los datos 
            printf("Ingrese el numero del paquete que desea modificar: \n");
            printf(">> ");
            scanf("%s",num_paquete);
            //validar si esta tienda  existe.
            sprintf(busqid,"select * from paquetes where num_paquete = '%s' ", num_paquete);
            printf("%s\n",busqid);
            resultado = PQexec(bd, busqid);
            char resp;
                if(PQntuples (resultado)== 0)
                {
                    printf("\nNo se encuentra el numero de paquete:(\n\n\n");
                }else
                {
                    //mando llamar la funcion de consulta para conocer el cual se va a editar
                    Consulta_paquetes();
                do{//menu de seleccion a editar***************************************************************************
                    printf("+==========================================================================+\n");   
                    printf("|                        Menu de edicion de paquetes                         |\n");
                    printf("+==========================================================================+\n");
                    printf("|                  seleccione el campo que desea editar:                   |\n");  
                    printf("|                                                                          |\n");
                    printf("|    1.-Numero ID      2.Volumen       3.-Peso          4.-Regresar        |\n");
                    printf("|                                                                          |\n");
                    printf("+==========================================================================+\n");  
                    printf(">> ");
                    scanf("%d",&op);
                    system("clear");//limpio la pantalla
                    printf("\n");

                        switch (op)
                        {
                        case 1://editar id
                        printf("ingrese el nuevo numero del paquete: \n");
                        scanf("%s",num_paquete_new);
                        sprintf(cadena,"update paquetes set num_paquete='%s' where num_paquete='%s';",num_paquete_new, num_paquete);
                        resultado = PQexec(bd, cadena);
                        memset(num_paquete,0,10);
                        strcpy(num_paquete,num_paquete_new);
                        memset(num_paquete_new,0,10);
                        printf("Datos modificados \n\n\n\n");
                        break;

                        case 2://editar ciudad
                        printf("ingrese el numero volumen de paquete: \n");
                        scanf("%f",&vol_paquete_new);
                        sprintf(cadena,"update paquetes set vol_paquete='%f' where num_paquete='%s';",vol_paquete_new , num_paquete);
                        resultado = PQexec(bd, cadena);

                        printf("Datos modificados \n\n\n\n");       
                            break;

                        case 3://editar telefono
                        printf("ingrese el nuevo peso de paquete: \n");
                        scanf("%f",&peso_paquete_new);
                        sprintf(cadena,"update paquetes set peso_paquete='%f' where num_paquete='%s';",peso_paquete_new , num_paquete);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                            break;

                        case 4:
                        printf("regresando al menu anterior... \n\n\n");
                            break;

                        
                        default:
                            printf("No existe acción para la opción seleccionada.\n\n");
                        }//fin switch
                    } while (op !=4);
                }
        }
}

void menu_entregas(){
    int id1;
    MPI_Comm_rank (MPI_COMM_WORLD,& id1 ) ;
    
    if(id1==0);{
    
    
    do
    {
    printf("+==========================================================================+\n");   
    printf("|                           Opciones de entregas                           |\n");
    printf("+==========================================================================+\n");
    printf("|                    seleccione una opcion del menu:                       |\n");  
    printf("|                                                                          |\n");
    printf("| 1.-Alta                2.-Baja                  3.-Consulta              |\n");
    printf("|                                                                          |\n");
    printf("| 4.-Modificacion        5.-Regresar                                       |\n");
    printf("|                                                                          |\n");
    printf("+==========================================================================+\n");  
    printf(">> ");
    scanf("%d", &res);//scaneo la respuesta ingresada por el usuario
    system("clear");//limpio la pantalla
    printf("\n");
       
        switch (res)
        {
        case 1:
            alta_entregas(); //mando a llamar la funcion que da alta 
            break;
        case 2:
           baja_entregas(); //mando a llamar la funcion de baja (delete) 
            break;
        case 3:
            Consulta_entregas();//mando llamar la funcion de consulta (select) 
            break;
        case 4:
            modifica_entregas();//mando llamar la función de modificación de (update)
            break;
        case 5:
            printf("\nRegresando al menu principal...\n\n\n");
            break;

        default:printf("Seleccione una opción correcta porfavor\n");
        }
    } while (res != 5); 
    }

}

void alta_entregas(){
    ExecStatusType status;
    //datos de la base de datos en varchar y enteros
    char  id_camion[30], num_viaje[30], num_paquete[30], tie_destino[30], fecha_entrega[30];
    char id_entrega[30];
    conexion();//mando llamar la funcion conexión
        if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
        {
        //printf("Conexion exitosa\n\n\n");
        printf("+==========================================================================+\n"); 
        printf("|                  insercion de datos a la tabla entregas                  |\n");
        printf("+==========================================================================+\n"); 
        printf("Ingrese el id de la entrega: "); scanf("%s",id_entrega); setbuf(stdin,NULL);
        sprintf(cadena,"select*from detalle_entrega where id_entrega='%s'", id_entrega);
        resultado=PQexec(bd,cadena);
            if(PQntuples(resultado)==1){
                printf("El id de la entrega ingresada ya existe\n\n");
             }else{
            Consulta_camiones();
            printf("ingrese el ID del camion: "); scanf("%s",id_camion);setbuf(stdin,NULL);
            Consulta_viajes();
            printf("Ingresa el numero de viaje: "); scanf("%s",num_viaje);setbuf(stdin,NULL);
            Consulta_paquetes();
            printf("ingrese el numero de paquete: "); scanf("%s",num_paquete);setbuf(stdin,NULL);
            Consulta_tiendas();
            printf("ingrese la tienda de destino: "); scanf("%s",tie_destino);setbuf(stdin,NULL);
            printf("Ingresa la fecha de la entrega(YY-MM-DD) :"); scanf("%s", fecha_entrega);setbuf(stdin,NULL);
            sprintf(cadena, "insert into detalle_entrega(id_entrega,id_camion,num_viaje,num_paquete,tie_destino,fecha_entrega) values('%s','%s','%s','%s','%s','%s');", id_entrega,id_camion,num_viaje,num_paquete,tie_destino,fecha_entrega);
            printf("Instruccion SQL antes de ejecutarse: %s \n",cadena);
            resultado= PQexec(bd, cadena);
            if(PQresultStatus(resultado)==PGRES_COMMAND_OK){
                printf("Se registro con exito...\n\n");  
            }else{
                printf("error al guardar ...\n\n");
            }
        }

        }else//si no hace la conexion
        {
            printf("Conexion fallida :(\n");
        }
}

void baja_entregas(){
    ExecStatusType status;
    char id_entrega[10]; // variable para guardar y hacer la consulta de la placa
    conexion();
    if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
    {
        //printf("Conexion exitosa\n\n\n");
        printf("+==========================================================================+\n"); 
        printf("|               Eliminacion de datos de la tabla entregas                  |\n");
        printf("+==========================================================================+\n"); 
        Consulta_entregas();
        printf("ingrese el numero de entrega que desea eliminar: \n");
        printf(">> ");
        scanf("%s",id_entrega);
        //validar si existe la entrega
        sprintf(busqid,"select * from detalle_entrega where id_entrega = '%s'",id_entrega);
        resultado = PQexec(bd, busqid);
            if(PQntuples (resultado)== 0)
            {
                printf("¡esta tienda NO existe el la base de datos! :(\n\n\n");

            }else
            {
        
                sprintf(cadena, "delete from detalle_entrega where id_entrega = '%s';",id_entrega);
                printf("%s\n",cadena);
                resultado = PQexec(bd, cadena);
                if (resultado != NULL)
                {
                    printf("\n\n¡entrega eliminada correctamente! \n\n\n");
                }
                else
                {
                    printf("hay datos no permitidos o ingresados incorrectamente\n\n\n");
                }
            }
}
}

void Consulta_entregas(){
     conexion();
        if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
        {
            sprintf(cadena,"select * from detalle_entrega");//consulta de la tabla viajes;
            resultado = PQexec(bd, cadena);
           
            if(resultado != NULL)
            {
                printf("=============================================================================================\n");
                printf("|                                      Consulta de entregas                                 |\n");
                printf("| id_entrega | id_camion |   num_viaje |   num_paquete |    tie_destino |     fecha_entrega | \n"); 
                printf("=============================================================================================\n");
                fila=PQntuples(resultado);
                columna=PQnfields(resultado);
                
                for (i = 0; i < fila ; i++)
                {
                        for (j = 0; j < columna; j++)
                        {
                                
                                printf("%s\t\t",PQgetvalue(resultado,i,j));
                               
                        }
                
                printf("\n\n\n");
               }
               printf("=============================================================================================\n\n\n");
            }

        }else//si no hace la cnoexion
        {
            printf("conexion fallida :( \n\n\n");
        }
}

void modifica_entregas(){
    ExecStatusType status;
    char id_entrega[30];
    char id_entrega_new[30], num_viaje_new[30], num_paquete_new[30],id_camion_new[30], tie_destino_new[30], fecha_entrega_new[30];
     conexion();
        if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
        {

            //printf("Conexion exitosa\n\n\n");
            printf("+==========================================================================+\n"); 
            printf("|                Modificacion de datos de la tabla entregas                |\n");
            printf("+==========================================================================+\n"); 
            Consulta_entregas();//mando llamar la consulta paquetes para mostrar los datos 
            printf("ingrese el ID de entregan que desea modificar: \n");
            printf(">> ");
            scanf("%s",id_entrega);
            //validar si esta tienda  existe.
            sprintf(busqid,"select * from detalle_entrega where id_entrega = '%s' ", id_entrega );
            printf("%s\n",busqid);
            resultado = PQexec(bd, busqid);
            char resp;
                if(PQntuples (resultado)== 0)
                {
                    printf("\nno se encuentra el ID de la entrega:(\n\n\n");
                }else
                {
                    //mando llamar la funcion de consulta para conocer el cual se va a editar
                    Consulta_entregas();
                do{//menu de seleccion a editar***************************
                    printf("+======================================================================================================================+\n");   
                    printf("|                                             Menu de edicion de entregas                                              |\n");
                    printf("+======================================================================================================================+\n");
                    printf("|                                         seleccione el campo que desea editar:                                        |\n");  
                    printf("|                                                                                                                      |\n");
                    printf("|    1.-id_entrega   2.-id_camion       3.-num_viaje     4.-num_paquete   5.-tie_destino   6.-fecha_Entrega  7.-salir  |\n");
                    printf("|                                                                                                                      |\n");
                    printf("+======================================================================================================================+\n");  
                    printf(">> ");
                    scanf("%d",&op);
                    system("clear");//limpio la pantalla
                    printf("\n");

                        switch (op)
                        {
                        case 1://editar id
                        printf("ingrese el nuevo id de la entrega: \n");
                        scanf("%s",id_entrega_new);
                        sprintf(cadena,"update detalle_entrega set id_entrega='%s' where id_entrega='%s';",id_entrega_new, id_entrega);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                        break;

                        case 2://editar id camion
                        printf("ingrese el nuevo id del camion: \n");
                        scanf("%s",id_camion_new);
                        sprintf(cadena,"update detalle_entrega set id_camion='%s' where id_entrega='%s';",id_camion_new , id_entrega);
                        resultado = PQexec(bd, cadena);

                        printf("Datos modificados \n\n\n\n");       
                            break;

                        case 3://editar numero de viaje
                        printf("ingrese el nuevo numero de viaje: \n");
                        scanf("%s",num_viaje_new);
                        sprintf(cadena,"update detalle_entrega set num_viaje='%s' where id_entrega='%s';",num_viaje_new , id_entrega);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                            break;
                        case 4: // edita el numero paquete 
                        printf("ingrese el nuevo numero de paquete: \n");
                        scanf("%s",num_paquete_new);
                        sprintf(cadena,"update detalle_entrega set num_paquete='%s' where id_entrega='%s';",num_paquete_new , id_entrega);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                            break;
                        case 5: //edita el id de la tienda desitino
                        printf("ingrese el nuevo ID de la tienda destino: \n");
                        scanf("%s",tie_destino_new);
                        sprintf(cadena,"update detalle_entrega set tie_destino='%s' where id_entrega='%s';",tie_destino_new , id_entrega);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                            break;
                        case 6: //edita la fecha de entrega
                        printf("ingrese la nueva fecha de entrega: \n");
                        scanf("%s",fecha_entrega_new);
                        sprintf(cadena,"update detalle_entrega set fecha_entrega='%s' where id_entrega='%s';",fecha_entrega_new , id_entrega);
                        resultado = PQexec(bd, cadena);
                        printf("Datos modificados \n\n\n\n");
                            break;

                        case 7:
                        printf("regresando al menu anterior... \n\n\n");
                            break;

                        
                        default:
                            printf("No existe acción para la opción seleccionada.\n\n");
                        }//fin switch
                    } while (op !=7);
                }
        }
}
void menu_consultas(){
    int id1;
    MPI_Comm_rank (MPI_COMM_WORLD,& id1 ) ;
    if(id1==0){
    
    do{
    printf("+=====================================================================================================================================+\n");   
    printf("|                                                DATOS A CONSULTAR EN EL SISTEMA                                                      |\n");
    printf("+=====================================================================================================================================+\n");
    printf("|                                                 seleccione una opcion del menu:                                                     |\n");  
    printf("|                                                                                                                                     |\n");
    printf("| 1.-Lista de entregas en tiendas       2.-Paquete de camiones por placa           3.-Paquetes que exceden 250k y 5000udv             |\n");
    printf("|                                                                                                                                     |\n");
    printf("| 4.-Paquetes por tienda                5.-Camion con más viajes segun una         6.-Tiendas con paquetes mayores a 1300udv          |\n");
    printf("|                                          tienda especifica.                                                                         |\n"); 
    printf("|                                                                                                                                     |\n");
    printf("| 7.-Camiones que superaron su          8.-Mes con menos viajes                    9.-Mes con mas viajes                              |\n");
    printf("|    capacidad                                                                                                                        |\n");
    printf("|                                                                                                                                     |\n");
    printf("| 10.-Reporte final                     11.-Salir                                                                                     |\n");
    printf("|                                                                                                                                     |\n");
    printf("+=====================================================================================================================================+\n");  
    printf("[1/2/3/4/5/6/7/8/9/10]>> ");
    scanf("%d", &res);//scaneo la respuesta ingresada por el usuario

    system("clear");//limpio la pantalla
    printf("\n");
 
        switch (res)
        {
        case 1:
            tiendas_camiones_paquetes();
            break;
        case 2:
             paquetes_por_placa();
            break;
        case 3:
             tiendas_paquetes_de_peso_mayor_250();
            break;
        case 4:
             paquetes_por_tienda();
            break;
        case 5:
            consulta_viajes_mas_Ntienda();            
            break;
        case 6:
            consulta_paquetesVM1300(); 
            break;
        case 7:
            consulta_camionCapacidad_Sup();
            break;
        case 8:
            consulta_mes_menos_viajes();
            break;
        case 9:
            consulta_mes_mas_viajes();
            break;
        case 10:
            consulta_reportefinal();
            break;
        case 11:
            printf("\nRegresando al menu principal...\n\n\n");
            break;

        default:printf("Seleccione una opción correcta porfavor\n");
        }
 
 }while(res!=11);
           

}
}
void tiendas_camiones_paquetes(){ //Consulta 1

    conexion();
    if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente 
    {   

        sprintf(cadena,"select DISTINCT t.* from tiendas t, detalle_entrega d_e where d_e.tie_destino = t.tie_destino;");
        resultado = PQexec(bd, cadena);
           
        if(resultado != NULL)
        {
           printf("\n==============================================================================\n");
            printf("|          Consulta  tiendas a las que los camiones entregaron paquetes        |\n");
            printf("|       T_destino           |       direc_tienda        |        Tel_tienda    | \n");
            printf("===============================================================================\n");
            fila=PQntuples(resultado);
            columna=PQnfields(resultado);
                
            for (i = 0; i < fila ; i++)
            {
                for (j = 0; j < columna; j++)
                {
                                
                    printf("\t\t%s\t",PQgetvalue(resultado,i,j));
                              
                }
                
                printf("\n\n\n");
            }
            printf("=============================================================================\n\n\n");
        }

    }else//si no hace la cnoexion
    {
        printf("conexion fallida :( \n\n\n");
    }

}
void paquetes_por_placa(){ //Consulta 2
      conexion();
    if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
    {   
      char placa[30];
        printf("Ingresa la placa del camion:"); scanf("%s",placa);setbuf(stdin,NULL);          

        sprintf(cadena,"select c.id_camion, e.* from detalle_entrega d_e, camiones c, paquetes e where c.placa = '%s' and c.id_camion = d_e.id_camion and d_e.num_paquete = e.num_paquete;",placa);
        resultado = PQexec(bd, cadena);
           

            if(resultado != NULL)
            {
                printf("======================================================================\n");
                printf("|   Consulta del paquete que viajó en el camión con esas placas:     |\n");
                printf("|  ID_camion |  Num_paquete  | Vol_paquete |   Peso_paquete |        |\n");
                printf("======================================================================\n   ");
                fila=PQntuples(resultado);
                columna=PQnfields(resultado);
                
                for (i = 0; i < fila ; i++)
                {
                        for (j = 0; j < columna; j++)
                        {
                                
                                printf("\t%s\t",PQgetvalue(resultado,i,j));
                               
                        }
                
                printf("\n\n\n");
               }
               printf("============================================================================================\n\n\n");
            }

    }else//si no hace la cnoexion
    {
        printf("conexion fallida :( \n\n\n");
    }


}
void tiendas_paquetes_de_peso_mayor_250(){ //Consulta 3
     conexion();
    if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
    {   

        sprintf(cadena,"select t.tie_destino, t.direc_tienda, e.num_paquete, e.vol_paquete, e.peso_paquete from tiendas t, detalle_entrega d_e, paquetes e where d_e.tie_destino = t.tie_destino and e.peso_paquete > 250 and  e.vol_paquete > 5000 and d_e.num_paquete = e.num_paquete;");
        resultado = PQexec(bd, cadena);
           
        if(resultado != NULL)
        {
           printf("\n============================================================================\n");
            printf("|                     Consulta de paquetes a tiendas mayor 250kg            |\n");
            printf("|   T_destino  | direc_tienda |   N_paquete  |  Vol_paquete | Peso_paquete  |\n");
            printf("=============================================================================\n");
            fila=PQntuples(resultado);
            columna=PQnfields(resultado);
                
            for (i = 0; i < fila ; i++)
            {
                for (j = 0; j < columna; j++)
                {
                                
                    printf("\t\t%s\t",PQgetvalue(resultado,i,j));
                              
                }
                
                printf("\n\n\n");
            }
            printf("=============================================================================\n\n\n");
        }

    }else//si no hace la conexion
    {
        printf("conexion fallida :( \n\n\n");
    }

}

void paquetes_por_tienda(){ //Consulta 4
    conexion();
    if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
    {   
      char tie_destino[30];
        printf("Ingresa la direc de la tienda:"); scanf("%s", tie_destino);setbuf(stdin,NULL);         

        sprintf(cadena,"select d_e.id_camion,c.modelo, c.placa, c.vol_camion, c.peso_camion, c.conductor, e.num_paquete, t.direc_tienda, d_e.num_viaje from detalle_entrega d_e, tiendas t, camiones c, paquetes e where d_e.tie_destino=t.tie_destino and t.direc_tienda='%s' and d_e.id_camion = c.id_camion and d_e.num_paquete=e.num_paquete group by d_e.id_camion, c.modelo, c.placa, c.vol_camion, c.peso_camion, c.conductor, e.num_paquete, t.direc_tienda, d_e.num_viaje;",tie_destino);
        resultado = PQexec(bd, cadena);
           

            if(resultado != NULL)
            {
                printf("=========================================================================================================================\n");
                printf("|                            Consulta los paquetes entregados segun la tienda y el camión                               |\n");
                printf("|  ID_camion | modelo | placa | vol_camion |   peso_camion | conductor| num_paquete |direc_tienda | num_viaje           |\n");
                printf("=========================================================================================================================\n");
                fila=PQntuples(resultado);
                columna=PQnfields(resultado);
                
                for (i = 0; i < fila ; i++)
                {
                        for (j = 0; j < columna; j++)
                        {
                                
                                printf("%s\t",PQgetvalue(resultado,i,j));
                               
                        }
                
                printf("\n\n\n");
               }
               printf("============================================================================================\n\n\n");
            }

    }else//si no hace la conexion
    {
        printf("conexion fallida :( \n\n\n");
    }


}

void consulta_viajes_mas_Ntienda(){ //Consulta 5

    conexion();
    if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
    {   
        char direc_tienda[30];
        printf("Ingresa la direc de la tienda:"); scanf("%s", direc_tienda);setbuf(stdin,NULL);          

        sprintf(cadena," select d_e.id_camion,c.modelo, c.placa, c.vol_camion, c.peso_camion, c.conductor, t.direc_tienda, COUNT(d_e.id_camion)as nViajes from detalle_entrega d_e, tiendas t, camiones c where d_e.tie_destino=t.tie_destino and t.direc_tienda='%s' and d_e.id_camion = c.id_camion group by d_e.id_camion, c.modelo, c.placa, c.vol_camion, c.peso_camion, c.conductor, t.direc_tienda having count(d_e.id_camion)=(select max(total) from(select count(d_e.id_camion)as total from detalle_entrega d_e, tiendas t  where d_e.tie_destino=t.tie_destino and t.direc_tienda='%s' group by d_e.id_camion)t1);", direc_tienda, direc_tienda);
        resultado = PQexec(bd, cadena);
           

            if(resultado != NULL)
            {
                printf("============================================================================================\n");
                printf("|             Consulta de auto con mas viajes a segun la dirección de la tienda            |\n");
                printf("|  ID |Modelo |Placa |Volumen |Peso |Conductor | Direcc tienda | Num viajes                |\n");
                printf("============================================================================================\n   ");
                fila=PQntuples(resultado);
                columna=PQnfields(resultado);
                
                for (i = 0; i < fila ; i++)
                {
                        for (j = 0; j < columna; j++)
                        {
                                
                                printf("%s\t",PQgetvalue(resultado,i,j));
                               
                        }
                
                printf("\n\n\n");
               }
               printf("============================================================================================\n\n\n");
            }

    }else//si no hace la cnoexion
    {
        printf("conexion fallida :( \n\n\n");
    }
}

void consulta_paquetesVM1300(){ //Consulta 6

    conexion();
    if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
    {   

        sprintf(cadena,"select t.tie_destino,t.direc_tienda, e.num_paquete, e.vol_paquete from tiendas t, detalle_entrega d_e, paquetes e where d_e.tie_destino = t.tie_destino and e.vol_paquete > 1300 and d_e.num_paquete = e.num_paquete;");
        resultado = PQexec(bd, cadena);
           
        if(resultado != NULL)
        {
           printf("\n===========================================================================\n");
            printf("|         Consulta de paquetes a tiendas con un volumen mayor a 1300       |\n");
            printf("|  T_destino |  Direc_tienda  |     N_paquete      |      Vol_paquete      | \n");
            printf("============================================================================\n");
            fila=PQntuples(resultado);
            columna=PQnfields(resultado);
                
            for (i = 0; i < fila ; i++)
            {
                for (j = 0; j < columna; j++)
                {
                                
                    printf("\t\t%s\t",PQgetvalue(resultado,i,j));
                              
                }
                
                printf("\n\n\n");
            }
            printf("=============================================================================\n\n\n");
        }

    }else//si no hace la conexion
    {
        printf("conexion fallida :( \n\n\n");
    }
}

void consulta_camionCapacidad_Sup(){ //Consulta 7

    conexion();
    if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
    {   

        sprintf(cadena,"select c.id_camion, c.modelo, c.peso_camion, e.num_paquete, e.peso_paquete from detalle_entrega d_e, camiones c, paquetes e where d_e.id_camion = c.id_camion and e.peso_paquete>(c.peso_camion*4) and d_e.num_paquete = e.num_paquete;");
        resultado = PQexec(bd, cadena);
           
        if(resultado != NULL)
        {
           printf("\n=================================================================================\n");
            printf("|                      Consultas camion que superaron su capacidad               |\n");
            printf("|   id_camion  |    Modelo    |    peso_camion  | num_paquete   |  peso_paquete  |\n");
            printf("==================================================================================\n");
            fila=PQntuples(resultado);
            columna=PQnfields(resultado);
                
            for (i = 0; i < fila ; i++)
            {
                for (j = 0; j < columna; j++)
                {
                                
                    printf("\t%s\t",PQgetvalue(resultado,i,j));
                              
                }
                
                printf("\n\n\n");
            }
            printf("==================================================================================\n\n\n");
        }

    }else//si no hace la conexion
    {
        printf("conexion fallida :( \n\n\n");
    }
}

void consulta_mes_menos_viajes(){ //Consulta 8
    conexion();
    if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
    {   

        sprintf(cadena,"select count (EXTRACT (MONTH from fecha_entrega)) as nViajes, EXTRACT(MONTH FROM fecha_entrega) as mes from detalle_entrega group by EXTRACT(MONTH FROM fecha_entrega) HAVING Count(EXTRACT(MONTH FROM fecha_entrega)) = (select MIN(nViajes) from (select count(EXTRACT(MONTH from d_e.fecha_entrega))as nViajes from detalle_entrega d_e group by EXTRACT(MONTH From d_e.fecha_entrega))t1);");
        resultado = PQexec(bd, cadena);
           
        if(resultado != NULL)
        {
           printf("\n=============================================================\n");
            printf("|               Consulta mes con menos viajes                |\n");
            printf("|        N_viajes           |            Mes                 | \n");
            printf("==============================================================\n");
            fila=PQntuples(resultado);
            columna=PQnfields(resultado);
                
            for (i = 0; i < fila ; i++)
            {
                for (j = 0; j < columna; j++)
                {
                                
                    printf("\t\t%s\t",PQgetvalue(resultado,i,j));
                              
                }
                
                printf("\n\n\n");
            }
            printf("===============================================================\n\n\n");
        }

    }else//si no hace la conexion
    {
        printf("conexion fallida :( \n\n\n");
    }
}

void consulta_mes_mas_viajes(){ //Consulta 9
    conexion();
    if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
    {   

        //sprintf(buscarCli,"select a.color, count(a.color)as cantRep from automoviles a group by a.color having count(a.num_auto) = (select max(total) from(select count(acc.num_auto)as total from accidentes acc group by acc.num_auto)t1);");
        sprintf(cadena,"select count (EXTRACT (MONTH from fecha_entrega)) as nViajes, EXTRACT(MONTH FROM fecha_entrega) as mes from detalle_entrega group by EXTRACT(MONTH FROM fecha_entrega) HAVING Count(EXTRACT(MONTH FROM fecha_entrega)) = (select max(nViajes) from (select count(EXTRACT(MONTH from d_e.fecha_entrega))as nViajes from detalle_entrega d_e group by EXTRACT(MONTH From d_e.fecha_entrega))t1);");
        resultado = PQexec(bd, cadena);
           
        if(resultado != NULL)
        {
           printf("\n=============================================================\n");
            printf("|               Consulta mes con mas viajes                  |\n");
            printf("|        Numero de viaje      |             Mes              | \n");
            printf("==============================================================\n");
            fila=PQntuples(resultado);
            columna=PQnfields(resultado);
                
            for (i = 0; i < fila ; i++)
            {
                for (j = 0; j < columna; j++)
                {
                                
                    printf("\t\t%s\t",PQgetvalue(resultado,i,j));
                              
                }
                
                printf("\n\n\n");
            }
            printf("===============================================================\n\n\n");
        }

    }else//si no hace la cnoexion
    {
        printf("conexion fallida :( \n\n\n");
    }
}

void consulta_reportefinal(){ //Procedimiento almacenado con consulta 10
    conexion();
    if(PQstatus(bd) == CONNECTION_OK)//si hace la conexion correctamente
    {   
        char fecha_entregaini[30], fecha_entregafin[30]; 

        printf("Ingresa la fecha de inicio(YY-MM-DD) :"); scanf("%s", fecha_entregaini);setbuf(stdin,NULL);          
        printf("Ingresa la fecha de fin(YY-MM-DD) :"); scanf("%s", fecha_entregafin);setbuf(stdin,NULL);
        printf("\n\tEl reporte total es:");

        sprintf(cadena,"Select * from reporte_total('%s','%s') as (num_viaje varchar, id_camion varchar, fecha_entrega date, direc_tienda varchar, num_paquete varchar, vol_paquete numeric);", fecha_entregaini, fecha_entregafin);
        resultado = PQexec(bd, cadena);
           
        if(resultado != NULL)
        {
           printf("\n===============================================================================\n");
            printf("|                               Consulta de autos                              |\n");
            printf("|num_viaje | id_camion |fecha_entrega |direc_entrega | num_paquete| vol_paquete| \n");
            printf("================================================================================u\n");
            fila=PQntuples(resultado);
            columna=PQnfields(resultado);
                
            for (i = 0; i < fila ; i++)
            {
                for (j = 0; j < columna; j++)
                {
                                
                    printf("%s\t",PQgetvalue(resultado,i,j));
                              
                }
                
                printf("\n\n\n");
            }
            printf("============================================================================\n\n\n");
        }

    }else//si no hace la cnoexion
    {
        printf("conexion fallida :( \n\n\n");
    }

}
