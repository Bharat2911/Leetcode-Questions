# Write your MySQL query statement below

# union kar do dono tabel se employee id ko
select employee_id 
FROM Employees 
WHERE 
employee_id not in (select employee_id from Salaries )

union

select employee_id
from Salaries 
where
employee_id not in (select employee_id from Employees)

order by employee_id ASc;
