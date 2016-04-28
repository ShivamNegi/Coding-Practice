-- when exception_name then statement
declare
no_rows number;
lolface exception;
begin
update names set name = 'something' where name like 'shiv%';
no_rows := sql%rowcount;
dbms_output.put_line('The number of rows are: ' || no_rows);
if sql%notfound	then
	raise NO_DATA_FOUND;
else
	raise lolface;	
end if;	
exception
when NO_DATA_FOUND then dbms_output.put_line('There are no such rows.');
when lolface then dbms_output.put_line('Welcome to the lolface.');
end;
/