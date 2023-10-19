#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Command
{
	std::string cmd;
	std::vector<std::string> args;
};

Commands shell_commands;

int main(int ac, char** argv)
{
	Command current_command;

	while (1)
	{
		current_command.cmd = std::string();
		std::getline(std::cin, current_command.cmd);

		string[] cmd = current_command.cmd.split('');
		for (string arg:cmd)
		{
			if (arg != "--help")
			{
				shell_commands.push_back{Command()
				{
				cmd = arg,
				args = {arg},
				}};
			}
		}

		if (cmd[0] == "-")
		{
			shell_commands.pop_front();
		}

		//Execute the command
		shell_commands[0].execute();
	}

	return (0);
}
