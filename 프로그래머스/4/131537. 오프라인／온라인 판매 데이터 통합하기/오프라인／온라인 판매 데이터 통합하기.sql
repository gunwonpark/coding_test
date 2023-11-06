-- 코드를 입력하세요
select sales_date, product_id, user_id, sales_amount
from(
    SELECT sales_date, product_id, user_id, sales_amount
    from online_sale
    union
    select sales_date, product_id, 'NULL' as user_id, sales_amount
    from offline_sale
) as t
where t.sales_date Like '2022-03%'
order by t.sales_date ASC, t.product_id ASC, t.user_id ASC;
SELECT * 
FROM (
SELECT DATE_FORMAT(SALES_DATE, '%Y-%m-%d') AS SALES_DATE, PRODUCT_ID, NULL AS USER_ID, SALES_AMOUNT
FROM OFFLINE_SALE 
UNION 
SELECT DATE_FORMAT(SALES_DATE, '%Y-%m-%d') AS SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
FROM ONLINE_SALE )A
WHERE SALES_DATE >= '2022-03-01' AND SALES_DATE <= '2022-03-31'
ORDER BY SALES_DATE ASC, PRODUCT_ID ASC, USER_ID ASC;