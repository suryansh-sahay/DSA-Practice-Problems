# Write your MySQL query statement below

SELECT a.name FROM employee as a
JOIN employee as b
ON a.id=b.managerID
GROUP BY a.id HAVING count(a.id)>=5;