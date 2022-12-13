#include "shell.h"

/**
 * _myexit - exit the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype
 * Return: exits with a give nexit status
 * (0) if info.argv[0] != "exit"
 */

int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* if there is an exit arg */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
