create database camioneros;


--CREACION DE TABLAS:


CREATE TABLE camiones(
almacen_Salida varchar,
id_camion varchar not null primary key,
modelo varchar NOT NULL,
placa varchar,
vol_camion numeric NOT NULL,
peso_camion numeric NOT NULL,
conductor varchar default 'No asignado'
);



insert into camiones values('a1','c1','2020','05fa',5000, 500,'Pablo');
insert into camiones values('a1','c2','2021','05fd',5000, 500,'Pedro');
insert into camiones values('a1','c3','2019','05df',5000, 500,'Julio');
insert into camiones values('a1','c4','2018','05gc',5000, 500,'Ana');
insert into camiones values('a1','c5','2017','05ga',5000, 500,'Juan');
insert into camiones values('a1','c6','2011','05gb',5000, 500,'Maria');
insert into camiones values('a2','c7','2012','05gc',5000, 500,'Lucas');
insert into camiones values('a2','c8','2013','05gd',5000, 500,'Rosita');
insert into camiones values('a3','c9','2014','05ge',5000, 500,'Alvaro');
insert into camiones values('a3','c10','2015','05gf',5000, 500,'Alexis');
insert into camiones values('a3','c11','2016','05gg',5000, 500,'Mateo');
insert into camiones values('a3','c12','2018','05gh',5000, 500,'Kevin');
insert into camiones values('a3','c13','2019','05gi',5000, 500,'Jhonatan');
insert into camiones values('a3','c14','2020','05gj',5000, 500,'Sofia');
insert into camiones values('a3','c15','2021','05gk',5000, 500,'Michell');
insert into camiones values('a3','c16','2001','05gm',5000, 500,'Irma');
insert into camiones values('a3','c17','2002','05gn',5000, 500,'Lizeth');
insert into camiones values('a4','c18','2003','05gñ',5000, 500,'Emilia');
insert into camiones values('a4','c19','2004','05go',5000, 500,'Marcos');
insert into camiones values('a4','c20','2005','05gp',5000, 500,'Diego');
insert into camiones values('a4','c21','2006','05gq',5000, 500,'Braulio');
insert into camiones values('a4','c22','2007','05gr',5000, 500,'Jose');
insert into camiones values('a5','c23','2008','05gs',5000, 500,'Antonio');
insert into camiones values('a5','c24','2009','05gt',5000, 500,'Josue');
insert into camiones values('a5','c25','2010','05gu',5000, 500,'Martina');
insert into camiones values('a5','c26','2011','05gv',5000, 500,'Natalia');
insert into camiones values('a5','c27','2012','05gw',5000, 500,'Yaneth');
insert into camiones values('a6','c28','2013','05gx',5000, 500,'Lucero');
insert into camiones values('a6','c29','2014','05gy',5000, 500,'Marisol');
insert into camiones values('a6','c30','2016','05gz',5000, 500,'Jennifer');

CREATE TABLE viajes(
id_camion varchar not null,
num_viaje varchar not null,
constraint viajes_pkey primary key (id_camion, num_viaje),
constraint viajes_id_camion_fkey foreign key (id_camion)
references camiones(id_camion) on delete cascade 
);

