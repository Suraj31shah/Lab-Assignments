CREATE TABLE Job (
    job_id VARCHAR(15),
    job_title VARCHAR(30),
    min_sal DECIMAL(7,2),
    max_sal DECIMAL(7,2)
);

DROP Table employee;

CREATE TABLE Employee (
    emp_no DECIMAL(3),
    emp_name VARCHAR(30),
    emp_sal DECIMAL(8,2),
    emp_comm DECIMAL(6,1),
    dept_no DECIMAL(3)
);

CREATE TABLE Deposit (
    a_no VARCHAR(5),
    cname VARCHAR(15),
    bname VARCHAR(10),
    amount DECIMAL(7,2),
    a_date DATE
);

CREATE TABLE Borrow (
    loanno VARCHAR(5),
    cname VARCHAR(15),
    bname VARCHAR(10),
    amount DECIMAL(7,2)
);

INSERT INTO Job VALUES ('J01', 'Manager', 5000, 12000);
INSERT INTO Job VALUES ('J02', 'Clerk', 2000, 5000);
INSERT INTO Job VALUES ('J03', 'Analyst', 4000, 10000);
INSERT INTO Job VALUES ('J04', 'Salesman', 3000, 8000);
INSERT INTO Job VALUES ('J05', 'HR', 3500, 7000);

INSERT INTO Employee VALUES (101, 'Anita', 6000, 500, 10);
INSERT INTO Employee VALUES (102, 'Anish', 5500, NULL, 20);
INSERT INTO Employee VALUES (103, 'Ankit', 5200, 300, 20);
INSERT INTO Employee VALUES (104, 'Sunil', 7000, 800, 30);
INSERT INTO Employee VALUES (105, 'Manoj', 6500, NULL, 30);

INSERT INTO Deposit VALUES
('A01', 'Anil', 'Surat', 2500.00, '2006-01-10'),
('A02', 'Sunil', 'Mumbai', 4000.00, '2006-06-15'),
('A03', 'Pramod', 'Delhi', 3000.00, '2006-07-30'),
('A04', 'Ravi', 'Surat', 2000.00, '2006-02-20'),
('A05', 'Amit', 'Delhi', 4500.00, '2006-12-25');

INSERT INTO Borrow VALUES ('L01', 'Anil', 'Surat', 1500);
INSERT INTO Borrow VALUES ('L02', 'Sunil', 'Mumbai', 3000);
INSERT INTO Borrow VALUES ('L03', 'Pramod', 'Delhi', 2500);
INSERT INTO Borrow VALUES ('L04', 'Ravi', 'Surat', 3500);
INSERT INTO Borrow VALUES ('L05', 'Amit', 'Delhi', 4000);

SELECT * FROM job;
SELECT * FROM employee;
SELECT * FROM deposit;
SELECT * FROM borrow;

SELECT a_no, amount FROM deposit WHERE a_date BETWEEN '2006-01-01' AND '2006-07-25';

SELECT emp_name AS "Employee Name", emp_sal FROM Employee WHERE dept_no = 20;

SELECT emp_name, emp_no, emp_sal FROM Employee WHERE emp_name LIKE 'Ani__';

SELECT * FROM Employee WHERE emp_name LIKE '_n___';

SELECT emp_no, emp_name, emp_sal, ROUND(emp_sal * 1.15) AS "New Salary" FROM Employee;

SELECT emp_no, emp_name, emp_sal, ROUND(emp_sal * 1.15) AS "New Salary", ROUND(emp_sal * 0.15) AS "Increase" FROM Employee;

SELECT CONCAT(UCASE(LEFT(emp_name, 1)), LCASE(SUBSTRING(emp_name, 2))) AS "Proper Name", LENGTH(emp_name) AS "Name Length" FROM Employee WHERE UPPER(SUBSTR(emp_name, 1, 1)) IN ('J', 'A', 'M') ORDER BY emp_name;

DROP TABLE nutrition_data;
DROP TABLE sales_history;
DROP TABLE product;
DROP Table department;

CREATE TABLE Department (
    dept_no INT(3) PRIMARY KEY,
    dept_name VARCHAR(30),
    location VARCHAR(30)
);

INSERT INTO Department VALUES 
(10, 'HR', 'NEW YORK'),
(20, 'ACCOUNTING', 'CHICAGO'),
(30, 'SALES', 'NEW YORK'),
(40, 'RESEARCH', 'DALLAS'),
(50, 'MARKETING', 'MUMBAI');

