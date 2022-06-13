# Write your MySQL query statement below
select  employee_id,
case 
   WHEN 
      employee_id%2!=0
      AND name not like "M%"
   THEN 
     salary
   ELSE 
     0
    END As bonus
from Employees 
order by employee_id;