insert into viajes values('c1','v1');
insert into viajes values('c2','v1');
insert into viajes values('c3','v1');
insert into viajes values('c4','v1');
insert into viajes values('c5','v1');
insert into viajes values('c6','v1');
insert into viajes values('c7','v1');
insert into viajes values('c8','v1');
insert into viajes values('c9','v1');
insert into viajes values('c10','v1');
insert into viajes values('c11','v1');
insert into viajes values('c12','v1');
insert into viajes values('c13','v1');
insert into viajes values('c14','v1');
insert into viajes values('c15','v1');
insert into viajes values('c16','v1');
insert into viajes values('c17','v1');
insert into viajes values('c18','v1');
insert into viajes values('c19','v1');
insert into viajes values('c20','v1');
insert into viajes values('c21','v1');
insert into viajes values('c22','v1');
insert into viajes values('c23','v1');
insert into viajes values('c24','v1');
insert into viajes values('c25','v1');
insert into viajes values('c26','v1');
insert into viajes values('c27','v1');
insert into viajes values('c28','v1');
insert into viajes values('c29','v1');
insert into viajes values('c30','v1');
insert into viajes values('c1','v2');
insert into viajes values('c2','v2');
insert into viajes values('c3','v2');
insert into viajes values('c4','v2');
insert into viajes values('c5','v2');
insert into viajes values('c6','v2');
insert into viajes values('c7','v2');
insert into viajes values('c8','v2');
insert into viajes values('c9','v2');
insert into viajes values('c10','v2');
insert into viajes values('c11','v2');
insert into viajes values('c12','v2');
insert into viajes values('c13','v2');
insert into viajes values('c14','v2');
insert into viajes values('c15','v2');
insert into viajes values('c16','v2');
insert into viajes values('c17','v2');
insert into viajes values('c18','v2');
insert into viajes values('c19','v2');
insert into viajes values('c20','v2');
insert into viajes values('c21','v2');
insert into viajes values('c22','v2');
insert into viajes values('c23','v2');
insert into viajes values('c24','v2');
insert into viajes values('c25','v2');
insert into viajes values('c26','v2');
insert into viajes values('c27','v2');
insert into viajes values('c28','v2');
insert into viajes values('c29','v2');
insert into viajes values('c30','v2');
insert into viajes values('c1','v3');
insert into viajes values('c2','v3');
insert into viajes values('c3','v3');
insert into viajes values('c4','v3');
insert into viajes values('c5','v3');
insert into viajes values('c6','v3');
insert into viajes values('c7','v3');
insert into viajes values('c8','v3');
insert into viajes values('c9','v3');
insert into viajes values('c10','v3');
insert into viajes values('c11','v3');
insert into viajes values('c12','v3');
insert into viajes values('c13','v3');
insert into viajes values('c14','v3');
insert into viajes values('c15','v3');
insert into viajes values('c16','v3');
insert into viajes values('c17','v3');
insert into viajes values('c18','v3');
insert into viajes values('c19','v3');
insert into viajes values('c20','v3');
insert into viajes values('c21','v3');
insert into viajes values('c22','v3');
insert into viajes values('c23','v3');
insert into viajes values('c24','v3');
insert into viajes values('c25','v3');
insert into viajes values('c26','v3');
insert into viajes values('c27','v3');
insert into viajes values('c28','v3');
insert into viajes values('c29','v3');
insert into viajes values('c30','v3');


CREATE TABLE tiendas(
tie_destino varchar primary key,
direc_tienda varchar,
tel_tienda numeric
);
insert into tiendas values('t1','Tapachula',962103234);
insert into tiendas values('t2','Mexical',99999999);
insert into tiendas values('t3','Puebla', 3400000);
insert into tiendas values('t4','Tuxtla',23333333);
insert into tiendas values('t5','Cancun',2245235);

CREATE TABLE paquetes(
num_paquete varchar primary key,
vol_paquete numeric(10,2),
peso_paquete numeric(10,2)
);

