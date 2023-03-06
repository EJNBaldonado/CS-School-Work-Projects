DROP TABLE IF EXISTS Students;

CREATE TABLE Students (SID numeric(9, 0), Name text, Grade float);
INSERT INTO Students VALUES (86050741, 'John Anderson', 3.67);
INSERT INTO Students VALUES (860309067, 'Tom Kamber', 3.12);
SELECT SID, Name, Grade FROM Students WHERE SID = 860507041;
INSERT INTO Students VALUES (86070439, 'George Haggerty', 3.67);
SELECT SID, Name, Grade FROM Students WHERE Grade = 3.67;