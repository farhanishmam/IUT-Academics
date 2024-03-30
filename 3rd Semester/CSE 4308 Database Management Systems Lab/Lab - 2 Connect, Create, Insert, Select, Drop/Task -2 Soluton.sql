create user USER20 identified BY iutcse;
grant create session, resource TO USER20;

create table players
(
	Kit_No int,
	Name VARCHAR2(30),
	Age INT,
	Batting_Style VARCHAR2(5) CHECK(Batting_Style = 'Left' OR Batting_Style = 'Right') ,
	Domestic_Team VARCHAR2(15),
	Height INT
);

ALTER TABLE players ADD CONSTRAINT pk_1 PRIMARY KEY(Kit_No);

create table grades 
(
	Kit_No int,
	Run INT,
	Competition VARCHAR2(4)
);

ALTER TABLE grades ADD CONSTRAINT fk FOREIGN KEY(kit_no) REFERENCES players;
ALTER TABLE grades ADD CONSTRAINT pk2 PRIMARY KEY(kit_no, Competition);
