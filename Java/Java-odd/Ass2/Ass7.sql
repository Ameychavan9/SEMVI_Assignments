drop table workLoad;
drop table Teacher;

create table Teacher(Teacher_id integer primary key,Teacher_name varchar(20));
create table workLoad(sub_code integer primary key,subject varchar(20),da date,time Time,class varchar(10),T_id integer references Teacher(Teacher_id ) on delete cascade);

insert into Teacher values(101,'Pramod Sir');
insert into Teacher values(102,'Patil Sir');
insert into Teacher values(103,'Lucky Sir');
insert into Teacher values(104,'Rashmi Maam');
insert into Teacher values(105,'Sujata Maam');


insert into workLoad values(1,'C++','2022-03-10','09:00:00','FY',101);
insert into workLoad values(2,'OS','2022-03-10','09:50:00','TY',105);
insert into workLoad values(3,'DBMS','2022-03-10','09:00:00','FY',103);
insert into workLoad values(4,'Java','2022-03-10','09:00:00','TY',104);
insert into workLoad values(5,'Python','2022-03-10','09:00:00','FY',101);
