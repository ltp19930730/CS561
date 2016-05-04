with quarter as(
select case
when month <= 3 then 'Q1'
when month <= 6 and month > 3 then 'Q2'
when month > 6 and month <= 9 then 'Q3'
when month > 9 and month <= 12 then 'Q4' end quar
from sales
group by quar
),
combi as(
select cust,prod,quar
from sales,quarter
group by cust,prod,quar
),
q1 as(
select cust, prod, round(sum/count) as avg
from
(select 
cust,prod ,sum(quant),count(quant)
from sales
where month<=3
group by cust, prod) as s
),

q2 as(
select cust, prod, round(sum/count) as avg
from
(select 
cust,prod ,sum(quant),count(quant)
from sales
where month<=6 and month>3
group by cust, prod) as s
),

q3 as(
select cust, prod, round(sum/count) as avg
from
(select 
cust,prod ,sum(quant),count(quant)
from sales
where month<=9 and month>6
group by cust, prod) as s
),

q4 as(
select cust, prod, round(sum/count) as avg
from
(select 
cust,prod ,sum(quant),count(quant)
from sales
where month>=10
group by cust, prod) as s
),


re as(
select combi.cust,combi.prod,combi.quar,
case 
when combi.quar='Q1' then NULL 
when combi.quar='Q2' then q1.avg 
when combi.quar='Q3' then q2.avg 
when combi.quar='Q4' then q3.avg end Before_Avg,
case 
when combi.quar='Q1' then q2.avg 
when combi.quar='Q2' then q3.avg 
when combi.quar='Q3' then q4.avg 
when combi.quar='Q4' then NULL end After_Avg

from combi
left outer join q1 on combi.cust=q1.cust and combi.prod=q1.prod
left outer join q2 on combi.cust=q2.cust and combi.prod=q2.prod
left outer join q3 on combi.cust=q3.cust and combi.prod=q3.prod
left outer join q4 on combi.cust=q4.cust and combi.prod=q4.prod
)
select * from re where Before_Avg is null or After_Avg is null or Before_Avg<After_Avg
order by  quar