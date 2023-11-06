-- 코드를 입력하세요


SELECT distinct a.car_id, a.car_type, ROUND(a.DAILY_FEE * (1- (c.DISCOUNT_RATE / 100))) as fee
from CAR_RENTAL_COMPANY_CAR as a join CAR_RENTAL_COMPANY_RENTAL_HISTORY as b join CAR_RENTAL_COMPANY_DISCOUNT_PLAN as c 
on a.car_id = b.car_id and a.car_type = c.car_type
where (b.start_date > '2022-11-30' or b.end_date < '2022-11-01')
and (a.car_type = '세단' or a.car_type = 'SUV')
and a.car_type in (
    select distinct a.car_type
    from CAR_RENTAL_COMPANY_CAR as a join CAR_RENTAL_COMPANY_DISCOUNT_PLAN as c on a.car_type = c.car_type
    where c.duration_type = '30일 이상' and a.daily_fee * c.discount_rate > 500000 
    and a.daily_fee * c.discount_rate < 2000000
    )   
order by fee DESC, a.car_type ASC, a.car_id DESC;

SELECT A.CAR_ID, A.CAR_TYPE, ROUND(A.DAILY_FEE * (1- (P.DISCOUNT_RATE / 100)) * 30, 0) AS FEE
FROM CAR_RENTAL_COMPANY_CAR AS A 
JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN AS P
ON A.CAR_TYPE = P.CAR_TYPE
WHERE 
    A.CAR_TYPE IN ('세단', 'SUV')
    AND P.DURATION_TYPE = '30일 이상'
    AND A.DAILY_FEE * (1 - (P.DISCOUNT_RATE / 100)) * 30 BETWEEN 500000 AND 2000000
    AND A.CAR_ID NOT IN (
        SELECT CAR_ID
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE END_DATE >= '2022-11-01' AND START_DATE < '2022-12-01'
)
ORDER BY FEE DESC, A.CAR_TYPE, A.CAR_ID DESC;