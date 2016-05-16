create table flights
	(
		fid varchar2(10) primary key,
		from_place varchar2(20),
		to_place varchar2(20),
		distance number(5, 2),
		departs varchar2(10),
		arrives varchar2(20),
		price number
		);

create table Aircraft
	(
		aid varchar2(10) primary key,
		aname varchar2(10),
		cruisingrange number
	);

create table Certified
	(
		eid varchar2(10),
		aid varchar2(10) primary key
	);

create table employee
	(
		eid varchar2(10) primary key,
		ename varchar2(20),
		salary number(6, 2)
	);

-- find the names of all the employees and the aid on which they have Certified.
select ename, aid from employee natural join certified;
-- find the names of pilots whose salary is less than the price of the cheapest route from bengaluru to frankfurt.
select ename from employee where salary < 
(select min(price) from flights where from_place = 'bengaluru' and to_place = 'frankfurt');
-- find the names of aircraft such that all pilots certified to operate them have salaries more than 10000.
select unique(aname) from aircraft natural join certified natural join employee where salary > 10000;

-- write a pl sql block that will display the names of employees with first 3 highest salary.
declare
	cursor c1 is
		select ename from employee order by salary desc;
	name1 employee.ename%type;
	name2 employee.ename%type;
	name3 employee.ename%type;
	counter number := 0;

begin
	open c1;
	loop
		if counter = 0 then
			fetch c1 into name1;
		elsif counter = 1 then
			fetch c1 into name2;
		elsif counter = 2 then
			fetch c1 into name3;
		else
			dbms_output.put_line(name1);
			dbms_output.put_line(name2);
			dbms_output.put_line(name3);
			exit;
		end if;			
		counter := counter + 1;			
		
	end loop;
	close c1;
end;
/	

-- write a database trigger on Aircraft table. The system should keep track of the records that are begin updated the old values of the 
-- updated record should be added in OldAircraft table if the new cruising range is more than 3500

create or replace trigger record
	after update or delete on aircraft
	for each row
	begin
		case
			when updating then
				if :new.cruisingrange > 3500 then
					insert into OldAircraft values(:old.aid, :old.aname, :old.cruisingrange);
				end if;
			when deleting then
				insert into OldAircraft values(:old.aid, :old.aname, :old.cruisingrange);
		end case;
	end;
	/							

-- 

create of replace function
	nothing(no number)
	return number as tot number;
	begin
		tot := no / 2;
		return tot;
	end;
	/

create or replace procedure somethingelse is
	begin
		dbms_output.put_line('I wanna die in an epic way.');
	end;
	/		
