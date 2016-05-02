
select V1.cust,v1.min,s.prod,s.day,s.month,s.year,s.state 
from v1,sales as s
where v1.cust=s.cust
and v1.min=s.quant