SELECT * FROM department;

ALTER TABLE Employee
ADD job_id VARCHAR(15),
ADD manager_id INT(3);

UPDATE Employee SET job_id = 'J01', manager_id = NULL WHERE emp_no = 104;  -- Sunil = Manager
UPDATE Employee SET job_id = 'J02', manager_id = 104 WHERE emp_no = 101;   -- Anita reports to Sunil
UPDATE Employee SET job_id = 'J03', manager_id = 104 WHERE emp_no = 102;   -- Anish reports to Sunil
UPDATE Employee SET job_id = 'J04', manager_id = 104 WHERE emp_no = 103;   -- Ankit reports to Sunil
UPDATE Employee SET job_id = 'J05', manager_id = 104 WHERE emp_no = 105;   -- Manoj reports to Sunil

SELECT DISTINCT j.job_title, d.location FROM Employee e JOIN Job j ON e.job_id = j.job_id JOIN department d ON e.dept_no = d.dept_no WHERE e.dept_no = 30;

SELECT e.emp_name, e.dept_no, d.dept_name FROM Employee e JOIN department d ON e.dept_no = d.dept_no WHERE d.location = 'New York';

SELECT e.emp_name AS Employee, e.emp_no AS "Emp#", m.emp_name AS Manager, m.emp_no AS "Mgr#" FROM Employee e JOIN Employee m ON e.manager_id = m.emp_no;

SELECT MAX(emp_sal) - MIN(emp_sal) AS DIFFERENCE FROM Employee;

ALTER TABLE Employee ADD hire_date DATE;
UPDATE Employee SET hire_date = '1995-05-20' WHERE emp_no = 101;
UPDATE Employee SET hire_date = '1996-07-15' WHERE emp_no = 102;
UPDATE Employee SET hire_date = '1997-09-10' WHERE emp_no = 103;
UPDATE Employee SET hire_date = '1998-01-05' WHERE emp_no = 104;
UPDATE Employee SET hire_date = '1998-12-22' WHERE emp_no = 105;

SELECT COUNT(*) AS Total_Employees, SUM(YEAR(hire_date) = 1995) AS Hired_1995, SUM(YEAR(hire_date) = 1996) AS Hired_1996, SUM(YEAR(hire_date) = 1997) AS Hired_1997, SUM(YEAR(hire_date) = 1998) AS Hired_1998 FROM Employee;

SELECT AVG(emp_sal) FROM Employee GROUP BY dept_no;

SELECT d.dept_no, j.job_title, SUM(e.emp_sal) AS Total_Salary FROM Employee e JOIN Job j ON e.job_id = j.job_id JOIN department d ON e.dept_no = d.dept_no GROUP BY d.dept_no, j.job_title ORDER BY d.dept_name, j.job_title;

SELECT AVG(emp_sal) FROM Employee WHERE emp_sal > 2000 GROUP BY dept_no; 

SELECT a_no AS id, cname, bname, amount, a_date AS transaction_date, 'Deposit' AS type FROM deposit WHERE bname = (SELECT bname FROM deposit WHERE cname = 'Pramod') UNION SELECT loanno AS id, cname, bname, amount, NULL AS transaction_date, 'Loan' AS type FROM borrow WHERE bname = (SELECT bname FROM deposit WHERE cname = 'Pramod'); 

SELECT emp_no, emp_name FROM Employee WHERE emp_sal > (SELECT AVG(emp_sal) FROM Employee) ORDER BY emp_sal;

SELECT cname FROM deposit WHERE bname = (SELECT bname FROM deposit WHERE cname = 'Anil') AND amount > 2000;

SELECT emp_name, emp_sal FROM Employee WHERE manager_id = (SELECT emp_no FROM Employee WHERE emp_name = 'Ford');

SELECT e.dept_no, e.emp_name, (SELECT j.job_title FROM Job j WHERE j.job_id = e.job_id) AS job_title FROM Employee e WHERE dept_no = (SELECT dept_no FROM department WHERE dept_name = 'ACCOUNTING');

SELECT bname FROM deposit GROUP BY bname HAVING COUNT(cname) = (SELECT MAX(depositor_count) FROM (SELECT bname, COUNT(cname) AS depositor_count FROM deposit GROUP BY bname) AS sub);

SELECT * FROM job;
SELECT * FROM employee;
SELECT * FROM deposit;
SELECT * FROM borrow;