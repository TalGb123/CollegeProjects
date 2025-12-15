-- Drop tables first if they exist
DROP TABLE Printer CASCADE CONSTRAINTS;
DROP TABLE Laptop CASCADE CONSTRAINTS;
DROP TABLE Pc CASCADE CONSTRAINTS;
DROP TABLE Products CASCADE CONSTRAINTS;

-- Create Products table
CREATE TABLE Products (
    maker CHAR(1),
    model NUMBER PRIMARY KEY,
    type VARCHAR2(20)
);

-- Create Pc table
CREATE TABLE Pc (
    model NUMBER PRIMARY KEY,
    speed NUMBER,
    ram NUMBER,
    hd NUMBER,
    price NUMBER,
    FOREIGN KEY (model) REFERENCES Products(model)
);

-- Create Laptop table
CREATE TABLE Laptop (
    model NUMBER PRIMARY KEY,
    speed NUMBER,
    ram NUMBER,
    hd NUMBER,
    screen NUMBER(4,1),
    price NUMBER,
    FOREIGN KEY (model) REFERENCES Products(model)
);

-- Create Printer table
CREATE TABLE Printer (
    model NUMBER PRIMARY KEY,
    color CHAR(5),
    type VARCHAR2(20),
    price NUMBER,
    FOREIGN KEY (model) REFERENCES Products(model)
);
