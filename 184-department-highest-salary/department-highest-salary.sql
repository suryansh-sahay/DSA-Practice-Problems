# Write your MySQL query statement below

-- SELECT d.name as Department, e.name as Employee, Salary
-- FROM Employee e
-- JOIN Department d
-- ON e.departmentId=d.id
-- WHERE salary=(
--     SELECT MAX(salary) 
--     FROM Employee
--     WHERE departmentId=d.id
-- );

SELECT Department, Employee, Salary
FROM(
SELECT d.name as Department, 
    e.name as Employee,
    Salary,
    RANK() OVER(PARTITION BY departmentID
                    ORDER BY salary DESc) AS r
FROM Employee e
JOIN Department d
ON e.departmentId=d.id) as temp
WHERE r=1;