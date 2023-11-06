-- 코드를 입력하세요
with recursive cte as (
    select 0 as num
    union all
    select num+1
    from cte
    where num < 23
)

select cte.num, ifnull(t.a, 0)
from cte
left join (select hour(datetime) as h, count(animal_id) as a
           from animal_outs
           group by hour(datetime)
           ) as t
           on t.h = cte.num