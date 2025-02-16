library ieee;
use ieee.std_logic_1164.all;

entity tb_shift_reg_5bit is
end tb_shift_reg_5bit;

architecture behavioral of tb_shift_reg_5bit is

component shift_reg_5bit
port(
	clk : in std_logic;
	D : in std_logic_vector(3 downto 0);
	Q : out std_logic_vector(3 downto 0)
);
end component;

signal tb_clk : std_logic;
signal tb_D : std_logic_vector(3 downto 0);
signal tb_Q : std_logic_vector(3 downto 0);
constant clk_period : time := 100 ns;

begin
uut: shift_reg_5bit port map(
	clk => tb_clk,
	D => tb_D,
	Q => tb_Q
);

-- clock process
clk_process: process
begin
	tb_clk <= '0';
	wait for clk_period/2;
	tb_clk <= '1';
	wait for clk_period/2;
end process;

-- stimulus process
stim_process: process
begin
	tb_D<="0000";
	wait for 100 ns;
	tb_D <= "0100";
	wait for 100 ns;
	tb_D <= "1010";
	wait for 100 ns;
	tb_D <= "0110";
	wait for 100 ns;
end process;

end architecture behavioral;

