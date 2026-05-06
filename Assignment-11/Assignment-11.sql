-- DECLARE
--     num NUMBER:=&num;
--     i NUMBER;
--     flag BOOLEAN:=TRUE;
-- BEGIN
--     IF num<=1 THEN
--         flag:=FALSE;
--     ELSE
--         FOR i IN 2 .. FLOOR(SQRT(num)) LOOP
--             IF num MOD i = 0 THEN
--                 flag:=FALSE;
--                 EXIT;
--             END IF;
--         END LOOP;
--     END IF;

--     IF flag THEN
--         DBMS_OUTPUT.PUT_LINE(num || ' is a prime number.');
--     ELSE
--         DBMS_OUTPUT.PUT_LINE(num || ' is NOT a prime number.');
--     END IF;
-- END;
-- /

-- DECLARE
--     num NUMBER:=&num;
--     original NUMBER:=num;
--     rev NUMBER:=0;
--     digit NUMBER;
-- BEGIN
--     WHILE num>0 LOOP
--         digit:=MOD(num, 10);
--         rev:=rev*10+digit;
--         num:=TRUNC(num/10);
--     END LOOP;

--     DBMS_OUTPUT.PUT_LINE('Original Number: ' || original);
--     DBMS_OUTPUT.PUT_LINE('Reversed Number: ' || rev);
-- END;
-- /

-- DECLARE
--     n NUMBER:=&n;
--     a NUMBER:=0;
--     b NUMBER:=1;
--     c NUMBER;
--     i NUMBER:=1;
-- BEGIN
--     DBMS_OUTPUT.PUT_LINE('Fibonacci Series:');

--     WHILE i<=n LOOP
--         DBMS_OUTPUT.PUT_LINE(a);

--         c:=a+b;
--         a:=b;
--         b:=c;

--         i:=i+1;
--     END LOOP;
-- END;
-- /

-- DECLARE
--     num NUMBER:=&num;
-- BEGIN
--     IF MOD(num, 2)=0 THEN
--         DBMS_OUTPUT.PUT_LINE(num || ' is Even.');
--     ELSE
--         DBMS_OUTPUT.PUT_LINE(num || ' is Odd.');
--     END IF;
-- END;
-- /

-- DECLARE
--     str VARCHAR2(100):='&str';
--     rev VARCHAR2(100):='';
--     i NUMBER;
-- BEGIN
--     FOR i IN REVERSE 1 .. LENGTH(str) LOOP
--         rev:=rev || SUBSTR(str, i, 1);
--     END LOOP;

--     DBMS_OUTPUT.PUT_LINE('Original String: ' || str);
--     DBMS_OUTPUT.PUT_LINE('Reversed String: ' || rev);
-- END;
-- /

-- DECLARE
--     num NUMBER:=&num;
--     original NUMBER:=num;
--     rev NUMBER:=0;
--     digit NUMBER;
-- BEGIN
--     WHILE num>0 LOOP
--         digit:=MOD(num, 10);
--         rev:=rev*10+digit;
--         num:=TRUNC(num/10);
--     END LOOP;

--     IF rev=original THEN
--         DBMS_OUTPUT.PUT_LINE(original || ' is a Palindrome Number.');
--     ELSE
--         DBMS_OUTPUT.PUT_LINE(original || ' is NOT a Palindrome Number');
--     END IF;
-- END;
-- /

-- DECLARE
--     a NUMBER:=&a;
--     b NUMBER:=&b;
--     temp NUMBER;
-- BEGIN
--     DBMS_OUTPUT.PUT_LINE('Before Swap: A=' || a || ', B=' || b);

--     temp:=a;
--     a:=b;
--     b:=a;

--     DBMS_OUTPUT.PUT_LINE('After Swap: A=' || a || ', B=' || b);
-- END;
-- /

-- DECLARE
--     num NUMBER:=&num;
--     original NUMBER:=num;
--     digit NUMBER;
--     sum NUMBER:=0;
--     n NUMBER;
-- BEGIN
--     n:=LENGTH(num);

--     WHILE num>0 LOOP
--         digit:=MOD(num, 10);
--         sum:=sum+POWER(digit, n);
--         num:=TRUNC(num/10);
--     END LOOP;

--     IF sum=original THEN
--         DBMS_OUTPUT.PUT_LINE(original || ' is an Armstrong Number.');
--     ELSE
--         DBMS_OUTPUT.PUT_LINE(original || ' is NOT an Armstrong Number.');
--     END IF;
-- END;
-- /

-- DECLARE
--     a NUMBER:=&a;
--     b NUMBER:=&b;
--     c NUMBER:=&c;
--     greatest NUMBER;
-- BEGIN
--     IF a>=b AND a>=c THEN
--         greatest:=a;
--     ELSIF b>=a AND b>=c THEN
--         greatest:=b;
--     ELSE
--         greatest:=c;
--     END IF;

--     DBMS_OUTPUT.PUT_LINE('Greatest Number= ' || greatest);
-- END;
-- /

-- BEGIN
--     FOR i IN 1..5 LOOP
--         DBMS_OUTPUT.PUT_LINE(RPAD('*', i, '*'));
--     END LOOP;
-- END;
-- /

-- BEGIN
--     FOR i IN REVERSE 1..5 LOOP
--         DBMS_OUTPUT.PUT_LINE(LPAD(' ', 5-i) || RPAD('*', i, '*'));
--     END LOOP;
-- END;
-- /

-- BEGIN
--     FOR i IN 1..5 LOOP
--         DBMS_OUTPUT.PUT_LINE(LPAD(' ', 5-i) || RPAD('*', 2*i-1, '*'));
--     END LOOP;
-- END;
-- /