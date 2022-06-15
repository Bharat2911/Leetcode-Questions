# Write your MySQL query statement below

select sell_date , Count(distinct product) 'num_sold' ,
Group_concat(Distinct product order by product) 'products'
from activities group by sell_date;