# Write your MySQL query statement below

SELECT a.user_id, ROUND(IFNULL(SUM(action="confirmed")/COUNT(a.user_id),0),2) as confirmation_rate  
FROM Signups as a
LEFT JOIN Confirmations as b
ON a.user_id = b.user_id
GROUP BY a.user_id;