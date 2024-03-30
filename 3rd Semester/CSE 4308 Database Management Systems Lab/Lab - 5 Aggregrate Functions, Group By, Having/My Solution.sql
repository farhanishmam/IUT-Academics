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
select max(salary) AS maximum_salary FROM citizen;

--2
	--Without aggregate function
	--This will not show accurate results if they ask you to show all the oldest male 
select c_name,age FROM 
(select c_name, age FROM citizen WHERE gender = 'Male' ORDER BY AGE DESC) WHERE ROWNUM = 1;

	--With aggregate function
select c_name, age FROM citizen where gender = 'Male' AND AGE = 
(select max(age) FROM citizen WHERE gender = 'Male');

--3

select c_name, age FROM citizen where gender = 'Female' AND age = 
(select min(age) FROM citizen WHERE gender = 'Female');

--4
	--In this case if aggregate functions weren't used then it won't show complete query output
select c_name, salary from citizen where occupation = 'Teacher' AND salary = 
(select max(salary) from citizen where occupation = 'Teacher');

--5

select c_name, salary from citizen where occupation = 'Doctor' AND salary = 
(select max(salary) from citizen where occupation = 'Doctor');

--6
select c_name from citizen where c_name LIKE '%a%';

--7
select c_name from citizen where c_name LIKE '__y%';

--8
select avg(age) from citizen;

--9
select sum(salary) from citizen GROUP BY occupation HAVING occupation = 'Teacher';

--or
select sum(salary) from citizen where occupation = 'Teacher';

--10
select avg(salary) from citizen where occupation = 'Student';

--11
select c_name from citizen where gender = 'Female' AND salary = 
(select max(salary) from citizen where gender = 'Female');

--12
select count(distinct c_home) from citizen group by c_home having c_home like '%tg%';

--or

select count(c_home) from (select c_home from citizen group by c_home having c_home like '%tg%'); 

--13
select max(salary) from citizen where c_name LIKE 'A%';

--14
select *from citizen where occupation = 'Teacher' and salary = 
(select max(salary) from citizen where occupation = 'Teacher');

--15
select avg(age) from citizen where occupation = 'Student';

--16
select c_home, count(*) FROM citizen GROUP BY c_home; 

--17
select occupation, max(salary) from citizen GROUP BY occupation;

--18 
select occupation, avg(salary) from citizen WHERE gender = 'Male' group by occupation;

--19
select occupation, avg(salary) from citizen WHERE gender = 'Female' group by occupation having avg(salary)>=10000;

--20
select count(*) from citizen WHERE salary NOT BETWEEN 40000 AND 50000;

--21
SELECT count(*) AS remaining_citizens FROM (select *from citizen where salary>20000 AND salary<50000) where c_home = 'Ctg';

--22
SELECT c_home, avg(salary) FROM citizen WHERE salary>=55000 GROUP BY c_home HAVING count(*)>=2;