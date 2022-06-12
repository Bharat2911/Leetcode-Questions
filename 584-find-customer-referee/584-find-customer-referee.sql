# Write your MySQL query statement below
select name
FROM customer
WHERE ( referee_id is NULL || referee_id!=2);
