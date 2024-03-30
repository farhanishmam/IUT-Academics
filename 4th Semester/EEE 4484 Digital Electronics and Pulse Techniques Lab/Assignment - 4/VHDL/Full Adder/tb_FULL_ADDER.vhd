LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY tb_full_adder IS
END tb_full_adder;

ARCHITECTURE behavioral OF tb_full_adder IS

COMPONENT full_adder
PORT(
	A, B, Cin : IN std_logic;
	S, Cout : OUT std_logic
);
END COMPONENT;
 
-- Inputs
signal A : std_logic := '0';
signal B : std_logic := '0';
signal Cin : std_logic := '0';
 
-- Outputs
signal S : std_logic;
signal Cout : std_logic;
 
BEGIN

uut: full_adder PORT MAP(
	A => A,
	B => B,
	Cin => Cin,
	S => S,
	Cout => Cout
);
 

stim_proc: process
begin
	wait for 30 ns;

	A <= '1';
	B <= '0';
	Cin <= '0';
	wait for 10 ns;
 
	A <= '0';
	B <= '1';
	Cin <= '0';
	wait for 10 ns;

	A <= '1';
	B <= '1';
	Cin <= '0';
	wait for 10 ns;

	A <= '0';
	B <= '0';
	Cin <= '1';
	wait for 10 ns;
 
	A <= '1';
	B <= '0';
	Cin <= '1';
	wait for 10 ns;
 
	A <= '0';
	B <= '1';
	Cin <= '1';
	wait for 10 ns;
 
	A <= '1';
	B <= '1';
	Cin <= '1';
	wait for 10 ns;

end process;

END architecture behavioral;