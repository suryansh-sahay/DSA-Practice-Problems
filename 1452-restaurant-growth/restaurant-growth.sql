-- WITH daily AS (
--     SELECT 
--         visited_on,
--         SUM(amount) AS daily_amount
--     FROM Customer
--     GROUP BY visited_on
-- )

WITH daily as(
    SELECT visited_on, SUM(amount) as daily_amount
    FROM Customer  
    GROUP BY visited_on
)
SELECT 
    visited_on, 
    SUM(daily_amount) OVER(
        ORDER BY visited_on 
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ) as amount,

    ROUND(AVG(daily_amount) OVER(
    ORDER BY visited_on 
    ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ), 2) as average_amount
    
FROM daily
LIMIT 6,100000;

