--SELECT * 
--FROM ORD 
--WHERE CUSTID = (
--    SELECT CUSTID
--    FROM CUSTOMER
--    WHERE NAME = 'VOLLYRITE'
--    );

--SELECT NAME 
--FROM CUSTOMER
--WHERE CUSTID IN (
--    SELECT CUSTID
--    FROM ORD
--    WHERE ORDID IN (
--        SELECT ORDID
--        FROM ITEM
--        WHERE PRODID = (
--            SELECT PRODID
--            FROM PRODUCT
--            WHERE 
--                DESCRIP = 'ACE TENNIS NET'
--        )
--    )
--);

--UPDATE ITEM
--SET ACTUALPRICE = ACTUALPRICE + 100
--WHERE 
--    PRODID = 100890
--    AND ORDID = (
--        SELECT ORDID
--        FROM ORD
--        WHERE 
--            CUSTID = 101
--            AND ORDERDATE = '7/01/1987'
--        )


        
            