insert into paquetes values('p1',5001,251);
insert into paquetes values('p2',500,3000);
insert into paquetes values('p3',5001,251);
insert into paquetes values('p4',5001,251);
insert into paquetes values('p5',500,2600);
insert into paquetes values('p6',5001,251);
insert into paquetes values('p7',450,1000);
insert into paquetes values('p8',5001,251);
insert into paquetes values('p9',300,850);
insert into paquetes values('p10',5001,251);
insert into paquetes values('p11',300,900);
insert into paquetes values('p12',290,1000);
insert into paquetes values('p13',800,1100);
insert into paquetes values('p14',270,1200);
insert into paquetes values('p15',340,1050);
insert into paquetes values('p16',600,2300);
insert into paquetes values('p17',2334,6500);
insert into paquetes values('p18',290,500);
insert into paquetes values('p19',230,980);
insert into paquetes values('p20',200,600);
insert into paquetes values('p21',200,670);
insert into paquetes values('p22',190,400);
insert into paquetes values('p23',180,890);
insert into paquetes values('p24',170,1150);
insert into paquetes values('p25',160,1230);
insert into paquetes values('p26',950,1220);
insert into paquetes values('p27',850,2340);
insert into paquetes values('p28',750,1600);
insert into paquetes values('p29',650,1605);
insert into paquetes values('p30',250,1400);
insert into paquetes values('p31',350,3000);
insert into paquetes values('p32',450,430);
insert into paquetes values('p33',550,600);
insert into paquetes values('p34',200,650);
insert into paquetes values('p35',300,3450);
insert into paquetes values('p36',400,2600);
insert into paquetes values('p37',500,2100);

CREATE TABLE detalle_entrega(
id_entrega varchar primary key,
id_camion varchar,
num_viaje varchar,
num_paquete varchar unique references paquetes, 
tie_destino varchar references tiendas,
fecha_entrega date,
constraint detalle_entrega_fkey foreign key(id_camion,num_viaje)
references viajes(id_camion,num_viaje) on delete no action
);

insert into detalle_entrega values('e1','c1','v1','p1','t1','2020-03-23');
insert into detalle_entrega values('e2','c2','v1','p2','t3','2020-03-25');
insert into detalle_entrega values('e3','c1','v1','p3','t1','2020-03-26');
insert into detalle_entrega values('e4','c2','v2','p4','t2','2020-03-02');
insert into detalle_entrega values('e5','c3','v2','p5','t2','2020-03-05');
insert into detalle_entrega values('e6','c4','v3','p6','t3','2020-04-23');
insert into detalle_entrega values('e7','c5','v1','p7','t4','2020-05-23');
insert into detalle_entrega values('e8','c6','v2','p8','t1','2020-05-23');
insert into detalle_entrega values('e9','c7','v3','p9','t2','2020-06-23');
insert into detalle_entrega values('e10','c8','v1','p10','t3','2020-06-23');
insert into detalle_entrega values('e11','c9','v2','p11','t4','2020-07-23');
insert into detalle_entrega values('e12','c10','v3','p12','t1','2020-07-23');
insert into detalle_entrega values('e13','c11','v1','p13','t2','2020-08-23');
insert into detalle_entrega values('e14','c12','v2','p14','t3','2020-08-23');
insert into detalle_entrega values('e15','c13','v3','p15','t4','2020-09-23');
insert into detalle_entrega values('e16','c14','v1','p16','t1','2020-09-23');
insert into detalle_entrega values('e17','c15','v2','p17','t2','2020-10-23');
insert into detalle_entrega values('e18','c16','v3','p18','t3','2020-10-23');
insert into detalle_entrega values('e19','c17','v1','p19','t4','2020-10-23');
insert into detalle_entrega values('e20','c18','v2','p20','t1','2020-11-23');
insert into detalle_entrega values('e21','c19','v3','p21','t2','2020-12-23');
insert into detalle_entrega values('e22','c20','v1','p22','t3','2020-11-23');
insert into detalle_entrega values('e23','c21','v2','p23','t3','2020-12-23');
insert into detalle_entrega values('e24','c22','v3','p24','t1','2020-01-23');
insert into detalle_entrega values('e25','c23','v1','p25','t2','2020-01-23');
insert into detalle_entrega values('e26','c24','v2','p26','t3','2020-02-23');
insert into detalle_entrega values('e27','c25','v3','p27','t4','2020-02-23');
insert into detalle_entrega values('e28','c26','v1','p28','t1','2020-04-23');
insert into detalle_entrega values('e29','c27','v2','p29','t2','2020-05-23');
insert into detalle_entrega values('e30','c28','v3','p30','t3','2020-04-23');
insert into detalle_entrega values('e31','c29','v1','p31','t4','2020-06-23');
insert into detalle_entrega values('e32','c30','v2','p32','t1','2020-03-23');
insert into detalle_entrega values('e33','c1','v3','p33','t2','2020-06-23');
insert into detalle_entrega values('e34','c2','v1','p34','t3','2020-05-23');
insert into detalle_entrega values('e35','c3','v2','p35','t4','2020-12-04');

