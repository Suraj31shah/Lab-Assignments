SET SERVEROUTPUT ON;

DECLARE
    num NUMBER:=&num;
    i NUMBER;
    flag BOOLEAN:=TRUE;
BEGIN
    IF num<=1 THEN
        flag:=FALSE;
    ELSE
        FOR i IN 2 .. FLOOR(SQRT(num)) LOOP
            IF num MOD i = 0 THEN
                flag:=FALSE;
                EXIT;
            END IF;
        END LOOP;
    END IF;

    IF flag THEN
        DBMS_OUTPUT.PUT_LINE(num || ' is a prime number.');
    ELSE
        DBMS_OUTPUT.PUT_LINE(num || ' is NOT a prime number.');
    END IF;
END;
/