select cust,prod,state,round(avg(quant)),round((
select avg(quant)
from sales s
where s.state!=sales.state and s.cust=sales.cust and s.prod=sales.prod)) as OTHER_STATE_AVG,round((
select avg(quant)
from sales s_2
where s_2.state=sales.state and s_2.cust=sales.cust and s_2.prod!=sales.prod)) as OTHER_PROD_AVG 
from sales 
GROUP BY cust,prod,state
ORDER BY cust,prod,state