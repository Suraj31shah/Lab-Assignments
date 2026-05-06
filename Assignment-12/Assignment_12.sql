-- CREATE TABLE employee (
--     emp_id        NUMBER,
--     first_name    VARCHAR2(50),
--     last_name     VARCHAR2(50),
--     job_id        VARCHAR2(20),
--     salary        NUMBER,
--     dept_id       NUMBER
-- );
-- INSERT INTO employee VALUES (101, 'John',  'Doe',      'IT_PROG', 60000, 10);
-- INSERT INTO employee VALUES (102, 'Alice', 'Smith',    'HR',      45000, 20);
-- INSERT INTO employee VALUES (103, 'Bob',   'Johnson',  'SA_REP',  52000, 30);
-- INSERT INTO employee VALUES (104, 'Riya',  'Sharma',   'IT_PROG', 70000, 10);
-- INSERT INTO employee VALUES (105, 'Aman',  'Patel',    'FIN',     48000, 40);
-- select * from employee;

-- SET SERVEROUTPUT ON;

-- DECLARE
--     CURSOR emp_cur IS
--         SELECT emp_id, first_name, last_name, job_id, salary, dept_id
--         FROM employee;

--     v_emp_id   employee.emp_id%TYPE;
--     v_fname    employee.first_name%TYPE;
--     v_lname    employee.last_name%TYPE;
--     v_job      employee.job_id%TYPE;
--     v_salary   employee.salary%TYPE;
--     v_dept     employee.dept_id%TYPE;
-- BEGIN
--     OPEN emp_cur;

--     LOOP
--         FETCH emp_cur INTO v_emp_id, v_fname, v_lname, v_job, v_salary, v_dept;
--         EXIT WHEN emp_cur%NOTFOUND;

--         DBMS_OUTPUT.PUT_LINE(
--             'ID: ' || v_emp_id ||
--             ', Name: ' || v_fname || ' ' || v_lname ||
--             ', Job: ' || v_job ||
--             ', Salary: ' || v_salary ||
--             ', Dept: ' || v_dept
--         );
--     END LOOP;

--     CLOSE emp_cur;
-- END;
-- /

-- SET SERVEROUTPUT ON;

-- DECLARE
--     CURSOR c_emp IS
--         SELECT * FROM employee;   -- ✔ Now it matches ROWTYPE

--     v_emp employee%ROWTYPE;
-- BEGIN
--     OPEN c_emp;

--     LOOP
--         FETCH c_emp INTO v_emp;
--         EXIT WHEN c_emp%NOTFOUND;

--         DBMS_OUTPUT.PUT_LINE(
--             v_emp.emp_id || ' - ' ||
--             v_emp.first_name || ' ' || v_emp.last_name ||
--             ' - Job: ' || v_emp.job_id ||
--             ' - Salary: ' || v_emp.salary ||
--             ' - Dept: ' || v_emp.dept_id
--         );
--     END LOOP;

--     CLOSE c_emp;
-- END;
-- /

-- SET SERVEROUTPUT ON;

-- BEGIN
--     FOR r IN (SELECT emp_id, first_name, last_name, salary FROM employee)
--     LOOP
--         DBMS_OUTPUT.PUT_LINE(
--             r.emp_id || ' - ' || r.first_name || ' ' ||
--             r.last_name || ' - Salary: ' || r.salary
--         );
--     END LOOP;
-- END;
-- /

-- SET SERVEROUTPUT ON;

-- DECLARE
--     CURSOR emp_cursor IS
--         SELECT emp_id, first_name, last_name, job_id
--         FROM employee;
-- BEGIN
--     FOR rec IN emp_cursor LOOP
--         DBMS_OUTPUT.PUT_LINE(
--             rec.emp_id || ' - ' || rec.first_name || ' ' ||
--             rec.last_name || ' - Job: ' || rec.job_id
--         );
--     END LOOP;
-- END;
-- /

-- CREATE TABLE books (
--     book_id        NUMBER PRIMARY KEY,
--     title          VARCHAR2(100),
--     qty_available  NUMBER
-- );

-- CREATE TABLE order_details (
--     order_id      NUMBER,
--     book_id       NUMBER REFERENCES books(book_id),
--     qty_ordered   NUMBER,
--     CONSTRAINT pk_order PRIMARY KEY (order_id, book_id)
-- );

-- INSERT INTO books VALUES (101, 'SQL Fundamentals', 50);
INSERT INTO books VALUES (102, 'PL/SQL Programming', 30);
-- INSERT INTO books VALUES (103, 'Database Systems', 40);