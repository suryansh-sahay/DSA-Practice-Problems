# Write your MySQL query statement below

-- select sum(weight)  from (SELECT * FROM Queue
-- ORDER BY turn
-- LIMIT 3) As q;

SELECT person_name
FROM (SELECT person_name, SUM(weight) OVER (ORDER BY turn) as sum FROM Queue) as num
WHERE sum<=1000
ORDER BY sum DESC
LIMIT 1;
