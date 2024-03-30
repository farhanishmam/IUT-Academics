conn user20
iutcse

--I didn't create the second scenario
--Hudai ajaira kaj barai labh nai
--Aki kaj ager table diye korsi
--Na bujhle nai

--Task 1

CREATE TABLE DEPARTMENT 
(
	Dept_Name VARCHAR2(20),
	Dept_ID INT,
	Establish_Year INT,
	CONSTRAINT dept_pk PRIMARY KEY(Dept_Name)
);

CREATE TABLE Employee
(
	E_ID INT,
	Name VARCHAR2(30),
	Salary INT,
	Hometown VARCHAR2(30),
	E_Dept VARCHAR2(20),
	CONSTRAINT emp_pk PRIMARY KEY(E_ID),
	CONSTRAINT emp_dept_fk FOREIGN KEY(E_Dept) REFERENCES DEPARTMENT
);

CREATE TABLE Student 
(
	Student_ID INT,
	Name VARCHAR2(30),
	CGPA NUMBER(3,2),
	Hometown VARCHAR2(30),
	Mobile_No VARCHAR2(14),
	S_Dept VARCHAR2(20),
	CONSTRAINT std_pk PRIMARY KEY(Student_ID),
	CONSTRAINT std_dept_fk FOREIGN KEY(S_Dept) REFERENCES DEPARTMENT
);

SELECT Student_ID, Dept_ID FROM student, department where student.s_dept = department.dept_name;

--Task 2
INSERT INTO department VALUES('EEE', 2, 1998);
INSERT INTO department VALUES('CSE', 1, 1999);

INSERT INTO student VALUES(1,'farhan',4.00,'dhaka',09099,'CSE');
INSERT INTO student VALUES(2,'dgsfarhan',4.00,'dhaka',09099,'EEE');
INSERT INTO student VALUES(4,'sdgarhan',4.00,'dhaka',09099,'EEE');
INSERT INTO student VALUES(3,'ttttfarhan',4.00,'dhaka',09099,'CSE');

--Task 3
ALTER TABLE Employee DROP COLUMN hometown;
ALTER TABLE Department ADD Building Varchar2(20);

ALTER TABLE Student DROP COLUMN student_id;
ALTER TABLE student ADD CONSTRAINT pk_student PRIMARY KEY(Name);