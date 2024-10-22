LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
  
ENTITY tb_ALU_4BIT IS
END tb_ALU_4BIT;
  
ARCHITECTURE behavioral OF tb_ALU_4BIT IS
  
-- Component Declaration for the Unit Under Test (UUT)
  
COMPONENT ALU_4BIT
PORT(
	a : IN signed(3 downto 0);
	b : IN signed(3 downto 0);
	s : IN std_logic_vector(1 downto 0);
	o : OUT signed(3 downto 0)
);
END COMPONENT;


-- Inputs
signal tb_a : signed(3 downto 0) := (others => '0');
signal tb_b : signed(3 downto 0) := (others => '0');
signal tb_s : std_logic_vector(1 downto 0) := (others => '0');
 
-- Outputs
signal tb_o : signed(3 downto 0);
  
BEGIN

-- Instantiate the Unit Under Test (UUT)
uut: ALU_4BIT PORT MAP(
	a => tb_a,
	b => tb_b,
	s => tb_s,
	o => tb_o
);

-- Stimulus process
stim_proc: process
begin
 
	tb_a <= "1001";
	tb_b <= "1111";
  
 	tb_s <= "00";
 	wait for 10 ns;
 	tb_s <= "01";
 	wait for 10 ns;
 	tb_s <= "10";
 	wait for 10 ns;
 	tb_s <= "11";
 	wait for 20 ns;

end process;

END behavioral;