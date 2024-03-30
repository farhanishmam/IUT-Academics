--Task-A

--1
CREATE TABLE address 
(
    address_id INTEGER,
    district VARCHAR2(20),  
    division VARCHAR2(20),
    CONSTRAINT address_pk PRIMARY KEY(address_id)
);

CREATE TABLE customer
(
    cust_id INTEGER,
    name VARCHAR2(20),
    dob DATE,
    address_id INTEGER,
    CONSTRAINT cust_pk PRIMARY KEY(cust_id),
    CONSTRAINT cust_address_fk FOREIGN KEY (address_id) REFERENCES address
);

CREATE TABLE subs_info
(
    cust_id INTEGER,
    subs_level VARCHAR2(10),
    lifetime_usage INTEGER,
    CONSTRAINT subs_pk PRIMARY KEY (cust_id),
    CONSTRAINT subs_cust_fk FOREIGN KEY(cust_id) REFERENCES customer
);

--2
INSERT INTO address VALUES (1,'gazipur', 'dhaka');
INSERT INTO address VALUES (2,'dhaka', 'dhaka');
INSERT INTO address VALUES (3,'tangail', 'dhaka');
INSERT INTO address VALUES (4,'rangamati', 'chittagong');
INSERT INTO address VALUES (5,'bogura', 'rajshahi');

INSERT INTO customer VALUES(1,'farhan','22-Jan-01',2);
INSERT INTO customer VALUES(2,'ishmam','2-Dec-99',3);
INSERT INTO customer VALUES(3,'rahman','12-Jun-02',4);
INSERT INTO customer VALUES(4,'faisal','21-Jul-01',1);
INSERT INTO customer VALUES(5,'sharzil','20-Mar-02',5);
INSERT INTO customer VALUES(6,'hasan','9-Sep-04',1);
INSERT INTO customer VALUES(7,'atiq','4-Nov-05',2);
INSERT INTO customer VALUES(8,'tasnim','12-Oct-05',2);
INSERT INTO customer VALUES(9,'ferdous','23-Feb-99',4);
INSERT INTO customer VALUES(10,'mushfiq','28-Dec-91',3);

INSERT INTO subs_info VALUES(1,'gold',550);
INSERT INTO subs_info VALUES(2,'platinum',1420);
INSERT INTO subs_info VALUES(3,'bronze',100);
INSERT INTO subs_info VALUES(4,'platinum',1000);
INSERT INTO subs_info VALUES(5,'silver',345);
INSERT INTO subs_info VALUES(6,'gold',560);
INSERT INTO subs_info VALUES(7,'platinum',1120);
INSERT INTO subs_info VALUES(8,'bronze',70);
INSERT INTO subs_info VALUES(9,'gold',600);
INSERT INTO subs_info VALUES(10,'silver',450);

--3
SELECT name, dob, district, division FROM customer, address, subs_info WHERE 
(
    address.address_id = customer.address_id AND 
    subs_info.cust_id = customer.cust_id AND
    subs_info.subs_level = 'platinum' AND
    subs_info.lifetime_usage>(SELECT 2*max(lifetime_usage) FROM subs_info WHERE subs_level = 'silver')
);

SELECT name, customer.cust_id, lifetime_usage FROM customer,
(
    SELECT *FROM
    (
        SELECT cust_id, lifetime_usage, RANK() OVER (ORDER BY lifetime_usage DESC) cust_rank FROM subs_info
    ) WHERE cust_rank<=5
) top_subs
WHERE customer.cust_id = top_subs.cust_id;

UPDATE subs_info SET subs_level = 'elite' WHERE cust_id IN
(
    SELECT cust_id FROM
    (
        SELECT cust_id, lifetime_usage, RANK() OVER (ORDER BY lifetime_usage DESC) cust_rank FROM subs_info
    ) WHERE cust_rank<=5
);

------- TASK B -------




-- SCHEMA --


CREATE TABLE employee(
e_id INTEGER,
dept_id INTEGER,
CONSTRAINT employee_pk PRIMARY KEY (e_id)
);

CREATE TABLE salary(
e_id INTEGER,
amount INTEGER,
pay_date DATE,
CONSTRAINT salary_employee_Fk FOREIGN KEY (e_id) REFERENCES employee(e_id)
);

INSERT INTO employee VALUES (1, 1);
INSERT INTO employee VALUES (2, 2);
INSERT INTO employee VALUES (3, 2);

INSERT INTO salary VALUES (1, 9000, TO_DATE('2017-03-31', 'YYYY-mm-DD'));
INSERT INTO salary VALUES (2, 6000, TO_DATE('2017-03-31', 'YYYY-mm-DD'));
INSERT INTO salary VALUES (3, 10000, TO_DATE('2017-03-31', 'YYYY-mm-DD'));
INSERT INTO salary VALUES (1, 7000, TO_DATE('2017-02-28', 'YYYY-mm-DD'));
INSERT INTO salary VALUES (2, 6000, TO_DATE('2017-02-28', 'YYYY-mm-DD'));
INSERT INTO salary VALUES (3, 8000, TO_DATE('2017-02-28', 'YYYY-mm-DD'));


-- QUERIES --


SELECT pay_month, dept_id, 
CASE
    WHEN dept_avg > comp_avg THEN 'higher'
    WHEN dept_avg < comp_avg THEN 'lower'
    ELSE 'same'
END AS comparison
FROM 
(
        SELECT  TO_CHAR(salary.pay_date, 'YYYY-MM') pay_month, employee.dept_id, avg(salary.amount) dept_avg, d.comp_avg
        FROM employee INNER JOIN salary ON (employee.e_id = salary.e_id) 
        INNER JOIN 
        (
            SELECT TO_CHAR(salary.pay_date, 'YYYY-MM') pay_month, avg(amount) comp_avg 
            FROM salary GROUP BY pay_date
        ) d ON (TO_CHAR(pay_date, 'YYYY-MM') = d.pay_month)
        GROUP BY pay_date, dept_id, d.comp_avg
);
