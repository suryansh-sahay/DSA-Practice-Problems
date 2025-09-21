# Write your MySQL query statement below

-- SELECT * FROM Customer c
-- RIGHT Join Product p
-- ON c.product_key=p.product_key;

SELECT customer_id 
FROM Customer
GROUP BY customer_id
HAVING count(distinct product_key)=(SELECT count(product_key) FROM Product);