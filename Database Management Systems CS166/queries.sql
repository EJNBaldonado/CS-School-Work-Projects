SELECT p.pid 
FROM parts p, catalog c 
WHERE p.pid = c.pid AND c.cost < 10;

SELECT p.pname
FROM parts p, catalog c 
WHERE p.pid = c.pid AND c.cost < 10;

SELECT s.address 
FROM suppliers s, parts p, catalog c 
WHERE s.sid = c.sid AND p.pid = c.pid AND pname = 'Fire Hydrant Cap';

SELECT s.sname 
FROM suppliers s, parts p, catalog c 
WHERE s.sid = c.sid AND p.pid = c.pid AND p.color = 'Green';

SELECT s.sname, p.pname 
FROM parts p, suppliers s, catalog c 
WHERE s.sid = c.sid AND p.pid = c.pid;