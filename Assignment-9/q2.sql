CREATE TABLE BRANCH (
    branch_name VARCHAR(30) PRIMARY KEY,
    branch_city VARCHAR(30),
    assets DECIMAL(15,2)
);

CREATE TABLE ACCOUNT (
    accno INT PRIMARY KEY,
    branch_name VARCHAR(30),
    balance DECIMAL(15,2),
    FOREIGN KEY (branch_name) REFERENCES BRANCH(branch_name)
);

CREATE TABLE DEPOSITOR (
    customer_name VARCHAR(30),
    accno INT,
    FOREIGN KEY (accno) REFERENCES ACCOUNT(accno)
);

CREATE TABLE CUSTOMER (
    customer_name VARCHAR(30) PRIMARY KEY,
    customer_street VARCHAR(50),
    customer_city VARCHAR(30)
);

CREATE TABLE LOAN (
    loan_number INT PRIMARY KEY,
    branch_name VARCHAR(30),
    amount DECIMAL(15,2),
    FOREIGN KEY (branch_name) REFERENCES BRANCH(branch_name)
);

CREATE TABLE BORROWER (
    customer_name VARCHAR(30),
    loan_number INT,
    FOREIGN KEY (customer_name) REFERENCES CUSTOMER(customer_name),
    FOREIGN KEY (loan_number) REFERENCES LOAN(loan_number)
);

INSERT INTO BRANCH VALUES
('Main', 'Mumbai', 1000000.00),
('Town', 'Mumbai', 750000.00),
('Park', 'Delhi', 600000.00),
('Central', 'Pune', 500000.00),
('South', 'Chennai', 550000.00);

INSERT INTO ACCOUNT VALUES
(101, 'Main', 50000.00),
(102, 'Main', 30000.00),
(103, 'Town', 25000.00),
(104, 'Park', 45000.00),
(105, 'Central', 60000.00),
(106, 'South', 20000.00),
(107, 'Main', 70000.00),
(108, 'Town', 15000.00);

INSERT INTO CUSTOMER VALUES
('Rahul', 'MG Road', 'Mumbai'),
('Sneha', 'Hill Street', 'Delhi'),
('Amit', 'Park Lane', 'Pune'),
('Priya', 'Marine Drive', 'Mumbai'),
('Ravi', 'Anna Nagar', 'Chennai'),
('Neha', 'Bandra', 'Mumbai');

INSERT INTO DEPOSITOR VALUES
('Rahul', 101),
('Rahul', 102),
('Priya', 103),
('Amit', 104),
('Ravi', 105),
('Neha', 107),
('Sneha', 106),
('Priya', 108);

INSERT INTO LOAN VALUES
(201, 'Main', 100000.00),
(202, 'Town', 50000.00),
(203, 'Park', 120000.00),
(204, 'Central', 80000.00),
(205, 'South', 60000.00);

INSERT INTO BORROWER VALUES
('Rahul', 201),
('Amit', 203),
('Priya', 202),
('Ravi', 205),
('Neha', 204);

SELECT * FROM branch;

SELECT * FROM account;

SELECT * FROM depositor;

SELECT * FROM customer;

SELECT * FROM loan;

SELECT * FROM borrower;

SELECT customer_name FROM Depositor WHERE accno IN (SELECT accno FROM Account WHERE branch_name = 'Main') GROUP BY customer_name HAVING COUNT(accno) >= 2;

SELECT D.customer_name FROM Depositor D WHERE NOT EXISTS (SELECT B.branch_name FROM Branch B WHERE B.branch_city = 'Mumbai' AND B.branch_name NOT IN (SELECT A.branch_name FROM Account A where A.accno IN (SELECT D2.accno FROM Depositor D2 WHERE D2.customer_name = D.customer_name)));

DELETE FROM Depositor WHERE accno IN (SELECT accno FROM Account WHERE branch_name IN (SELECT branch_name FROM Branch WHERE branch_city = 'Mumbai'));
DELETE FROM Account WHERE branch_name IN (SELECT branch_name FROM Branch WHERE branch_city = 'Mumbai');

SELECT * FROM account;