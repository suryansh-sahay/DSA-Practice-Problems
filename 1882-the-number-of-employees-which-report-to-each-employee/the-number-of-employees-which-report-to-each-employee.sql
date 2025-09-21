# Write your MySQL query statement below

SELECT b.employee_id, b.name,
      COUNT(a.employee_id) as reports_count, 
      ROUND(AVG(a.age)) as average_age FROM Employees a
JOIN Employees b
ON a.reports_to=b.employee_id
GROUP BY b.employee_id
ORDER BY b.employee_id;
 