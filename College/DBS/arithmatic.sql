declare
no1 number;
no2 number;
op varchar2(1);
begin
dbms_output.put_line('Enter the first no:');
no1 := & no1;
dbms_output.put_line('Enter the second no:');
no2 := & no2;
dbms_output.put_line('Enter the operator:');
op := & op;

if op = '/' and no2 = 0 then
	raise zero_divide;
end if;
exception
	when zero_divide then dbms_output.put_line('Cannot divide when deno is 0');
end;	
/