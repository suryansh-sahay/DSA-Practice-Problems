# Write your MySQL query statement below

-- SELECT  ROUND(100*SUM(IF(order_date=customer_pref_delivery_date,1,0))/count(distinct order_date),2) as immediate_percentage FROM delivery
-- WHERE (customer_id, order_date) in 
--     (SELECT customer_id, MIN(order_date) 
--     FROM delivery
--     GROUP BY customer_id
--     );

# Write your MySQL query statement below
select 
    ROUND(Sum(IF(order_date = customer_pref_delivery_date, 1 ,0))* 100/Count(distinct customer_id), 2)
    as immediate_percentage
from delivery
where(customer_id, order_date) in
    (
        select customer_id, MIN(order_date)
        from delivery
        group by customer_id
    )
