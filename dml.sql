drop database marta;
create schema marta;
use marta;

create table routes(
	route_id int not null unique,
	route_name varchar(50) not null,
	primary key(route_id)
);

create table stops(
	stop_id int not null unique,
	stop_name varchar(50) not null,
	primary key(stop_id)
);

create table vehicles(
	vehicle_id int not null unique,
	primary key(vehicle_id)
);
create table passenger_data(
	pindex int not null unique auto_increment,
	pdate date not null,
	route_id int not null,
	direction varchar(50) not null,
	stop_id int not null,
	on_number int not null default 0,
	off_number int not null default 0,
	vehicle_id int not null,
	primary key(pindex),
	foreign key(route_id) references routes(route_id),
	foreign key(stop_id) references stops(stop_id),
	foreign key(vehicle_id) references vehicles(vehicle_id)
);
