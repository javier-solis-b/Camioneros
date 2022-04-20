// gcc -o camioneros camioneros.c -I /usr/include/postgresql/ -lpq
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <libpq-fe.h>


//---------------------------------variables globales-------------------------------------------------------------------------                                              
PGconn *bd;  // Variable que almacena la conexion con una BDs en postgres
PGresult *resultado; //variables para consultas
PGresult *ress;
int i,j,fila,columna;
int res, opc, op; //variable para las respuestas del menú
char cadena[1000],busqid[1000];;//variable(s) para las funciones de psql
//----------------------------------------------------------------------------------------------------------
void conexion()
{
    //(ip_servidor,puerto_postgres,NULL,NULL,BDs,Usuario,contraseña)
	bd=PQsetdbLogin("localhost","5432",NULL,NULL,"camioneros","postgres","1234");
}//fin metodo de conexion
//-------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[]){     
	menu_principal();//mando llamar la funcion del menu principal
    return 0;
}//fin main-----------------------------------------------------------------------------------------------------

void empty_stdin() // limpiar el buffer
{
    int s;
    do
    {
        s = getchar();
    } while (s != '\n' && s != EOF);
}//fin limpiar el buffer---------------------------------------------------------------- 

void menu_principal()//función para el menú principal
{
   setbuf(stdin,NULL); // Limpiar
   printf("\n       Bienvenido al administrador de provisiones 'Perez hermanos'  \t\t\n");
    do
    {
    // menu principal*****************************************************************************************************
    printf("+========================================================================+\n");   
    printf("|                            Menu principal                              |\n");
    printf("+========================================================================+\n");
    printf("|                    seleccione una opcion del menu:                     |\n");  
    printf("|                                 |                                      |\n");
	printf("| 1.-opciones para camiones       |     2.-opciones para viajes          |\n");
    printf("|                                 |                                      |\n");
    printf("| 3.-opciones para tiendas        |     4.-opciones para envios          |\n");
    printf("|                                 |                                      |\n");
    printf("| 5.-opciones para entregas       |     6.-consultas                     |\n");
    printf("|                                 |                                      |\n");
    printf("| 7.-Salir                        |                                      |\n");
    printf("|                                 |                                      |\n");
	printf("+==========================================================================+\n");  
    printf(">> ");
    scanf("%d", &res);//scaneo la respuesta ingresada por el usuario
    system("clear");//limpio la pantalla
    printf("\n");//menu_viajes();//mando llamar a la funcion del menu viajes
       
        switch (res)
        {
        case 1:
            menu_camiones();//mando llamar a la funcion del menu de camiones
            break;

        case 2:
            menu_viajes();//mando llamar a la funcion del menu viajes
            break;

        case 3:
            menu_tiendas();//mando llamar a la funcion del menu tiendas
            break;

        case 4:
            //menu_envios();//mando llamar a la funcion del menu envios
            break;
        
        case 5:
            //menu_entregas();//mando llamar a la funcion del menu entregas
            break;

        case 6:
            //menu_consultas();
            break;

        case 7:
            printf("saliendo...\n\n\n");
            break;

        default:printf("\n Error, esta opción no está disponible, ingrese una opción válida\n");
        }
    } while (res != 7); 

	// return 0;

}//fin funcion menu_pricipal----------------------------------------------------------------------------------------

void menu_camiones()//funcion para el menu de camiones
{
    do
    {
    printf("+==========================================================================+\n");   
    printf("|                          opciones de camiones                            |\n");
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
}//fin menu camiones-----------------------------------------------------------------------------------------

void alta_camiones()//funcion para alta(insert)
{
    ExecStatusType status;
    //datos de la base de datos en varchar y enteros
    char idcamion[10], modelo[10], placa[10], conductor[40];
    float volcamion, pesocamion;

    conexion();//mando llamar la funcion conexión
        if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
        {
        //printf("Conexion exitosa\n\n\n");
        printf("+==========================================================================+\n"); 
        printf("|                  insercion de datos a la tabla camiones                  |\n");
        printf("+==========================================================================+\n"); 
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
        sprintf(cadena,"insert into camiones values('%s', '%s', '%s', %f,  %f, '%s');",idcamion, modelo, placa,volcamion,pesocamion, conductor);
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
                printf("================================================================\n");
                printf("|                     Consulta de autos                        |\n");
                printf("|id    |Modelo |placa |Volumen |peso  |conductor               | \n");
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
    

}//fin consulta camiones--------------------------------------------------------------------------------------------

void modifica_camiones()
{
    ExecStatusType status;
    //datos de la basae de datos en varchar y enteros
    float volcamion, pesocamion;
    char idcamion[10], modelo[10], placa[10],conductor[40], placanew[10];

    conexion();
        if (PQstatus(bd) == CONNECTION_OK)//si la conexion es exitosa
        {
            //printf("Conexion exitosa\n\n\n");
            printf("+==========================================================================+\n"); 
            printf("|                Modificacion de datos de la tabla camiones                   |\n");
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
                    printf("| 1.-Id del camion         2.-modelo              3.-placa                 |\n");
                    printf("|                                                                          |\n");
                    printf("| 4.-volumen                5.-peso               6.-conductor             |\n");
                    printf("|                                                                          |\n");
                    printf("| 7.-regresar                                                              |\n");
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
                            printf("regresando al menu anterior...\n\n\n");
                            break;                

                        default:
                            printf("No existe acción para la opción seleccionada.\n\n");
                        }//fin switch
                    } while (op !=7);
                }

    }
    else
    {
        printf("error al conectar :( \n\n\n");
    }

}//fin modifica camiones-------------------------------------------------------------------------------

void menu_viajes()//menú para opciones de viajes
{
    do
    {
    printf("+==========================================================================+\n");   
    printf("|                           opciones de viajes                             |\n");
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
        printf("|                  insercion de datos a la tabla viajes                    |\n");
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
        printf("|               Eliminacion de datos de la tabla Camiones                  |\n");
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
                printf("| auto|numero de viaje                                         | \n"); 
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
            printf("ingrese el numero de viaje que desea editar: \n");
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
                    printf("| 1.-Id del camion         2.-num_viaje              3.-regresar           |\n");
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
                        printf("regresando al menu anterior... \n\n\n");
                        
                            
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
     do
    {
    printf("+==========================================================================+\n");   
    printf("|                           opciones de tiendas                            |\n");
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
        printf("|                  insercion de datos a la tabla tiendas                   |\n");
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
                printf("| ID | Ciudad | teléfono                                       | \n"); 
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
                    printf("hay datos no permitidos o ingresados incorrectamente\n\n\n");
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
                        printf("ingrese el nuevo id: \n");
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
                        printf("regresando al menu anterior... \n\n\n");
                            break;

                        
                        default:
                            printf("No existe acción para la opción seleccionada.\n\n");
                        }//fin switch
                    } while (op !=4);
                }
        }
}//fin modidfica tiendas