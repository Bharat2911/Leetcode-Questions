# Write your MySQL query statement below
select product_id ,"store1" as store ,store1 as price
From Products 
WHERE
store1 is not NULL

union 

select product_id ,"store2" as store ,store2 as price
From Products 
WHERE
store2 is not NULL


union

select product_id ,"store3" as store ,store3 as price
From Products 
WHERE
store3 is not NULL