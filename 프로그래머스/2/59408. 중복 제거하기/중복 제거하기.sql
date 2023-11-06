-- 코드를 입력하세요
select count(*)
from(
    SELECT distinct name
    from animal_ins
    where name is not null
    ) as a;