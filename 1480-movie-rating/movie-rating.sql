# Write your MySQL query statement below

(
SELECT u.name as results
FROM Users u
JOIN MovieRating mr
ON u.user_id=mr.user_id
GROUP BY u.user_id
ORDER BY COUNT(u.user_id) DESC, u.name
LIMIT 1
)

UNION ALL

(
SELECT m.title results
FROM Movies m
JOIN MovieRating mr
ON m.movie_id=mr.movie_id
WHERE MONTH(mr.created_at)=2 AND YEAR(mr.created_at)=2020
GROUP BY m.movie_id
ORDER BY AVG(mr.rating) DESC, m.title
LIMIT 1
);