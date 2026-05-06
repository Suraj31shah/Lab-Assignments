CREATE Table Sailors (
    sid INT PRIMARY KEY,
    sname VARCHAR(30),
    rating INT,
    age decimal(4, 1)
);

CREATE Table Boats (
    bid INT PRIMARY KEY,
    bname VARCHAR(30),
    color VARCHAR(15)
);

CREATE Table Reserves (
    sid INT,
    bid INT,
    day DATE,
    PRIMARY KEY (sid, bid, day),
    Foreign Key (sid) REFERENCES Sailors(sid),
    Foreign Key (bid) REFERENCES Boats(bid)
);

INSERT INTO Sailors (sid, sname, rating, age) VALUES
(1, 'Bob', 7, 25.5),
(2, 'Alice', 8, 30.0),
(3, 'John', 5, 22.0),
(4, 'David', 9, 35.0),
(5, 'Eva', 7, 19.0),
(6, 'Chris', 5, 22.0);

INSERT INTO Boats (bid, bname, color) VALUES
(101, 'Ocean Queen', 'red'),
(102, 'Sea Rider', 'blue'),
(103, 'Wave King', 'green'),
(104, 'Sun Chaser', 'red'),
(105, 'Aqua Dream', 'yellow');

INSERT INTO Reserves (sid, bid, day) VALUES
(1, 101, '2024-05-10'),
(1, 103, '2024-05-10'),
(2, 102, '2024-05-11'),
(3, 104, '2024-05-12'),
(4, 103, '2024-05-13'),
(5, 101, '2024-05-14'),
(6, 105, '2024-05-15'),
(6, 103, '2024-05-15');

SELECT * FROM Sailors;

SELECT * FROM Boats;

SELECT * FROM Reserves;

SELECT * FROM Sailors WHERE sid IN (SELECT sid FROM Reserves WHERE bid=101);

SELECT bname FROM Boats WHERE bid IN (SELECT bid FROM Reserves WHERE sid = (SELECT sid FROM Sailors WHERE sname='Bob'));

SELECT sname FROM Sailors WHERE sid IN (SELECT sid FROM Reserves WHERE bid IN (SELECT bid FROM Boats WHERE color='Red')) ORDER BY age;

SELECT sname from Sailors WHERE sid IN (SELECT DISTINCT sid FROM Reserves);

SELECT sid, sname FROM Sailors WHERE sid IN (SELECT sid from Reserves GROUP BY sid, day HAVING COUNT(DISTINCT bid) > 1);

SELECT DISTINCT sid FROM Reserves WHERE bid IN (SELECT bid FROM Boats WHERE color IN ('red', 'green'));

SELECT sname, age FROM Sailors WHERE age = (SELECT MIN(age) FROM Sailors);

SELECT COUNT(DISTINCT sname) AS total_names from Sailors;

SELECT rating, AVG(age) AS avg_age FROM Sailors GROUP BY rating;

SELECT rating, AVG(age) AS avg_age FROM Sailors GROUP BY rating HAVING COUNT(*) >= 2;

