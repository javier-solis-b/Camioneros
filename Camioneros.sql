create database camioneros;


--CREACION DE TABLAS:


CREATE TABLE camiones(
id_camion varchar not null primary key,
modelo varchar NOT NULL,
placa varchar,
vol_camion numeric(10,2) NOT NULL,
peso_camion numeric(10,2) NOT NULL,
conductor varchar default 'No asignado'
);
insert into camiones values('c1','2020','05fa',54,20,'Pablo Maqueda');
insert into camiones values('c2','2021','05fd',55,30,'Pedro Prado');
insert into camiones values('c3','2019','05df',52,20,'Julio Profe');
insert into camiones values('c4','2018','05gc',50,20,'Ana Banana');

CREATE TABLE viajes(
id_camion varchar not null,
num_viaje varchar not null,
constraint viajes_pkey primary key (id_camion, num_viaje),
constraint viajes_id_camion_fkey foreign key (id_camion)
references camiones(id_camion) on delete cascade 
);
insert into viajes values('c1','v1');
insert into viajes values('c2','v1');
insert into viajes values('c2','v2');
insert into viajes values('c3','v1');
insert into viajes values('c3','v1');

CREATE TABLE tiendas(
tie_destino varchar primary key,
nombre_tienda varchar,
direc_tienda varchar,
tel_tienda varchar
);
insert into tiendas values('t1','Mercantil PH','Tapachula',962103234);
insert into tiendas values('t2','AutoServicio Rapido PH','El Porvenir Mexicali',99999999);
insert into tiendas values('t3','Colchones PH','Calle Juanisimo CDMX', 3400000);
insert into tiendas values('t4','Abarrotes PH','5 de Febrero TapChiapas',23333333);

CREATE TABLE paquetes(
num_paquete varchar primary key,
vol_paquete numeric(10,2),
peso_paquete numeric(10,2)
);
insert into paquetes values('p1',15,25);
insert into paquetes values('p2',14,30);
insert into paquetes values('p3',10,23);
insert into paquetes values('p4',20,25);

CREATE TABLE detalle_entrega(
id_entrega varchar primary key,
id_camion varchar,
num_viaje varchar,
num_paquete varchar unique references envios, 
tie_destino varchar references tiendas,
fecha_entrega date,
constraint detalle_entrega_fkey foreign key(id_camion,num_viaje)
references viajes(id_camion,num_viaje) on delete no action
);
insert into detalle_entrega values('e1','c1','v1','p1','t1','2020-03-23');
insert into detalle_entrega values('e2','c2','v1','p2','t3','2020-03-25');
insert into detalle_entrega values('e3','c1','v1','p3','t1','2020-03-26');
insert into detalle_entrega values('e4','c2','v1','p4','t2','2020-03-23');

--alter table "detalle_entrega" add constraint "detalle_entrega_fkey_val" unique (num_envio);
menu
--Administrador proovedores Perez hermanos

	--Camiones
		--Crud
		--Consulta pesos
	--Tiendas
		--Crud	t1-t45
	--Envios
		-- Agregar un nuevo envio
		-- Modificar datos
	--entregas


