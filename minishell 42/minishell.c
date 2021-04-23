#include "minishell.h"
//;                pwd   ;    cd         ..    ;   pwd   ;cd;pwd;;;  asdf;  cd   asdfasdf; pwd  pwd      pwd     pwd;  a=4;    b=5;    c=6   ;  a=10;pwd;  test   ;;;
int	main(void)
{
	t_minishell	m;
	minishell_init(&m);

	while (1)
	{
		m.fixed_tab = user_input(&(m.tab));
		while (*(m.tab))
		{
			m.dollar_question = 0;
			m.parser_block = 0;
			printf("<<%s>> <$%d>\n", *(m.tab), m.dollar_question);/////////////////////////
			if (ft_strchr(*(m.tab), '='))
			{
				set_variables(&m);
			}
			if (!m.parser_block)
				command_parser(&m);
			m.tab++;
		}
		free_tab(m.fixed_tab);
	}
}
