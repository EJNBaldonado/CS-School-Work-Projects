-- Count how many parts in NYC have more than 70 parts in hand
SELECT COUNT(*) AS NYC_on_hand_higher_70
FROM part_nyc pn
WHERE pn.on_hand > 70;

-- Count how many total parts on_hand, in both NYC and SFO, are Red
SELECT COUNT(pn.on_hand) + COUNT(ps.on_hand) AS Sum_both_red_in_hand
FROM part_nyc pn, part_sfo ps, color c
WHERE (c.color_id = pn.color AND c.color_id = ps.color) AND ps.part_number = pn.part_number AND c.color_name = 'Red';

-- List all the suppliers that have more total on_hand parts in NYC than they do in SFO
SELECT *
FROM supplier s
WHERE s.supplier_id IN (SELECT pn.supplier
                        FROM part_sfo ps, part_nyc pn
                        WHERE ps.supplier = pn.supplier
                        GROUP BY pn.supplier
                        HAVING SUM(pn.on_hand) > SUM(ps.on_hand));

-- List all suppliers that supply parts in NYC that aren't supplied by anyone in SFO
SELECT *
FROM supplier s
WHERE s.supplier_id IN (SELECT DISTINCT pn.supplier
                        FROM part_nyc pn
                        LEFT JOIN
                        part_sfo ps
                        ON ps.part_number = pn.part_number
                        WHERE ps.part_number IS NULL);

--Update all of the NYC on_hand values to on_hand - 10
UPDATE part_nyc
SET on_hand = on_hand - 10
WHERE on_hand >= 10;

--Delete all parts from NYC which have less than 30 parts on_hand
DELETE FROM part_nyc
WHERE on_hand < 30;