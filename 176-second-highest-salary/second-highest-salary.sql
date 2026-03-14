SELECT
CASE 
 WHEN COUNT(DISTINCT salary)<2 THEN NULL
 ELSE (
    SELECT MIN(salary)
    FROM (
        SELECT DISTINCT salary
        FROM Employee
        ORDER BY salary DESC 
        LIMIT 2
    ) as temp
 ) 
END AS SecondHighestSalary
FROM Employee;


