SELECT s.sname, COUNT(p) AS partsCount 
FROM parts p, suppliers s, catalog c 
WHERE c.pid = p.pid AND c.sid = s.sid GROUP BY s.sname;

SELECT s.sname, COUNT(p) AS partsCount
FROM parts p, suppliers s, catalog c
WHERE c.pid= p.pid AND c.sid = s.sid 
GROUP BY s.sname
HAVING COUNT(p) >= 3;

SELECT s.sname, COUNT(p) AS partsCount 
FROM parts p, suppliers s, catalog c 
WHERE c.pid= p.pid AND c.sid = s.sid AND p.color = 'Green' 
GROUP BY s.sname;

DROP TABLE IF EXISTS 'redSuppliers';
DROP TABLE IF EXISTS 'greenSuppliers';
DROP TABLE IF EXISTS 'RandGSuppliers';

SELECT s.sname, s.sid INTO redSuppliers
FROM parts p, suppliers s, catalog c
WHERE c.pid = p.pid AND c.sid = s.sid AND p.color = 'Red';

SELECT s.sname, s.sid INTO greenSuppliers
FROM parts p, suppliers s, catalog c
WHERE c.pid = p.pid AND c.sid = s.sid AND p.color = 'Green';

SELECT s.sid, s.sname INTO RandGSuppliers
FROM suppliers s, redSuppliers rs, greenSuppliers gs
WHERE s.sid = rs.sid AND rs.sid = gs.sid;

SELECT rgs.sname, MAX(c.cost) as maxPart
FROM RandGSuppliers rgs, parts p, catalog c
WHERE rgs.sid = c.sid AND p.pid = c.pid
GROUP BY rgs.sname;