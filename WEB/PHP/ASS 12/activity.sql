drop table book;
create table book(book_name varchar(50) primary key,book_author varchar(20),book_category varchar(20),book_price int);

insert into book values('Think and grow rich','Oscar wilde','novel',230);
insert into book values('Harry Potter','J.K Rowling','Fantasy',500);
insert into book values('Rich dad and poor dad','Alexander Dumas','novel',450);
insert into book values('ignite mind','A P J Abdul Kalam','novel',350);

select * from book;
