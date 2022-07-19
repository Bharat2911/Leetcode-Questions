# Write your MySQL query statement below
select
 wt1.id
from
Weather wt1,Weather wt2

where
 datediff(wt1.recordDate,wt2.recordDate)=1
 
 and
 
 wt1.temperature>wt2.temperature;