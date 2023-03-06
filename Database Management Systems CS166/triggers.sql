CREATE SEQUENCE part_number_seq START WITH 50000;

CREATE LANGUAGE plpgsql;
CREATE OR REPLACE FUNCTION incPartNum()
 RETURNS "trigger" AS
 $BODY$
 BEGIN
 NEW.part_number := nextVal('part_number_seq');
 RETURN NEW;
 END;
 $BODY$
 LANGUAGE plpgsql VOLATILE;

CREATE TRIGGER part_nyc_trigger BEFORE INSERT
ON part_nyc FOR EACH ROW
EXECUTE PROCEDURE incPartNum()