library ieee;
use ieee.std_logic_1164.all;

entity tb_demux_1x8 is
end tb_demux_1x8;

architecture behavioral of tb_demux_1x8 is

component demux_1x8
port(
	i:in std_logic;
	s:in std_logic_vector(2 downto 0);
	o:out std_logic_vector(7 downto 0)
);
end component;

-- Inputs
signal tb_i : std_logic := '0';
signal tb_s : std_logic_vector (2 downto 0) := (others => '0');

-- Outputs
signal tb_o : std_logic_vector (7 downto 0) := (others => '0');

begin

uut: demux_1x8 port map (
	i => tb_i,
	s => tb_s,
	o => tb_o
);


-- stimulus process
stim_process: process
begin
	tb_i<='1';
	wait for 10 ns;
	tb_s <= "000";
	wait for 10 ns;
	tb_s <= "001";
	wait for 10 ns;
	tb_s <= "010";
	wait for 10 ns;
	tb_s <= "011";
	wait for 10 ns;
	tb_s <= "100";
	wait for 10 ns;
	tb_s <= "101";
	wait for 10 ns;
	tb_s <= "110";
	wait for 10 ns;
	tb_s <= "111";
	wait for 20 ns;
	tb_i<='0';
	wait for 10 ns;
	tb_s <= "000";
	wait for 10 ns;
	tb_s <= "001";
	wait for 10 ns;
	tb_s <= "010";
	wait for 10 ns;
	tb_s <= "011";
	wait for 10 ns;
	tb_s <= "100";
	wait for 10 ns;
	tb_s <= "101";
	wait for 10 ns;
	tb_s <= "110";
	wait for 10 ns;
	tb_s <= "111";
	wait for 20 ns;
end process;

end architecture behavioral;