declare
x number;
fact number;
begin
x := &x;
fact := 1;

for i in 1 .. x
	loop
	fact := fact * i;
	end loop;
dbms_output.put_line('The factorial is');
dbms_output.put_line(fact);
end;
/