--Alteración de la tabla detalle_entrega para que no se pueda repetir el paquete entregado (constraint)

--alter table "detalle_entrega" add constraint "detalle_entrega_fkey_val" unique (num_paquete);


--Menu

--Administrador proovedores peres hermanos

	--Camiones
		
	--Tiendas
	
	--Paquetes
		
	--Entregas
	
	--Consultas adicionales
-----------------------------------------------------------

--Consulta 1•	Mostrar cada una de las tiendas a las que los camiones entregaron paquetes.
select DISTINCT t.* from tiendas t, detalle_entrega d_e where d_e.tie_destino = t.tie_destino;

-----------------------------------------------------------

--Consulta 2•	Mostrar los paquetes que viajaron en el camion con numero de placa FGH-19-56 (este es un ejemplo. Utilice una placa que tenga dada de alta en su sistema).
select c.id_camion, e.* from detalle_entrega d_e, camiones c, paquetes e
where c.placa = '05fa' and c.id_camion = d_e.id_camion and d_e.num_paquete = e.num_paquete; 

-----------------------------------------------------------

--Consulta 3•	Mostrar los nombres de las tiendas que recibieron paquetes con un peso mayor que 250kg y un volumen mayor que 5000 unidades.
	select t.tie_destino, t.direc_tienda, e.num_paquete, e.vol_paquete, e.peso_paquete from tiendas t, detalle_entrega d_e, paquetes e
	where d_e.tie_destino = t.tie_destino and e.peso_paquete > 250 and  e.vol_paquete > 5000 and d_e.num_paquete = e.num_paquete;

-----------------------------------------------------------

--Consulta 4•	Mostrar los paquetes que llegaron a la tienda Perez Hermanos en Monterrey asi también mostrar los camiones que llevaron dichos paquetes y en que viaje fueron trasladados.

select d_e.id_camion,c.modelo, c.placa, c.vol_camion, c.peso_camion, c.conductor, e.num_paquete, t.direc_tienda, d_e.num_viaje from detalle_entrega d_e, tiendas t, camiones c, paquetes e where d_e.tie_destino=t.tie_destino and t.direc_tienda='%s' and d_e.id_camion = c.id_camion and d_e.num_paquete=e.num_paquete group by d_e.id_camion, c.modelo, c.placa, c.vol_camion, c.peso_camion, c.conductor, e.num_paquete, t.direc_tienda, d_e.num_viaje;"

-----------------------------------------------------------

--consulta 5•	Datos del camion que mas viajes ha realizado a la tienda Perez Hnos. Chiapas.

select d_e.id_camion,c.modelo, c.placa, c.vol_camion, c.peso_camion, c.conductor, t.direc_tienda, COUNT(d_e.id_camion)as nViajes
from detalle_entrega d_e, tiendas t, camiones c 
where d_e.tie_destino=t.tie_destino and t.direc_tienda='%s' and d_e.id_camion = c.id_camion group by d_e.id_camion, c.modelo, c.placa, c.vol_camion, c.peso_camion, c.conductor, t.direc_tienda
having count(d_e.id_camion)=(select max(total) from(select count(d_e.id_camion)as total from detalle_entrega d_e, tiendas t  where d_e.tie_destino=t.tie_destino and t.direc_tienda='%s' group by d_e.id_camion)t1)

-----------------------------------------------------------

