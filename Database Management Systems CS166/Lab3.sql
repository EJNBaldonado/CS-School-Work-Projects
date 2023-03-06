DROP TABLE IF EXISTS work_in;
DROP TABLE IF EXISTS work_proj;
DROP TABLE IF EXISTS Graduate;
DROP TABLE IF EXISTS Project;
DROP TABLE IF EXISTS Dept;
DROP TABLE IF EXISTS Professor;
CREATE TABLE Professor(ssn INTEGER NOT NULL, name TEXT, age INTEGER, rank INTEGER, specialty TEXT, PRIMARY KEY(ssn));
--If a Professor is fired, a project is not deleted but a default is set until the Professor supervising is updated
CREATE TABLE Project(pno INTEGER NOT NULL, sponsor TEXT, start_date DATE, end_date DATE, budget INTEGER, ssn INTEGER NOT NULL DEFAULT '0', 
PRIMARY KEY(pno), FOREIGN KEY (ssn) REFERENCES Professor(ssn) ON DELETE SET DEFAULT);
--Relationships cascade however, as they are deleted once either entities are deleted
CREATE TABLE work_in(pno INTEGER REFERENCES Project ON DELETE CASCADE, ssn INTEGER REFERENCES Professor ON DELETE CASCADE, PRIMARY KEY(pno, ssn));
--Similar logic to the project in regards to what happens if a manager is fired who runs a department
CREATE TABLE Dept(dno INTEGER NOT NULL, dname TEXT, office TEXT, ssn INTEGER NOT NULL DEFAULT '0', PRIMARY KEY(dno), 
FOREIGN KEY (ssn) REFERENCES Professor(ssn) ON DELETE SET DEFAULT);
--If somehow a Dept gets deleted, Graduate students shouldn't get deleted until they choose a new dept, therefore it is also set to default
CREATE TABLE Graduate(SSN INTEGER NOT NULL, name TEXT, age INTEGER, deg_pg TEXT, dno INTEGER NOT NULL DEFAULT '0', gradSSN INTEGER, 
PRIMARY KEY(SSN), FOREIGN KEY(dno) REFERENCES Dept ON DELETE SET DEFAULT, FOREIGN KEY(gradSSN) REFERENCES Graduate);
--Cascade logic similar to the logic earlier
CREATE TABLE work_proj(pno INTEGER NOT NULL, GSSN INTEGER NOT NULL DEFAULT '0', Pssn INTEGER NOT NULL DEFAULT '0', since DATE, PRIMARY KEY(pno, GSSN), 
FOREIGN KEY(pno) REFERENCES Project ON DELETE CASCADE, FOREIGN KEY(GSSN) REFERENCES Graduate(SSN) ON DELETE SET DEFAULT, FOREIGN KEY(Pssn) REFERENCES Professor(ssn) ON DELETE SET DEFAULT);


DROP TABLE IF EXISTS Plays;
DROP TABLE IF EXISTS Instrument;
DROP TABLE IF EXISTS Perform;
DROP TABLE IF EXISTS Songs;
DROP TABLE IF EXISTS Album;
DROP TABLE IF EXISTS Lives;
DROP TABLE IF EXISTS Telephone;
DROP TABLE IF EXISTS Place;
DROP TABLE IF EXISTS Musicians;

CREATE TABLE Musicians(ssn INTEGER NOT NULL, name TEXT, PRIMARY KEY(ssn));
CREATE TABLE Instrument(istrID INTEGER NOT NULL, dname TEXT, key TEXT, PRIMARY KEY(istrID));
--If either entity is deleted in this relationship the row should be deleted, so both deletes should cascade
CREATE TABLE Plays(istrID INTEGER REFERENCES Instrument ON DELETE CASCADE, ssn INTEGER REFERENCES Musicians ON DELETE CASCADE, PRIMARY KEY(ssn, istrID));
--An album shouldn't be able to reference a musician no longer in the database, so it would also be deleted as musician entities get deleted
CREATE TABLE Album(albumIdentifier INTEGER NOT NULL, copyrightDate DATE, speed INTEGER, title TEXT, ssn INTEGER NOT NULL, 
FOREIGN KEY(ssn) REFERENCES Musicians ON DELETE CASCADE, PRIMARY KEY(albumIdentifier));
--Song's need to identify albums, album no longer in the database = songs no longer in database
CREATE TABLE Songs(songID INTEGER NOT NULL, author TEXT, title TEXT, albumIdentifier INTEGER NOT NULL, FOREIGN KEY(albumIdentifier) REFERENCES Album ON DELETE CASCADE, 
PRIMARY KEY(songID));
--Relationship is deleted if either entity occurence is deleted
CREATE TABLE Perform(ssn INTEGER REFERENCES Musicians ON DELETE CASCADE, songID INTEGER REFERENCES Songs ON DELETE CASCADE, PRIMARY KEY(ssn, songID));
CREATE TABLE Place(address TEXT NOT NULL, PRIMARY KEY(address));
--Surrogate key created, but uniqueness of one to many phone_no/address still enforced
CREATE TABLE Telephone(phone_placeID INTEGER NOT NULL, address TEXT NOT NULL REFERENCES Place ON DELETE CASCADE, 
phone_no INTEGER NOT NULL, UNIQUE(address, phone_no), PRIMARY KEY(phone_placeID));
--Composite entity for many to many relationship between musician and lives relationship deleted if either entity is removed
CREATE TABLE Lives(ssn INTEGER NOT NULL, phone_placeID INTEGER NOT NULL, FOREIGN KEY(ssn) REFERENCES Musicians ON DELETE CASCADE, 
FOREIGN KEY(phone_placeID) REFERENCES Telephone ON DELETE CASCADE, PRIMARY KEY(ssn, phone_placeID));