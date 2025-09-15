# Write your MySQL query statement below

SELECT customer_id, count(customer_id) as count_no_trans FROM Visits as a
LEFT JOIN Transactions as b
ON a.visit_id=b.visit_id 
WHERE b.visit_id IS NULL
GROUP BY a.customer_id;