--consulta 6•	A que tiendas se han realizado paquetes de mas de 1300 piezas (volumen de mas de 1300) y Cuantos se han sido.

select vol_paquete from paquetes where vol_paquete>1300;
--Modificar c 
select t.tie_destino,t.direc_tienda, e.num_paquete, e.vol_paquete from tiendas t, detalle_entrega d_e, paquetes e 
where d_e.tie_destino = t.tie_destino and e.vol_paquete > 1300 and d_e.num_paquete = e.num_paquete;

-----------------------------------------------------------

--Consulta 7•	Camiones que han superado su capacidad de peso 4 veces.
select c.id_camion, c.modelo, c.peso_camion, e.num_paquete, e.peso_paquete from detalle_entrega d_e, camiones c, paquetes e 
where d_e.id_camion = c.id_camion and e.peso_paquete>(c.peso_camion*4) and d_e.num_paquete = e.num_paquete;

-----------------------------------------------------------

--Consulta 8•	Mes en el que se han hecho menos viajes.
select count (EXTRACT (MONTH from fecha_entrega)) as nViajes, EXTRACT(MONTH FROM fecha_entrega) as mes
from detalle_entrega group by EXTRACT(MONTH FROM fecha_entrega)
HAVING Count(EXTRACT(MONTH FROM fecha_entrega)) = (select MIN(nViajes) from (select count(EXTRACT(MONTH from d_e.fecha_entrega))as nViajes from detalle_entrega d_e group by EXTRACT(MONTH From d_e.fecha_entrega))t1);

-----------------------------------------------------------

--Consulta 9 •	Mes en el que se han hecho mas viajes.
select count (EXTRACT (MONTH from fecha_entrega)) as nViajes, EXTRACT(MONTH FROM fecha_entrega) as mes
from detalle_entrega group by EXTRACT(MONTH FROM fecha_entrega)
HAVING Count(EXTRACT(MONTH FROM fecha_entrega)) = (select max(nViajes) from (select count(EXTRACT(MONTH from d_e.fecha_entrega))as nViajes from detalle_entrega d_e group by EXTRACT(MONTH From d_e.fecha_entrega))t1);

-----------------------------------------------------------

--Consulta 10•	Procedimiento almacenado que realice el reporte siguiente: muestre todos los viajes que ha realizado cada camion en cierto periodo determinado y a que tiendas les ha llevado envio en cada viaje, ordenados según la cantidad de piezas que lleva(volumen). 

-----------------------------------------------------------
-- PL para obtener una consulta a partir de dos fechas

--PL para dos fechas						devolver el conjunto de registros(seleccion)
create or replace function reporte_total(date,date) returns setof "record" --setof para recoger n registros
as $$
declare
	vfecha alias for $1; --Date ingresado
	vfechafin alias for $2;
	r record;			--Recorer la seleccion
begin 
	for r in Select d_e.num_viaje, d_e.id_camion, d_e.fecha_entrega, t.direc_tienda, d_e.num_paquete, e.vol_paquete from detalle_entrega d_e, tiendas t, paquetes e
		     where d_e.fecha_entrega>=vfecha and d_e.fecha_entrega<=vfechafin and d_e.tie_destino = t.tie_destino
 			 and d_e.num_paquete = e.num_paquete order by e.vol_paquete asc
 		loop
 			return next r; --recorre la consulta hasta que no haya relacion en vfecha
 		end loop; --Fin del ciclo
 	return;
end;
$$
language plpgsql;

--Selecciona todos datos de la funcion reporte en la seleccion de la fecha y 
Select * from reporte_total('2020-03-23','2020-03-25') as (num_viaje varchar, id_camion varchar, fecha_entrega date, direc_tienda varchar, num_paquete varchar, vol_paquete numeric);



Select * from reporte_total('%s','%s') as (num_viaje varchar, id_camion varchar, fecha_entrega date, direc_tienda varchar, num_paquete varchar, vol_paquete numeric);


