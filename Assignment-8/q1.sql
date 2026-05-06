use dms_assignment

CREATE TABLE Author (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    birth_year INT,
    death_year INT
);

DROP Table Book;

CREATE TABLE Book (
    id INT PRIMARY KEY,
    author_id INT,
    title VARCHAR(200),
    publish_year INT,
    publishing_house VARCHAR(100),
    Foreign Key (author_id) REFERENCES Author(id)
);

CREATE TABLE Adaptation (
    book_id INT,
    type VARCHAR(50),
    title VARCHAR(200),
    release_year INT,
    rating DECIMAL(3, 1),
    Foreign Key (book_id) REFERENCES Book(id)
);

CREATE TABLE Book_review (
    book_id INT,
    review TEXT,
    author VARCHAR(100),
    Foreign Key (book_id) REFERENCES Book(id)
);

-- Authors
INSERT INTO Author VALUES
(1, 'J.K. Rowling', 1965, NULL),
(2, 'George Orwell', 1903, 1950),
(3, 'Haruki Murakami', 1949, NULL),
(4, 'New Author', 1980, NULL);

-- Books
INSERT INTO Book VALUES
(1, 1, 'Harry Potter and the Goblet of Fire', 2000, 'Bloomsbury'),
(2, 1, 'Harry Potter and the Deathly Hallows', 2007, 'Bloomsbury'),
(3, 2, '1984', 1949, 'Secker & Warburg'),
(4, 3, 'Kafka on the Shore', 2002, 'Shinchosha'),
(5, NULL, 'Anonymous Tales', 2020, 'IndiePress');

-- Adaptations
INSERT INTO Adaptation VALUES
(1, 'Movie', 'Harry Potter and the Goblet of Fire (Film)', 2005, 7.7),
(2, 'Movie', 'Harry Potter and the Deathly Hallows: Part 1', 2010, 8.1),
(3, 'Movie', '1984 (Film)', 1984, 7.2);

-- Book Reviews
INSERT INTO Book_review VALUES
(1, 'A magical continuation of the series.', 'John Smith'),
(3, 'A chilling dystopian masterpiece.', 'Alice Brown'),
(4, 'Surreal and deep.', 'Tom Hanks');

SELECT a.name AS author_name, b.title AS book_title, b.publish_year FROM Author a JOIN Book b ON a.id = b.author_id

SELECT a.name AS author_name, b.title AS book_title, b.publish_year FROM Author a JOIN Book b ON a.id = b.author_id WHERE b.publish_year > 2005

SELECT b.title AS book_title, ad.title AS adaptation_title, ad.release_year AS adaptation_year, b.publish_year FROM Book b JOIN Adaptation ad ON b.id = ad.book_id

SELECT b.title AS book_title, ad.title AS adaptation_title, ad.release_year FROM Book b LEFT JOIN Adaptation ad ON b.id = ad.book_id;

SELECT b.title AS book_title, b.publishing_house, ad.title AS adaptation_title, ad.type AS adaptation_type FROM Book b LEFT JOIN Adaptation ad ON b.id = ad.book_id;

SELECT b.title AS book_title, br.review, br.author AS review_author FROM Book_review br RIGHT JOIN Book b ON br.book_id = b.id;

SELECT b.title AS book_title, a.name AS author_name FROM Book b LEFT JOIN Author a ON b.author_id = a.id UNION SELECT b.title AS book_title, a.name AS author_name FROM Book b LEFT JOIN Author a ON b.author_id = a.id;