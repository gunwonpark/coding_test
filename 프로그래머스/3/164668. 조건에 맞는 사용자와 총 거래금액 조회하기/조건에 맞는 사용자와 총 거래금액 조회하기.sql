-- 코드를 입력하세요
SELECT u.USER_ID, u.NICKNAME, SUM(b.PRICE) TOTAL_SALES
FROM USED_GOODS_BOARD b JOIN USED_GOODS_USER u ON b.WRITER_ID = u.USER_ID
WHERE b.STATUS = 'DONE'
GROUP BY b.WRITER_ID
HAVING SUM(b.PRICE) >= 700000
ORDER BY TOTAL_SALES;