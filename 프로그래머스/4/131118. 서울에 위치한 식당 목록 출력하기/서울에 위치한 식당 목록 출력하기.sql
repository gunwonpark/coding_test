-- 코드를 입력하세요
select rest_id, rest_name, food_type, favorites, address, round(avg(review_score),2) as score
from(
    SELECT rest_info.rest_id, rest_name, food_type, favorites, address, review_score
    from rest_info join rest_review on rest_info.rest_id = rest_review.rest_id
    where address like '서울%'
    ) as r
group by rest_id
order by score desc, favorites desc;