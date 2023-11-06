-- 코드를 입력하세요
with un as(
    select * from First_Half
     UNION all
     select * from JULY
)

select flavor
from(
    SELECT flavor, sum(total_order) as total
    from un
    group by flavor
) as t
order by t.total DESC limit 3