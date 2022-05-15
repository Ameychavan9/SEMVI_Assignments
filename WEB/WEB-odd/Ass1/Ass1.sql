drop table ma;
drop table actor;
drop table movie;

create table movie (movie_no int primary key,movie_name text not NULL,release_year int);
create table actor(actor_no int primary key ,actor_name text not NULL);
create table ma (movie_no int references movie(movie_no)on delete cascade,
actor_no int references actor(actor_no)on delete cascade);

INSERT into movie Values(1,'MOONFALL',2022);
INSERT into movie Values(2,'AVENGERS',2020);
INSERT into movie Values(3,'HARRY POTTER',2000);
INSERT into movie Values(4,'TENET',2021);
INSERT into movie Values(5,'FIFTY SHADES',2016);


INSERT into actor Values(101,'JOHN BRADLEY');
INSERT into actor Values(202,'RDJ');
INSERT into actor Values(303,'EMMA WATSON');
INSERT into actor Values(404,'ROBOT PATTINSON');
INSERT into actor Values(505,'DAKOTA JOHNSON');

INSERT into ma values(1,101);
INSERT into ma values(2,202);
INSERT into ma values(3,303);
INSERT into ma values(4,404);
INSERT into ma values(5,505);






--  create table student (no int primary key,SName text not NULL,Per float,dob date,Email text not NULL);



























