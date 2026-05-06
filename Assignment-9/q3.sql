DROP TABLE book_review;
DROP TABLE book;
DROP TABLE author;
CREATE TABLE AUTHOR (
    author_id INT PRIMARY KEY,
    name VARCHAR(50),
    city VARCHAR(30),
    country VARCHAR(30)
);

CREATE TABLE PUBLISHER (
    publisher_id INT PRIMARY KEY,
    name VARCHAR(50),
    city VARCHAR(30),
    country VARCHAR(30)
);

CREATE TABLE CATEGORY (
    category_id INT PRIMARY KEY,
    description VARCHAR(50)
);

CREATE TABLE CATALOG (
    book_id INT PRIMARY KEY,
    title VARCHAR(100),
    author_id INT,
    publisher_id INT,
    category_id INT,
    year INT,
    price DECIMAL(10,2),
    FOREIGN KEY (author_id) REFERENCES AUTHOR(author_id),
    FOREIGN KEY (publisher_id) REFERENCES PUBLISHER(publisher_id),
    FOREIGN KEY (category_id) REFERENCES CATEGORY(category_id)
);

CREATE TABLE ORDER_DETAILS (
    order_no INT,
    book_id INT,
    quantity INT,
    PRIMARY KEY (order_no, book_id),
    FOREIGN KEY (book_id) REFERENCES CATALOG(book_id)
);

DESC author;

DESC publisher;

DESC catalog;

DESC category;

DESC order_details;

INSERT INTO AUTHOR VALUES
(1, 'Chetan Bhagat', 'Mumbai', 'India'),
(2, 'J.K. Rowling', 'London', 'UK'),
(3, 'George R.R. Martin', 'New Jersey', 'USA'),
(4, 'Ruskin Bond', 'Dehradun', 'India'),
(5, 'Dan Brown', 'New York', 'USA');

INSERT INTO PUBLISHER VALUES
(1, 'Penguin Books', 'Delhi', 'India'),
(2, 'Bloomsbury', 'London', 'UK'),
(3, 'HarperCollins', 'New York', 'USA'),
(4, 'Rupa Publications', 'Mumbai', 'India'),
(5, 'Random House', 'Boston', 'USA');

INSERT INTO CATEGORY VALUES
(1, 'Fiction'),
(2, 'Fantasy'),
(3, 'Mystery'),
(4, 'Thriller'),
(5, 'Romance');

INSERT INTO CATALOG VALUES
(101, 'Five Point Someone', 1, 4, 1, 2004, 300),
(102, '2 States', 1, 4, 5, 2009, 350),
(103, 'Harry Potter', 2, 2, 2, 2001, 500),
(104, 'Game of Thrones', 3, 3, 2, 2005, 800),
(105, 'Angels and Demons', 5, 5, 4, 2003, 600),
(106, 'Room on the Roof', 4, 1, 1, 1956, 250),
(107, 'Half Girlfriend', 1, 4, 1, 2014, 400),
(108, 'The Da Vinci Code', 5, 5, 3, 2004, 700);

INSERT INTO ORDER_DETAILS VALUES
(1001, 101, 20),
(1002, 102, 15),
(1003, 103, 30),
(1004, 104, 25),
(1005, 105, 40),
(1006, 107, 10),
(1007, 108, 50);

SELECT * FROM author;

SELECT * FROM publisher;

SELECT * FROM catalog;

SELECT * FROM category;

SELECT * FROM order_details;

SELECT DISTINCT A.author_id, A.name, A.city, A.country FROM Author A WHERE A.author_id IN (SELECT author_id FROM Catalog WHERE price > (SELECT AVG(price) FROM Catalog) AND year > 2000 GROUP BY author_id HAVING COUNT(book_id) >= 2);

SELECT A.name, A.city, A.country FROM Author A JOIN Catalog C ON A.author_id = C.author_id JOIN (SELECT book_id FROM Order_details GROUP BY book_id HAVING SUM(quantity) = (SELECT MAX(total_sales) FROM (SELECT SUM(quantity) AS total_sales FROM Order_details GROUP BY book_id) AS t)) AS TopBooks ON c.book_id = TopBooks.book_id;

UPDATE Catalog SET price = price * 1.1 WHERE publisher_id = (SELECT publisher_id FROM Publisher WHERE name = 'Rupa Publications');
SELECT * FROM catalog;

