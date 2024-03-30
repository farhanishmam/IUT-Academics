library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity full_adder is
port(
	A, B, Cin : in STD_LOGIC;
	S, Cout : out STD_LOGIC
);
end full_adder;

architecture gate_level of full_adder is

begin
	S <= A XOR B XOR Cin ;
	Cout <= (A AND B) OR (Cin AND A) OR (Cin AND B) ;
end gate_level;