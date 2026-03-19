CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT salary as getNthHighestSalary
      FROM(
       SELECT *,
        DENSE_RANK() OVER(ORDER BY salary DESC) as r
       FROM Employee
      ) as temp
      WHERE r=N
  );
END