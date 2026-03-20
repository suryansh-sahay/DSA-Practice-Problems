# Write your MySQL query statement below


-- SELECT *,
--     LAG(student) OVER() as p, 
--     LEAD(student) OVER() as n
-- FROM Seat;

SELECT id,
CASE 
    WHEN id%2=1 THEN COALESCE(LEAD(student) OVER(), student)
ELSE
    LAG(student) OVER()
END AS student
FROM Seat;
    