# Write your MySQL query statement below

WITH ids as(SELECT requester_id as id FROM RequestAccepted
UNION ALL 
SELECT accepter_id FROM RequestAccepted)

SELECT id, COUNT(id) AS num
FROM ids
GROUP BY id
ORDER BY num DESC
LIMIT 1;