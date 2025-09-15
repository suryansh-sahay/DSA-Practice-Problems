# Write your MySQL query statement below

SELECT b.unique_id, a.name FROM Employees as a
LEFT JOIN EmployeeUNI as b
ON a.id=b.id;
