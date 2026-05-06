use dms_assignment

-- Table: Department
CREATE TABLE Department (
    id INT PRIMARY KEY,
    name VARCHAR(100)
);

-- Table: Producer
CREATE TABLE Producer (
    id INT PRIMARY KEY,
    name VARCHAR(100)
);

-- Table: Product
CREATE TABLE Product (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    department_id INT,
    shelf_id INT,
    producer_id INT,
    price DECIMAL(10,2),
    FOREIGN KEY (department_id) REFERENCES Department(id),
    FOREIGN KEY (producer_id) REFERENCES Producer(id)
);

-- Table: Nutrition_data
CREATE TABLE Nutrition_data (
    product_id INT PRIMARY KEY,
    calories INT,
    fat DECIMAL(5,2),
    carbohydrate DECIMAL(5,2),
    protein DECIMAL(5,2),
    FOREIGN KEY (product_id) REFERENCES Product(id)
);

-- Table: Sales_history
CREATE TABLE Sales_history (
    date DATE,
    product_id INT,
    amount INT,
    FOREIGN KEY (product_id) REFERENCES Product(id)
);

-- Department
INSERT INTO Department VALUES
(1, 'Beverages'),
(2, 'Snacks'),
(3, 'Dairy'),
(4, 'Bakery');

-- Producer
INSERT INTO Producer VALUES
(1, 'Nestle'),
(2, 'PepsiCo'),
(3, 'Amul'),
(4, 'Britannia');

-- Product
INSERT INTO Product VALUES
(1, 'Coke', 1, 101, 2, 35.00),
(2, 'Lays Chips', 2, 102, 2, 20.00),
(3, 'Milk', 3, 103, 3, 25.00),
(4, 'Chocolate Bar', 2, 104, 1, 45.00),
(5, 'Bread', 4, 105, 4, 30.00),
(6, 'Energy Drink', NULL, 106, NULL, 60.00);

-- Nutrition Data
INSERT INTO Nutrition_data VALUES
(1, 140, 0.00, 39.00, 0.00),
(2, 160, 10.00, 15.00, 2.00),
(3, 120, 5.00, 12.00, 8.00),
(4, 220, 12.00, 25.00, 3.00),
(5, 100, 1.00, 20.00, 4.00),
(6, 80, 0.00, 18.00, 1.00);

-- Sales History
INSERT INTO Sales_history VALUES
('2024-12-01', 1, 500),
('2024-12-02', 2, 700),
('2024-12-03', 3, 200),
('2024-12-04', 4, 150),
('2024-12-05', 5, 300);

SELECT p.name AS product, d.name as department FROM Product p JOIN Nutrition_data n ON p.id=n.product_id JOIN Department d ON p.department_id = d.id WHERE n.calories < 150;

SELECT p.name AS product_name, p.price AS producer_price, pr.name as producer_name, d.name as department_name FROM Product p LEFT JOIN Producer pr ON p.producer_id = pr.id LEFT JOIN Department d ON p.department_id = d.id UNION SELECT p.name AS product_name, p.price AS producer_price, pr.name as producer_name, d.name as department_name FROM Product p RIGHT JOIN Producer pr ON p.producer_id = pr.id RIGHT JOIN Department d ON p.department_id = d.id

SELECT pr.name AS product_name, d.name AS department_name, p.name AS product_name, n.carbohydrate FROM Product p LEFT JOIN Producer pr ON p.producer_id = pr.id LEFT JOIN Department d ON p.department_id = d.id LEFT JOIN Nutrition_data n ON p.id = n.product_id;