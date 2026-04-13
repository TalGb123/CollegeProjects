--SET SERVEROUTPUT ON
--
--DECLARE 
--    
--BEGIN
--    UPDATE EMP
--    SET SAL = SAL * 1.15
--    WHERE DEPTNO = 10;
--END;
--/

DECLARE
    var_old EMP.JOB%TYPE := 'MANAGER';
    var_new EMP.JOB%TYPE := 'SALESMAN';
    var_count NUMBER;
BEGIN
    UPDATE EMP
    SET JOB = var_new
    WHERE JOB = var_old;
    
    var_count := SQL%ROWCOUNT;
    
    IF var_count > 0 THEN
        DBMS_OUTPUT.PUT_LINE(var_count || 'emp updated');
    ELSE
        DBMS_OUTPUT.PUT_LINE('No records updated');
    END IF;
END;
/

