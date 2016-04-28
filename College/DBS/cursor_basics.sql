declare
cursor c1 is select id from firefox;
some number;
--some firefox.id%type;
begin
open c1;
loop
	fetch c1 into some;
	exit when c1%notfound;	
	dbms_output.put_line(some);
end loop;
close c1;
end;
/
-- insert into firefox values('01/09/2090', 4);
--if sql%not_found then
	--	goto quit;
	--end if;		
--<<quit>>	