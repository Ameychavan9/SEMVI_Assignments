drop table std_comp;
DROP TABLE competition;
DROP TABLE student;

CREATE TABLE student(std_id INTEGER PRIMARY KEY, name VARCHAR(50), class VARCHAR(2));

CREATE TABLE competition(c_no INTEGER PRIMARY KEY, c_name VARCHAR(20), c_type VARCHAR(10));


CREATE TABLE std_comp(std_id INTEGER REFERENCES student(std_id), c_no INTEGER REFERENCES competition(c_no), rank_no INTEGER NOT NULL, year INTEGER NOT NULL);

INSERT INTO student VALUES(1, 'Ankit Chavhan', 'FY');
INSERT INTO student VALUES(2, 'Shreekant Kohli', 'SY');
INSERT INTO student VALUES(3, 'Mangesh Rane', 'TY');
select * from student;


INSERT INTO competition values(101, 'Cricket', 'Outdoor');
INSERT INTO competition values(102, 'Chess', 'Indoor');
INSERT INTO competition values(103, 'Hockey', 'Outdoor');
select * from competition;


insert into std_comp values(1,101,3,1999);
insert into std_comp values(2,101,2,1989);
insert into std_comp values(3,103,4,1989);
insert into std_comp values(1,102,1,1993);
insert into std_comp values(1,102,5,1991);

select * from std_comp;
select * from student;



