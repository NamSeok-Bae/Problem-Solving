-- 코드를 입력하세요
SELECT FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
FROM REST_INFO AS A 
WHERE A.FAVORITES = (SELECT MAX(FAVORITES) FROM REST_INFO WHERE A.FOOD_TYPE = REST_INFO.FOOD_TYPE)
ORDER BY FOOD_TYPE DESC