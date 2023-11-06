-- 코드를 입력하세요
SELECT ins.animal_id, ins.name
from animal_ins as ins inner join animal_outs as outs on ins.animal_id = outs.animal_id
where ins.datetime < outs.datetime
order by ins.datetime ASC;

SELECT I.ANIMAL_ID, I.NAME FROM ANIMAL_INS AS I
INNER JOIN ANIMAL_OUTS AS O ON I.ANIMAL_ID = O.ANIMAL_ID
WHERE O.DATETIME < I.DATETIME
ORDER BY I.DATETIME ASC;