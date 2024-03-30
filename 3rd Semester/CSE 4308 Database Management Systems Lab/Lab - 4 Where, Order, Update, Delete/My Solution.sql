SET PAGESIZE 100;

DROP TABLE CITIZEN;

CREATE TABLE CITIZEN (
	C_ID NUMBER (3),
	C_NAME VARCHAR2 (10),
	C_HOME VARCHAR2 (10),
	AGE NUMBER (2),
	OCCUPATION VARCHAR2 (15),
	GENDER VARCHAR2 (6),
	SALARY NUMBER,
	CONSTRAINTS PK_CITIZEN PRIMARY KEY (C_ID)
);
--1

SELECT *FROM citizen;

--2

SELECT c_name, age, occupation FROM citizen;

--3

select c_name from citizen where c_home = 'Dhaka';

--4

select *from citizen where salary>45000;

--5

select c_name, c_home as hometown from citizen where age<45;

--6

select *from citizen where gender = 'Female';

--7

select *from citizen where occupation IN('Engineer','Doctor','Retired');

--8

select c_id, c_name, salary FROM citizen where occupation IN ('Musician','Businessman');

--9

select c_id, c_name FROM citizen where occupation = 'Doctor' OR occupation = 'Engineer';

--10

select *from citizen where occupation = 'Doctor' order by salary asc;

--11

select c_name, age from citizen order by age desc, c_name asc;

--12

select distinct c_home as Unique_District from citizen;

--13

select c_name, salary*1.4 as increased_salary FROM citizen where occupation != 'Retired';

--14

select *from citizen where gender = 'Male' AND salary > 50000;

--15

select *from citizen where salary between 30000 and 50000;

--16 

select *from citizen where age NOT BETWEEN 30 AND 55;

--17

create table updated_citizen as select *from citizen;
alter table updated_citizen RENAME COLUMN salary TO updated_salary;
UPDATE updated_citizen SET c_home = 'Cumilla' where c_home = 'Comilla';

--18
delete updated_citizen where rownum<=10;

--19

UPDATE updated_citizen SET age = age + 10,updated_salary = updated_salary*1.3;

--20

SELECT citizen.C_ID, citizen.salary, updated_citizen.updated_salary FROM citizen, updated_citizen WHERE citizen.c_id = updated_citizen.c_id;
