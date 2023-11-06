-- 코드를 입력하세요
select f.category, price, f.product_name
from food_product f join
(SELECT category, max(price) as max_price
    from food_product
    where category in ('과자','국','김치','식용유')
    group by category
) as fv 
on f.category = fv.category and f.price = fv.max_price
order by price DESC;
