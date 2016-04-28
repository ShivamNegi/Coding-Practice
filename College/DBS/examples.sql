alter table table_name add column_name datatype;
alter table table_name modify column_name datatype;
alter table table_name drop column column_name;
truncate table table_name;
delete table table_name;

rename old_table_name to new_table_name;
delete from table_name where conditions;
update table_name set something where conditions;


-- a function to check if the given number is prime or not
create or replace function isprime(no number)
	return number as flag number;
	begin
		for i in 2 .. round(sqrt(no)) 
			loop
				if no mod i = 0 then
					flag := 0;
				end if;					
			end loop;
		return flag;			
	end;
	/


