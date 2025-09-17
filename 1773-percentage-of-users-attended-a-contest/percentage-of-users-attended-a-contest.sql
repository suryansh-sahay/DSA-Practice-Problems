# Write your MySQL query statement below

SELECT contest_id, 
    ROUND(count(user_id)*100/(SELECT count(user_id) FROM Users),2) as percentage 
FROM Register 
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;